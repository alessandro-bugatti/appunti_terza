#include "include/raylib.h"

int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "Mouse click reading");

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    int x, y;
    bool visible =  false;
    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        //Verifica se è stato premuto il tasto sinistro del mouse
        //Nel caso rende visibile il cerchio in modo che successivamente
        //venga disegnato alle coordinate del mouse
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
        {
            visible = true;
            x = GetMouseX();
            y = GetMouseY();
        }
        //Se viene premuta la barra dello spazio viene cancellato il cerchio
        if (IsKeyPressed(KEY_SPACE))
        {
            visible = false;
        }

        BeginDrawing();

        ClearBackground(RAYWHITE);

        if (visible)
            DrawCircle(x, y, 30, RED);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}

