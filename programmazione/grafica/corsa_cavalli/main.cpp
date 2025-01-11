#include <cstdlib>
#include <iostream>
#include <ostream>

#include "include/raylib.h"


int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 450;
    const int TRAGUARDO = screenWidth - 103;
    const int N_CAVALLI = 4;
    const int SPOSTAMENTO = 5;

    InitWindow(screenWidth, screenHeight, "Corsa dei cavalli");
    InitAudioDevice();
    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    Texture2D cavallo = LoadTexture("../assets/horse.png");
    int pos_cavalli[N_CAVALLI] = {0};
    Color colori[N_CAVALLI] = {RED, GREEN, BLUE, BLACK};

    Music music = LoadMusicStream("../assets/mini1111.xm");
    PlayMusicStream(music);


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
                if (pos_cavalli[i] > TRAGUARDO) {
                    gara_in_corso = false;
                    vincitore = i + 1;
                    std::cout << "Ha vinto il cavallo " << vincitore << std::endl;
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
            }
        }
        else{

        }
        if(!gara_in_corso){
            for (int i = 0; i < N_CAVALLI; ++i) {
                DrawTexture(cavallo,pos_cavalli[i], (screenHeight/N_CAVALLI) * i, colori[i]);
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

