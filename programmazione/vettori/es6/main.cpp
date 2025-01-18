#include <iostream>

int main() {
    const int DIM = 20;
    int a, b;
    float v[DIM];
    for (int i = 0; i < DIM; ++i) {
        v[i] = rand()%1000;
        v[i] /= 10; //v[i] = v[i]/10;
    }
    std::cin >> a >> b;
    while (a >= 0 && b >= 0) {
        float somma = 0;
        for (int i = a; i < b; ++i) {
            somma += v[i];
        }
        std::cout << somma << std::endl;
        std::cin >> a >> b;
    }
    return 0;
}