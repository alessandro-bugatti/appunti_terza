#include <iostream>

using namespace std;

int main() {
    const int N = 60;
    float valori[N], medie[N];
    for (int i = 0; i < N; ++i) {
        cout << "Inserisci il dato: ";
        cin >> valori[i];
    }
    medie[0] = (valori[0] * 2 + valori[1])/3;
    for (int i = 1; i < N - 1; ++i) {
        medie[i] = (valori[i-1] + valori[i] + valori[i+1])/3;
    }
    medie[N-1] = (valori[N-1] * 2 + valori[N-2])/3;
    for (int i = 0; i < N; ++i) {
        cout << medie[i] << " ";
    }
    return 0;
}
