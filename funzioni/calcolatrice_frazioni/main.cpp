#include <iostream>

void somma(int n1, int d1, int n2, int d2, int &nr, int &dr) {
    dr = d1 * d2;
    nr = n1 * d2 + n2 * d1;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}