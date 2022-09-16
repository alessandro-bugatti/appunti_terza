#include <iostream>

int main() {
    int a = 5, b = 7, c;
    c = a + b;
    for (int i = 0; i < 10; i++)
        c += a;
    std::cout << c << std::endl;
    return 0;
}
