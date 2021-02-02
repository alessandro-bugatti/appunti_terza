//Autore: Leporati Marco

#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

float scalarProduct (float a[], float b[], int n)
{
    float risultato = 0;
    for (int i=0; i<n; i++)
    {
        risultato = risultato + a[i]*b[i];
    }
    return risultato;
}

int main()
{
    srand(time(NULL));
    const int N = 10;
    float a[N], b[N];

    for (int i=0; i<N; i++)
    {
//        cout << "Inserisci il valore " << i+1 <<  ": ";
//        cin >> a[i];
        a[i] = rand()%10+1;
    }

    for (int i=0; i<N; i++)
    {
//        cout << "Inserisci il valore " << i+1 <<  ": ";
//        cin >> b[i];
        b[i] = rand()%10+1;
    }

    cout << endl << "Vettore a" << endl;

    for (int i=0; i<N; i++)
        cout << a[i] << endl;

    cout << endl << "Vettore b" << endl;

    for (int i=0; i<N; i++)
        cout << b[i] << endl;

    cout << endl << "Il prodotto scalare vale " << scalarProduct(a,b,N) << endl;

    return 0;
}
