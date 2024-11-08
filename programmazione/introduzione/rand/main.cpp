#include <iostream>

int main() {
    int n;
    srand(time(NULL));
    n = rand() % 100 + 1;
    std::cout << n << std::endl;
    return 0;
}
