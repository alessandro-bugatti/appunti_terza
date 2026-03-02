#include <cmath>
#include <iostream>
#include <string>
#include <vector>

#include "raylib.h"

/**
 *
 * @param v vettore delle coordinate
 * @param quale buco scelto per il disegno
 * @param t immagine della talpa
 */
void disegna_talpa(const std::vector<Vector2> &v, int quale, const Texture &t) {
    Vector2 pos = v.at(quale);
    int w = t.width;
    int h = t.height;
    DrawTexture(t, pos.x - w / 2, pos.y - h, WHITE);
}

bool colpita(Vector2 coord_talpa, Vector2 coord_mouse, int raggio) {
    return true;
}

int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 1024;
    const int screenHeight = 500;

    InitWindow(screenWidth, screenHeight, "Whack-a-mole");
    std::vector<Vector2> coordinate;

    //Inseriamo le coordinatare dei buchi
    Vector2 v;
    //Primo buco
    v.x = 300;
    v.y = 100;
    coordinate.push_back(v);
    //Secondo buco
    v.x = 150;
    v.y = 220;
    coordinate.push_back(v);
    //Terzo buco
    v.x = 800;
    v.y = 300;
    coordinate.push_back(v);

    int buca_attuale = rand() % coordinate.size();

    Texture background = LoadTexture("assets/background.png");
    Texture mole = LoadTexture("assets/mole.png");


    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
            //Update
            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
                Vector2 mouse;
                mouse.x = GetMouseX();
                mouse.y = GetMouseY();
                Vector2 talpa;
                talpa.x = coordinate.at(buca_attuale).x;
                talpa.y = coordinate.at(buca_attuale).y - mole.height / 2;
                int raggio = mole.width / 2;
                if (colpita(talpa, mouse, raggio)) {
                    buca_attuale = rand() % coordinate.size();
                }
            }

            //Drawing
            BeginDrawing();
            ClearBackground(RAYWHITE);
            DrawTexture(background, 0, 0 , WHITE);
            for (int i = 0; i < coordinate.size(); ++i) {
                Vector2 v = coordinate.at(i);
                DrawEllipse(v.x, v.y, 100, 30,BLACK);
            }
            disegna_talpa(coordinate, buca_attuale, mole);

            EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}

