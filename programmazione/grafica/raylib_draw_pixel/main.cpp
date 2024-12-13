#include <string>
#include <vector>

#include "include/raylib.h"

void disegna_pixels(int x, int y, int w, int h, Color c) {
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (i % 3 == 0){
                DrawPixel(x + j, y + i, c);
            }
        }
    }
}

int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 450;

    std::string s = "raylib ";
    s += RAYLIB_VERSION;
    s += " draw pixel";

    InitWindow(screenWidth, screenHeight, s.c_str());
    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

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

        //DrawText("Template version 2024-12-09", 190, 200, 30, BLACK);
        disegna_pixels(100 , 100, 40, 20, RED);
        int n = GetRandomValue(0,100);
        n = rand()%100;


        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}

