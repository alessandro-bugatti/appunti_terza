#include <iostream>

int main() {
    int N;
    std::cin >> N;
    if (N == 1){
        std::cout << -1 << std::endl;
    }
    else if (N % 2 == 0){
        for (int i = 0; i < N / 2; ++i) {
            std::cout << "15";
        }
        std::cout << std::endl;
    }
    else{
        for (int i = 0; i < N / 2 - 1; ++i) {
            std::cout << "15";
        }
        std::cout << "111" << std::endl;
    }
    return 0;
}
