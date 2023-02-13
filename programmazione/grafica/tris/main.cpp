#include <cstdlib>
#include "include/raylib.h"
#include <iostream>

const int N = 3;

void disegna_griglia(){
    DrawLine(GetScreenWidth()/3, 0, GetScreenWidth()/3,GetScreenHeight(), BLACK);
    DrawLine(GetScreenWidth()*2/3, 0, GetScreenWidth()*2/3, GetScreenHeight(), BLACK);
}

void disegna(int tris[][N]){
    disegna_griglia();
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (tris[i][j] == 1) {
                int x = GetScreenWidth()/6 + j*GetScreenWidth()/3;
                int y = GetScreenHeight()/6 + i*GetScreenHeight()/3;;
                DrawCircle(x, y, GetScreenWidth() / 6 - 20, RED);
            }
            if (tris[i][j] == 2) {
                int x = GetScreenWidth()/6 + j*GetScreenWidth()/3;
                int y = GetScreenHeight()/6 + i*GetScreenHeight()/3;;
                DrawCircle(x, y, GetScreenWidth() / 6 - 20, BLUE);
            }
        }
    }
}

/**
 * Funzione che inserisce una mossa, se valida
 * @param tris La matrice del tris
 * @param r la riga dove voglio inserire, prima riga 0
 * @param c la colonna dove voglio inserire, prima colonna 0
 * @param giocatore 1 o 2
 * @return true se la mossa è valida, e quindi viene fatta, false altrimenti
 */
bool fai_mossa(int tris[][N],int r, int c, int giocatore){
    if (r < 0 || r > 2)
        return false;
    if (c < 0 || c > 2)
        return false;
    if (tris[r][c] != 0)
        return false;
    tris[r][c] = giocatore;
    return true;
}

/**
 *
 * @param tris
 * @return 1 se vince il giocatore 1
 *  2 se vince il giocatore 2
 *  3 patta
 *  0 partita in corso
 */
int verifica_stato(int tris[][N]){
    //controllo delle righe
    for (int i = 0; i < N; ++i) {
        if(tris[i][0] == tris[i][1] && tris[i][0] == tris[i][2])
            return tris[i][0];
    }
    //controllo delle colonne
    for (int i = 0; i < N; ++i) {
        if(tris[0][i] == tris[1][i] && tris[0][i] == tris[2][i])
            return tris[0][i];
    }
    if (tris[0][0] == tris[1][1] && tris[1][1] == tris[2][2])
        return tris[1][1];
    if (tris[0][2] == tris[1][1] && tris[1][1] == tris[2][0])
        return tris[1][1];
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (tris[i][j] == 0)
                return 0;
        }
    }
    return 3;
}


int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 400;
    const int screenHeight = 400;
    InitWindow(screenWidth, screenHeight, "Tris");

    int tris[N][N];

    //Azzero la matrice
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            tris[i][j] = 0;
        }
    }

    tris[1][0] = 1;
    tris[1][1] = 2;


    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        disegna(tris);
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
            Vector2 posizione = GetMousePosition();
            std::cout << posizione.x << " " << posizione.y << std::endl;
        }
        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();
        ClearBackground(WHITE);


        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}

