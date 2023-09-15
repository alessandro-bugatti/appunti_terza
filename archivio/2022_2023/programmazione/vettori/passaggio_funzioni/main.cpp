#include <iostream>
/**
 *
 * @param v il vettore, tra le parentesi non va niente
 * @param n numero degli elementi del vettore
 * @param cercato in numero da cercare nel vettore
 * @return vero se cercato è presente, false altrimenti
 */
bool trovato(int v[], int n, int cercato){
    for (int i = 0; i < n; ++i) {
        if(v[i] == cercato)
            return true;
    }
    return false;
}

int main() {
    const int N_VALORI = 100;
    int valori[N_VALORI], quanti;
    std::cout << "Quanti valori vuoi inserire?";
    std::cin >> quanti;
    for (int i = 0; i < quanti; ++i) {
        std::cin >> valori[i];
    }
    int da_trovare;
    std::cout << "Dimmi il numero da cercare: ";
    std::cin >> da_trovare;
    if (trovato(valori, quanti, da_trovare)){
        std::cout << "Elemento trovato" << std::endl;
    }
    else
    {
        std::cout << "Elemento non trovato" << std::endl;
    }

    return 0;
}
