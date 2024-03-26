#include <string>
#include "include/raylib.h"

/**
 * Esempio di utilizzo del mouse, lettura delle coordinate
 * e della pressione dei tasti
 */
int main(void)
{
    const int screenWidth = 800;
    const int screenHeight = 450;

    const int lato_quadrato = 40;

    const int mouse_area_height  = screenHeight * 2 / 3;

    int mouse_x, mouse_y;
    std::string coordinate;
    int contatore_left_click = 0, contatore_right_click = 0;
    std::string messaggio_tasto_sinistro, messaggio_tasto_destro;

    InitWindow(screenWidth, screenHeight, "Utilizzo del mouse");

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        //Legge il valore della x della posizione del mouse
        mouse_x = GetMouseX();
        //Verifica se il valore della y si trova nell'area del mouse
        //in modo da non far scendere il disegno delle coordinate
        //al di sotto di mouse_area_height, poichè quell'area è dedicata
        //ad altre informazioni
        if (GetMouseY() < mouse_area_height)
            mouse_y = GetMouseY();
        //I valori delle coordinate del mouse vengono concattenati in una stringa per
        //poterli poi mostrare a video
        coordinate = std::to_string(mouse_x) + " " + std::to_string(mouse_y);
        //Controlla se il tasto sinistro è stato premuto, è vera al
        //primo click e non tornerà ad essere vera fino al prossimo rilascio
        //e successivo click del tasto
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
            contatore_left_click++;
        //Stessa cosa per il tasto destro
        if (IsMouseButtonPressed(MOUSE_BUTTON_RIGHT))
            contatore_right_click++;
        //Aggiorna i messaggi da mostrare a video
        messaggio_tasto_sinistro = "Click sul tasto sinistro: " + std::to_string(contatore_left_click);
        messaggio_tasto_destro = "Click sul tasto destro: " + std::to_string(contatore_right_click);

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawRectangle(mouse_x - 5, mouse_y - 5, 5, 5, RED);
        DrawText(coordinate.c_str(),mouse_x - 40, mouse_y - 25, 20, BLACK);
        //Funzione che controlla se il tasto sinistro del mouse è attualmente premuto
        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
            DrawRectangle(10, mouse_area_height + 30, lato_quadrato, lato_quadrato, BLUE);
        //Funzione che controlla se il tasto destro del mouse è attualmente premuto
        if (IsMouseButtonDown(MOUSE_BUTTON_RIGHT))
            DrawRectangle(screenWidth - 10 - lato_quadrato, mouse_area_height + 30, lato_quadrato, lato_quadrato, RED);
        //Disegno del numero di click dei bottoni del mouse
        DrawText(messaggio_tasto_sinistro.c_str(), 20 + lato_quadrato, mouse_area_height + 30, 20,BLUE);
        int dimensione_stringa = MeasureText(messaggio_tasto_destro.c_str(), 20);
        DrawText(messaggio_tasto_destro.c_str(),
            screenWidth - 20 - lato_quadrato - dimensione_stringa, mouse_area_height + 30, 20, RED);
        EndDrawing();
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}

