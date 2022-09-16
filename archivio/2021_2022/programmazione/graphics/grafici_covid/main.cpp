#include "include/raylib.h"
#include <string>
#include <fstream>



using namespace std;

void carica(int v[], int &n, int &max, char *nome_dati, const char *nome_file){
    ifstream in(nome_file);
    in >> nome_dati;
    int contatore = 0;
    max = 0;
    while(in >> v[contatore]){
        if (v[contatore] > max)
            max = v[contatore];
        contatore++;
    }
    n = contatore;
}

//Aggiungere un parametro per il colore
void disegna(int v[], int n, int max, int width, int height){
    int x0, y0, x1, y1;
    for (int i = 1; i < n; ++i) {
        x0 = (i - 1) * width / n;
        x1 = i * width / n;
        y0 = height - (v[i-1] * height / max );
        y1 = height - (v[i] * height / max );
        DrawLine(x0, y0, x1, y1, RED);
    }
}

//Da costruire
void media_mobile(int originale[], int filtrato[], int n) {

}

int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 1400;
    const int screenHeight = 700;

    InitWindow(screenWidth, screenHeight, "Grafici covid");
    const int MAX_DATI = 2000;

    int dati_originali[MAX_DATI];
    int dati_filtrati[MAX_DATI];

    char titolo[100];

    int n, max_valore;

    carica(dati_originali, n, max_valore,titolo, "deceduti_giornalieri.csv");

    //Da costruire
    media_mobile(dati_originali, dati_filtrati, n);


    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        BeginDrawing();

        ClearBackground(RAYWHITE);

        disegna(dati_originali, n, max_valore, screenWidth, screenHeight);
        disegna(dati_filtrati, n, max_valore, screenWidth, screenHeight);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}



