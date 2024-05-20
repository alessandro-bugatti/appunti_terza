

/*******************************************************************************************
*
*   raylib [core] example - Basic window
*
*   Welcome to raylib!
*
*   To test examples, just press F6 and execute raylib_compile_execute script
*   Note that compiled executable is placed in the same folder as .c file
*
*   You can find all basic examples on C:\raylib\raylib\examples folder or
*   raylib official webpage: www.raylib.com
*
*   Enjoy using raylib. :)
*
*   This example has been created using raylib 1.0 (www.raylib.com)
*   raylib is licensed under an unmodified zlib/libpng license (View raylib.h for details)
*
*   Copyright (c) 2013-2016 Ramon Santamaria (@raysan5)
*
********************************************************************************************/

#include <sstream>
#include <vector>

#include "include/raylib.h"

#ifdef WIN32
#include "include/raylib_compatibility.h"
#endif

#include "src/UDP_Communicator.h"

std::vector<std::string> split(const std::string& s, char delimiter = ' ')
{
    std::stringstream in(s);
    std::string temp;
    std::vector<std::string> v;
    while(getline(in, temp, delimiter))
        v.push_back(temp);
    return v;
}

int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 450;
    int x = screenWidth/2, y = screenHeight/2,
        xa = screenWidth/2, ya = screenHeight/2;
    int status = 0;
    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------
    simple::UDP_Communicator client;
    std::string message;
    std::string ip;
    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        if (status == 0) { //inserimento indirizzo
            //Legge il tasto premuto e lo mette in c, se è un simbolo dell'ASCII,
            //altrimenti inserisce 0, valore che può essere usato per sapere se concatenare o meno
            char c = GetCharPressed();
            if (c > 0)
                ip += c;
            //Parte per la gestione del backspace, che non è gestito automaticamente
            if (IsKeyPressed(KEY_BACKSPACE))
                if (!ip.empty())
                    ip.pop_back();
            //Per eventualmente fare qualcosa premendo il tasto invio
            if (IsKeyPressed(KEY_ENTER)) {
                //Si fa quello che si vuol fare con la stringa inserita
                status = 1;
                client.setParameters(ip.c_str());
            }
        }

        if (status == 1) {
            if (IsKeyDown(KEY_UP)) {
                y -= 1;
                client.send(std::to_string(x) + " " + std::to_string(y));
            }
            if (IsKeyDown(KEY_DOWN)) {
                y += 1;
                client.send(std::to_string(x) + " " + std::to_string(y));
            }
            if (IsKeyDown(KEY_LEFT)) {
                x -= 1;
                client.send(std::to_string(x) + " " + std::to_string(y));
            }
            if (IsKeyDown(KEY_RIGHT)) {
                x += 1;
                client.send(std::to_string(x) + " " + std::to_string(y));
            }
            if (client.incomingMessage()) {
                message = client.getMessage();
                std::vector<std::string> tokens = split(message);
                xa = stoi(tokens.at(0));
                ya = stoi(tokens.at(1));
            }
        }
        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(RAYWHITE);

        if (status == 0) {
            std::string shown = "Inserisci l'indirizzo IP dell'avversario: " + ip;
            DrawText(shown.c_str(),10, screenHeight/2,20,BLACK);
        }
        if (status == 1){
            DrawRectangle(x, y, 10, 10, RED);
            DrawRectangle(xa, ya, 10, 10, BLUE);
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

