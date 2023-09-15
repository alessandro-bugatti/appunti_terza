#include <cstdlib>
#include "include/raylib.h"

int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 450;
    InitWindow(screenWidth, screenHeight, "Palline");

    const int N_PALLINE = 1000;

    Vector2 pos[N_PALLINE];
    Vector2 vel[N_PALLINE];
    Color colore[N_PALLINE];

    for (int i = 0 ; i < N_PALLINE; i++) {
        pos[i].x = rand()%GetScreenWidth();
        pos[i].y = rand()%GetScreenHeight();

        vel[i].x = (rand()%2 * 2) - 1;
        vel[i].y = (rand()%2 * 2) - 1;

        colore[i].r = rand()%256;
        colore[i].g = rand()%256;
        colore[i].b = rand()%256;
        colore[i].a = 255;
    }

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------

        for (int i = 0; i< N_PALLINE; i++) {
            pos[i].x += vel[i].x;
            pos[i].y += vel[i].y;
            //Da completare
            if (pos[i].x > GetScreenWidth())
                vel[i].x *= -1;
            if (pos[i].x < 0)
                vel[i].x *= -1;
            if (pos[i].y > GetScreenHeight())
                vel[i].y *= -1;
            if (pos[i].y < 0)
                vel[i].y *= -1;
        }

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();
        ClearBackground(WHITE);
        for (int i = 0; i < N_PALLINE; ++i) {
            DrawCircle(pos[i].x, pos[i].y, 10, colore[i]);
        }
        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}

