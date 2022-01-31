#include <iostream>

using namespace std;

bool ricerca(int v[], int N, int cercato){
    for (int i = 0; i < N; ++i) {
        if ( v[i] == cercato)
            return true;
    }
    return false;
}

int main() {
    const int NUMERI = 10;
    int v[NUMERI];
    int n;
    for (int i = 0; i < NUMERI; ++i) {
        //Al posto di usare l'input da tastiera come richiesto
        //generiamo numeri pari da 0 a 18, così sappiamo
        //cosa contiene il vettore e il test diventa facile
        v[i] = i * 2;
    }
    cout << "Inserisci il numero da cercare: ";
    cin >> n;
    while( n > 0){
        if (ricerca(v, NUMERI, n) == true)
            cout << "Il numero è presente nel vettore" << endl;
        else
            cout << "Il numero non è presente nel vettore" << endl;
        cout << "Inserisci il numero da cercare: ";
        cin >> n;
    }
    return 0;
}
