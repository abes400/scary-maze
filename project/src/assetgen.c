/**
 * This is a SEPARATE program that is used to convert audiovisual assets to RAYLIB's hardcoded asset format.
 * It's not included in the resultant binary. It's just compiled, run to make convert the assets, and deleted.
 * The main program is compiled afterwards with the converted assets embedded to it.
 * 
 * This program is here so you can add your own endcard and sound.
 * See README.md for the instructions.
 */

#include "raylib.h"
#include <stdlib.h>

int main() {
    // Need to open a window because RAYLIB says so.
    InitWindow(100, 100, "");

    // Load the assets
    Image logoimg   = LoadImage ("source/logo.png" );
    Image endimgimg = LoadImage ("source/endcard.png");
    Image playimg   = LoadImage ("source/play.png");
    Wave  audio     = LoadWave  ("source/sound.wav");

    // Init output dir.
    MakeDirectory("temp_asset_headers");

    // Convert the assets
    ExportImageAsCode(logoimg,      "temp_asset_headers/logoimg.h");
    ExportImageAsCode(endimgimg,    "temp_asset_headers/endimg.h");
    ExportImageAsCode(playimg,      "temp_asset_headers/playimg.h");
    ExportWaveAsCode (audio,        "temp_asset_headers/sound.h");

    // Unload the assets
    UnloadImage(logoimg);
    UnloadImage(endimgimg);
    UnloadImage(playimg);
    UnloadWave(audio);
    CloseWindow();
    
    return 0;
}