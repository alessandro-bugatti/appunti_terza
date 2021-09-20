#include <iostream>

using namespace std;

int main()
{
    int n;
    long long int fattoriale = 1;
    int m;
    cout << "Inserisci il numero: ";
    cin >> n;
    m = n;
    for (int i = 0; i < n; i++)
    {
        fattoriale = fattoriale * m;
        m = m - 1;
    }

    cout << "Il fattoriale vale " << fattoriale << endl;
    //Secondo modo
    fattoriale = 1;
    for (int i = 1; i < n + 1; i++)
        fattoriale = fattoriale * i;
    cout << "Il fattoriale vale " << fattoriale << endl;


    return 0;
}
