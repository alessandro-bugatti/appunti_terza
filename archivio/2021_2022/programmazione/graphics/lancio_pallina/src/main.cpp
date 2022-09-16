#include "raylib.h"

float uniforme(float v, float t)
{
    float s;
    s = v * t;
    return s;
}

float accelerato(float v, float t)
{
    const float G = 9.81;
    float s;
    s = - 0.5 * G * t * t + v * t;
    return s;
}

int main(void)
{
    float x, y;
    x = 0;
    y = 0;
    float vx, vy;
    vx = 65;
    vy = 65;
    float t = 0;
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 1024;
    const int screenHeight = 512;

    InitWindow(screenWidth, screenHeight, "Scacchiera");

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        t += 0.1;
        x = uniforme(vx, t);
        y = accelerato(vy, t);
        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(RAYWHITE);

        //DrawText("Congrats! You created your first window!", 190, 200, 40, RED);

        DrawCircle(x, 512 - y, 20, RED);

        EndDrawing();

        if (y < 0)
            break;
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}

