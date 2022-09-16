#include "raylib.h"

void disegna_scacchiera(int w, int h, int N, Color c1, Color c2)
{
   int lato = w / N;
   int colore = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (colore % 2 == 0)
                DrawRectangle(j*lato,i*lato,lato, lato, c1);
            else
                DrawRectangle(j*lato,i*lato,lato, lato, c2);
            colore++;
        }
        colore++;
    }
}

int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 512;
    const int screenHeight = 512;

    InitWindow(screenWidth, screenHeight, "Scacchiera");

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(RAYWHITE);

        //DrawText("Congrats! You created your first window!", 190, 200, 40, RED);

        disegna_scacchiera(screenWidth, screenWidth, 8, RED, YELLOW);
        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}

