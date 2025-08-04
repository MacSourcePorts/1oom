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

char savename[SAVE_NAME_LEN] = "";

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
    return libsave_1oom_get_slot_fname(i, savenamebuf, savenamebuflen);
}

static int game_save_check_saves(void)
{
    for (int i = 0; i < NUM_ALL_SAVES; ++i) {
        game_save_tbl_have_save[i] = false;
        game_save_tbl_name[i][0] = '\0';
    }
    libsave_1oom_check_saves();
    return 0;
}

int libsave_do_load_smart(const char *filename, struct game_s *g)
{
    if (libsave_moo13_check(g, filename) && !libsave_moo13_decode(g, filename)) {
        return 0;
    }
    return libsave_1oom_do_load(filename, g, -1, NULL);
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
