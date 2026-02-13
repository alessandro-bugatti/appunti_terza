#include <iostream>
#include <ratio>
#include <vector>
//Conversione decimale binario
//Input: un numero decimale
//Output: un numero binario

int main() {
    int decimale;
    std::vector<int> binario;
    std::cout << "Inserisci il numero decimale da convertire: ";
    std::cin >> decimale;
    while (decimale > 0) {
        binario.push_back(decimale % 2);
        decimale /= 2;
    }
    for (int i = binario.size() - 1; i >= 0; --i) {
        std::cout << binario.at(i);
    }
    std::cout << std::endl;
    return 0;
}