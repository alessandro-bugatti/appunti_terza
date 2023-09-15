#include <cstdlib>
#include "include/raylib.h"
#include <iostream>
#include <string>
#include <iostream>

const int N = 3;

bool ricerca(const std::string &s, char c){
    for (int i = 0; i < s.size(); ++i) {
        if (c == s.at(i))
            return true;
    }
    return false;
}

void svela(std::string &visibile, char c, const std::string &segreta){
    for (int i = 0; i < segreta.size(); ++i) {
        if (segreta.at(i) == c)
            visibile.at(i) = c;
    }
}

void disegna(Texture2D &tex, int errori){
    int pos_x = (GetScreenWidth() - tex.width) / 2;
    DrawTexture(tex, pos_x, 0, WHITE);
    int w = tex.width / N;
    int h = tex.height / N;
    for (int i = errori; i < N*N; ++i) {
        DrawRectangle(pos_x + i%N * w,i/N * h, w,h, WHITE);
    }

}

int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 600;
    InitWindow(screenWidth, screenHeight, "Attenti al mostro");

    std::string segreta = ""; //"cancello";
    std::string visibile;



    int errori = 0;

    int game_state;

    const int INIZIO = 0;
    const int SCELTA_PAROLA = 1;
    const int INDOVINA = 2;
    const int RIGIOCA = 3;

    Texture2D tex = LoadTexture("../mind_flayer.png");

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------
    game_state = INIZIO;
    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {

        char key = GetCharPressed();
        BeginDrawing();
        ClearBackground(WHITE);

        switch (game_state) {
            case INIZIO:
                DrawText("Attenti al mostro", 20, 100, 30, BLACK);
                DrawText("Premi un tasto per continuare", 20, 150, 30, BLACK);
                if (key > 0)
                    game_state = SCELTA_PAROLA;
                break;
            case SCELTA_PAROLA:
                DrawText("Inserisci la parola da indovinare", 20, 100, 30, BLACK);
                DrawText(segreta.c_str(), 20, 150, 30, BLACK);
                if (key > 0)
                    segreta += key;
                if (IsKeyPressed(KEY_BACKSPACE))
                    segreta = segreta.substr(0, segreta.size() - 1);
                if (IsKeyPressed(KEY_ENTER)) {
                    game_state = INDOVINA;
                    for (int i = 0; i < segreta.size(); ++i) {
                        visibile += '_';
                    }
                }
                break;
            case INDOVINA:
                while(key > 0){
                    if (ricerca(segreta, key) == false)
                        errori++;
                    else
                        svela(visibile, key, segreta);
                    std::cout << errori << std::endl;
                    key = GetCharPressed();
                }
                disegna(tex, errori);
                DrawText(visibile.c_str(),20, screenHeight - 60, 60,BLACK);
                if (errori == 9 || visibile == segreta)
                    game_state = RIGIOCA;
                break;
            case RIGIOCA:
                if (errori == 9) {
                    DrawText("Hai perso", 20, 100, 60, BLACK);
                    std::string messaggio = "La parola da indovinare era " + segreta;
                    DrawText(messaggio.c_str(), 20, 180, 30, BLACK);
                }
                else{
                    DrawText("Hai vinto", 20, 100, 60, BLACK);
                }
                DrawText("Vuoi continuare (y/n)?", 20, 300, 30, BLACK);
                if (key > 0) {
                    if (key == 'y'){
                        game_state = SCELTA_PAROLA;
                        segreta = visibile = "";
                        errori = 0;
                    }
                    else{
                        CloseWindow();
                        return 0;
                    }

                }
                break;
        }

        // Update
        //----------------------------------------------------------------------------------



        // Draw
        //----------------------------------------------------------------------------------


        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}

