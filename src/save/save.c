#include "config.h"

#include <stdio.h>
#include <string.h>
#include <unistd.h>

#include "save.h"
#include "game.h"
#include "lib.h"
#include "log.h"
#include "os.h"
#include "types.h"
#include "util.h"

/* -------------------------------------------------------------------------- */

bool game_save_tbl_have_save[NUM_ALL_SAVES];
char game_save_tbl_name[NUM_ALL_SAVES][SAVE_NAME_LEN];

static int savenamebuflen = 0;
static char *savenamebuf = NULL;

static int game_save_check_saves(void);

void libsave_init(void)
{
    savenamebuflen = FSDEV_PATH_MAX;
    savenamebuf = lib_malloc(savenamebuflen);
    game_save_check_saves();
}

void libsave_shutdown(void)
{
    lib_free(savenamebuf);
    savenamebuf = NULL;
    savenamebuflen = 0;
}

/* -------------------------------------------------------------------------- */

const char *game_save_get_slot_fname(int i)
{
    const char *path = os_get_path_user();
    char namebuf[16];
    int res;
    if (!os_get_fname_save(namebuf, i + 1)) {
        sprintf(namebuf, "1oom_save%i.bin", i + 1);
    }
    res = util_concat_buf(savenamebuf, savenamebuflen, path, FSDEV_DIR_SEP_STR, namebuf, NULL);
    if (res < 0) {
        log_error("Save: BUG: save name buffer too small by %i bytes\n", -res);
        return NULL;
    }
    return savenamebuf;
}

static int game_save_check_saves(void)
{
    struct libsave_1oom_hdr_data_s hdr_data;
    for (int i = 0; i < NUM_ALL_SAVES; ++i) {
        const char *fname = game_save_get_slot_fname(i);
        game_save_tbl_have_save[i] = false;
        game_save_tbl_name[i][0] = '\0';
        if (libsave_1oom_read_header(fname, &hdr_data) && (hdr_data.version == GAME_SAVE_VERSION)) {
            game_save_tbl_have_save[i] = true;
            memcpy(game_save_tbl_name[i], hdr_data.savename, SAVE_NAME_LEN);
            game_save_tbl_name[i][SAVE_NAME_LEN - 1] = '\0';
        }
    }
    return 0;
}

int game_save_do_load_fname(const char *filename, char *savename, struct game_s *g)
{
    return libsave_1oom_do_load(filename, g, -1, savename);
}

int game_save_do_load_i(int savei, struct game_s *g)
{
    int res;
    const char *filename = game_save_get_slot_fname(savei);
    res = libsave_1oom_do_load(filename, g, savei, 0);
    return res;
}

int game_save_do_save_i(int savei, const char *savename, const struct game_s *g)
{
    int res;
    const char *filename;
    if (os_make_path_user()) {
        log_error("Save: failed to create user path '%s'\n", os_get_path_user());
    }
    filename = game_save_get_slot_fname(savei);
    res = libsave_1oom_do_save(filename, savename, g, savei);
    return res;
}
