#include <iostream>
#include <ostream>
#include <string>

#include "include/raylib.h"

void inizializza(const std::string &segreta, std::string& attuale) {
    attuale = "";
    for (int i = 0; i < segreta.size(); ++i) {
        attuale += '_';
    }
}

bool controlla(const std::string& segreta, char lettera,
    std::string &attuale) {
    bool trovata = false;
    for (int i = 0; i < segreta.size(); ++i) {
        if (segreta.at(i) == lettera) {
            attuale.at(i) = lettera;
            trovata = true;
        }
    }
    return trovata;
}

void disegna(const Texture &immagine, int errori) {
    DrawTexture(immagine,0,0,WHITE);
    int w = immagine.width;
    int h = immagine.height;
    for (int i = errori; i < 9; ++i) {
        DrawRectangle((i % 3) * (w / 3), (i / 3) * (h /3), w/3, h/3, WHITE);
    }
}

int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 650;

    const int MAX_ERRORI = 9;
    int conta_errori = 0;
    std::string segreta, provate, attuale;

    segreta = "armadillo";
    inizializza(segreta, attuale);


    InitWindow(screenWidth, screenHeight, "Attento al mostro");

    Texture2D immagine = LoadTexture("../assets/mind_flayer.png");

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose() && conta_errori < MAX_ERRORI && segreta != attuale)    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        // TODO: Update your variables here
        //----------------------------------------------------------------------------------
        char lettera = GetCharPressed();
        if (lettera > 0) {
            std::cout << lettera << std::endl;
            if (controlla(segreta, lettera, attuale) == false)
                conta_errori++;
        }
        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(RAYWHITE);

        disegna(immagine, conta_errori);
        DrawText(attuale.c_str(), 20, screenHeight - 60, 60, BLACK);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------
    if (segreta == attuale) {
        std::cout << "Hai indovinato la parola " << segreta << std::endl;
    }
    else {
        std::cout << "Hai sbagliato, la parola era " << segreta << std::endl;
    }
    return 0;
}

