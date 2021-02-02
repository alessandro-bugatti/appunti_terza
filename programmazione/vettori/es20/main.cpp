//Autrice: Pamela Loda

#include <iostream>

using namespace std;

int conta_numeri_tra_estremi(int v[], int N, int a, int b)
{
    int contatore = 0;
    for (int i = 0; i < N; i++)
    {
        if (v[i] > a && v[i] < b)
            contatore++;
    }
    return contatore;
}

int main()
{
    const int N = 10;
    int v[N], a, b;

    for(int i = 0; i < N; i++)
    {
        cout << "Inserisci un numero: ";
        cin >> v[i];
    }
    cout << endl << "Inserisci il numero minore (il primo estremo): ";
    cin >> a;
    cout << "Inserisci il numero maggiore (il secondo estremo): ";
    cin >> b;
    while (b < a)
    {
        cout << "Il secondo estremo risulta minore del primo." << endl;
        cout << "Inserisci il numero maggiore (il secondo estremo): ";
        cin >> b;
    }
    cout << endl;
    int conteggio = conta_numeri_tra_estremi(v, N, a, b);
    cout << "Il conteggio dei numeri compresi tra " << a << " e " << b << " risulta: " << conteggio << endl;
    return 0;
}
