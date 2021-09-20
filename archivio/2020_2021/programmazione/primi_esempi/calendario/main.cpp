#include <iostream>

using namespace std;

int main()
{
    int mese, giorni_mese;
    cout << "Inserisci il mese: ";
    cin >> mese;
    if (mese == 2)
        giorni_mese = 28;
    else if (mese == 11 || mese == 4 || mese == 9 || mese == 6)
        giorni_mese = 30;
    else
        giorni_mese = 31;
    for (int i = 0; i < giorni_mese; i++)
    {
        cout << i + 1 << " ";
    }

    return 0;
}
