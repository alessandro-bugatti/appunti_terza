#include "include/raylib.h"
#include <iostream>
#include <cstring>

using namespace std;

const int RIGHE = 20;
const int COLONNE = 20;

void disegna_posto(int x, int y, bool prenotato,Texture2D posto)
{
    if (prenotato)
        DrawTexture(posto,x + 10, y + 10, RED);
    else
        DrawTexture(posto,x + 10, y + 10, GREEN);

    /*
    if (prenotato)
        DrawCircle(x + 10, y + 10, 10, RED);
    else
        DrawCircle(x + 10, y + 10, 10, GREEN);
    */
}

void disegna_sala(bool posti[][COLONNE], int righe,int w, int h, Texture2D posto)
{
    for (int i = 0; i < righe; ++i) {
        for (int j = 0; j < COLONNE; ++j) {
            int x = w / COLONNE * j;
            int y = h / righe * i;
            disegna_posto(x ,y ,posti[i][j], posto);
        }
    }
}

string stampa_posto(int riga, int colonna)
{
    string posto = "";
    posto += (char)('A' + riga);
    posto += " - ";
    posto += to_string(colonna + 1);

    return posto;
}

int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 1200;
    const int screenHeight = 800;


    bool posti[RIGHE][COLONNE];
    for (int i = 0; i < RIGHE; ++i) {
        for (int j = 0; j < COLONNE; ++j) {
            posti[i][j] = false;
        }
    }
    //posti[10][10] = true;


    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");
    Texture2D posto = LoadTexture("img/posto.png");
    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------
    Vector2 posizioneMouse;
    int deltaX = screenWidth / COLONNE;
    int deltaY = screenHeight / RIGHE;
    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        posizioneMouse = GetMousePosition();
        int riga = posizioneMouse.y / deltaY;
        int colonna = posizioneMouse.x / deltaX;
        string posizione = stampa_posto(riga, colonna);
        //cout << riga << " " << colonna << posizione << endl;

        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
            posti[riga][colonna] = !posti[riga][colonna];
        /*Oppure se si vogliono usare i due bottoni del mouse
        if (IsMouseButtonPressed(MOUSE_BUTTON_RIGHT))
            posti[riga][colonna] = false;
        */
         // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(RAYWHITE);

        char stringa_c[20];
        strcpy(stringa_c, posizione.c_str());
        disegna_sala(posti, RIGHE, screenWidth, screenHeight, posto);
        DrawRectangle(posizioneMouse.x - 4, posizioneMouse.y - 44,130,40,WHITE);
        DrawText(stringa_c, posizioneMouse.x, posizioneMouse.y - 40,40,BLACK);
        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}

