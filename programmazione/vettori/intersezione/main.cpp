#include <iostream>
#include <vector>

void riempi(int v[], int n) {
    for (int i = 0; i < n; ++i) {
        v[i] = rand() % 20;
    }
}

void stampa(int v[], int n) {
    for (int i = 0; i < n; ++i) {
        std::cout << v[i] << " ";
    }
    std::cout << std::endl;
}

void stampa(const std::vector<int> &v) {
    for (int i = 0; i < v.size(); ++i) {
        std::cout << v.at(i) << " ";
    }
    std::cout << std::endl;
}


bool presente (const std::vector<int> &v, int c) {
    for (int i = 0; i < v.size(); ++i) {
        if (v.at(i) == c)
            return true;
    }
    return false;
}

void unisci(int src[], int n, std::vector<int> &dst) {
    for (int i = 0; i < n; ++i) {
        if (!presente(dst, src[i])) {
            dst.push_back(src[i]);
        }
    }
}

void interseca(int src1[], int src2[], int n, std::vector<int> &dst) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (src1[i] == src2[j] && !presente(dst, src1[i])) {
                dst.push_back(src1[i]);
            }
        }
    }
}

int main() {
    const int DIM = 10;
    int v1[DIM], v2[DIM];
    std::vector<int> unione, intersezione;
    riempi(v1, DIM);
    riempi(v2, DIM);
    stampa(v1, DIM);
    stampa(v2, DIM);
    unisci(v1, DIM, unione);
    unisci(v2, DIM, unione);
    stampa(unione);
    interseca(v1, v2, DIM, intersezione);
    stampa(intersezione);
    return 0;
}
