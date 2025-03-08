#include <string>

#include "include/raylib.h"

const int DIM = 3;

void riempi (int tris[][DIM]){
    for (int i=0; i<DIM; ++i){
        for (int j=0; j<DIM; ++j){
            tris[i][j]=0;
        }
    }
}


bool mossa_valida(int tris[][DIM], int r, int c) {
    if (r < 0 || r >= DIM)
        return false;
    if (c < 0 || c >= DIM)
        return false;
    if (tris[r][c] != 0)
        return false;
    return true;
}

int verifica_stato(int tris[][DIM]) {

    //Controlla le righe, se c'è un tris ritorna il
    //valore del giocatore che l'ha fatto
    for (int i = 0; i < DIM; ++i) {
        if (tris[i][0] == tris[i][1] &&
            tris[i][1]== tris[i][2] &&
            tris[i][0] != 0){
        return tris[i][0];
        }
    }
    //Controlla le colonne, se c'è un tris ritorna il
    //valore del giocatore che l'ha fatto
    for (int i = 0; i < DIM; ++i) {
        if (tris[0][i] == tris[1][i] &&
            tris[1][i]== tris[2][i] &&
            tris[0][i] != 0){
            return tris[0][i];
            }
    }
    //Prima diagonale
    if (tris[0][0] == tris[1][1] &&
            tris[1][1]== tris[2][2] &&
            tris[0][0] != 0){
            return tris[0][0];
    }
    //Prima diagonale
    if (tris[0][2] == tris[1][1] &&
            tris[1][1]== tris[2][0] &&
            tris[0][2] != 0){
                return tris[0][2];
            }
    for (int i = 0; i < DIM; ++i) {
        for (int j = 0; j < DIM; ++j) {
            if (tris[i][j] == 0){
                return 0;
            }
        }
    }
    return 3; //pareggio
}


void disegna_griglia(int w, int h) {
    for (int i = 1; i <= 2; ++i) {
        //DrawLine((w / 3) * i, 0, (w / 3) * i, h, BLACK);
        //DrawLine(0, (h / 3) * i, w, (h / 3) * i, BLACK);
        Vector2 v1 = {(float)(w / 3) * i, 0};
        Vector2 v2 = {(float)(w / 3) * i, (float)h};
        DrawLineEx(v1, v2, 10, BLACK);
    }
}

void disegna_simboli(int w, int h, int tris[][DIM]) {
    for (int i = 0; i < DIM; ++i) {
        for (int j = 0; j < DIM; ++j) {
            if (tris[i][j] == 1) {
                Vector2 centro = {(float)w/2, (float)h/2};
                DrawRing(centro, w/6 * 0.9 - 20, w/6 * 0.9, 0, 360, 50, RED);
            }
        }
    }
}

int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 800;

    int tris[DIM][DIM];
    riempi (tris);
    tris[0][0] = 1;
    std::string s = "Tris";


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

        disegna_griglia(screenWidth, screenHeight);
        disegna_simboli(screenWidth, screenHeight, tris);
        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}

