#include <iostream>

const int R = 10;
const int C = 8;

/**
 * Inizilizza la matrice m con il 50%
 * di celle vive e il 50% di celle morte
 * distribuite in maniera casuale
 * @param m la matrice da inizializzare
 */
void inizializza(bool m[R][C]) {
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            if (rand() % 2 == 1) {
                m[i][j] = true;
            }
            else {
                m[i][j] = false;
            }
        }
    }
}
/**
 * Controlla il numero di celle vive
 * intorno alla cella in posizione r, c
 * @param m la matrice da controllare
 * @param r la riga della casella centrale
 * @param c la colonna della casella centrale
 * @return il numero di celle vive
 */
int quante_vive(bool m[R][C], int r, int c) {
    int conta = 0;
    for (int i = -1; i <= 1; ++i) {
        for (int j = -1; j <= 1 ; ++j) {
            if (m[r + i][c + j] == true && !(i == 0 && j == 0)) {
                conta++;
            }
        }
    }
    return conta;
}

void stampa(bool m[R][C]) {
    std::cout << "Tabella" << std::endl;
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            std::cout << m[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

/**
 * Fa evolvere la matrice m secondo
 * le regole del gioco Life di Conway
 * @param m La matrice di stato del gioco
 */
void evolvi(bool m[R][C]) {
    bool temp[R][C];
    for (int i = 1; i < R - 1; ++i) {
        for (int j = 1; j < C - 1; ++j) {
            int vive = quante_vive(m, i, j);
            if (m[i][j] == true && (vive == 2 || vive == 3)) {
                temp[i][j] = true;
            }
            else if (m[i][j] == true && vive < 2) {
                temp[i][j] = false;
            }
            else if (m[i][j] == true && vive > 3) {
                temp[i][j] = false;
            }
            else if (m[i][j] == false && vive == 3) {
                temp[i][j] = true;
            }
            else {
                temp[i][j] = false;
            }
        }
    }
    //Qui va la copia dei valori di temp in m
    for (int i = 1; i < R - 1; ++i) {
        for (int j = 1; j < C - 1; ++j) {
            m[i][j] = temp[i][j];
        }
    }
}

int main() {
    bool mappa[R][C];
    inizializza(mappa);
    //La chiamata a questa funzione sarà
    //all'interno di un ciclo
    stampa(mappa);
    for (int i = 0; i < 5; ++i) {

        evolvi(mappa);
        stampa(mappa);
    }
    return 0;
}