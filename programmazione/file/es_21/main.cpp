#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ofstream multipli("files/multipli5.txt");
    if (!multipli)
    {
        cout << "Non sono riuscito ad aprire il file richiesto" << endl;
        return 103;
    }
    int n;
    cout << "Inserisci un numero (0 per terminare): ";
    cin >> n;
    while (n != 0)
    {
        if (n % 5 == 0)
            multipli << n << endl;
        cout << "Inserisci un numero (0 per terminare): ";
        cin >> n;
    }
    multipli.close();
    return 0;
}
