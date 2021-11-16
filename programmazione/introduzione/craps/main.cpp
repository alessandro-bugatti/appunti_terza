#include <iostream>
#include <ctime>

using namespace std;

int main() {
    srand(time(NULL));
    int lancio;
    int a = 2, b = 12;
    lancio = rand();
    cout << "Valore prodotto da rand: " << lancio << endl;
    //Vogliamo invece un valore compreso tra a e b
    cout << "Limito il numero di numeri da produrre a quello che mi interessa: "
    << lancio% (b-a+1) << endl;
    cout << "Aumento dell'estremo inferiore dell'intervallo" <<
        lancio% (b-a+1) + a << endl;
    //La parte precedente però non va bene per il gioco del Craps
    //che vuole due dadi da 6, non uno da 12
    lancio = (rand()%6 + 1) + (rand()%6 + 1);
    cout << "Il primo lancio ha prodotto il numero " << lancio << endl;
    if (lancio == 7 || lancio == 11){
        cout << "Hai vinto" << endl;
    }
    else if (lancio <= 3 || lancio == 12){
        cout << "Hai perso" << endl;
    }
    else{
        int target = lancio;
        lancio = (rand()%6 + 1) + (rand()%6 + 1);
        cout << "Il lancio ha prodotto il numero " << lancio << endl;
        while (lancio != target && lancio != 7)
        {
            lancio = (rand()%6 + 1) + (rand()%6 + 1);
            cout << "Il lancio ha prodotto il numero " << lancio << endl;
        }
        if (lancio == target)
            cout << "Hai vinto" << endl;
        else
            cout << "Hai perso" << endl;

    }
    return 0;
}
