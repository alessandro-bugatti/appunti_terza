#include <iostream>

// Giacomo Garoffoli
using namespace std;

int main()
{
 float spessore_laminato, spessore_semilavorato;
 int laminatoi = 0;
 cout << "Inserire lo spessore del laminato semilavorato: ";
 cin >> spessore_semilavorato;
 cout << "Inserire lo spessore del laminato: ";
 cin >> spessore_laminato;
 while (spessore_semilavorato > spessore_laminato)
 {
     spessore_semilavorato = spessore_semilavorato * 0.9;
     laminatoi++;
 }
 cout << "Sono serviti: " << laminatoi << " laminatoi";
 return 0;
}
