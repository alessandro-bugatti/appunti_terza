#include <string>
#include <vector>

#include "include/raylib.h"



void disegna_buchi(const std::vector<int> &vx, const std::vector<int> &vy) {
    for (int i = 0; i < vx.size(); ++i) {
        DrawEllipse(vx.at(i), vy.at(i), 80, 20, BLACK);
    }
}

void disegna_talpa(const std::vector<int> &vx, const std::vector<int> &vy,
    int i, const Texture &talpa) {
    int x = vx.at(i) - talpa.width / 2;
    int y = vy.at(i) - talpa.height;
    DrawTexture(talpa, x, y, WHITE);
}

int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 1024;
    const int screenHeight = 500;

    std::string s = "Whack-a-mole";

    InitWindow(screenWidth, screenHeight, s.c_str());
    SetTargetFPS(60);

    std::vector<int> vx;
    std::vector<int> vy;
    Texture talpa = LoadTexture("../assets/mole.png");

    //Inseriamo a mano le coordinate di 6 buchi
    {
        vx.push_back(100);
        vy.push_back(200);
        vx.push_back(200);
        vy.push_back(300);
        vx.push_back(600);
        vy.push_back(400);
        vx.push_back(800);
        vy.push_back(400);
        vx.push_back(650);
        vy.push_back(220);
        vx.push_back(700);
        vy.push_back(300);
    }// Main game loop
    int talpa_attiva = rand() % vx.size();
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        // TODO: Update your variables here
        //----------------------------------------------------------------------------------
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
            int xm = GetMouseX();
            int ym = GetMouseY();
            if (true) {
                talpa_attiva = rand() % vx.size();
            }

        }
        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(RAYWHITE);

        disegna_buchi(vx, vy);
        disegna_talpa(vx, vy, talpa_attiva, talpa);
        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}

