#include "include/raylib.h"

void aggiorna_posizione(float &x, float &y, float vx, float vy, float t) {
    x += vx;
    y = vy * t - 0.5 * 9.81 * t * t;
}

int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 800;

    float x = 0;
    float vx = 0.5;
    float t = 0;
    float y = 0;
    float vy = 50;

    InitWindow(screenWidth, screenHeight, "Movimento");

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        if(y < 0) {
            break;
        }

        aggiorna_posizione(x, y, vx, vy, t);
        t += 0.01;

        BeginDrawing();

        ClearBackground(RAYWHITE);
        DrawCircle(x, screenHeight - y, 10, RED);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        BeginDrawing();

        ClearBackground(RAYWHITE);
        DrawCircle(x, screenHeight - y, 10, RED);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}

