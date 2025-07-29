#ifndef INC_1OOM_SAVE_H
#define INC_1OOM_SAVE_H

#include "types.h"

#define NUM_SAVES   6
#define NUM_ALL_SAVES   (NUM_SAVES + 1/*continue game*/ + 1/*undo*/)
#define SAVE_NAME_LEN   20
#define GAME_SAVE_VERSION   0

struct libsave_1oom_hdr_data_s {
    uint32_t version;
    char savename[SAVE_NAME_LEN];
};

#define GAME_SAVE_I_CONTINUE    (7 - 1)
#define GAME_SAVE_I_UNDO        (8 - 1)

extern bool game_save_tbl_have_save[NUM_ALL_SAVES];
extern char game_save_tbl_name[NUM_ALL_SAVES][SAVE_NAME_LEN];

extern char savename[SAVE_NAME_LEN];

extern bool opt_use_configmoo;

extern void save_conv_init(void);
extern void save_conv_shutdown(void);

extern void libsave_init(void);
extern void libsave_shutdown(void);

extern int libsave_1oom_read_header(const char *filename, struct libsave_1oom_hdr_data_s *hdr_data);
extern const char *libsave_1oom_get_slot_fname(int i, char *buf, int buflen);
extern const char *libsave_moo13_get_slot_fname(int i, char *buf, int buflen);
extern void libsave_1oom_check_saves(void);
extern void libsave_moo13_check_saves(void);
extern const char *libsave_get_slot_fname(int i);
extern void libsave_moo13_cfg_set_name(int savei, const char *savename);

struct game_s;

extern bool libsave_moo13_check(const struct game_s *g, const char *fname);
extern int libsave_moo13_decode(struct game_s *g, const char *fname);
extern int libsave_moo13_encode(const struct game_s *g, const char *fname);

extern bool savetype_is_text(const struct game_s *g, const char *fname);
extern int savetype_de_text(struct game_s *g, const char *fname);
extern int savetype_en_text(const struct game_s *g, const char *fname);

extern int libsave_1oom_do_save(const char *filename, const char *savename, const struct game_s *g, int savei);
extern int libsave_1oom_do_load(const char *filename, struct game_s *g, int savei, char *savename);
extern int libsave_do_load_smart(const char *filename, struct game_s *g);
extern int libsave_do_load_i(int savei/*0..NUM_ALL_SAVES-1*/, struct game_s *g);
extern int libsave_do_save_i(int savei/*0..NUM_ALL_SAVES-1*/, const char *savename, const struct game_s *g);

#endif
