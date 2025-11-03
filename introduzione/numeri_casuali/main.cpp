#include <iostream>

int main() {
    int n;
    srand(time(NULL));
    for (int i = 0; i < 10000; ++i) {
        n = rand() % 1000 + 1;
        std::cout << n << std::endl;
    }
    return 0;
}