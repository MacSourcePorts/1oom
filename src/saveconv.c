#include "config.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "main.h"
#include "game/game.h"
#include "lib.h"
#include "log.h"
#include "os.h"
#include "save/save.h"
#include "util.h"

/* -------------------------------------------------------------------------- */

const char *idstr_main = "saveconv";

bool main_use_lbx = false;
bool ui_use_audio = false;

/* -------------------------------------------------------------------------- */

static struct game_s *gameptr = 0;

typedef enum {
    SAVETYPE_SMART = 0,
    SAVETYPE_MOO13,
    SAVETYPE_1OOM0,
    SAVETYPE_TEXT,
    SAVETYPE_DUMMY,
    SAVETYPE_NUM
} savetype_t;

#define SAVETYPE_NATIVE     SAVETYPE_1OOM0

#define SAVETYPE_F_OPTOUT   (1 << 1)

static int savetype_de_smart(struct game_s *g, const char *fname);
static int savetype_de_1oom0(struct game_s *g, const char *fname);
static int savetype_en_1oom0(struct game_s *g, const char *fname);

static const struct {
    const char *name;
    int (*decode)(struct game_s *g, const char *fname); /* to native */
    int (*encode)(struct game_s *g, const char *fname);
    uint8_t flags;
    savetype_t othertype;
} savetype[SAVETYPE_NUM] = {
    { /* SAVETYPE_SMART */
        "smart",
        savetype_de_smart,
        0,
        0, SAVETYPE_NUM
    },
    { /* SAVETYPE_MOO13 */
        "MOO v1.3",
        savetype_de_moo13,
        savetype_en_moo13,
        0, SAVETYPE_NATIVE
    },
    { /* SAVETYPE_1OOM0 */
        "1oom save version 0",
        savetype_de_1oom0,
        savetype_en_1oom0,
        0, SAVETYPE_MOO13
    },
    { /* SAVETYPE_TEXT  */
        "text",
        savetype_de_text,
        savetype_en_text,
        SAVETYPE_F_OPTOUT, SAVETYPE_NATIVE
    },
    { /* SAVETYPE_DUMMY */
        "dummy",
        0,
        0,
        0, SAVETYPE_NUM
    }
};

static const struct {
    char const * const str;
    const savetype_t type;
} savetype_match[] = {
    { "m", SAVETYPE_MOO13 },
    { "1", SAVETYPE_1OOM0 },
    { "s", SAVETYPE_SMART },
    { "t", SAVETYPE_TEXT },
    { "d", SAVETYPE_DUMMY },
    { 0, 0 }
};

static savetype_t savetypei = SAVETYPE_SMART;
static savetype_t savetypeo = SAVETYPE_SMART;
static int main_fname_num = 0;
static const char *fnames[2] = { 0/*in*/, 0/*out*/ };

/* -------------------------------------------------------------------------- */

static int savetype_de_smart(struct game_s *g, const char *fname)
{
    struct libsave_1oom_hdr_data_s hdr_data;
    FILE *fd;
    int res;
    LOG_DEBUG((2, "%s: '%s'\n", __func__, fname));
    if ((fd = fopen(fname, "rb")) == 0) {
        log_error("opening file '%s'\n", fname);
        return -1;
    }
    fclose(fd);
    fd = NULL;
    if (libsave_1oom_read_header(fname, &hdr_data) && (hdr_data.version == GAME_SAVE_VERSION)) {
        savetypei = SAVETYPE_NATIVE;
        res = savetype[SAVETYPE_NATIVE].decode(g, fname);
    } else if (savetype_is_moo13(g, fname)) {
        savetypei = SAVETYPE_MOO13;
        res = savetype_de_moo13(g, fname);
    } else if (savetype_is_text(g, fname)) {
        savetypei = SAVETYPE_TEXT;
        res = savetype_de_text(g, fname);
    } else {
        log_error("file '%s' type autodetection failed\n", fname);
        return -1;
    }
    LOG_DEBUG((1, "%s: i '%s' o '%s'\n", __func__, savetype[savetypei].name, savetype[savetypeo].name));
    if (savetypeo == SAVETYPE_SMART) {
        savetype_t typeo = savetype[savetypei].othertype;
        if (typeo == SAVETYPE_NUM) {
            log_error("BUG: no other type for type '%s'\n", savetype[savetypei].name);
            return -1;
        }
        savetypeo = typeo;
        LOG_DEBUG((1, "%s: diverted to '%s'\n", __func__, savetype[typeo].name));
    }
    return res;
}

/* -------------------------------------------------------------------------- */

static int savetype_de_1oom0(struct game_s *g, const char *fname)
{
    char *sname = (*savename == '\0') ? savename : NULL;
    LOG_DEBUG((2, "%s: '%s'\n", __func__, fname));
    return libsave_1oom_do_load(fname, g, -1, sname);
}

static int savetype_en_1oom0(struct game_s *g, const char *fname)
{
    LOG_DEBUG((2, "%s: '%s'\n", __func__, fname ? fname : "(null)"));
    return libsave_1oom_do_save(fname, savename, g, -1);
}

/* -------------------------------------------------------------------------- */

static void savegame_usage(void)
{
    log_message_direct("Usage:\n    1oom_saveconv [OPTIONS] INPUT [OUTPUT]\n");
}

void (*main_usage)(void) = savegame_usage;

int main_handle_option(const char *argv)
{
    if (main_fname_num < 2) {
        fnames[main_fname_num++] = argv;
        return 0;
    } else {
        log_error("too many parameters!\n");
        return -1;
    }
}

static int saveconv_opt_typeo(char **argv, void *var)
{
    int i = 0;
    while (savetype_match[i].str) {
        if (strcmp(savetype_match[i].str, argv[1]) == 0) {
            savetypeo = savetype_match[i].type;
            LOG_DEBUG((1, "%s: set output type to '%s' -> '%s'\n", __func__, argv[1], savetype[savetypeo].name));
            return 0;
        }
        ++i;
    }
    log_error("unknown type '%s'\n", argv[1]);
    return -1;
}

static int saveconv_opt_typei(char **argv, void *var)
{
    int i = 0;
    while (savetype_match[i].str) {
        if (strcmp(savetype_match[i].str, argv[1]) == 0) {
            if (savetype[savetypei].decode) {
                savetypei = savetype_match[i].type;
                LOG_DEBUG((1, "%s: set input type to '%s' -> '%s'\n", __func__, argv[1], savetype[savetypei].name));
                return 0;
            } else {
                log_error("unknown type '%s' is not a valid input type\n", savetype[savetypei].name);
                return -1;
            }
        }
        ++i;
    }
    log_error("unknown type '%s'\n", argv[1]);
    return -1;
}

static int saveconv_opt_cmoo_en(char **argv, void *var)
{
    opt_use_configmoo = true;
    LOG_DEBUG((1, "%s\n", __func__));
    return 0;
}

static int saveconv_opt_sname(char **argv, void *var)
{
    strncpy(savename, argv[1], SAVE_NAME_LEN);
    savename[SAVE_NAME_LEN - 1] = '\0';
    LOG_DEBUG((1, "%s: set save name '%s'\n", __func__, savename));
    return 0;
}

const struct cmdline_options_s main_cmdline_options_early[] = {
    { "-i", 1,
      saveconv_opt_typei, 0,
      "INTYPE", "Input type:\n"
                 "  s   - smart: autodetect (default)\n"
                 "  m   - MOO1 v1.3\n"
                 "  1   - 1oom save version 0\n"
                 "  t   - text"
    },
    { "-o", 1,
      saveconv_opt_typeo, 0,
      "OUTTYPE", "Output type:\n"
                 "  s   - smart: in old/new -> out new/old (default)\n"
                 "  m   - MOO1 v1.3\n"
                 "  1   - 1oom save version 0\n"
                 "  t   - text\n"
                 "  d   - dummy (no output)"
    },
    { "-cmoo", 0,
      saveconv_opt_cmoo_en, 0,
      NULL, "Enable CONFIG.MOO use"
    },
    { "-n", 1,
      saveconv_opt_sname, 0,
      "NAME", "Set save name"
    },
    { 0, 0, 0, 0, 0, 0 }
};

const struct cmdline_options_s main_cmdline_options[] = {
    { 0, 0, 0, 0, 0, 0 }
};

/* -------------------------------------------------------------------------- */

static int main_early_init(void)
{
    if (os_early_init()) {
        return 1;
    }
    gameptr = lib_malloc(sizeof(struct game_s));
    libsave_init();
    return 0;
}

static int main_init(void)
{
    if (os_init()) {
        return 1;
    }
    return 0;
}

static void main_shutdown(void)
{
    libsave_shutdown();
    lib_free(gameptr);
    os_shutdown();
}

int main_do(void)
{
    int res;
    uint32_t v;
    const char *fname;
    if (main_fname_num == 0) {
        options_show_usage();
        return 0;
    }
    fname = fnames[0];
    if ((util_parse_number(fname, &v)) && (v >= 1) && (v <= NUM_ALL_SAVES)) {
        fname = game_save_get_slot_fname(v - 1);
    }
    res = savetype[savetypei].decode(gameptr, fname);
    if (res < 0) {
        log_error("decoding file '%s' failed\n", fname);
        return 1;
    }
    log_message("saveconv: decode type '%s' file '%s'\n", savetype[savetypei].name, fname);
    if (!savetype[savetypeo].encode) {
        LOG_DEBUG((1, "%s: encode type '%s' no callback\n", __func__, savetype[savetypeo].name));
        if (main_fname_num == 2) {
            log_error("output filename given for type '%s' which has no output\n", savetype[savetypeo].name);
            return 1;
        }
        return 0;
    }
    fname = fnames[1];
    if (fname == 0) {
        if (!(savetype[savetypeo].flags & SAVETYPE_F_OPTOUT)) {
            log_error("output filename missing\n");
            return 1;
        }
    } else if ((util_parse_number(fname, &v)) && (v >= 1) && (v <= NUM_ALL_SAVES)) {
        fname = game_save_get_slot_fname(v - 1);
    }
    log_message("saveconv: encode type '%s' file '%s'\n", savetype[savetypeo].name, fname ? fname : "(null)");
    if (savename[0] == '\0') {
        strcpy(savename, "saveconv");
    }
    res = savetype[savetypeo].encode(gameptr, fname);
    if (res < 0) {
        log_error("encoding file '%s' failed\n", fname ? fname : "(null)");
        return 1;
    }
    return 0;
}

/* -------------------------------------------------------------------------- */

int main_1oom(int argc, char **argv)
{
    if (main_early_init()) {
        return 1;
    }
    if (options_parse_early(argc, argv)) {
        return 1;
    }
    atexit(main_shutdown);
    if (main_init()) {
        return 2;
    }
    if (options_parse(argc, argv)) {
        return 3;
    }
    return main_do();
}
