#include <string>

#include "include/raylib.h"

int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 450;

    std::string s;
    std::string inserita;
    bool mostra = false;
    InitWindow(screenWidth, screenHeight, "Lettura stringhe");

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        //Legge il tasto premuto e lo mette in c, se è un simbolo dell'ASCII,
        //altrimenti inserisce 0, valore che può essere usato per sapere se concatenare o meno
        char c = GetCharPressed();
        if (c > 0)
            s += c;
        //Parte per la gestione del backspace, che non è gestito automaticamente
        if (IsKeyPressed(KEY_BACKSPACE))
            if (!s.empty())
                s.pop_back();
        //Per eventualmente fare qualcosa premendo il tasto invio
        if (IsKeyPressed(KEY_ENTER)) {
            //SI fa quello che si vuol fare con la stringa inserita
            mostra = true;
            inserita = s;
            s = "";
        }


        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawFPS(0,0);

        std::string messaggio = "Inserisci una stringa: " + s;
        DrawText(messaggio.c_str(), 190, 200, 32, BLACK);
        if (mostra) {
            messaggio = "La stringa inserita è: " + inserita;
            DrawText(messaggio.c_str(), 190, 300, 32, BLACK);
        }
        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}

