

/*******************************************************************************************
*
*   Esempio di utilizzo di colori
*
********************************************************************************************/

#include "raylib.h"

int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 512;
    const int screenHeight = 512;

    InitWindow(screenWidth, screenHeight, "Esempio di utilizzo di colori");

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------
    Color rosso = {255, 0, 0, 255};
    Color verde_chiaro = {0, 200, 0, 255};
    Color giallo_acido = {221, 234, 6, 255};
    Color azzurro = {12, 231, 190, 128};
    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(RAYWHITE);
        //Rettangolo rosso
        DrawRectangle(0,0,screenWidth/2, screenHeight/2,rosso);
        DrawText("Rosso",screenWidth/6, screenHeight/4,30, BLACK);
        //Rettangolo verde chiaro
        DrawRectangle(screenWidth/2, 0, screenWidth, screenHeight/2, verde_chiaro);
        DrawText("Verde chiaro",screenWidth/2 + 10, screenHeight/4, 30, BLACK);
        //Rettangolo giallo acido
        DrawRectangle(0, screenHeight/2 , screenWidth/2, screenHeight, giallo_acido);
        DrawText("Giallo acido",screenWidth/8, screenHeight/4*3, 30, BLACK);
        //Rettangolo azzurro trasparente
        DrawRectangle(screenWidth/2 - 40, screenHeight/2 - 40, screenWidth, screenHeight, azzurro);
        DrawText("Azzurro\ntrasparente",screenWidth/2 + 10, screenHeight/4*3, 30, BLACK);


        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}

