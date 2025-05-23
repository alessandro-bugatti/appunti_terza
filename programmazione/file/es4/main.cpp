#include <iostream>
#include <fstream>

int main() {
    std::ofstream out("quadrato.txt");
    if (!out) {
        std::cout << "Errore nell'apertura";
        return 1;
    }
    int n;
    char c;
    std::cout << "Di che lato vuoi il quadrato? ";
    std::cin >> n;
    std::cout << "Con che lettera vuoi sia formato? ";
    std::cin >> c;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            out << c;
        }
        out << std::endl;
    }
    out.close();
    return 0;
}
