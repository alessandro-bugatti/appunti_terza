#include <fstream>
#include <iostream>
#include <ostream>
#include <string>
#include <vector>

#include "include/raylib.h"

struct Carta {
    int pos_x;
    int pos_y;
    int valore;
    int seme;
    Rectangle r;
    Texture2D *carte;
};
void mescola_mazzo(std::vector<Carta>& m) {
    Carta temp;
    int a, b;
    for (int i = 0; i < 10 * m.size(); ++i) {
        a = rand() % m.size();
        b = rand() % m.size();
        temp = m.at(a);
        m.at(a) = m.at(b);
        m.at(b) = temp;
    }
}

Carta pesca_carta(std::vector<Carta>& m) {
    Carta c = m.at(m.size() - 1);
    m.pop_back();
    return c;
}

int conta_punti(const std::vector<Carta>& mano) {
    int somma = 0;
    for (int i = 0; i < mano.size(); ++i) {
        int valore = mano.at(i).valore;
        if (valore <= 10) {
            somma += valore;
        }
        else {
            somma += 10;
        }
    }
    return somma;
}


void disegna_carta(const Carta& c) {
    Rectangle destination;
    destination.x = c.pos_x;
    destination.y = c.pos_y;
    destination.width = c.r.width;
    destination.height = c.r.height;
    DrawTexturePro(*c.carte, c.r, destination,{},0,WHITE);
}



int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 1200;
    const int screenHeight = 800;

    InitWindow(screenWidth, screenHeight, "Gioco di carte");

    Texture2D immagine = LoadTexture("../assets/deck.png");

    Carta c;
    c.pos_x = 0;
    c.pos_y = 0;
    c.seme = 1;
    c.valore = 1;
    c.r.x = 170;
    c.r.y = 15;
    c.r.width = 125;
    c.r.height = 172;
    c.carte = &immagine;
    //Carica le 52 carte del mazzo
    std::vector<Carta> mazzo;

    for (int i = 0; i < 13; ++i) {
        for (int j = 0; j < 4; ++j) {
            Carta d = c;
            d.valore=i+1;
            d.seme=j;
            d.pos_x = c.pos_x + 130 * j+10*i;
            d.pos_y = c.pos_y + 130 * j+10*i;
            d.r.x = 173 + (c.r.width + 14) * i;
            d.r.y = 35+(c.r.height+18)*j;
            mazzo.push_back(d);
        }
    }
    /**
 * Carica le quattro carte speciali di questo mazzo all'interno di un vettore di carte
 * Le carte sono, rispetto agli indici del vettore
 * 0 - dorso colorato
 * 1 - jolly B/N
 * 2 - jolly colorato
 * 3 - dorso B/N
*/
    std::vector<Carta> altre;
    for (int i = 0; i < 4; ++i) {
            Carta d = c;
            d.r.x = 32;
            d.r.y = 35 +  (c.r.height + 18) * i;
            altre.push_back(d);
    }

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------
    mescola_mazzo(mazzo);
    std::vector<Carta>mano;
    Carta temp=pesca_carta(mazzo);
    mano.push_back(temp);
    temp=pesca_carta(mazzo);
    mano.push_back(temp);
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
            int x=GetMouseX();
            int y=GetMouseY();
            if (x>=800 and x<=900 and y>=500 and y<=600) {
                mano.push_back(pesca_carta(mazzo));
            }
        }
        BeginDrawing();

        ClearBackground(DARKGREEN);

        for (int i = 0; i < mano.size(); ++i) {
            mano.at(i).pos_x=100+mano.at(i).r.width*i;
            mano.at(i).pos_y=200;

            disegna_carta(mano.at(i));
        }
        altre.at(0).pos_x=100+altre.at(0).r.width*mano.size();
        altre.at(0).pos_y=200;

        disegna_carta(altre.at(0));
        int punti=conta_punti(mano);
        std::string s;
        std::cout<<punti<<std::endl;
        s="Il tuo punteggio è "+ std::to_string(punti);
        DrawText(s.c_str(),100,500,40,BLACK);
        DrawRectangle(800,500,100,100,YELLOW);


        EndDrawing();

    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context

    return 0;
}

