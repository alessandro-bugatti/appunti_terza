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
    int n;
    std::vector<float> v;
    in >> n;
    for (int i = 0; i < n; ++i) {
        float f;
        in >> f;
        v.push_back(f);
    }
    std::cout << v.size() << std::endl;
    for (int i = 0; i < v.size(); ++i) {
        std::cout << v.at(i) << std::endl;
    }
    return 0;
}
