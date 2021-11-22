#include <iostream>

using namespace std;

int main() {
    int A, N;
    cout << "Inserisci un intero che rappresenta A: " << endl;
    cin >> A;
    cout << "Inserisci su quanti pari vuoi fare la somma e la media: " << endl;
    cin >> N;
    while(N < 1)
    {
        cout << "Valore inserito non valido" << endl;
        cout << "Inserisci su quanti pari vuoi fare la somma e la media: " << endl;
        cin >> N;
    }
    int somma = 0;
    float media;
    if (A %2 == 0)
        A++;
    for (int i = 0; i < N; ++i) {
        somma += A + 2*i;
    }
    media = ((float)somma)/N;
    cout << "Somma: " << somma << endl << "Media: " << media << endl;
    return 0;
}
