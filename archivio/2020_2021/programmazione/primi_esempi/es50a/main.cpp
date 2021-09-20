#include <iostream>

// Giacomo Garoffoli
using namespace std;

int main()
{
 float spessore_laminato, spessore_semilavorato;
 int laminatoi = 0;
 cout << "Inserire lo spessore del laminato semilavorato: ";
 cin >> spessore_semilavorato;
 cout << "Inserisci il numero di laminatoi: ";
 cin >> laminatoi;
 spessore_laminato = spessore_semilavorato;
 for (int i = 0; i < laminatoi; i++)
    spessore_laminato *= 0.9;
 cout << "Dopo " << laminatoi << " laminatoi lo spessore "
    " diventa di " << spessore_laminato << " mm";
 return 0;
}
