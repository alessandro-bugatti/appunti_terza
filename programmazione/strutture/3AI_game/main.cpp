#include <iostream>
#include <ctime>
#include <vector>
#include <fstream>
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

/*
    In questo caso il const non può essere utilizzato
    perchè lo scopo della funzione è proprio quello
    di modificare il parametro passato come riferimento
*/
void muovi_studente(Studente &s)
{
    s.x += s.dx;
    s.y += s.dy;
    //Controllo di uscita dalla parete di destra
    if (s.x + s.raggio >= get_window_width())
    {
        s.dx = -s.dx;
        s.dy = rand()%3 - 1;
    }
    //Controllo di uscita dalla parete di sinistra
    if (s.x - s.raggio <= 0)
    {
        s.dx = -s.dx;
        s.dy = rand()%3 - 1;
    }
    //Controllo di uscita dalla parete inferiore
    if (s.y + s.raggio >= get_window_height())
    {
        s.dy = -s.dy;
        s.dx = rand()%3 - 1;
    }
    //Controllo di uscita dalla parete superiore
    if (s.y - s.raggio <= 0)
    {
        s.dy = -s.dy;
        s.dx = rand()%3 - 1;
    }


}

/*
    Quando la parola chiave const viene usata per un parametro
    passato come riferimento il compilatore viene "istruito" a
    verificare che il parametro passato per riferimento non venga
    modifica accidentalmente nel codice della funzione
*/
void disegna_studente(const Studente &s)
{
    draw_image("./images/" + s.immagine,
               s.x - s.raggio,
               s.y - s.raggio,
               s.raggio*2,
               s.raggio*2,
               255);
    int x_testo = s.x - s.raggio;
    int y_testo = s.y + s.raggio;
    draw_text("PTMono.ttf",12,s.nome,x_testo, y_testo,Color(0,0,0,255));
}

int main(int argc, char* argv[]) {

    srand(time(NULL));
    init();
    //create the window and show it
    set_window(1024,700,"3AI game, the best in the town");
    //main loop

    ifstream in("studenti.txt");
    if (!in)
    {
        cout << "Impossibile aprire il file delle immagini" << endl;
        close();
        return -1;
    }
    cout << "Inizio" << endl;
    Studente studenti[30];
    int n_studenti = 0;
    string nome, immagine;
    while(in >> nome >> immagine)
    {
        cout << nome << endl;
        Studente temp;
        temp.nome = nome;
        temp.immagine = immagine;
        temp.x = rand()%get_window_width();
        temp.y = rand()%get_window_height();
        temp.raggio = 20;
        temp.dx = rand()%3 - 1;
        temp.dy = rand()%3 - 1;
        studenti[n_studenti] = temp;
        n_studenti++;

    }
    in.close();
    /*
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


    studenti[0] = langellotti;
    studenti[1] = betella;
    studenti[2] = loda;
    studenti[3] = arrivetti;
    */

    /*for (int i = 0; i < n_studenti; i++)
    {
        studenti[i].dx = rand()%40 - 20;
        studenti[i].dy = rand()%40 - 20;
    }*/
    //studenti[0].dx = 10;
    //studenti[0].dy = -1;
    //init the library

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
