#include <cstdlib>
#include "include/raylib.h"
#include <iostream>
#include <string>
#include <iostream>

const int N = 3;

bool ricerca(const std::string &s, char c){
    for (int i = 0; i < s.size(); ++i) {
        if (c == s.at(i))
            return true;
    }
    return false;
}

void svela(std::string &visibile, char c, const std::string &segreta){
    for (int i = 0; i < segreta.size(); ++i) {
        if (segreta.at(i) == c)
            visibile.at(i) = c;
    }
}

void disegna(Texture2D &tex, int errori){
    int pos_x = (GetScreenWidth() - tex.width) / 2;
    DrawTexture(tex, pos_x, 0, WHITE);
    int w = tex.width / N;
    int h = tex.height / N;
    for (int i = errori; i < N*N; ++i) {
        DrawRectangle(pos_x + i%N * w,i/N * h, w,h, WHITE);
    }

}

int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 600;
    InitWindow(screenWidth, screenHeight, "Attenti al mostro");

    std::string segreta = "cancello";
    std::string visibile;

    for (int i = 0; i < segreta.size(); ++i) {
        visibile += '_';
    }

    int errori = 0;

    Texture2D tex = LoadTexture("../mind_flayer.png");

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        char key = GetCharPressed();
        while(key > 0){
            if (ricerca(segreta, key) == false)
                errori++;
            else
                svela(visibile, key, segreta);
            std::cout << errori << std::endl;
            key = GetCharPressed();
        }

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();
        ClearBackground(WHITE);
        disegna(tex, errori);
        DrawText(visibile.c_str(),20, screenHeight - 60, 60,BLACK);


        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}

