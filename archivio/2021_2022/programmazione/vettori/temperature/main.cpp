//Esempio introduttivo del libro

#include <iostream>

using namespace std;

int main() {
    //Dichiarazione del vettore
    //Prima va il tipo, come per le variabili
    //Segue il nome, con le stesse regole delle variabili viste finora
    //INfine ci deve essere una coppia di parentesi quadre che contiene
    //la dimensione del vettore
    const int NUM_MESI = 12;
    int mm_pioggia[NUM_MESI];
    //Input
    for (int i = 0; i < NUM_MESI; ++i) {
        cout << "Inserisci i millimetri di pioggia del mese " << i + 1 << endl;
        cin >> mm_pioggia[i];
        //Se voglio velocizzare l'input tolgo le due righe sopra e inserisco
        //quella qua sotto
        //mm_pioggia[i] = rand() % 100;
    }
    int somma = 0;

    for (int i = 0; i < NUM_MESI; i++) {
        somma += mm_pioggia[i];
    }
    float media;
    media = somma / NUM_MESI;
    for (int i = 0; i < NUM_MESI; ++i) {
        if (mm_pioggia[i] > media)
            cout << "Nel mese " << i+1 << " ha piovuto più della media" << endl;
    }
    return 0;
}
