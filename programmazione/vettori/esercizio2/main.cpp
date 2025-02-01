#include <iostream>
#include <vector>

void filtra(std::vector<int> &v, int k) {
    std::vector<int> temp;
    temp = v;
    for (int i = k; i < v.size() - k; ++i) {
        int media, somma = 0;
        for (int j = i -k ; j < i + k + 1; ++j) {
            somma += v.at(j);
        }
        media = somma / (2*k + 1);
        temp.at(i) = media;
    }
    v = temp;
}

void stampa(const std::vector<int> &v) {
    for (int i = 0; i < v.size(); ++i) {
        std::cout << v.at(i) << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::vector<int> v;
    int k = 3, N = 20;
    for (int i = 0; i < N; ++i) {
        if (rand() % 10 < 2) {
            v.push_back(rand() % 200);
        }
        else {
            v.push_back(rand() % 10 + 95);
        }
    }
    stampa(v);
    filtra(v, k);
    stampa(v);

    return 0;
}