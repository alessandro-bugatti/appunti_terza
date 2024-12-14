

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

#include "raylib.h"
#include <string>

int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 512;
    const int screenHeight = 512;
    std::string s = "raylib ";
    s += RAYLIB_VERSION;
    s += " orientamento seconde";

    float x = 0;
    float y = 0;
    float dx = 4;
    float dy = 0;
    float g = -0.2;

    InitWindow(screenWidth, screenHeight, s.c_str());

    Texture2D image = LoadTexture("basketball.png");
    Texture2D background = LoadTexture("background.png");

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------

        x += dx;
        y += dy;
        dy -= g;

        if (y > screenHeight) {
            dy = -dy;
            dy = dy * 0.9;
            dx = dx * 0.85;
            y = screenHeight;
        }
        if (x > screenWidth) {
            dx = -dx;
        }
        if (y < 0 ) {
            dy = -dy;
        }
        if (x < 0) {
            dx = -dx;
        }

        //----------------------------------------------------------------------------------
        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(RAYWHITE);
        DrawTexture(background, 0, 0, WHITE);

        //DrawText(s.c_str(), 190, 200, 30, BLACK);
        DrawCircle(x, y, 20, RED);
        DrawTexture(image, x, y - 30, WHITE);
        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}

