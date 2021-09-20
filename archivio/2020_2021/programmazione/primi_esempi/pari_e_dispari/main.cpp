#include <iostream>
#include <cstdlib>
#include <ctime>


/**
Gioco del pari e dispari.
Il giocatore umano sceglie tra pari e dispari, lancia un numero
compreso tra 0 e 5, il computer sceglie un numero casuale compreso nello
stesso range e poi il programma vede chi ha vinto con la regola
del gioco reale del pari e dispari
Il programma permette di rigiocare quante volte si vuole e
tiene conto delle vittorie dell'umano e del computer
*/

using namespace std;

int main()
{
    int numero_giocatore, numero_computer;
    int somma, pari, scelta = 1;
    srand(time(NULL));
    while(scelta == 1)
    {
        cout << "Scegli 1 se vuoi pari o 0 se vuoi dispari: ";
        cin >> pari;
        numero_computer = rand()%6;
        cout << "Scegli un numero compreso tra 0 e 5: ";
        cin >> numero_giocatore;
        somma = numero_computer + numero_giocatore;
        cout << "Il computer ha tirato " << numero_computer << endl;
        if (somma % 2 == 0)
        {
            if (pari == 1)
                cout << "Vinci tu" << endl;
            else
                cout << "Vince il computer" << endl;
        }
        else
        {
            if (pari == 0)
                cout << "Vinci tu" << endl;
            else
                cout << "Vince il computer" << endl;
        }
        cout << "Vuoi giocare ancora (1 Sì - 0 No)?";
        cin >> scelta;
    }
    return 0;
}
