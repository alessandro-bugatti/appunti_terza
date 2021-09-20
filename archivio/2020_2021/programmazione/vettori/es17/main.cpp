//Autore: Garoffoli Giacomo

#include <iostream>

using namespace std;

bool valore_presente(int v[], int n, int cercato)
{
    for(int i = 0; i < n; i++)
    {
        if(v[i] == cercato)
            return true;
    }
    return false;
}

int main()
{
    const int N = 20;
    int n,vettore[N];
    bool risposta;
    for(int i = 0; i < N; i++)
    {
        //cout << "Inserisci un valore nella posizione " << i << ": ";
        //cin >> vettore[i];
        vettore[i] = rand()%100;
        cout << vettore[i] << endl;
    }
    cout << endl;
    cout << "Inserisci un numero: ";
    cin >> n;

    risposta = valore_presente(vettore, N, n);

    if(risposta == true)
        cout << "Il numero è presente nel vettore";
    else
        cout << "Il numero non è presente nel vettore";
    return 0;
}
