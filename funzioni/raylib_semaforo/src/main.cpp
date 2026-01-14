

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

#include <chrono>
#include <iostream>

#include "raylib.h"
#include <string>

#include "raymath.h"

bool verifica_in_zona(int mx, int my, int x, int y, int w, int h) {
    if ((mx >= x && mx <= x + w) && (my >= y && my <= y + h)) {
        return true;
    }
    return false;
}

void disegna_luce(int x, int y, int r, Color mio_colore, bool acceso) {
    if (acceso == true) {
        DrawCircle(x, y, r, mio_colore);
    }else {
        DrawCircle(x, y, r, BLACK);
    }
}

/**
 *
 * @param x
 * @param y
 * @param dim
 * @param stato 1 - verde, 2 - giallo, 3 - rosso
 */
void disegna_semaforo(int x, int y, int dim, int stato) {
    int r = (dim - 60) / 3;
    if (stato == 1) {
        disegna_luce(x + r, y + r, r, RED, false);
        disegna_luce(x + r, y + 3*r, r, YELLOW, false);
        disegna_luce(x + r, y + 5*r, r, GREEN, true);
    }else if (stato == 2) {
        disegna_luce(x + r, y + r, r, RED, false);
        disegna_luce(x + r, y + 3*r, r, YELLOW, true);
        disegna_luce(x + r, y + 5*r, r, GREEN, false);
    }else if (stato == 3) {
        disegna_luce(x + r, y + r, r, RED, true);
        disegna_luce(x + r, y + 3*r, r, YELLOW, false);
        disegna_luce(x + r, y + 5*r, r, GREEN, false);
    }
}

void cambia_stato(int &stato) {
    stato++;
    if (stato == 4) {
        stato = 1;
    }
}

int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 768;
    const int screenHeight = 768;
    int contatore = 0;
    int stato = 1;
    std::string s = "Semaforo";

    InitWindow(screenWidth, screenHeight, s.c_str());

    //Coordinate del bottone
    int x = 150, y = 500, w = 300, h = 100;

    //coordinate del mouse
    int mx, my;
    //std::cout << "INserisci il raggio del cerchio: ";
    //std::cin >> raggio;

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        mx = GetMouseX();
        my = GetMouseY();

        // if (verifica_in_zona(mx, my, x, y, w, h)) {
        //     contatore++;
        //     std::cout << contatore << std::endl;
        // }
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
            //std::cout << mx << " " << my << std::endl;
            if (verifica_in_zona(mx, my, x, y, w, h)) {
                cambia_stato(stato);
                std::cout << "Bottone premuto" << std::endl;
            }
        }
        //----------------------------------------------------------------------------------
        //----------------------------------------------------------------------------------
        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(RAYWHITE);
        disegna_semaforo(300, 50, 240, stato);
        DrawRectangle(x, y, w, h, GRAY);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}

