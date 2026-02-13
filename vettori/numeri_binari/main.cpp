#include <iostream>
#include <vector>

//Conversione binario decimale
//Input : un numero binario
//Output : numero decimale
int main() {
    std::vector<int> binario;
    int decimale = 0, temp;
    std::cout << "Inserisci un bit del numero binario: ";
    std::cin >> temp;
    while (temp != -1) {
        binario.push_back(temp);
        std::cout << "Inserisci il prossimo bit del numero binario: ";
        std::cin >> temp;
    }
    for (int i = 0; i < binario.size(); ++i) {
        std::cout << binario.at(i);
    }
    std::cout << std::endl;
    int potenza = 1;
    for (int i = binario.size() - 1; i >= 0 ; --i) {
        if (binario.at(i) == 1) {
            decimale += potenza;
        }
        potenza *= 2; //Preparo il valore della potenza del due successiva
    }
    std::cout << "Il valore decimale è " << decimale << std::endl;
    return 0;
}