#include <cstdlib>
#include "include/raylib.h"
#include <iostream>

const int N = 128;
const int DIM_CELL = 8;

void azzera(int m[][N]){
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            m[i][j] = 0;
        }
    }
}

void inizializza(int m[][N]){
    for (int i = 1; i < N-1; ++i) {
        for (int j = 1; j < N-1; ++j) {
            if(rand()%4 == 0)
                m[i][j] = 1;
        }
    }
}

int vicini(int life[][N], int r, int c){
    int contatore = 0;
    for (int i = r - 1; i <= r + 1; ++i) {
        for (int j = c - 1; j <= c + 1; ++j) {
            contatore += life[i][j];
        }
    }
    return contatore - life[r][c];
}

void evolvi(int life[][N], int life_next[][N]){
    for (int i = 1; i < N-1; ++i) {
        for (int j = 1; j < N-1; ++j) {
            int v = vicini(life, i, j);
            //prima regola
            if (v == 3 && life[i][j] == 0){
                life_next[i][j] = 1;
            }
            //seconda regola
            if (life[i][j] == 1 && (v == 2 || v == 3)){
                life_next[i][j] = 1;
            }
            //terza regola
            if (life[i][j] == 1 && (v < 2 || v > 3)){
                life_next[i][j] = 0;
            }
        }
    }
}

void copia(int dst[][N], int src[][N]){
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            dst[i][j] = src[i][j];
        }
    }
}

void disegna(int life[][N]){
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (life[i][j] == 1){
                DrawRectangle(i * DIM_CELL,j * DIM_CELL ,DIM_CELL, DIM_CELL, GREEN);
            }
        }
    }
}

int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = N * DIM_CELL;
    const int screenHeight = N * DIM_CELL;
    InitWindow(screenWidth, screenHeight, "Life");

    int life[N][N];
    int life_next[N][N];

    azzera(life);
    azzera(life_next);
    inizializza(life);



    SetTargetFPS(10);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        evolvi(life, life_next);
        copia(life, life_next);
        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();
        ClearBackground(BLACK);

        disegna(life);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}

