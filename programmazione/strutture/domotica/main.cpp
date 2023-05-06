#include <iostream>

struct Lampadina{
    int potenza;
    std::string colore;
    int intensita;
    bool accesa;
    std::string nome;
};

struct Sistema{
    Lampadina lampadine[100];
    int n_lampadine;
};

void menu(){
    std::cout << "1) Aggiungi una nuova lampadina" << std::endl;

    std::cout << "0) Esci" << std::endl;
}

void stampa_sistema(const Sistema &casa){
    std::cout << "Attualmente ci sono " << casa.n_lampadine << " lampadine" << std::endl;
    for (int i = 0; i < casa.n_lampadine; ++i) {
        std::cout << casa.lampadine[i].nome << " " << casa.lampadine[i].intensita << std::endl;
    }
}

void elenco_lampadine(const Sistema &s){
    std::cout << "Elenco lamapadine" << std::endl;
    for (int i = 0; i < s.n_lampadine; ++i) {
        std::cout << s.lampadine[i].nome << std::endl;
    }
}

int cerca_lampadina(const Sistema &s, const std::string &n){
    for (int i = 0; i < s.n_lampadine; ++i) {
        if (s.lampadine[i].nome == n)
            return i;
    }
    return -1;
}

int main() {
    int scelta;
    Sistema casa;
    casa.n_lampadine = 0;
    menu();
    std::cout << "Scegli cosa fare: ";
    std::cin >> scelta;
    while(scelta != 0){
        switch (scelta) {
            case 1:{
                    Lampadina temp;
                    std::cout << "Scegli il nome della lampadina: ";
                    std::cin >> temp.nome;
                    std::cout << "Inserisci la potenza: ";
                    std::cin >> temp.potenza;
                    temp.colore = "bianco";
                    temp.intensita = 100;
                    temp.accesa = false;
                    casa.lampadine[casa.n_lampadine] = temp;
                    casa.n_lampadine++;
                }
                break;
            case 2:
                {
                    std::cout << "Scegli la lampadina di cui vuoi cambiare la potenza" << std::endl;
                    elenco_lampadine(casa);
                    std::string nome;
                    std::cin >> nome;
                    int posizione = cerca_lampadina(casa, nome);
                    //Parte di gestione dell'intensità, da fare
                }
                break;
            default:
                std::cout << "Scelta non corretta" << std::endl;
        }
        stampa_sistema(casa);
        menu();
        std::cout << "Scegli cosa fare: ";
        std::cin >> scelta;
    }

    return 0;
}
