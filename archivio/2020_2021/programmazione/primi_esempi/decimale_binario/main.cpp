//Conversione binario decimale

#include <iostream>

using namespace std;

int main()
{
    int N_bit;
    int bit;
    int numero_decimale = 0;
    int potenza = 1;
    cout << "Inserisci il numero di bit: ";
    cin >> N_bit;
    for (int i = 0; i < N_bit; i++)
    {
        cout << "Inserisci un bit: ";
        cin >> bit;
        numero_decimale += bit * potenza;
        potenza = potenza * 2;
    }
    cout << "Il numero in decimale: " << numero_decimale
        << endl;
    return 0;
}
