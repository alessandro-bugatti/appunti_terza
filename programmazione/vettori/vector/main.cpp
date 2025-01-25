#include <iostream>
#include <vector>

bool crescente(std::vector<int> &v) {
    for (int i = 0; i < v.size() - 1; ++i) {
        if (v.at(i) > v.at(i+1)) {
            return false;
        }
    }
    return true;
}

int main() {
    std::vector<int> v;
    for (int i = 0; i < 100; ++i) {
        // int n = rand()%6 + 1;
        // if (n % 2 == 0)
        //     v.push_back(n);
        v.push_back(i);
    }
    int somma = 0;
    for (int i = 0; i <
        v.size(); ++i) {
        somma += v[i];
    }
    std::cout << somma << std::endl;
    somma = 0;
    for (int i = 0; i < v.size(); ++i) {
        somma += v.at(i);
    }
    std::cout << somma << std::endl;
    if (crescente(v)) {
        std::cout << "crescente" << std::endl;
    }
    else {
        std::cout << "non crescente" << std::endl;
    }
    return 0;
}
