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
};

//https://forms.gle/MhXRS7fCjqu6acZU8

void disegna_studente(const Studente &s)
{
    draw_image("./images/" + s.immagine,s.x,s.y,s.raggio*2,s.raggio*2,255);
    int x_testo = s.x;
    int y_testo = s.y + s.raggio*2;
    draw_text("amatic.ttf",20,s.nome,x_testo, y_testo,Color(0,0,0,255));
}

int main(int argc, char* argv[]) {

    Studente langellotti = {
        30,
        30,
        "Langellotti.jpg",
        "Langellotti",
        40
    }, betella = {
        130,
        130,
        "Betella.jpeg",
        "Betella",
        40

    };
    //init the library
    init();
    //create the window and show it
    set_window(512,512,"3AI game, the best in the town");
    //main loop

    while(!done())
    {
        disegna_studente(langellotti);
        disegna_studente(betella);
        update();
    }

    //close the library and clean up everything
    close();
    return 0;
}
