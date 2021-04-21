#include <iostream>
#include <ctime>
#include <vector>
#include "../../vsgl2.h"

using namespace std;
using namespace vsgl2;
using namespace vsgl2::general;
using namespace vsgl2::video;
using namespace vsgl2::utils;
using namespace vsgl2::io;
using namespace vsgl2::ttf_fonts;

struct Studente{
    int x;
    int y;
    string immagine;
    string nome;
    int raggio;
    int dx;
    int dy;
};

//https://forms.gle/MhXRS7fCjqu6acZU8

void muovi_studente(Studente &s)
{
    s.x += s.dx;
    s.y += s.dy;
    if (s.x >= get_window_width())
    {
        s.dx = -s.dx;
        s.dy = rand()%3 - 1;
    }

}

void disegna_studente(const Studente &s)
{
    draw_image("./images/" + s.immagine,s.x,s.y,s.raggio*2,s.raggio*2,255);
    int x_testo = s.x;
    int y_testo = s.y + s.raggio*2;
    draw_text("PTMono.ttf",12,s.nome,x_testo, y_testo,Color(0,0,0,255));
}

int main(int argc, char* argv[]) {

    srand(time(NULL));
    Studente langellotti = {
        30,
        30,
        "Langellotti.jpg",
        "Langellotti",
        20,
        1,
        1
    }, betella = {
        130,
        130,
        "Betella.jpeg",
        "Betella",
        20,
        0,
        1

    }, loda = {
        230,
        230,
        "loda.png",
        "Loda",
        20,
        1,
        -1
    }, arrivetti = {
        330,
        330,
        "arrivetti.jfif",
        "Arrivetti",
        20,
        -1,
        -1
    };

    Studente studenti[30];
    studenti[0] = langellotti;
    studenti[1] = betella;
    studenti[2] = loda;
    studenti[3] = arrivetti;
    int n_studenti = 4;

    for (int i = 0; i < n_studenti; i++)
    {
        studenti[i].dx = rand()%3 - 1;
        studenti[i].dy = rand()%3 - 1;
    }
    studenti[0].dx = 10;
    //studenti[0].dy = -1;
    //init the library
    init();
    //create the window and show it
    set_window(1024,700,"3AI game, the best in the town");
    //main loop

    while(!done())
    {
        for (int i = 0; i < n_studenti; i++)
        {
            muovi_studente(studenti[i]);
            disegna_studente(studenti[i]);
        }
        delay(100);
        update();
    }

    //close the library and clean up everything
    close();
    return 0;
}
