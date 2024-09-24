#include <iostream>
using namespace std;

int main() {
    srand(time(NULL));
   int n = rand()%101+1;
   int numero, n_tentativi = 1;
   cout << "Inserire un numero :";
   cin >> numero;
    while (numero != n ) {
        if (numero > n) {
            cout << "Hai inserito un numero maggiore di n " <<endl;
        } else {
            cout << "Hai inserito un numero minore di n " <<endl;
        }
        n_tentativi++;
        cout << "Inserire un numero :";
        cin >> numero;
    }
    cout << "Il numero di tentativi è :" << n_tentativi <<endl;
    return 0;
}
