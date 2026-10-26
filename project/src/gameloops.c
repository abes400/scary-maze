#include "raylib.h"
#include "scenes.h"
#include "config.h"
#include "common.h"

void level_1() {

    const Rectangle mr1 = {296, 40, 199, 541};
    const Rectangle mr2 = {495, 40, 209, 35 };
    const Rectangle fin = {704, 40, 76,  35 };

    Vector2 mouse_pos;

    while(current_scene == SCN_LVL1 && !WindowShouldClose()) {

        mouse_pos = GetMousePosition();

        // Checking if cursor is at the finish line //
        if(CheckCollisionPointRec(mouse_pos, fin)) {
            current_scene = SCN_LVL2;
            return;
        }

        // Checking if cursor is at the black zone //
        if(!CheckCollisionPointRec(mouse_pos, mr1) && !CheckCollisionPointRec(mouse_pos, mr2)) {
            current_scene = SCN_MENU;
            return;
        }

        // Rendering Level 1 //
        BeginDrawing();
        ClearBackground(BLACK);
        DrawTextEx(font, "Level 1", (Vector2){705, 80}, 25, 0, WHITE);
        DrawRectangleRec(mr1, MAZE_BLUE);
        DrawRectangleRec(mr2, MAZE_BLUE);
        DrawRectangleRec(fin, RED);
        draw_cursor(mouse_pos);
        EndDrawing();

    }
}

void level_2() {

    const Rectangle mr1 = {75,  30,  676, 49 };
    const Rectangle mr2 = {75,  79,  59,  83 };
    const Rectangle mr3 = {75,  162, 676, 49 };
    const Rectangle mr4 = {692, 211, 59,  83 };
    const Rectangle mr5 = {75,  291, 676, 49 };
    const Rectangle mr6 = {75,  340, 59,  83 };
    const Rectangle mr7 = {75,  419, 676, 49 };
    const Rectangle mr8 = {626, 468, 125, 70 };
    const Rectangle mr9 = {141, 538, 610, 27 };
    const Rectangle fin = {75,  538, 66,  27 };

    Vector2 mouse_pos;
    
    while(current_scene == SCN_LVL2 && !WindowShouldClose()) {

        mouse_pos = GetMousePosition();

        // Checking if cursor is at the finish line //
        if(CheckCollisionPointRec(mouse_pos, fin)) {
            current_scene = SCN_LVL3;
            return;
        }

        // Checking if cursor is at the black zone //
        if(
            !CheckCollisionPointRec(mouse_pos, mr1) && 
            !CheckCollisionPointRec(mouse_pos, mr2) &&
            !CheckCollisionPointRec(mouse_pos, mr3) && 
            !CheckCollisionPointRec(mouse_pos, mr4) &&
            !CheckCollisionPointRec(mouse_pos, mr5) && 
            !CheckCollisionPointRec(mouse_pos, mr6) &&
            !CheckCollisionPointRec(mouse_pos, mr7) &&
            !CheckCollisionPointRec(mouse_pos, mr8) && 
            !CheckCollisionPointRec(mouse_pos, mr9)
        ) {
            current_scene = SCN_MENU;
            return;
        }

        // Rendering Level 2 //
        BeginDrawing();
        ClearBackground(BLACK);
        DrawTextEx(font, "Level 2", (Vector2){75, 508}, 25, 0, WHITE);
        DrawRectangleRec(mr1, MAZE_BLUE);
        DrawRectangleRec(mr2, MAZE_BLUE);
        DrawRectangleRec(mr3, MAZE_BLUE);
        DrawRectangleRec(mr4, MAZE_BLUE);
        DrawRectangleRec(mr5, MAZE_BLUE);
        DrawRectangleRec(mr6, MAZE_BLUE);
        DrawRectangleRec(mr7, MAZE_BLUE);
        DrawRectangleRec(mr8, MAZE_BLUE);
        DrawRectangleRec(mr9, MAZE_BLUE);
        DrawRectangleRec(fin, RED);
        draw_cursor(mouse_pos);
        EndDrawing();
    }
}

void level_3() {

    const Rectangle mr1 = {76,  530,  585, 38  };
    const Rectangle mr2 = {623, 491,  38,  39  };
    const Rectangle mr3 = {76,  453,  585, 38  };
    const Rectangle mr4 = {76,  294,  38,  159 };
    const Rectangle mr5 = {76,  256,  305, 38  };
    const Rectangle mr6 = {381, 256,  22,  9   };
    const Rectangle mr7 = {394, 212,  9,   44  };
    const Rectangle mr8 = {366, 203,  37,  9   };
    const Rectangle mr9 = {366, 183,  9,   20  };
    const Rectangle mra = {366, 174,  37,  9   };
    const Rectangle mrb = {394, 156,  9,   18  };
    const Rectangle fin = {373, 80,   51,  76  };

    Vector2 mouse_pos;

    bool test, test2;


    while(current_scene == SCN_LVL3 && !WindowShouldClose()) {

        mouse_pos = GetMousePosition();

        // Checking if cursor is at the finish line //
        if(mouse_pos.y <= 222) {
            current_scene = SCN_ENDC;
            return;
        }

        // Checking if cursor is at the black zone //
        if(
            !CheckCollisionPointRec(mouse_pos, mr1) && 
            !CheckCollisionPointRec(mouse_pos, mr2) &&
            !CheckCollisionPointRec(mouse_pos, mr3) && 
            !CheckCollisionPointRec(mouse_pos, mr4) &&
            !CheckCollisionPointRec(mouse_pos, mr5) && 
            !CheckCollisionPointRec(mouse_pos, mr6) &&
            !CheckCollisionPointRec(mouse_pos, mr7)
        ) {
            current_scene = SCN_MENU;
            return;
        }

        BeginDrawing();
        ClearBackground(BLACK);
        //DrawText("Level 3", 434, 135, 20, WHITE);
        DrawTextEx(font, "Level 3", (Vector2){434, 135}, 25, 0, WHITE);
        DrawRectangleRec(mr1, MAZE_BLUE);
        DrawRectangleRec(mr2, MAZE_BLUE);
        DrawRectangleRec(mr3, MAZE_BLUE);
        DrawRectangleRec(mr4, MAZE_BLUE);
        DrawRectangleRec(mr5, MAZE_BLUE);
        DrawRectangleRec(mr6, MAZE_BLUE);
        DrawRectangleRec(mr7, MAZE_BLUE);
        DrawRectangleRec(mr8, MAZE_BLUE);
        DrawRectangleRec(mr9, MAZE_BLUE);
        DrawRectangleRec(mra, MAZE_BLUE);
        DrawRectangleRec(mrb, MAZE_BLUE);
        DrawRectangleRec(fin, RED);
        draw_cursor(mouse_pos);
        EndDrawing();
    }
}