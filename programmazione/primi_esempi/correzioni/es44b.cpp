/*
il programma ha il compito di calcolare dopo
quanti anni la massa residua di un materiale
sia inferiore a 1 gr
autore : Rampazzo Enrico
*/

#include <iostream>

using namespace std;

int main()
{
    float  massa_residua, costante_decadimento, massa_perduta;
    int anni= 0;

    cout << "inserisci il valore della massa iniziale in grammi: ";
    cin >> massa_residua;


    cout << "inserisci il valore di costante_decadimento: ";
    cin >> costante_decadimento;

    while (massa_residua >= 1)
    {
        massa_perduta = massa_residua * costante_decadimento;
        massa_residua = massa_residua - massa_perduta;
        //massa_residua = massa_residua - massa_residua*costante_decadimento;
        anni = anni + 1;
        //anni++;
        //anni + 1; NOOOO!

    }
    cout << "la massa scende sotto 1 gr dopo:" << anni << "anni";

    return 0;
}
