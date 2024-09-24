#include <cstdlib>
#include "include/raylib.h"


void muovi_tartaruga (int &posizione){
    int n;
    n=rand()%100+1;
    if (n<=50){
        posizione+=3;
    } else if (n<=70){
        posizione-=6;
    } else {
        posizione++;
    }
    if (posizione < 0)
        posizione = 0;
}

void muovi_lepre (int &posizione){
    int n;
    n = rand()%100+1;
    if (n<=20){
        posizione+=9;
    } else if (n<=30){
        posizione-=12;
    } else if (n<=60) {
        posizione += 1;
    } else if (n <= 80){
        posizione -= 2;
    }
    //Per il 20% non fa nulla, dorme
    if (posizione < 0 )
        posizione = 0;
}

int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 800;

    int pos_lepre = 0, pos_tartaruga = 0;

    const int corsia_lepre = 50;
    const int corsia_tartaruga = 200;

    InitWindow(screenWidth, screenHeight, "Movimento");

    SetTargetFPS(20);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        muovi_lepre(pos_lepre);
        muovi_tartaruga(pos_tartaruga);
        BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawRectangle(pos_lepre, corsia_lepre, 50, 50, RED);
        DrawRectangle(pos_tartaruga, corsia_tartaruga, 50, 50, BLUE);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}

