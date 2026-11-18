/*******************************************************************************************
*
*   Copyright (c) 2013-2025 Ramon Santamaria (@raysan5)
*
********************************************************************************************/

#include <cstring>
#include <string>
#include "raylib.h"

//Definizione
void quadrettatura(int dim, int w, int h, Color c, Color b) {
    DrawRectangle(0, 0, w, h, b);
    //Linee verticali
    for (int i = 0; i < w / dim; ++i) {
        DrawLine(dim * i, 0, dim * i, h, c);
    }
    //Linee orizzontali
    for (int i = 0; i < h / dim; ++i) {
        DrawLine(0, dim * i, w, dim * i, c);
    }
}

int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "Hello Alessandro");


    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------
    int dim = 10, scatto = 0;
    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        if (scatto % 10 == 0) {
            dim++;
        }
        scatto++;
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(RAYWHITE);

        quadrettatura(20, screenWidth, screenHeight, BLACK, GREEN);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}

