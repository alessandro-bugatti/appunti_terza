#include <iostream>
#include <fstream>

struct Giocatore{
    std::string nome;
    std::string cognome;
    float altezza;
    std::string ruolo;
};

struct Squadra{
    Giocatore giocatori[40];
    int n_giocatori;
    std::string nome;
};

float altezza_media(const Squadra& s){
    float somma = 0;
    for (int i = 0; i < s.n_giocatori; ++i) {
        somma += s.giocatori[i].altezza;
    }
    return somma / s.n_giocatori;
}

int main() {
    Squadra squadra;
    squadra.nome = "Los Angeles Lakers";
    squadra.n_giocatori = 0;
    //Lettura file
    std::ifstream in("../giocatori.txt");
    if (!in){
        std::cout << "Apertura fallita" << std::endl;
        return 1;
    }
    std::string riga;
    while(std::getline(in, riga)){
        int inizio, fine;
        std::string temp;
        //Leggo il cognome
        inizio = 0;
        fine = riga.find(';', inizio);
        temp = riga.substr(inizio, fine - inizio);
        squadra.giocatori[squadra.n_giocatori].cognome = temp;
        //Leggo il nome

        //Leggo l'altezza
        inizio = fine + 1;
        fine = riga.find(';', inizio);
        temp = riga.substr(inizio, fine - inizio);
        squadra.giocatori[squadra.n_giocatori].altezza = std::stof(temp);

        squadra.n_giocatori++;
    }

    return 0;
}
