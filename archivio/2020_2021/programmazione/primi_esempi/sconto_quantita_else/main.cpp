/*
Programma che fa un sconto del 10%
su un prodotto se si acquistano più di 10 pezzi
Versione con l'else
Autore: Alessandro Bugatti
*/

#include <iostream>

using namespace std;

int main()
{
    int n_prodotti;
    float  sconto, costo_totale, costo_unitario;
    cout << "Inserisci il numero di prodotti acquistati: ";
    cin >> n_prodotti;
    cout << "Inserisci il costo del prodotto singolo: ";
    cin >> costo_unitario;
    //Se i prodotti sono più di 10
    if (n_prodotti > 10)
    {
        sconto = 10;
    }
    //Se i prodotti sono 10 o meno
    else
    {
        sconto = 0;
    }
    costo_totale = (costo_unitario * (100 - sconto)/100) * n_prodotti;
    cout << "Il costo totale vale: " << costo_totale << endl;
    return 0;
}











