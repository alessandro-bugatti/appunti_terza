#include <iostream>

using namespace std;

//Soluzione corretta senza circolarità
//Punteggio nella verifica 1,5 punti
void sposta(int v[], int n, int K)
{
    for (int i = n - K - 1; i >= 0; i--)
       v[i+K] = v[i];
}

//Soluzione corretta con circolarità semplice
//Punteggio nella verifica 2 punti
void sposta_circolare(int v[], int n, int K)
{
    for (int p = 0; p < K; p++)
    {
        int temp = v[n-1];
        for (int i = n - 2; i >= 0; i--)
        {
            v[i+1] = v[i];
        }
        v[0] = temp;
    }
}

int main()
{
    int v[] = {4,3,6,2,1,3,4,8,6,4,1};
    sposta_circolare(v, 11, 2);
    for (int i = 0; i < 11; i++)
        cout << v[i] << endl;
    return 0;
}
