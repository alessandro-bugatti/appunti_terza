#include "include/raylib.h"
#include <iostream>

#define MAX_PARTICLES 200

#define MAX_FIREWORKS 15
// Particle structure with basic data
typedef struct {
    Vector2 position;
    Color color;
    float alpha;
    float size;
    float rotation;
    bool active;        // NOTE: Use it to activate/deactive particle
    float vx;
    float vy;
    float x;
    float y;
} Particle;

typedef struct{
    Particle fireTail[MAX_PARTICLES] = { 0 };
    float vx;
    float x;
    float vy;
    int delay;
    int n_disactived;
}Firework;

void initialize_firework(Firework &f){
    // Initialize particles
    for (int i = 0; i < MAX_PARTICLES; i++)
    {
        f.fireTail[i].position = (Vector2){500, 500 };
        f.fireTail[i].color = (Color){static_cast<unsigned char>(GetRandomValue(0, 255)), static_cast<unsigned char>(GetRandomValue(0, 255)), static_cast<unsigned char>(GetRandomValue(0, 255)), 255 };
        f.fireTail[i].alpha = 1.0f;
        f.fireTail[i].size = 0.1f;
        f.fireTail[i].rotation = (float)GetRandomValue(0, 360);
        f.fireTail[i].active = false;
        f.fireTail[i].vx = f.vx;
        f.fireTail[i].vy = f.vy;
        f.fireTail[i].x = f.x;
        f.fireTail[i].y = 0.2;
    }
}

int activate_particles(Firework &f){
    f.delay--;
    if (f.delay > 0){
            return 0;
    }
    if (f.delay == 0){
        return 1;
    }
    for (int i = 0; i < MAX_PARTICLES; i++)
    {
        if (!f.fireTail[i].active)
        {
            f.fireTail[i].active = true;
            f.fireTail[i].alpha = 1.0f;
            f.fireTail[i].position.x = f.fireTail[i].x * GetScreenWidth();
            f.fireTail[i].position.y = (1 - f.fireTail[i].y) * GetScreenHeight();
            i = MAX_PARTICLES;
        }
    }
    return 0;
}

void update_particles(Firework &f){
    for (int i = 0; i < MAX_PARTICLES; i++)
    {
        if (f.fireTail[i].active)
        {
            if (f.fireTail[i].vy >= 0.0f) {
                f.fireTail[i].x += f.fireTail[i].vx;
                f.fireTail[i].vy -= 0.00004;
                f.fireTail[i].y += f.fireTail[i].vy;
                f.fireTail[i].position.x = f.fireTail[i].x * GetScreenWidth();
                f.fireTail[i].position.y = (1 - f.fireTail[i].y) * GetScreenHeight();
                f.fireTail[i].alpha -= 0.005f;
                f.fireTail[i].size += 0.005f;
            }
            else{
                f.fireTail[i].active = false;
                f.n_disactived++;
            }
            f.fireTail[i].rotation += 2.0f;
        }
    }

    if (f.n_disactived >= MAX_PARTICLES){
        f.x = GetRandomValue(200,800) / 1000.0f;
        f.vx = GetRandomValue(-100,100) / 50000.0f;
        f.vy = GetRandomValue(500,900) / 100000.0f;
        f.delay = GetRandomValue(0,1000);
        f.n_disactived = 0;
        initialize_firework(f);
    }

}

void draw_particles(const Firework &f, Texture2D &smoke){
    for (int i = 0; i < MAX_PARTICLES; i++)
    {
        if (f.fireTail[i].active) DrawTexturePro(smoke, (Rectangle){0.0f, 0.0f, (float)smoke.width, (float)smoke.height },
                                               (Rectangle){f.fireTail[i].position.x, f.fireTail[i].position.y, smoke.width * f.fireTail[i].size, smoke.height * f.fireTail[i].size },
                                               (Vector2){(float)(smoke.width * f.fireTail[i].size / 2.0f), (float)(smoke.height * f.fireTail[i].size / 2.0f) }, f.fireTail[i].rotation,
                                               Fade(f.fireTail[i].color, f.fireTail[i].alpha));
    }
}

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 1280;
    const int screenHeight = 945;

    InitWindow(screenWidth, screenHeight, "Happy Holidays");
    InitAudioDevice();
    // Particles pool, reuse them!
    Firework fireworks[MAX_FIREWORKS];

    for (int i = 0; i < MAX_FIREWORKS; ++i) {
        fireworks[i].x = GetRandomValue(200,800) / 1000.0f;
        fireworks[i].vx = GetRandomValue(-100,100) / 50000.0f;
        fireworks[i].vy = GetRandomValue(500,900) / 100000.0f;
        fireworks[i].delay = GetRandomValue(0,1000);
        fireworks[i].n_disactived = 0;
        initialize_firework(fireworks[i]);
    }
    Sound fxWav = LoadSound("../firework.ogg");
    Texture2D smoke = LoadTexture("../spark_flame.png");
    Texture2D texture_sfondo = LoadTexture("../background.png");
    SetSoundVolume(fxWav, 0.2f);
    int blending = BLEND_ADDITIVE;

    SetTargetFPS(60);
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------

        for (int i = 0; i < MAX_FIREWORKS; ++i) {
            int suono = activate_particles(fireworks[i]);
            if (suono == 1)
                PlaySoundMulti(fxWav);
        }

        for (int i = 0; i < MAX_FIREWORKS; ++i) {
            update_particles(fireworks[i]);
        }

        //std::cout << fireworks[0].n_disactived << std::endl;

        if (IsKeyPressed(KEY_SPACE))
        {
            if (blending == BLEND_ALPHA) blending = BLEND_ADDITIVE;
            else blending = BLEND_ALPHA;
        }
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();
        //ClearBackground(DARKGRAY);
        DrawTexture(texture_sfondo, 0, 0, WHITE);

        BeginBlendMode(blending);

        // Draw active particles
        for (int i = 0; i < MAX_FIREWORKS; ++i) {
            draw_particles(fireworks[i], smoke);
        }

        EndBlendMode();

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    UnloadTexture(smoke);
    UnloadTexture(texture_sfondo);

    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}