#include <fstream>
#include <iostream>
#include <ostream>
#include <string>
#include <vector>

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

std::vector<std::string> carica(std::string nomefile) {
    std::vector<std::string> v;
    std::string s;
    std::ifstream in(nomefile);
    if (in) {
        while (in >> s) {
            v.push_back(s);
        }
    }
    return v;
}

int main(void)
{
    srand(time(NULL));
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 650;

    const int MAX_ERRORI = 9;
    int conta_errori = 0;
    std::string segreta, provate, attuale;

    std::vector<std::string> parole;

    /*
    parole.push_back("assegni");
    parole.push_back("coccodrillo");
    parole.push_back("automobile");
    parole.push_back("finestra");
    */
    parole = carica("../assets/parole.txt");
    if (parole.size() == 0) {
        std::cout << "Errore nell'apertura file.";
        return 1;
    }
    segreta = parole.at(rand()%parole.size());
    inizializza(segreta, attuale);


    InitWindow(screenWidth, screenHeight, "Attento al mostro");

    Texture2D immagine = LoadTexture("../assets/mind_flayer.png");

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------
    int stato;
    const int GIOCO = 1;
    const int FINALE = 2;
    const int CHIUDI_PROGRAMMA = 3;
    stato = GIOCO;
    // Main game loop
    while (!WindowShouldClose() && stato != CHIUDI_PROGRAMMA)    // Detect window close button or ESC key
    {
        char lettera = GetCharPressed();
        BeginDrawing();

        ClearBackground(RAYWHITE);
        if (stato == GIOCO) {
            if (lettera > 0) {
                std::cout << lettera << std::endl;
                if (controlla(segreta, lettera, attuale) == false)
                    conta_errori++;
            }
            if (conta_errori == MAX_ERRORI || segreta == attuale)
                stato = FINALE;

            disegna(immagine, conta_errori);
            DrawText(attuale.c_str(), 20, screenHeight - 60, 60, BLACK);

        }else if (stato == FINALE) {
            if (lettera > 0) {
                if (lettera == 'y') {
                    stato = GIOCO;
                    segreta = parole.at(rand() % parole.size());
                    inizializza(segreta, attuale);
                    conta_errori = 0;
                }
                else {
                    stato = CHIUDI_PROGRAMMA;
                }
            }
            if (conta_errori == MAX_ERRORI) {
                std::string s = "Hai perso, la parola era " + segreta;
                DrawText(s.c_str(), 100, 200, 36, BLACK);
            }
            else {
                std::string s = "Hai vinto, la parola era " + segreta;
                DrawText(s.c_str(), 100, 200, 36, BLACK);
            }
            DrawText("y per continuare, n per uscire",100, 300,36,BLACK);
        }
        EndDrawing();

    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------
    //Questa parte può essere rimossa se viene gestita nella parte grafica
    if (segreta == attuale) {
        std::cout << "Hai indovinato la parola " << segreta << std::endl;
    }
    else {
        std::cout << "Hai sbagliato, la parola era " << segreta << std::endl;
    }
    return 0;
}

