#include <cstdlib>
#include <iostream>
#include <ostream>

#include "include/raylib.h"

void assegna_numeri(int v[], int n) {
    for (int i = 0; i < n; ++i) {
        v[i] = rand() % 80 + 1;
    }
}


int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 1000;
    const int screenHeight = 650;
    const int TRAGUARDO = screenWidth - 103;
    const int N_CAVALLI = 6;
    const int PREMIATI = 3;
    const int SPOSTAMENTO = 5;
    int arrivati = 0;

    InitWindow(screenWidth, screenHeight, "Corsa dei cavalli");
    InitAudioDevice();
    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    Texture2D cavallo = LoadTexture("../assets/horse.png");
    int pos_cavalli[N_CAVALLI] = {0};
    int num_cavalli[N_CAVALLI];
    bool cavalli_arrivati[N_CAVALLI] = {false};
    int ordine[3];

    Color colori[N_CAVALLI] = {
        RED,
        GREEN,
        BLUE,
        BLACK,
        YELLOW,
        PURPLE
    };

    Music music = LoadMusicStream("../assets/mini1111.xm");
    PlayMusicStream(music);

    assegna_numeri(num_cavalli, N_CAVALLI);

    int vincitore;
    bool gara_in_corso = true;

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        // TODO: Update your variables here
        //----------------------------------------------------------------------------------
        UpdateMusicStream(music);
        if (gara_in_corso) {

            for (int i = 0; i < N_CAVALLI; ++i) {
                pos_cavalli[i] += rand() % SPOSTAMENTO;
            }
            for (int i = 0; i < N_CAVALLI; ++i) {
                if (pos_cavalli[i] > TRAGUARDO && cavalli_arrivati[i] == false) {
                    ordine[arrivati] = num_cavalli[i];
                    cavalli_arrivati[i] = true;
                    arrivati++;
                    if (arrivati == PREMIATI) {
                        gara_in_corso = false;
                        for (int i = 0; i < PREMIATI; ++i) {
                            std::cout << ordine[i] << std::endl;
                        }
                    }
                }
            }
        }
        if (IsKeyDown(KEY_R)) {
            if (!gara_in_corso){
                gara_in_corso = true;
                for (int i = 0; i < N_CAVALLI; ++i) {
                    pos_cavalli[i] = 0;
                }
            }
        }
        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();
        ClearBackground(WHITE);
        //DrawTexture(texture_sfondo, 0, 0, WHITE);
        if (gara_in_corso) {
            for (int i = 0; i < N_CAVALLI; ++i) {
                DrawTexture(cavallo,pos_cavalli[i], (screenHeight/N_CAVALLI) * i, colori[i]);
                std::string numero = std::to_string(num_cavalli[i]);
                DrawText(numero.c_str(),pos_cavalli[i] + 40, (screenHeight/N_CAVALLI) * i,24,BLACK);
            }
        }
        else{

        }
        if(!gara_in_corso){
            for (int i = 0; i < N_CAVALLI; ++i) {
                DrawTexture(cavallo,pos_cavalli[i], (screenHeight/N_CAVALLI) * i, colori[i]);
                std::string numero = std::to_string(num_cavalli[i]);
                DrawText(numero.c_str(),pos_cavalli[i], (screenHeight/N_CAVALLI) * i,24,BLACK);
            }
        }

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    UnloadMusicStream(music);
    UnloadTexture(cavallo);
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}

