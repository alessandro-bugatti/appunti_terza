#include <iostream>
#include <vector>

void riempi(std::vector<int> &v, int n) {
    for (int i = 0; i < n; ++i) {
        v.push_back(rand()%100 + 1);
    }
}

/**
 *
 * @param v
 * @param n
 * @return posizione dell'elemento di valore massimo
 */
int massimo(const std::vector<int> &v) {
    int pos = 0;
    for (int i = 0; i < v.size(); ++i) {
        if (v.at(i) > v.at(pos)) {
            pos = i;
        }
    }
    return pos;
}

int mediano(std::vector<int> v) {
    for (int i = 0; i < v.size() / 2; ++i) {
        int m = massimo(v);
        v.at(m) = -1;
    }
    int med = massimo(v);
    return v.at(med);
}

int main() {
    const int N = 100;
    std::vector<int> v;
    riempi(v, N);
    std::cout << "Il mediano è " << mediano(v) << std::endl;
    return 0;
}