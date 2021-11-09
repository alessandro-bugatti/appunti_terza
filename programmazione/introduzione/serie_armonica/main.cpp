#include <iostream>

using namespace std;

int main() {
    int n;
    cout << "Inserisci la lunghezza: ";
    cin >> n;
    float somma = 0;
    for (int i = 1; i <= n; i++) {
        float temp = i;
        somma += 1 / temp;
        cout << somma << endl;
    }

    cout << somma << endl;
    return 0;
}
