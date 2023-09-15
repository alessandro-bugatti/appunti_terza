#include <iostream>

int main() {
    const int MAX = 10;
    int v[MAX];
    int n;
    std::cout << "Quanti elementi vuoi inserire (max 10)?";
    std::cin >> n;
    //Acquisizione degli elementi
    for (int i = 0; i < n; ++i) {
        std::cout << "Inserisci un valore:";
        std::cin >> v[i];
    }
    //Conteggio dei pari e dei dispari
    int pari = 0, dispari = 0;
    for (int i = 0; i < n; ++i) {
        if (v[i] % 2 == 0){
            pari++;
        }
        else{
            dispari++;
        }
    }
    //Stampa della riga dei pari
    std::cout << "Ci sono " << pari << " numeri pari e sono: ";
    for (int i = 0; i < n; ++i) {
        if (v[i] % 2 == 0){
            std::cout << v[i] << " ";
        }
    }
    std::cout << std::endl << "Ci sono " << dispari << " numeri dispari e sono:";
    for (int i = 0; i < n; ++i) {
        if (v[i] % 2 != 0){
            std::cout << v[i] << " ";
        }
    }
    std::cout << std::endl;
    return 0;
}
