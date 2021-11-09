#include <iostream>
#include <ctime>

using namespace std;

int main() {
    const int MAX = 10000;
    srand(time(NULL));
    int numero_da_indovinare = rand()%MAX + 1;
    int tentativo;
    cout << "Indovina il numero che ho pensato: ";
    cin >> tentativo;
    while (tentativo != numero_da_indovinare)
    {
        if (tentativo > numero_da_indovinare)
            cout << "Il numero è troppo grande, riprova" << endl;
        else
            cout << "Il numero è troppo piccolo, riprova" << endl;

        cout << "Indovina il numero che ho pensato: ";
        cin >> tentativo;
    }
    return 0;
}
