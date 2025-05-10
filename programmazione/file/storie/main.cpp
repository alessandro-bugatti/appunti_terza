#include <iostream>
#include <fstream>
#include <vector>

struct Scelta {
    std::string testo;
    int sezione_successiva;
};

struct Sezione {
    std::string scena;
    Scelta scelte[3];
};

int main() {
    std::ifstream in("../assets/storia.txt");

    if (!in) {
        std::cout << "Apertura fallita" << std::endl;
        return 1;
    }
    std::vector<std::string> righe;
    std::string temp;
    while (std::getline(in, temp)) {
        righe.push_back(temp);
    }
    std::cout << "Nel file sono presenti " << righe.size() << " righe." << std::endl;

    for (int i = 0; i < righe.size(); ++i) {
        std::cout << righe.at(i) << std::endl;
    }
    in.close();
    return 0;
}
