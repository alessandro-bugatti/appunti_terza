#include "include/raylib.h"


int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 800;

    int x, y;

    x = 0;
    y = 0;

    InitWindow(screenWidth, screenHeight, "Movimento");

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        x+=2;
        y+=2;
        if (x > GetScreenWidth() - 50)
            x -= 2;
        if (y > GetScreenHeight() - 50)
            y -= 2;
        BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawRectangle(x, y, 50, 50, RED);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}

