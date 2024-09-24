#include <iostream>

using namespace std;

int main() {
    srand(time(NULL));
    int somma = rand() % 6 + 1 + rand() % 6 + 1;
    int punteggio;
    int scelta;
    cout << "Premi il tasto 1 e invio per iniziare" << endl;
    cin >> scelta;
    cout << "Tentativo n.1 è uscito: " << somma << endl;
    if(somma == 7 || somma == 11 ) {
        cout << "Hai vinto! è uscito: " << somma << endl;
    } else if(somma == 2 || somma == 3 || somma == 12) {
        cout << "Hai perso! è uscito: " << somma << endl;
    } else {
        punteggio = somma;
        somma = rand() % 6 + 1 + rand() % 6 + 1;
        cout << "Premi il tasto 1 e invio per tirare il dado" << endl;
        cin >> scelta;
        int count = 2;
        while(somma != punteggio && somma != 7) {
            cout << "Tentativo n." << count << endl;
            cout << "è uscito: " << somma << endl;
            cout << "Premi il tasto 1 e invio per tirare il dado" << endl;
            cin >> scelta;
            somma = rand() % 6 + 1 + rand() % 6 + 1;
            count++;
        }
        cout << "Tentativo n." << count << endl;
        if(somma == punteggio) {
            cout << "Hai vinto! è uscito: " << somma << endl;
        } else {
            cout << "Hai perso! è uscito: " << somma << endl;
        }
    }

    return 0;
}
