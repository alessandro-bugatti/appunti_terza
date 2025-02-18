#include <string>
#include <vector>

#include "include/raylib.h"


void filtra(std::vector<int> &v, int k) {
    std::vector<int> temp;
    temp = v;
    for (int i = k; i < v.size() - k; ++i) {
        int media, somma = 0;
        for (int j = i -k ; j < i + k + 1; ++j) {
            somma += v.at(j);
        }
        media = somma / (2*k + 1);
        temp.at(i) = media;
    }
    v = temp;
}

void disegna(const std::vector<int> &v, int width, Color color) {
    for (int i = 0; i < v.size() - 1; ++i) {
        int x1 = width / v.size() * i;
        int x2 = width /v.size() * (i + 1);
        DrawLineEx({(float)x1, (float)v.at(i) + 100},{(float) x2, (float)v.at(i+1) + 100}, 3,color);
    }
}

int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 1200;
    const int screenHeight = 450;

    std::string s = "Filtro a media mobile";

    InitWindow(screenWidth, screenHeight, s.c_str());
    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    std::vector<int> originale, filtrato;

    int k = 10, N = 200;
    for (int i = 0; i < N; ++i) {
        if (rand() % 20 < 1) {
            originale.push_back(rand() % 200);
        }
        else {
            originale.push_back(rand() % 10 + 95);
        }
    }
    filtrato = originale;
    filtra(filtrato, k);
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

        disegna(originale, screenWidth, BLACK);
        disegna(filtrato, screenWidth, RED);


        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}

