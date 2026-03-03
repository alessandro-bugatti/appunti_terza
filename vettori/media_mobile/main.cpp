#include <iostream>
#include <shared_mutex>
#include <vector>

//[10, 3, 4, ....
void stampa(const std::vector<float> &v) {
    std::cout << '[' << v.at(0);
    for (int i = 1; i < v.size(); ++i) {
        std::cout << ", " << v.at(i);
    }
    std::cout << ']' << std::endl;
}

/**
 * Calcola la media su un sottointervallo del vettore v
 * @param v il vettore
 * @param begin l'elemento da cui partire
 * @param end l'elemento in cui finire, escluso
 * @return la media sull'intervallo [begin, end)
 */
float media(const std::vector<float> &v, int begin, int end) {
    float m = 0;
    for (int i = begin; i < end; ++i) {
        m += v.at(i);
    }
    return m / (end - begin);
}

int main() {
    std::vector<float> valori = {10, 3, 4, 7, 8, 112, 3, 5, 12, 10};
    stampa(valori);
    //test per un caso singolo
    std::cout << "Test: " << media(valori, 2, 6) << std::endl;
    //Calcolo della media mobile sul vettore valori
    int k = 2;
    std::vector<float> valori_mediati;
    for (int i = 0; i < valori.size(); ++i) {
        int begin = i - k;
        if (begin < 0) {
            begin = 0;
        }
        int end = i + k + 1;
        if (end > valori.size()) {
            end = valori.size();
        }
        valori_mediati.push_back(media(valori, begin, end));
    }
    stampa(valori_mediati);

    return 0;
}
