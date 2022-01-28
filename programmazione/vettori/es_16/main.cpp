#include <iostream>

using namespace std;

int main() {
    const int MAX_VALORI = 1000;
    int v[MAX_VALORI];
    int n;
    cout << "Quanti valori vuoi inserire? ";
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cout << "Inserisci un valore:";
        cin >> v[i];
    }
    int massimo = v[0];
    int minimo = v[0];
    float media = 0;
    for (int i = 0; i < n; ++i) {
        if (v[i] > massimo)
            massimo = v[i];
        if (v[i] < minimo)
            minimo = v[i];
        media += v[i];
    }
    cout << "Massimo: " << massimo << endl;
    cout << "Minimo: " << minimo << endl;
    cout << "Media: " << media/n << endl;

    return 0;
}
