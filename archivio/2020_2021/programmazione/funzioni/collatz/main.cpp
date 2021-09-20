#include <iostream>

using namespace std;

int lunghezza_sequenza_collatz(int N)
{
    int iterazioni = 0;
    while (N != 1)
    {
        if (N % 2 == 0)
            N = N/2;
        else
            N = (3*N + 1);
        //cout << N << endl;
        iterazioni++;
    }
    return iterazioni;
}

int main()
{
    int M;
    cout << "Inserisci un numero intero positivo: " << endl;
    cin >> M;
    cout << lunghezza_sequenza_collatz(M) << endl;
    cout << "Il valore di partenza era " << M << endl;
    return 0;
}
