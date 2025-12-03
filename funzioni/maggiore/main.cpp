#include <iostream>

int maggiore(int a, int b) {
    if (a > b) {
        return a;
    }
    return b;
}

int maggiore(int a, int b, int c) {
    return maggiore(a, maggiore(b, c));
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}