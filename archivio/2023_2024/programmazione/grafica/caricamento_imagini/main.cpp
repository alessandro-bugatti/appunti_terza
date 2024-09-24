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
    int x=0,y=0;
    InitWindow(screenWidth, screenHeight, "Lettura tasti");

    Texture2D image;
    image = LoadTexture("../assets/immagine.png");


    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        if (IsKeyDown(KEY_LEFT)){
            x--;
        }
        if (IsKeyDown(KEY_RIGHT)){
            x++;
        }
        BeginDrawing();

        ClearBackground(RAYWHITE);
        DrawTexture(image,x,y,WHITE);


        EndDrawing();
        //----------------------------------------------------------------------------------
    }


    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}

