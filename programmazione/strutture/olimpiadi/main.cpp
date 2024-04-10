#include <iostream>
#include <vector>

struct Problema{
    std::string titolo;
    int valore;
    int punteggio;
};

struct Partecipante{
    std::string nome;
    std::string cognome;
    std::string sede_territoriale;
    std::vector <Problema> problemi;
};

void inizializza(std::vector <Problema> &problemi) {
    int quanti;
    std::cout << "Quanti problemi?" << std::endl;
    std::cin >> quanti;
    for (int i = 0; i < quanti; ++i) {
        Problema p;
        std::cout << "Inserisci il titolo" << std::endl;
        std::cin >> p.titolo;
        std::cout << "Inserisci il valore del problema" << std::endl;
        std::cin >> p.valore;
        p.punteggio = 0;
        problemi.push_back(p);
    }
}

void stampa_problema(const Problema &p) {
    std::cout << "titolo: " << p.titolo << " - punteggio: " << p.punteggio
    << " / " << p.valore << std::endl;
}

void stampa_problemi(const std::vector <Problema> &problemi) {
    for (int i = 0; i < problemi.size(); ++i) {
        stampa_problema(problemi.at(i));
    }
}

void inserisci_partecipante(std::vector <Partecipante> &partecipanti,
                            const std::vector <Problema> &gara) {
    Partecipante p;
    std::cout << "Nome?" << std::endl;
    std::cin >> p.nome;
    std::cout << "Cognome?" << std::endl;
    std::cin >> p.cognome;
    std::cout << "Sede?" << std::endl;
    std::cin >> p.sede_territoriale;
    p.problemi = gara;
}

int main(){
    std::vector <Problema> gara;
    std::vector <Partecipante> partecipanti;
    // inizializza(gara);
    gara = {
            {
                "caramelle",
                100,
                0
            },
            {
                "parcogiochi",
                100,
                0
            }
    };
    stampa_problemi(gara);
    inserisci_partecipante(partecipanti, gara);

    return 0;
}