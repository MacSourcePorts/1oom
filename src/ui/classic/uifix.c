#include "config.h"

#include "uifix.h"

/* -------------------------------------------------------------------------- */

bool ui_fix_cursor_nav_offset = false;
bool ui_fix_starmap_background = false;

bool ui_qol_cursor_nav_all_obj = false;
bool ui_qol_numeric_key_bindings = false;
bool ui_qol_starmap_msg_pos = false;

void ui_enable_fix_bugs(void)
{
    ui_fix_cursor_nav_offset = true;
    ui_fix_starmap_background = true;
}

void ui_enable_fix_qol(void)
{
    ui_qol_cursor_nav_all_obj = true;
    ui_qol_numeric_key_bindings = true;
    ui_qol_starmap_msg_pos = true;
}
