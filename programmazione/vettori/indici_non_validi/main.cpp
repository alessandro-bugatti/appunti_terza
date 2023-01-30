#include <iostream>

int main() {
    const int N = 1000;
    int v[N];
    for (int i = 0; i < N; i++)
        v[i] = 0;
    std::cout << v[100] << std::endl;
    std::cout << v[-100] << std::endl;
    std::cout << v[1000] << std::endl;
    std::cout << v[1002] << std::endl;

    int somma = 0;
    for (int i = 0; i <= N; ++i) {
        somma += v[i];
    }
    std::cout << somma << std::endl;
    return 0;
}
