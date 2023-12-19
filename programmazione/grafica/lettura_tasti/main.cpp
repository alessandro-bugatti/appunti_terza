#include "include/raylib.h"

void aggiorna_posizione(float &x, float &y, float vx, float vy, float t) {
    x += vx;
    y = vy * t - 0.5 * 9.81 * t * t;
}

int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 800;

    float x = screenWidth / 2;
    float vx = 2.0;
    float y = screenHeight / 2;
    float vy = 2.0;

    InitWindow(screenWidth, screenHeight, "Lettura tasti");

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        /*
         * Questa funzione intercetta l'evento "è stato premuto un tasto" e serve
         * se interessa verifica una pressione singola, non la pressione continua
         *
        if(IsKeyPressed(KEY_D)) {
            x += vx;
        }
        */

        /*
         * Questa funzione invece verifica se un tasto è attualmente premuto
         */
        if(IsKeyDown(KEY_D)) {
            x += vx;
        }
        if(IsKeyDown(KEY_A)) {
            x -= vx;
        }
        if(IsKeyDown(KEY_S)) {
            y += vy;
        }
        if(IsKeyDown(KEY_W)) {
            y -= vy;
        }

        BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawCircle(x, y, 10, RED);
        DrawText("Premi i tasti WASD per muovere il cerchio rosso.", 170, 10, 20, GRAY);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }


    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}

