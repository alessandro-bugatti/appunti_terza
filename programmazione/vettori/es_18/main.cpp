#include <iostream>

using namespace std;

void inverti(int v[], int n){
    for (int i = 0; i < n/2; ++i) {
        int temp;
        temp = v[i];
        v[i] = v[n - i - 1];
        v[n - i - 1] = temp;
    }
}

void stampa(int v[], int n)
{
    for (int i = 0; i < n; ++i) {
        cout << v[i] << " ";
    }
    cout << endl;
}

int main() {
    const int NUMERI = 100;
    int vet[NUMERI];
    int n;
    cout << "Inserisci la dimensione del vettore (massimo 100): ";
    cin >> n;
    for (int i = 0; i < n; ++i) {
        //Al posto di usare l'input da tastiera come richiesto
        //generiamo i primi n numeri, così possiamo testare il
        //programma facilmente
        vet[i] = i;
    }
    stampa(vet, n);
    inverti(vet, n);
    stampa(vet, n);
    return 0;
}
