#include <cstdlib>
#include "include/raylib.h"

const int screenWidth = 800;
const int screenHeight = 450;

struct Punto{
    //Rappresenta l'ascissa
    float x;
    //Rappresenta l'ordinata
    float y;
};

struct Triangolo{
    Punto a;
    Punto b;
    Punto c;
    Color colore;
};

const int MAX_PUNTI = 100;

struct Spezzata{
    Punto punti[MAX_PUNTI];
    int n_punti;
};

void crea_spezzata(Spezzata &s){
    s.n_punti = rand()%(MAX_PUNTI - 2) + 2;
    for (int i = 0; i < s.n_punti; ++i) {
        s.punti[i].x = rand() % screenWidth;
        s.punti[i].y = rand() % screenHeight;
    }
}

void disegna(const Spezzata &s){
    for (int i = 0; i < s.n_punti - 1; ++i) {
        DrawLine(s.punti[i].x, s.punti[i].y,
                 s.punti[i+1].x, s.punti[i+1].y, RED);
    }
}

void crea_triangolo(Triangolo &t){
    t.a.x = rand() % screenWidth;
    t.b.x = rand() % screenWidth;
    t.c.x = rand() % screenWidth;
    t.a.y = rand() % screenHeight;
    t.b.y = rand() % screenHeight;
    t.c.y = rand() % screenHeight;
    t.colore.a = 255;
    t.colore.r = rand()%256;
    t.colore.g = rand()%256;
    t.colore.b = rand()%256;
}

void disegna(const Triangolo &t){
    DrawLineEx({t.a.x, t.a.y}, {t.b.x,  t.b.y}, 5, t.colore);
    DrawLineEx({t.c.x, t.c.y}, {t.b.x,  t.b.y}, 5, t.colore);
    DrawLineEx({t.a.x, t.a.y}, {t.c.x,  t.c.y}, 5, t.colore);
}

int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------

    InitWindow(screenWidth, screenHeight, "Geometria");

    const int NUM_TRIANGOLI = 50;
    Spezzata s;
    crea_spezzata(s);
    Triangolo t[NUM_TRIANGOLI];
    for (int i = 0; i < NUM_TRIANGOLI; ++i) {
        crea_triangolo(t[i]);
    }

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();
        ClearBackground(WHITE);

        //disegna(s);
        for (int i = 0; i < NUM_TRIANGOLI; i++) {
            disegna(t[i]);
        }

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}

