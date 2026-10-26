#include "raylib.h"
#include "scenes.h"
#include "config.h"
#include "common.h"
#include <stdlib.h>


// Keep the IntelliSense from whining about the headers generated while building the program.
#ifndef __INTELLISENSE__

#include "logoimg.h"
#include "playimg.h"
#include "endimg.h"
#include "sound.h"
#include "font.h"


void load_hardcoded_assets() {
    logo        = LoadTextureFromImage((Image) {LOGOIMG_DATA, LOGOIMG_WIDTH, LOGOIMG_HEIGHT, 1, LOGOIMG_FORMAT });
    play        = LoadTextureFromImage((Image) {PLAYIMG_DATA, PLAYIMG_WIDTH, PLAYIMG_HEIGHT, 1, PLAYIMG_FORMAT });
    endimg      = LoadTextureFromImage((Image) {ENDIMG_DATA,  ENDIMG_WIDTH,  ENDIMG_HEIGHT,  1, ENDIMG_FORMAT  });
    endsound    = LoadSoundFromWave((Wave) {SOUND_FRAME_COUNT, SOUND_SAMPLE_RATE, SOUND_SAMPLE_SIZE, SOUND_CHANNELS, SOUND_DATA});
    font        = LoadFont_Font();
}

#endif

short current_scene = SCN_STRT;

int main(int argc, char** argv) {

    InitWindow(WIN_W, WIN_H, "The Maze");
    SetTargetFPS(60);
    InitAudioDevice();

    load_hardcoded_assets();

    
    while(!WindowShouldClose()) {

        switch(current_scene) {
        case SCN_MENU: menu();      break;
        case SCN_STRT: start();     break;
        case SCN_LVL1: level_1();   break;
        case SCN_LVL2: level_2();   break;
        case SCN_LVL3: level_3();   break;
        case SCN_ENDC: end_card();  break;
        }
        
    }

    CloseAudioDevice();
    CloseWindow();

    UnloadTexture(logo);
    UnloadTexture(play);
    UnloadTexture(endimg);
    UnloadSound(endsound);
    // Embedded font should not be unloaded
    
    return 0;
}