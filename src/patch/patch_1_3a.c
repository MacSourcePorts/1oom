#include "common.h"

const int chunk0_start = 0x75792;
const int chunk0_end = 0x75794;
const uint8_t chunk0_ui_qol_starmap_no_qmark_cursor[] = {
    /*75792*/ 0xeb, 0x07,
};

const int chunk1_0_start = 0x6d8f5;
const int chunk1_0_end = 0x6d8fe;
const uint8_t chunk1_0_game_fix_space_scanners[] = {
    /*6d8f5*/ 0x83, 0x7e, 0xe6, 0x00,
    /*6d8f9*/ 0x7f, 0x03,
    /*6d8fb*/ 0xe9, 0xd8, 0x00,
};

const int chunk1_1_start = 0x6d96e;
const int chunk1_1_end = 0x6d993;
const uint8_t chunk1_1_game_fix_space_scanners[] = {
    /*6d96e*/ 0x8b, 0x46, 0xec,
    /*6d971*/ 0xbb, 0x0a, 0x00,
    /*6d974*/ 0x99,
    /*6d975*/ 0xf7, 0xfb,
    /*6d977*/ 0x0b, 0xd2,
    /*6d979*/ 0x75, 0x0b,
    /*6d97b*/ 0x8b, 0x46, 0xec,
    /*6d97e*/ 0xbb, 0x0a, 0x00,
    /*6d981*/ 0x99,
    /*6d982*/ 0xf7, 0xfb,
    /*6d984*/ 0xeb, 0x0a,
    /*6d986*/ 0x8b, 0x46, 0xec,
    /*6d989*/ 0xbb, 0x0a, 0x00,
    /*6d98c*/ 0x99,
    /*6d98d*/ 0xf7, 0xfb,
    /*6d98f*/ 0x40,
    /*6d990*/ 0x89, 0x46, 0xec,
};

const int chunk1_2_start = 0x6d99b;
const int chunk1_2_end = 0x6d9a1;
const uint8_t chunk1_2_game_fix_space_scanners[] = {
    /*6d99b*/ 0x8b, 0x46, 0xf2,
    /*6d99e*/ 0x89, 0x46, 0xec,
};
const uint8_t subst1_2_game_fix_space_scanners[] = {
    /*6d99b*/ 0x8b, 0x46, 0xec,
    /*6d99e*/ 0x89, 0x46, 0xf2,
};

const int chunk2_0_off = 0x7a6e5;
const int chunk2_1_off = 0x7a6f7;
const int chunk2_2_off = 0x7a70d;
const int chunk2_3_off = 0x7a723;
const int chunk3_0_off = 0x7a73d;
const int chunk3_1_off = 0x7a74f;
const int chunk3_2_off = 0x7a765;
const int chunk3_3_off = 0x7a77b;
const uint8_t chunk2_ui_fix_starmap_background[] = {
    /*7a6e5*/ 0xff, 0x36, 0x0c, 0x77,
};
const uint8_t chunk3_ui_fix_starmap_background[] = {
    /*7a74f*/ 0xff, 0x36, 0x0a, 0x77,
};

const int chunk4_start = 0x7c83e;
const int chunk4_end = 0x7c841;
const uint8_t chunk4_ui_fix_spy_cost[] = {
    /*7c83e*/ 0xf7, 0x6e, 0xd8,
};

const int chunk5_start = 0x64c4e;
const int chunk5_end = 0x64c51;
const uint8_t chunk5_ui_fix_tech_complete_probability[] = {
    /*64c4e*/ 0xba, 0x02, 0x00,
};
const uint8_t subst5_ui_fix_tech_complete_probability[] = {
    /*64c4e*/ 0xba, 0x01, 0x00,
};

const int chunk6_start = 0x79c08;
const int chunk6_end = 0x79c0d;
const uint8_t chunk6_ui_qol_starmap_msg_pos[] = {
    /*79c08*/ 0xc7, 0x46, 0xf6, 0x36, 0x00,
};
const uint8_t subst6_ui_qol_starmap_msg_pos[] = {
    /*79c08*/ 0xc7, 0x46, 0xf6, 0x2d, 0x00,
};

const int chunk7_start = 0x69f72;
const int chunk7_end = 0x69f8a;
const uint8_t chunk7_game_ai_fix_spy_hiding[] = {
    /*0x69f72*/ 0x8b, 0x1e, 0xaa, 0xd4,
    /*0x69f76*/ 0xd1, 0xe3,
    /*0x69f78*/ 0xc7, 0x87, 0x6a, 0x79, 0x00, 0x00,
    /*0x69f7e*/ 0x8b, 0x1e, 0xaa, 0xd4,
    /*0x69f82*/ 0xd1, 0xe3,
    /*0x69f84*/ 0xc7, 0x87, 0x36, 0x7b, 0x00, 0x00,
};
const uint8_t subst7_game_ai_fix_spy_hiding[] = {
    /*0x69f72*/ 0x90, 0x90,
    /*0x69f74*/ 0xa1, 0xaa, 0xd4,
    /*0x69f77*/ 0xba, 0xd4, 0x0d,
    /*0x69f7a*/ 0xf7, 0xea,
    /*0x69f7c*/ 0x8b, 0xd8,
    /*0x69f7e*/ 0xc7, 0x87, 0x6a, 0x79, 0x00, 0x00,
    /*0x69f84*/ 0xc7, 0x87, 0x36, 0x7b, 0x00, 0x00,
};

const int chunk8_start = 0x6cc9;
const int chunk8_end = 0x6ccb;
const uint8_t chunk8_main_allow_direct_launch[] = {
    /*0x6cc9*/ 0x75, 0x08,
};
const uint8_t subst8_main_allow_direct_launch[] = {
    /*0x6cc9*/ 0xeb, 0x12,
};

const int chunk9_1_start = 0x77f31;
const int chunk9_1_end = 0x77f34;
const int chunk9_2_start = 0x78830;
const int chunk9_2_end = 0x78833;
const uint8_t chunk9_ui_qol_extra_key_bindings_space[] = {
    /*0x77f31*/ 0xb8, 0xa2, 0x50,
};
const uint8_t subst9_ui_qol_extra_key_bindings_space[] = {
    /*0x77f31*/ 0xb8, 0xa8, 0x47,
};

const int chunk10_1_start = 0xf126;
const int chunk10_1_end = 0xf127;
const int chunk10_2_start = 0xf14a;
const int chunk10_2_end = 0xf14b;
const uint8_t chunk10_game_fix_sg_finished[] = {
    /*0xf126*/ 0x52,
};
const uint8_t replace10_game_fix_sg_finished[] = {
    /*0xf126*/ 0x50,
};

const int chunk11_1_start = 0xb1e7;
const int chunk11_1_end = 0xb1e9;
const int chunk11_2_start = 0xb1fd;
const int chunk11_2_end = 0xb1ff;
const uint8_t chunk11_game_fix_max_factories[] = {
    /*0xb1e7*/ 0xc4, 0x09,
};
const uint8_t replace11_game_fix_max_factories[] = {
    /*0xb1e7*/ 0x8c, 0x0a,
};

const int chunk12_start = 0x61e39;
const int chunk12_end = 0x61e44;
const uint8_t chunk12_ui_fix_planet_list_pos[] = {
    /*0x61e39*/ 0x8b, 0xc7,
    /*0x61e3b*/ 0x05, 0xfb, 0xff,
    /*0x61e3e*/ 0xa3, 0x0c, 0xd2,
    /*0x61e41*/ 0xa1, 0x10, 0xd2,
};
const uint8_t replace12_ui_fix_planet_list_pos[] = {
    /*0x61e39*/ 0xa1, 0x10,
    /*0x61e3b*/ 0xd2, 0x50, 0x05,
    /*0x61e3e*/ 0xfb, 0xff, 0xa3,
    /*0x61e41*/ 0x0c, 0xd2, 0x58,
};

const int chunk13_1_start = 0x70638;
const int chunk13_1_end = 0x70644;
const uint8_t chunk13_1_ui_qol_no_cancel_via_lmb[] = {
    /*0x70638*/ 0x50,
    /*0x70639*/ 0x33, 0xc0,
    /*0x7063b*/ 0x50,
    /*0x7063c*/ 0x9a, 0xec, 0x3b, 0x68, 0x01,
    /*0x70641*/ 0x83, 0xc4, 0x0c,
};
const uint8_t replace13_1_ui_qol_no_cancel_via_lmb[] = {
    /*0x70638*/ 0xb8, 0xa6, 0x47,
    /*0x7063b*/ 0x50,
    /*0x7063c*/ 0x9a, 0x7a, 0x3e, 0x68, 0x01,
    /*0x70641*/ 0x59,
    /*0x70642*/ 0x90, 0x90,
};
const int chunk13_2_start = 0x70626;
const int chunk13_2_end = 0x70628;
const uint8_t chunk13_2_ui_qol_no_cancel_via_lmb[] = {
    /*0x70626*/ 0xb8, 0xff,
};
const uint8_t replace13_2_ui_qol_no_cancel_via_lmb[] = {
    /*0x70626*/ 0xeb, 0x10,
};
const int chunk13_3_start = 0x705e9;
const int chunk13_3_end = 0x705ea;
const uint8_t chunk13_3_ui_qol_no_cancel_via_lmb[] = {
    /*0x705e9*/ 0x3c,
};
const uint8_t replace13_3_ui_qol_no_cancel_via_lmb[] = {
    /*0x705e9*/ 0x4e,
};

const int chunk14_1_start = 0x705f2;
const int chunk14_1_end = 0x705f5;
const uint8_t chunk14_1_ui_qol_extra_key_bindings_scrap[] = {
    /*0x705f2*/ 0xb8, 0x5a, 0x48,
};
const uint8_t replace14_1_ui_qol_extra_key_bindings_scrap[] = {
    /*0x705f2*/ 0x90, 0xeb, 0x33,
};
const int chunk14_2_start = 0x70628;
const int chunk14_2_end = 0x70631;
const uint8_t chunk14_2_ui_qol_extra_key_bindings_scrap[] = {
    /*0x70628*/ 0xff,   /* NOTE: this requires fix@13 */
    /*0x70629*/ 0x50,
    /*0x7062a*/ 0xb8, 0xf5, 0x48,
    /*0x7062d*/ 0x50,
    /*0x7062e*/ 0xb8, 0xc7, 0x00,
};
const uint8_t replace14_2_ui_qol_extra_key_bindings_scrap[] = {
    /*0x70628*/ 0xb8, 0x84, 0x6d,
    /*0x7062b*/ 0x03, 0xc6,
    /*0x7062d*/ 0xeb, 0xc6,
    /*0x7062f*/ 0x90, 0x90,
};

const int chunk15_1_start = 0x7bf0a;
const int chunk15_1_end = 0x7bf16;
const uint8_t chunk15_1_ui_qol_extra_key_bindings_races[] = {
    /*0x7bf0a*/ 0x33, 0xf6,
    /*0x7bf0c*/ 0xeb, 0x17,
    /*0x7bf0e*/ 0x8b, 0xde,
    /*0x7bf10*/ 0xd1, 0xe3,
    /*0x7bf12*/ 0x8b, 0x87, 0xc2, 0xd1,
};
const uint8_t replace15_1_ui_qol_extra_key_bindings_races[] = {
    /*0x7bf0a*/ 0xeb, 0x20,
    /*0x7bf0c*/ 0xb8, 0x84, 0x6d,
    /*0x7bf0f*/ 0x03, 0xc6,
    /*0x7bf11*/ 0xe9, 0x8d, 0x01,
    /*0x7bf14*/ 0x90, 0x90,
};
const int chunk15_2_start = 0x7c09e;
const int chunk15_2_end = 0x7c0a1;
const uint8_t chunk15_2_ui_qol_extra_key_bindings_races[] = {
    /*0x7c09e*/ 0xb8, 0xb0, 0x55,
};
const uint8_t replace15_2_ui_qol_extra_key_bindings_races[] = {
    /*0x7c09e*/ 0xe9, 0x6b, 0xfe,
};

const int chunk16_1_start = 0x637af;
const int chunk16_1_end = 0x637b2;
const int chunk16_2_start = 0x637d2;
const int chunk16_2_end = 0x637d5;
const int chunk16_3_start = 0x637f5;
const int chunk16_3_end = 0x637f8;
const int chunk16_4_start = 0x63818;
const int chunk16_4_end = 0x6381b;
const int chunk16_5_start = 0x6383b;
const int chunk16_5_end = 0x6383e;
const int chunk16_6_start = 0x6385e;
const int chunk16_6_end = 0x63861;
const uint8_t chunk16_ui_qol_extra_key_bindings_tech[] = {
    /*0x637af*/ 0xb8, 0x0a, 0x3c,
};
const uint8_t replace16_1_ui_qol_extra_key_bindings_tech[] = {
    /*0x637af*/ 0xb8, 0x84, 0x6d,
};
const uint8_t replace16_2_ui_qol_extra_key_bindings_tech[] = {
    /*0x637d2*/ 0xb8, 0x85, 0x6d,
};
const uint8_t replace16_3_ui_qol_extra_key_bindings_tech[] = {
    /*0x637f5*/ 0xb8, 0x86, 0x6d,
};
const uint8_t replace16_4_ui_qol_extra_key_bindings_tech[] = {
    /*0x63818*/ 0xb8, 0x87, 0x6d,
};
const uint8_t replace16_5_ui_qol_extra_key_bindings_tech[] = {
    /*0x6383b*/ 0xb8, 0x88, 0x6d,
};
const uint8_t replace16_6_ui_qol_extra_key_bindings_tech[] = {
    /*0x6385e*/ 0xb8, 0x89, 0x6d,
};

const int chunk17_1_start = 0x7f500;
const int chunk17_1_end = 0x7f503;
const int chunk17_2_start = 0x7f523;
const int chunk17_2_end = 0x7f526;
const int chunk17_3_start = 0x7f546;
const int chunk17_3_end = 0x7f549;
const uint8_t chunk17_ui_qol_extra_key_bindings_election[] = {
    /*0x7f500*/ 0xb8, 0x0e, 0x57,
};
const uint8_t replace17_1_ui_qol_extra_key_bindings_election[] = {
    /*0x7f500*/ 0xb8, 0x84, 0x6d,
};
const uint8_t replace17_2_ui_qol_extra_key_bindings_election[] = {
    /*0x7f523*/ 0xb8, 0x85, 0x6d,
};
const uint8_t replace17_3_ui_qol_extra_key_bindings_election[] = {
    /*0x7f546*/ 0xb8, 0x83, 0x6d,
};

const int chunk18_start = 0x7e112;
const int chunk18_end = 0x7e116;
const uint8_t chunk18_ui_fix_empirereport_enviro[] = {
    /*0x7e112*/ 0xdc, 0x02,
    /*0x7e114*/ 0x98,
    /*0x7e115*/ 0x40,
};
const uint8_t replace18_ui_fix_empirereport_enviro[] = {
    /*0x7e112*/ 0x90, 0x03,
    /*0x7e114*/ 0x98,
    /*0x7e115*/ 0x90,
};

const int chunk101_start = 0x114c9;
const int chunk101_end = 0x114ca;
const uint8_t chunk101_game_fix_orbital_torpedo[] = {
    /*0x114c9*/ 0x75,
};
const uint8_t replace101_game_fix_orbital_torpedo[] = {
    /*0x114c9*/ 0x74,
};

const int chunk102_1_start = 0x115fa;
const int chunk102_1_end = 0x115fb;
const int chunk102_2_start = 0x8271b;
const int chunk102_2_end = 0x8271c;
const uint8_t chunk102_game_fix_orbital_weap_any[] = {
    /*0x115fa*/ 0x3d,
};
const uint8_t replace102_game_fix_orbital_weap_any[] = {
    /*0x115fa*/ 0x40,
};

const bin_patch_t patch_1_3a[] = {
    {chunk0_ui_qol_starmap_no_qmark_cursor, NULL, chunk0_start, chunk0_end},
    {chunk1_0_game_fix_space_scanners, NULL, chunk1_0_start, chunk1_0_end},
    {chunk1_1_game_fix_space_scanners, NULL, chunk1_1_start, chunk1_1_end},
    {chunk1_2_game_fix_space_scanners, subst1_2_game_fix_space_scanners, chunk1_2_start, chunk1_2_end},
    {chunk2_ui_fix_starmap_background, chunk3_ui_fix_starmap_background, chunk2_0_off, chunk2_0_off + 4},
    {chunk2_ui_fix_starmap_background, chunk3_ui_fix_starmap_background, chunk2_1_off, chunk2_1_off + 4},
    {chunk2_ui_fix_starmap_background, chunk3_ui_fix_starmap_background, chunk2_2_off, chunk2_2_off + 4},
    {chunk2_ui_fix_starmap_background, chunk3_ui_fix_starmap_background, chunk2_3_off, chunk2_3_off + 4},
    {chunk3_ui_fix_starmap_background, chunk2_ui_fix_starmap_background, chunk3_0_off, chunk3_0_off + 4},
    {chunk3_ui_fix_starmap_background, chunk2_ui_fix_starmap_background, chunk3_1_off, chunk3_1_off + 4},
    {chunk3_ui_fix_starmap_background, chunk2_ui_fix_starmap_background, chunk3_2_off, chunk3_2_off + 4},
    {chunk3_ui_fix_starmap_background, chunk2_ui_fix_starmap_background, chunk3_3_off, chunk3_3_off + 4},
    {chunk4_ui_fix_spy_cost, NULL, chunk4_start, chunk4_end},
    {chunk5_ui_fix_tech_complete_probability, subst5_ui_fix_tech_complete_probability, chunk5_start, chunk5_end},
    {chunk6_ui_qol_starmap_msg_pos, subst6_ui_qol_starmap_msg_pos, chunk6_start, chunk6_end},
    {chunk7_game_ai_fix_spy_hiding, subst7_game_ai_fix_spy_hiding, chunk7_start, chunk7_end},
    {chunk8_main_allow_direct_launch, subst8_main_allow_direct_launch, chunk8_start, chunk8_end},
    {chunk9_ui_qol_extra_key_bindings_space, subst9_ui_qol_extra_key_bindings_space, chunk9_1_start, chunk9_1_end},
    {chunk9_ui_qol_extra_key_bindings_space, subst9_ui_qol_extra_key_bindings_space, chunk9_2_start, chunk9_2_end},
    {chunk10_game_fix_sg_finished, replace10_game_fix_sg_finished, chunk10_1_start, chunk10_1_end},
    {chunk10_game_fix_sg_finished, replace10_game_fix_sg_finished, chunk10_2_start, chunk10_2_end},
    {chunk11_game_fix_max_factories, replace11_game_fix_max_factories, chunk11_1_start, chunk11_1_end},
    {chunk11_game_fix_max_factories, replace11_game_fix_max_factories, chunk11_2_start, chunk11_2_end},
    {chunk12_ui_fix_planet_list_pos, replace12_ui_fix_planet_list_pos, chunk12_start, chunk12_end},
    {chunk13_1_ui_qol_no_cancel_via_lmb, replace13_1_ui_qol_no_cancel_via_lmb, chunk13_1_start, chunk13_1_end},
    {chunk13_2_ui_qol_no_cancel_via_lmb, replace13_2_ui_qol_no_cancel_via_lmb, chunk13_2_start, chunk13_2_end},
    {chunk13_3_ui_qol_no_cancel_via_lmb, replace13_3_ui_qol_no_cancel_via_lmb, chunk13_3_start, chunk13_3_end},
    {chunk14_1_ui_qol_extra_key_bindings_scrap, replace14_1_ui_qol_extra_key_bindings_scrap, chunk14_1_start, chunk14_1_end},
    {chunk14_2_ui_qol_extra_key_bindings_scrap, replace14_2_ui_qol_extra_key_bindings_scrap, chunk14_2_start, chunk14_2_end},
    {chunk15_1_ui_qol_extra_key_bindings_races, replace15_1_ui_qol_extra_key_bindings_races, chunk15_1_start, chunk15_1_end},
    {chunk15_2_ui_qol_extra_key_bindings_races, replace15_2_ui_qol_extra_key_bindings_races, chunk15_2_start, chunk15_2_end},
    {chunk16_ui_qol_extra_key_bindings_tech, replace16_1_ui_qol_extra_key_bindings_tech, chunk16_1_start, chunk16_1_end},
    {chunk16_ui_qol_extra_key_bindings_tech, replace16_2_ui_qol_extra_key_bindings_tech, chunk16_2_start, chunk16_2_end},
    {chunk16_ui_qol_extra_key_bindings_tech, replace16_3_ui_qol_extra_key_bindings_tech, chunk16_3_start, chunk16_3_end},
    {chunk16_ui_qol_extra_key_bindings_tech, replace16_4_ui_qol_extra_key_bindings_tech, chunk16_4_start, chunk16_4_end},
    {chunk16_ui_qol_extra_key_bindings_tech, replace16_5_ui_qol_extra_key_bindings_tech, chunk16_5_start, chunk16_5_end},
    {chunk16_ui_qol_extra_key_bindings_tech, replace16_6_ui_qol_extra_key_bindings_tech, chunk16_6_start, chunk16_6_end},
    {chunk17_ui_qol_extra_key_bindings_election, replace17_1_ui_qol_extra_key_bindings_election, chunk17_1_start, chunk17_1_end},
    {chunk17_ui_qol_extra_key_bindings_election, replace17_2_ui_qol_extra_key_bindings_election, chunk17_2_start, chunk17_2_end},
    {chunk17_ui_qol_extra_key_bindings_election, replace17_3_ui_qol_extra_key_bindings_election, chunk17_3_start, chunk17_3_end},
    {chunk18_ui_fix_empirereport_enviro, replace18_ui_fix_empirereport_enviro, chunk18_start, chunk18_end},

    {chunk101_game_fix_orbital_torpedo, replace101_game_fix_orbital_torpedo, chunk101_start, chunk101_end},
    {chunk102_game_fix_orbital_weap_any, replace102_game_fix_orbital_weap_any, chunk102_1_start, chunk102_1_end},
    {chunk102_game_fix_orbital_weap_any, replace102_game_fix_orbital_weap_any, chunk102_2_start, chunk102_2_end},
    {NULL, NULL, 0, 0},
};
