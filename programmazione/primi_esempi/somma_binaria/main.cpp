//Somma binaria

#include <iostream>

using namespace std;

/**

1011+
0010
-----
1101
*/
int main()
{
    int N_bit;
    int bit1, bit2;
    int riporto = 0;
    int risultato = 0;
    int potenza = 1;
    cout << "Inserisci il numero di bit: ";
    cin >> N_bit;
    for (int i = 0; i < N_bit; i++)
    {
        int somma;
        cout << "Inserisci il bit del primo numero: ";
        cin >> bit1;
        cout << "Inserisci il bit del secondo numero: ";
        cin >> bit2;
        somma = bit1 + bit2 + riporto;
        if (somma == 0)
        {
            riporto = 0;
        }
        else if (somma == 1)
        {
            riporto = 0;
        }
        else if (somma == 2)
        {
            somma = 0;
            riporto = 1;
        }
        else
        {
            somma = 1;
            riporto = 1;
        }
        cout << "Somma bit " << i+1 << " = " << somma << endl;
        risultato += somma*potenza;
        potenza *= 2;
    }
    cout << "Il risultato decimale vale: " << risultato << endl;
    if (riporto == 1)
        cout << "C'è stato overflow" << endl;
    else
        cout << "Nessun overflow" << endl;
    return 0;
}
