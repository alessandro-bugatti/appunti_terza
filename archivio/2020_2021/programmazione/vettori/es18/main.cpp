//Autore: Codenotti Fabio

#include <iostream>

using namespace std;

void scambio_posizione(int v[], int n)
{
    int a = n-1;
    int temp;
    for (int i = 0; i < n/2; i++)
    {
        temp= v[a];
        v[a]= v[i];
        v[i]= temp;
        a--;
    }
}


int main()
{
    const int N = 10;
    int v[N];
    for (int i=0; i<N; i++)
    {
        //cout << "inserisci un numero: ";
        //cin >> v[i];
        v[i] = rand()%100 + 1;
        cout << v[i] << endl;
    }

    scambio_posizione(v, N);
    cout << "Dopo l'inversione" << endl;
    for (int i=0; i<N; i++)
    {
        cout << v[i] << endl;
    }
    return 0;
}
//non riesco a capire dove non  funziona
