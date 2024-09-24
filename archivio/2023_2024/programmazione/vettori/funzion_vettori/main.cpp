#include <iostream>

/*
 * Esercizio 11 pag.13 della dispensa
 */

/**
 * Elimina l'elemento in posizione pos
 * @param v il vettore
 * @param n il numero di elementi contenuti nel vettore
 * @param pos la posizione da cui eliminare l'elemento
 * @return il numero di elementi validi contenuti nel vettore
 */

int elimina_in_posizione(int v[], int n, int pos){
    if (pos < 0 || pos >= n){
        return n;
    }
    for (int i = pos; i < n - 1 ; ++i) {
        v[i] = v[i+1];
    }
    return n - 1;
}

void stampa_vettore(int v[], int n){
    for (int i = 0; i < n; ++i) {
        std::cout << v[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    const int MAX = 20;
    int v[MAX];
    int n_elementi = MAX;
    for (int i = 0; i < MAX; ++i) {
        v[i] = rand()%101;
    }
    stampa_vettore(v, n_elementi);
    n_elementi = elimina_in_posizione(v, n_elementi, 3);
    stampa_vettore(v, n_elementi);
    return 0;
}
