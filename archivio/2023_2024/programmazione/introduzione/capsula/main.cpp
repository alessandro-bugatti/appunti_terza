#include <iostream>

int main() {
    int n = 3;
    //std::cout << "Inserire un numero n positivo: ";
    std::cout << std::endl;
    //Lato superiore
    for (int i = 0; i < n; ++i) {
        std::cout << " ";
    }
    for (int i = 0; i < n; ++i) {
        std::cout << "_";
    }
    std::cout << std::endl;
    //Lati inclinati della parte superiore
    int spazi_prima = n - 1, spazi_dentro = n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < spazi_prima; ++j) {
            std::cout << " ";
        }
        std::cout << "/";
        for (int j = 0; j < spazi_dentro; ++j) {
            std::cout << " ";
        }
        std::cout << "\\" << std::endl;
        spazi_prima--;
        spazi_dentro+=2;
    }
    //Lati paralleli
    spazi_dentro -= 2;
    for (int i = 0; i < n; ++i) {
        std::cout << "|";
        for (int j = 0; j < spazi_dentro; ++j) {
            std::cout << " ";
        }
        std::cout << "|" << std::endl;

    }
    //Lati inclinati della parte inferiore
    spazi_prima++;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < spazi_prima; ++j) {
            std::cout << " ";
        }
        std::cout << "\\";
        for (int j = 0; j < spazi_dentro; ++j) {
            //Controllo per mettere il lato inferiore nell'ultima riga
            if (i != n-1)
                std::cout << " ";
            else
                std::cout << "_";
        }
        std::cout << "/" << std::endl;
        spazi_prima++;
        spazi_dentro-=2;
    }
    std::cout << std::endl;
    return 0;
}
