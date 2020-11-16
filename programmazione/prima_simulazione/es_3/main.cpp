#include <iostream>

using namespace std;

int main()
{
    int N, somma_pari = 0, somma_dispari = 0;
    cout << "Inserisci il numero intero: ";
    cin >> N;
    for (int i = 2; i <= N; i += 2)
    {
        cout << i*i << endl;
        somma_pari += i*i;
    }
    for (int i = 1; i <= N; i += 2)
    {
        cout << i*i*i << endl;
        somma_dispari += i*i*i;
    }
    cout << "La somma dei quadrati vale " << somma_pari
        << " e dei cubi vale " << somma_dispari << endl;
    return 0;
}
