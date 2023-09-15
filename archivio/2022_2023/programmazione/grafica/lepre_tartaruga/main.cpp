#include <cstdlib>
#include "include/raylib.h"

int movimento_tartaruga(){
    int mossa_tartaruga = rand()%100;
    if (mossa_tartaruga < 50){
        return 3;
    }
    else if (mossa_tartaruga < 70){
        return -6;
    }
    else{
        return 1;
    }
}

int movimento_lepre(){
    int mossa_lepre = rand()%100;
    if (mossa_lepre < 20){
        return 9;
    }
    else if (mossa_lepre < 30){
        return -12;
    }
    else if (mossa_lepre < 60){
        return 1; //lepre += 1;
    }
    else if (mossa_lepre < 80){
        return -2;
    }
    return 0;
}

int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 450;
    const int y_lepre = 200;
    const int y_tartaruga = 330;
    const int TRAGUARDO = screenWidth - 103;

    InitWindow(screenWidth, screenHeight, "Gara della lepre e della tartaruga");
    InitAudioDevice();
    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    Texture2D texture_lepre = LoadTexture("../assets/lepre.png");
    Texture2D texture_tartaruga = LoadTexture("../assets/tartaruga.png");
    Texture2D texture_sfondo = LoadTexture("../assets/road.png");

    Music music = LoadMusicStream("../assets/mini1111.xm");
    PlayMusicStream(music);

    int pos_lepre = 0;
    int pos_tartaruga = 0;

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
            pos_tartaruga += movimento_tartaruga();
            if (pos_tartaruga < 0)
                pos_tartaruga = 0;
            pos_lepre += movimento_lepre();
            if (pos_lepre < 0)
                pos_lepre = 0;
            if (pos_tartaruga > TRAGUARDO || pos_lepre > TRAGUARDO)
                gara_in_corso = false;
        }
        if (IsKeyDown(KEY_R)) {
            if (!gara_in_corso){
                gara_in_corso = true;
                pos_lepre = 0;
                pos_tartaruga = 0;
            }
        }
        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        DrawTexture(texture_sfondo, 0, 0, WHITE);
        if (gara_in_corso) {
            DrawTexture(texture_lepre, pos_lepre, y_lepre, WHITE);
            DrawTexture(texture_tartaruga, pos_tartaruga, y_tartaruga, WHITE);
        }
        else{
            if (pos_tartaruga > pos_lepre)
                DrawTexture(texture_tartaruga, pos_tartaruga, y_tartaruga, WHITE);
            else
                DrawTexture(texture_lepre, pos_lepre, y_lepre, WHITE);

        }
        if(!gara_in_corso){
            DrawRectangle(0,0,650,50, WHITE);
            if(pos_lepre > pos_tartaruga)
                DrawText("Ha vinto la lepre - R per ripetere", 20, 20, 30, BLACK);
            else
                DrawText("Ha vinto la tartaruga - R per ripetere", 20, 20, 30, BLACK);
        }

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    UnloadMusicStream(music);
    UnloadTexture(texture_tartaruga);
    UnloadTexture(texture_lepre);
    UnloadTexture(texture_sfondo);
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}

