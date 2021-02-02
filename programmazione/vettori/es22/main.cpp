//Autore: Palatini Stefano

#include <iostream>

using namespace std;

void derive(float data[], int n, float difference[])
{
    for (int i = 0; i < n - 1; i++)
    {
        difference[i] = data[i+1] - data[i];
        cout << difference[i] << endl;
    }
}

int main()
{
    const int N = 10;
    float dati[N], differenza[N];
    for (int i = 0; i < N; i++)
    {
        //cout << "Inserisci il valore " << i << ": ";
        //cin >> dati[i];
        dati[i] = rand() % 100;
        cout << dati[i] << endl;
    }
    cout << "Differenze" << endl;
    derive(dati, N, differenza);
    return 0;
}
