#include <iostream>
using namespace std;

int main() {
    int n, n_max , n_min , numero;
    cout << "Inserire valore n :";
    cin >> n;
    cout << "Inserire un numero :";
    cin >> numero;
    n_max = numero;
    n_min = numero;
    for (int i = 0; i < n-1; ++i) {
        cout << "Inserire un numero :";
        cin >> numero;
        if ( numero > n_max ) {
            n_max = numero;
        }
        if ( numero < n_min) {
            n_min = numero;
        }
    }
    cout << "Il massimo è :" << n_max <<endl;
    cout << "Il minimo è :" << n_min <<endl;
//    while equivalente al for
//    int i = 0;
//    while (i<n)  {
//        cout << "Inserire un numero :";
//        cin >> numero;
//        ++i;
//    }
    return 0;
}
