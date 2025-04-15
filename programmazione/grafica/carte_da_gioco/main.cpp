#include <fstream>
#include <iostream>
#include <ostream>
#include <string>
#include <vector>

#include "include/raylib.h"

struct Carta {
    int pos_x;
    int pos_y;
    int valore;
    int seme;
    Rectangle r;
    Texture2D *carte;
};

void disegna_carta(const Carta& c) {
    Rectangle destination;
    destination.x = c.pos_x;
    destination.y = c.pos_y;
    destination.width = c.r.width;
    destination.height = c.r.height;
    DrawTexturePro(*c.carte, c.r, destination,{},0,WHITE);
}

int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 1200;
    const int screenHeight = 800;

    InitWindow(screenWidth, screenHeight, "Attento al mostro");

    Texture2D immagine = LoadTexture("../assets/deck.png");

    Carta c;
    c.pos_x = 0;
    c.pos_y = 0;
    c.seme = 1;
    c.valore = 1;
    c.r.x = 170;
    c.r.y = 15;
    c.r.width = 125;
    c.r.height = 172;
    c.carte = &immagine;

    std::vector<Carta> mazzo;

    for (int i = 0; i < 13; ++i) {
        Carta d = c;
        d.pos_x = c.pos_x + 20 * i;
        d.pos_y = c.pos_y + 20 * i;
        d.r.x = 173 + (c.r.width + 14) * i;
        d.r.y = 35;
        mazzo.push_back(d);
    }

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        BeginDrawing();

        ClearBackground(DARKGREEN);

        //disegna_carta(c);

        for (int i = 0; i < mazzo.size(); ++i) {
            disegna_carta(mazzo.at(i));
        }

        EndDrawing();

    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context

    return 0;
}

