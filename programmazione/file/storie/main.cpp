#include <iostream>
#include <fstream>
#include <vector>

struct Scelta {
    std::string testo;
    int sezione_successiva;
};

struct Sezione {
    std::string scena;
    Scelta scelte[3];
};

void stampa_sezione(const Sezione& s) {
    std::cout << s.scena << std::endl;
    if (s.scelte[0].sezione_successiva != -1) {
        for (int i = 0; i < 3; ++i) {
            std::cout << (i + 1) << ") " << s.scelte[i].testo <<  std::endl;
        }
    }
}

int main() {
    std::ifstream in("../assets/storia.txt");

    if (!in) {
        std::cout << "Apertura fallita" << std::endl;
        return 1;
    }
    std::vector<Sezione> sezioni;
    std::string temp;

    //PArte di caricamento della storia
    while (std::getline(in, temp)) {
        Sezione s;
        s.scena = temp;
        //Leggo le scelte
        for (int i = 0; i < 3; ++i) {
            std::getline(in, temp);
            s.scelte[i].testo = temp;
            std::getline(in, temp);
            s.scelte[i].sezione_successiva = std::stoi(temp);
        }
        sezioni.push_back(s);
    }
    in.close();
    //test
    //stampa_sezione(sezioni.at(0));

    std::cout << "GIOCO DEI LIBRI GAME" << std::endl;

    Sezione corrente = sezioni.at(0);

    while (corrente.scelte[0].sezione_successiva != -1) {
        stampa_sezione(corrente);
        int scelta;
        std::cout << "Fai la tua scelta: ";
        std::cin >> scelta;
        int nuova_sezione = corrente.scelte[scelta - 1].sezione_successiva;
        corrente = sezioni.at(nuova_sezione);
    }
    stampa_sezione(corrente);
    std::cout << "END GAME"  << std::endl;

    return 0;
}
