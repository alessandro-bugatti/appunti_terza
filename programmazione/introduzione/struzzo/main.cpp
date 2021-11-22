#include <iostream>
#include <cmath>

using namespace std;
int main() {
    int distanza;
    char direzione;
    int x = 0, y = 0;
    cout << "Inserisci la distanza: ";
    cin >> distanza;
    cout << "Inserisci la direzione: ";
    cin >> direzione;
    while (distanza > 0)
    {
        /*
         * if (direzione == 'N)
         *      y += distanza;
         * else if (direzione == 'S')
         *      y -= distanza;
         * ecc.
         */
        switch (direzione) {
            case 'N':
                y += distanza;
                break;
            case 'S':
                y -= distanza;
                break;
            case 'E':
                x += distanza;
                break;
            case 'W':
                x -= distanza;
                break;
        }

        cout << "Inserisci la distanza: ";
        cin >> distanza;
        cout << "Inserisci la direzione: ";
        cin >> direzione;
    }
    double risultato = sqrt(pow(x,2) + y*y);
    cout << "La distanza dal punto di partenza vale " <<
        risultato;
    return 0;
}
