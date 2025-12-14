

/*******************************************************************************************
*
*   raylib [core] example - Basic window
*
*   Welcome to raylib!
*
*   To test examples, just press F6 and execute raylib_compile_execute script
*   Note that compiled executable is placed in the same folder as .c file
*
*   You can find all basic examples on C:\raylib\raylib\examples folder or
*   raylib official webpage: www.raylib.com
*
*   Enjoy using raylib. :)
*
*   This example has been created using raylib 1.0 (www.raylib.com)
*   raylib is licensed under an unmodified zlib/libpng license (View raylib.h for details)
*
*   Copyright (c) 2013-2016 Ramon Santamaria (@raysan5)
*
********************************************************************************************/

#include <chrono>
#include <iostream>

#include "raylib.h"
#include <string>

#include "raymath.h"

void aggiorna_posizione(float &x, float &y, float r, float &vx, float &vy, float a) {
    x = x + vx;
    y = y + vy;
    vy = vy + a;
    if (y + r > GetScreenHeight()) {
        y = GetScreenHeight() - r;
        vy = -vy;
        vy = vy * 0.9;
    }
    if (x + r > GetScreenWidth()) {
        x = GetScreenWidth() - r;
        vx = -vx;
    }
    if (x - r < 0) {
        x = r;
        vx = -vx;
    }
}

int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 768;
    const int screenHeight = 768;

    std::string s = "Esempio di passaggio di parametri";

    InitWindow(screenWidth, screenHeight, s.c_str());

    float x = 100;
    float y = 100;
    float vx = 2;
    float vy = 5;
    float r = 20;
    float a = 0.5;

    //Parametri della seconda pallina
    float x2 = 400;
    float y2 = 150;
    float vx2 = 5;
    float vy2 = 2;
    float r2 = 30;



    //std::cout << "INserisci il raggio del cerchio: ";
    //std::cin >> raggio;

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        aggiorna_posizione(x, y, r, vx, vy, a);
        aggiorna_posizione(x2, y2, r2, vx2, vy2, a);

        //----------------------------------------------------------------------------------
        //----------------------------------------------------------------------------------
        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawCircle(x, y, r, BLACK);
        DrawCircle(x2, y2, r2, RED);
        DrawLine(x, y, x2, y2, BLUE);


        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}

