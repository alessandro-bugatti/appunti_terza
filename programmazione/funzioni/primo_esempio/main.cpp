#include <iostream>

using namespace std;

//Definizione di una funzione
//VA definita all'esterno del main
//Si sceglie il nome che spiega cosa fa la funzione
//Le regole dei nomi sono come per i nomi di variabile
//Poi si scelgono i parametri e il loro tipo
//Infine si sceglie il tipo del valore di ritorno
/**
 * Questa funzione rappresenta una retta del tipo
 * f(x) = mx + q
 * x,m e q sono detti parametri formali, perchè non hanno dei valori
 * concreti, servono solo a definire cosa fa la funzione
 * @param x la variabile indipendente
 * @param m coefficiente angolare
 * @param q intercetta
 * @return
 */

float retta(float x, float m, float q) //La firma della funzione
{
    //Corpo della funzione
    //POssiamo dichiarare tutte le variabili che ci servono
    float y = m*x + q;
    //Ritorniamo il risultato
    return y;
}

float potenza_esponente_intera(float base, int esponente)
{
    //Al momento assumiamo che l'esponente sia positivo
    float risultato = 1;
    for (int i = 0; i < esponente; ++i) {
        risultato *= base;
    }
    return risultato;
}


int main() {
    float y;
    y = retta(0, 3, 2);
    cout << y << endl;
    float x = -1;
    while (x < 1){
        cout << retta(x, 3, 2) << endl;
        x += 0.1;
    }
    cout << "3 elevato alla 4 vale: " << potenza_esponente_intera(3,4) << endl;

    float coefficiente_angolare, intercetta;
    cout << "Inserisci il coeffiente angolare della retta: ";
    cin >> coefficiente_angolare;
    cout << "Inserisci l'intercetta della retta: ";
    cin >> intercetta;
    x = -1;
    while (x < 1){
        cout << x << " -> " <<retta(x, coefficiente_angolare, intercetta) << endl;
        x += 0.1;
    }
    return 0;
}
