#include "raylib.h"
#include "scenes.h"
#include "config.h"
#include "common.h"

#include <stdio.h>

void start() {

    const Rectangle playbtn = { 370, 240, play.width, play.height };
    
    Vector2 mouse_pos;

    while(current_scene == SCN_STRT && !WindowShouldClose()) {
        
        // Checking Button Click //

        mouse_pos = GetMousePosition();

        if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && CheckCollisionPointRec(mouse_pos, playbtn)) {
            current_scene = SCN_MENU;
            HideCursor();
            return;
        }

        
        // Rendering Menu //

        BeginDrawing();
        ClearBackground(MAZE_BLUE);
        DrawTexture(play, playbtn.x, playbtn.y, WHITE);
        DrawTextEx(font, "Play The Maze", (Vector2){330, 320}, 25, 0, BLACK);
        EndDrawing();

    }
}

#include <stdio.h>
void menu() {

    static const char* const menustr = 
    "Test your skills!\nTry to reach the goal without touching the walls.\n"
    "How steady is your hand?\nLet's find out! Try hard and beat all four levels!";

    const Rectangle menuRect = {20, 20, WIN_W - 40, WIN_H - 40};
    const Rectangle playBtn = {310, 500, 180, 80};

    Vector2 mouse_pos;

    while(current_scene == SCN_MENU && !WindowShouldClose()) {
        
        // Checking Button Click //

        mouse_pos = GetMousePosition();

        if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && CheckCollisionPointRec(mouse_pos, playBtn)) {
            current_scene = SCN_LVL1;
            return;
        }

        
        // Rendering Menu //

        BeginDrawing();
        ClearBackground(BLACK);
        DrawRectangleRounded(menuRect, 0.05, 4, MAZE_BLUE);
        DrawTexture(logo, 225, 50, WHITE);
        DrawTextEx(font, menustr, (Vector2){150, 300}, 28, 0, BLACK);
        DrawTextEx(font, "Sound effects will help.", (Vector2){315, 470}, 18, 0, BLACK);
        DrawRectangleRec(playBtn, BLACK);
        DrawText("PLAY", 345, 520, 40, WHITE);
        draw_cursor(mouse_pos);
        EndDrawing();

    }
}

void end_card() {

    const Rectangle rstBtn = {0, 520, 180, 80};

    Vector2 mouse_pos;
    
    PlaySound(endsound);

    while(current_scene == SCN_ENDC && !WindowShouldClose()) {
        
        // Checking Button Click //

        mouse_pos = GetMousePosition();

        if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && CheckCollisionPointRec(mouse_pos, rstBtn)) {
            current_scene = SCN_MENU;
            return;
        }

        
        // Rendering End Card //

        BeginDrawing();
        ClearBackground(BLACK);
        DrawTexture(endimg, 0, 0, WHITE);
        DrawRectangleRec(rstBtn, BLACK);
        DrawText("RESTART", 40, 540, 23, WHITE);
        draw_cursor(mouse_pos);
        EndDrawing();
    }

}