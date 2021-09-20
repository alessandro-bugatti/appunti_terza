#include <iostream>
#include <cmath>

using namespace std;

/**
Questa funzione calcola la potenza intera, con esponente
positiva, di un certo numero reale
Es. 3.5 elevato a 2 ritorna 12.25
*/

float potenza_intera(float base, int esponente)
{

    /*b^4 = b*b*b*b;
    ris = 1
    ris = ris * b => b
    ris = ris * b => b*b
    ris = ris * b => b*b*b
    ris = ris * b => b*b*b*b*/
    float risultato = 1;
    for (int i = 0; i < esponente; i++)
        risultato *= base;
    return risultato;
}



int main()
{
    float b;
    int e;
    cout << "Inserisci la base: " << endl;
    cin >> b;
    cout << "Inserisci l'esponente: " << endl;
    cin >> e;
    float risultato = potenza_intera(b, e);
    cout << "Il risultato vale: " << risultato << endl;

    return 0;
}
