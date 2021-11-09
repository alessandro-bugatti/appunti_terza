#include <iostream>

/*
 * Successione di Fibonacci
 * Fn = Fn-1 + Fn-2
 * F0 = 0
 * F1 = 1
 */

using namespace std;

int main() {
    int n; //Fino a dove dobbiamo arrivare con la sequenza di Fibonacci
    int n_1, n_2, attuale;
    cout << "Inserisci la lunghezza che desideri: ";
    cin >> n;
    n_1 = 1;
    n_2 = 0;
    cout << "0 -> " << n_2 << endl;
    cout << "1 -> " << n_1 << endl;
    for (int i = 2; i <= n; i++)
    {
        attuale = n_1 + n_2;
        cout << i << " -> " << attuale << endl;
        n_2 = n_1;
        n_1 = attuale;
    }
    return 0;
}
