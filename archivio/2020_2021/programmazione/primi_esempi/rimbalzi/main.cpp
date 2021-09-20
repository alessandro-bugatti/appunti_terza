//Problema dei rimbalzi

#include <iostream>

using namespace std;

int main()
{
    float altezza;
    int numero_rimbalzi = 0;
    cout << "Inserisci l'altezza in millimetri: ";
    cin >> altezza;
    while (altezza > 1)
    {
        altezza *= 0.99;
        numero_rimbalzi++;
    }
    cout << "Il numero di rimbalzi sarà: " << numero_rimbalzi
        << endl;
    return 0;
}
