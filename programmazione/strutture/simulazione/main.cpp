#include <iostream>
#include <fstream>

//Esercizio 5 della simulazione
int main_originale() {
    std::ifstream in("input.txt");
    std::ofstream out ("totale.txt");
    if (!in || !out) {
        std::cout << "Errore nell'apertura dei file";
        return 1;
    }
    float totale = 0;
    int qta, sconto;
    float prezzo;
    while (in >> qta >> prezzo >> sconto) {
        totale += (qta * prezzo) * (100 - sconto) / 100.0;
    }
    out << totale << std::endl;
    in.close();
    out.close();
    return 0;
}

//Esercizio 5 della simulazione con la variante virgola
int main() {
    std::ifstream in("input.txt");
    std::ofstream out ("totale.txt");
    if (!in || !out) {
        std::cout << "Errore nell'apertura dei file";
        return 1;
    }
    float totale = 0;
    int qta, sconto;
    std::string prezzo;
    while (in >> qta >> prezzo >> sconto) {
        std::cout << prezzo << std::endl;
        for (int i = 0; i < prezzo.size(); ++i) {
            if (prezzo.at(i) == ',') {
                prezzo.at(i) = '.';
            }
        }
        std::cout << prezzo << std::endl;
        float pf = stof(prezzo);
        totale += (qta * pf) * (100 - sconto) / 100.0;
    }
    out << totale << std::endl;
    in.close();
    out.close();
    return 0;
}