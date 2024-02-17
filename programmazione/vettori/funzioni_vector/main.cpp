#include <iostream>
#include <vector>

/*
 * Esercizio 11 a pag.13 della dispensa
 */

void elimina_in_posizione(std::vector<int> &v, int pos){
    if (pos < 0 || pos >= v.size()){
        return;
    }
    //Il metodo erase vuole un iteratore, cioè una specie di
    //posizione che viene ottenuta per "spiazzamento" rispetto
    //all'inizio del vettore, che è v.begin()
    v.erase(v.begin() + pos);
}

void stampa_vettore(const std::vector<int> &v){
    for (int i = 0; i < v.size(); ++i) {
        std::cout << v.at(i) << " ";
    }

    std::cout << std::endl;
}

int main() {
    std::vector<int> v;
    for (int i = 0; i < 20; ++i) {
        v.push_back(rand()%101);
    }
    stampa_vettore(v);
    elimina_in_posizione(v, 3);
    stampa_vettore(v);
    return 0;
}
