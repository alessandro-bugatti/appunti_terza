#include <iostream>

using namespace std;

int main() {
    int N ;
    cout << "Inserisci il lato del rombo: ";
    cin >> N;
    int lunghezza_riga = 1;
    int lunghezza_spazi = N - 1;
    //Input dell'utente
    for (int j = 0; j < N; j++) {
        //Disegna una linea di spazi
        for (int i = 0; i < lunghezza_spazi; ++i) {
            cout << " ";
        }
        //Disegna una linea di asterischi
        for (int i = 0; i < lunghezza_riga; ++i) {
            cout << "*";
        }
        lunghezza_riga+=2;
        lunghezza_spazi--;
        cout << endl;
    }
    lunghezza_spazi = 1;
    lunghezza_riga -= 4; //Perchè la riga centrale è una sola, quindi -2
    // e devo elimnare l'ultimo incremento, quindi un altro -2
    //Parte che disegna la parte sotto del rombo
    for (int j = 0; j < N - 1; j++) {
        //Disegna una linea di spazi
        for (int i = 0; i < lunghezza_spazi; ++i) {
            cout << " ";
        }
        //Disegna una linea di asterischi
        for (int i = 0; i < lunghezza_riga; ++i) {
            cout << "*";
        }
        lunghezza_riga-=2;
        lunghezza_spazi++;
        cout << endl;
    }
    return 0;
}
