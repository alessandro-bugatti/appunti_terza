/*
Programma che fa un sconto del 10%
su un prodotto se si acquistano più di 10 pezzi
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
    //Versione proposta da me
    //Se i prodotti sono più di 10
    if (n_prodotti > 10)
    {
        sconto = 10;
    }
    //Versione proposta da Medici
//    if (n_prodotti > 10)
//    {
//        sconto = 10;
//        costo_unitario = costo_unitario * (100 - sconto)/100;
//    }
    costo_totale = (costo_unitario * (100 - sconto)/100) * n_prodotti;
    //Nel caso si usi la proposta di Medici va commentata la riga sopra
    //e decommentata quella qua sotto
    //costo_totale = costo_unitario * n_prodotti;
    cout << "Il costo totale vale: " << costo_totale << endl;
    return 0;
}











