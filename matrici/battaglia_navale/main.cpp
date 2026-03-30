#include <iostream>
#include <vector>

const int DIM = 10;

bool inserisci_nave(int m[][DIM], int lunghezza, int direzione,
                int r, int c) {
    //Controllo se esco dalla matrice
    //Bordo in alto
    if (direzione == 1 && r - lunghezza < 0) {
        return false;
    }

    //Controllo di non sovrapposizione
    //Direzione alto
    if (direzione == 1) {
        for (int i = 0; i < lunghezza; ++i) {
            if (m[r - i][c] == 1) {
                return false;
            }
        }
    }


    return true;
}

int main() {
    std::vector<int> l_navi = {
        2, 2, 3, 3, 4, 5
    };
    int griglia[DIM][DIM] = {0};
    for (int i = 0; i < l_navi.size(); ++i) {
        std::cout << "Inserisci una nave da " <<
            l_navi.at(i) << " : ";
        int r, c, direzione;
        std::cout << "Inserisci le coordinate r e c:";
        std::cin >> r >> c;
        std::cout << "Inserisci la direzione (1 - alto, 2 - destra, 3 - basso, 4 - sinistra: ";
        std::cin >> direzione;
        inserisci_nave(griglia, l_navi.at(i), direzione, r, c);
    }

    return 0;
}
