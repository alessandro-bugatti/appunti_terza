#include <iostream>

using namespace std;

const int N_SENSORI = 10;
const int GIORNI = 30;

int main()
{
    int scelto;
    float temperature[N_SENSORI][GIORNI];
    for (int i = 0; i < N_SENSORI; i++)
        for (int j = 0; j < GIORNI; j++)
            temperature[i][j] = rand()%100;
    cout << "Scegli un sensore";
    cin >> scelto;
    cout << "Il valori letti dal sensore " << scelto << " sono :" << endl;
    for (int i = 0; i < GIORNI; i++)
        cout << "Il giorno " << i + 1 << " la temperatura era : " << temperature[scelto][i] << endl;
    float media = 0;
    for (int i = 0; i < GIORNI; i++)
        media += temperature[scelto][i];
    media /= GIORNI;
    return 0;
}
