#include <iostream>

int trasforma_in_secondi(int h, int m, int s) {
    return s + m * 60 + h * 3600;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}