#include <iostream>
#include <set>
#include <vector>

/**
 *
 * @param v vettore da modificare eliminando i numeri non primi
 */
void crivello(std::vector<int> &v) {
    for (int i = 0; i <= v.size() / 2; ++i) {
        int pos_attuale = i;
        if (v.at(pos_attuale) != -1) {
            int val_attuale = v.at(pos_attuale);
            for (int j = pos_attuale + val_attuale; j < v.size(); j += val_attuale) {
                v.at(j) = -1;
            }
        }
    }
}

int main() {
    std::vector<int> setaccio;
    int n;
    std::cout << "Inserisci n: ";
    std::cin >> n;
    //Inserimento dei numeri
    for (int i = 2; i <= n; ++i) {
        setaccio.push_back(i);
    }
    crivello(setaccio);
    for (int i = 0; i < setaccio.size(); ++i) {
        if (setaccio.at(i) != -1) {
            std::cout << setaccio.at(i) << " ";
        }
    }
    std::cout << std::endl;
    return 0;
}
