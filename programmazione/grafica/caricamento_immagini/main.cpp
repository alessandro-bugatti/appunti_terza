#include "include/raylib.h"

int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 500;


    //tutte le istruzioni di caricamento devono essere scritte dopo questa istruzione
    InitWindow(screenWidth, screenHeight, "Caricamento immagini");
    //Caricamento dell'immagine dal disco
    Texture2D img = LoadTexture("../assets/image.png");
    float x = 0;
    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        // TODO: Update your variables here
        //----------------------------------------------------------------------------------
        x += 0.1;
        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(RAYWHITE);
        //Disegna la texture
        DrawTexture(img, screenWidth/2 - 100 + x, screenHeight/2, WHITE);
        DrawText("Caricamento riuscito, ninja girl attiva.", 120, 150, 30, GRAY);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}

