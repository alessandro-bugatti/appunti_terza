#include <cstddef>
#include <string>

#include "include/raylib.h"

/**
 * Da completare, serve a disegnare una tessera dello scarabeo,
 * potrebbero servire anche altri parametri
 * @param x
 * @param y
 * @param lato Dimensione della tessera
 * @param c Carattere sulla tessera
 * @param n Numero sulla tessera
 * @param font Font della lettera
 */
void disegna_tessera(int x, int y, int lato, char c, int n, Font font) {
    std::string s;
    s += c;
    DrawRectangle(x,y, lato, lato, YELLOW);
    DrawTextEx(font,s.c_str(),{x,y},110,0,BLACK);
}

int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 960;
    const int screenHeight = 960;

    InitWindow(screenWidth, screenHeight, "Scrabble");

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------
    Texture board = LoadTexture("../assets/board.png");
    int fontsize = 110;

    Font font = LoadFontEx("../assets/wix.ttf",fontsize,NULL,0);
    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        // TODO: Update your variables here
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawTexture(board,(screenWidth - board.width) / 2,0,WHITE);
        disegna_tessera(10,10,50,'C',12,font);
        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}

