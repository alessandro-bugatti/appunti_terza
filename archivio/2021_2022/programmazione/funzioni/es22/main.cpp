#include <iostream>

using namespace std;

/**
 * FUnzione che determina se un numero è primo o no
 * @param n Il numero da verificare
 * @return true se il numero è primo, false altrimenti
 */
bool primo(int n){
    for (int i = 2; i <= n/2; ++i) {
        if (n % i == 0)
            return false;
    }
    return true;
}

int main() {
    int n, contatore = 0;
    cout << "Inserisci il numero n: ";
    cin >> n;
    int precedente = 0;
    for (int i = 2; i <= n ; ++i) {
        if (primo(i)) //oppure if (primo(i) == true)
            contatore++;
        if (i % 1000 == 0){
            cout << i << ": " << contatore << " "
            << contatore - precedente << endl;
            precedente = contatore;
        }
    }
    /*
     * 1000: 168 168
     * 2000: 303 135
     * 3000: 411 108
     */
    cout << contatore << endl;
    return 0;
}
