#include <iostream>

int main() {
    int N = 5, conta = 1;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < i + 1; ++j) {
            std::cout << conta << " ";
            conta++;
        }
        std::cout << std::endl;
    }
    return 0;
}
