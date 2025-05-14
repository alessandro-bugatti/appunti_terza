#include <iostream>
#include <vector>

struct Calciatore {
    std::string nome;
    std::string cognome;
    std::string ruolo;
    int goal_segnati;
    int numero_maglia;
};

struct Squadra {
    std::string nome;
    std::vector<Calciatore> calciatori;
};

void stampa_calciatore(const Calciatore& c) {
    std::cout << "Nome: " << c.nome << std::endl;
    std::cout << "Cognome: " << c.cognome << std::endl;
    std::cout << "Ruolo: " << c.ruolo << std::endl;
    std::cout << "Goal segnati: " << c.goal_segnati << std::endl;
    std::cout << "Numero di maglia: " << c.numero_maglia << std::endl;
}

void stampa_squadra(const Squadra& s) {
    std::cout << s.nome << std::endl;
    for (int i = 0; i < s.calciatori.size(); ++i) {
        stampa_calciatore(s.calciatori.at(i));
    }
}

int main() {
    Squadra s = {
        "Juventus",
        {
            {
                "Niccolò",
                "Savona",
                "Terzino",
                2,
                13
            },
            {
                "Andrea",
                "Nitroni",
                "Attaccante",
                32,
                11
            },{
                "Alberto",
                "Pierugi",
                "Portiere",
                0,
                1
            }
        }
    };
    stampa_squadra(s);
    return 0;
}