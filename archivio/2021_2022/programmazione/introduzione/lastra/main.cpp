/*
 * Problema della piegatura della lastra di metallo
 * per ottenere il volume maggiore
 */

#include <iostream>

using namespace std;

int main() {
    float larghezza, altezza; //Dimensioni della lastra : input
    float lato; //Lato del quadrato di taglio
    float volume, volumeMax, latoMax;
    //Inizializzazione del problema
    cout << "Inserisci la dimensione in cm del lato corto: ";
    cin >> larghezza;
    cout << "Inserisci la dimensione del lato lungo: ";
    cin >> altezza;
    //Il lato del quadrato iniziale è quando non c'è il quadrato
    lato = 0;
    volume = 0;
    volumeMax = volume;
    latoMax = 0;
    while (lato < larghezza / 2)
    {
        lato += 0.1; //forma breve di lato = lato + 0.1;
        //Calcola il volume con il lato di questo giro
        volume = (larghezza - 2*lato)*(altezza - 2*lato)*lato;
        cout << "Lato: " << lato << " Volume: " << volume << endl;
        //Verifica se il nuovo volume calcolato è maggiore
        //del massimo trovato finora
        if (volume > volumeMax)
        {
            //Se è maggiore aggiorna le informazioni
            volumeMax = volume;
            latoMax = lato;
        }
    }
    cout << "Utilizzando un lato di " << latoMax << " cm otterrai " <<
        " un volume massimo di " << volumeMax << " cm cubici" << endl;
    return 0;
}
