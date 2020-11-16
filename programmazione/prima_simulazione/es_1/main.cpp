#include <iostream>

using namespace std;

int main()
{
    int N, fattoriale = 1;
    cout << "Inserisci il numero di cui vuoi il fattoriale: ";
    cin >> N;
    for (int i = 1; i <= N; i++)
        fattoriale = fattoriale * i;
    cout << "Risultato: " << fattoriale << endl;
    return 0;
}
