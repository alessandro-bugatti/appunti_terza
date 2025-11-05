#include <iostream>

int main() {
    int a = 12, b = 9;

    if (a > b) {
        int temp = a;
        a = b;
        b = temp;
    }
    int d = a;
    while (a % d != 0 || b % d != 0) {
        d--;
    }
    std::cout << "Il MCD tra " << a << " e " << b << " è " << d;
    std::cout << " e il mcm è " << a * b / d  << std::endl;
    return 0;
}