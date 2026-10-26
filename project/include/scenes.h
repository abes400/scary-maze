#pragma once

#define SCN_MENU    0
#define SCN_LVL1    1
#define SCN_LVL2    2
#define SCN_LVL3    3
#define SCN_STRT    4
#define SCN_ENDC    5

extern short current_scene;

void start();
void menu();
void level_1();
void level_2();
void level_3();
void end_card();