#include <fstream>
#include <iostream>
#include <vector>

int main() {
    std::ifstream in("input.txt");
    //Controllo sull'apertura del file
    //Va letto come "se non è aperto ...."
    if (!in) {
        std::cout << "Errore nell'apertura del file input.txt" << std::endl;
        return 1;
    }

    int t;
    std::vector<int> v;
    while(in >> t) {
        v.push_back(t);
    }
    for (int i = 0; i < v.size(); ++i) {
        std::cout << v.at(i) << std::endl;
    }
    return 0;
}
