#include <iostream>

bool is_maggiore(int a, int b){
    if (a > b)
        return true;
    return false;
}

void minore_maggiore(int N, int &minore, int &maggiore){
    std::cout << "Inserisci " << N << " numeri: " << std::endl;
    int temp;
    std::cin >> temp;
    minore = maggiore = temp;
    for (int i = 0; i < N - 1; ++i) {
        std::cin >> temp;
        if (is_maggiore(temp, maggiore)){
            maggiore = temp;
        }
        if (temp < minore){
            minore = temp;
        }
    }
}



int main() {
    int minore, maggiore;
    minore_maggiore(4, minore, maggiore);
    std::cout << "Il minore è " << minore << " e il maggiore è " << maggiore << std::endl;
    return 0;
}
