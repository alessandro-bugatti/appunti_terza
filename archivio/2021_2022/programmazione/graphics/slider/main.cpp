#include "include/raylib.h"

int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "slider");

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------
    float value = 0;
    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        //Lettura della pressione dei tasti UP e DOWN
        if(IsKeyDown(KEY_UP)){
            value += 0.01;
            if (value > 1)
                value = 1;
        }
        if(IsKeyDown(KEY_DOWN)){
            value -= 0.01;
            if (value < 0)
                value = 0;
        }
        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawRectangle(30,screenHeight - screenHeight*value,50, screenHeight*value, RED);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}

