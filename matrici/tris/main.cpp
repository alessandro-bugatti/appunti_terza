#include <iostream>

const int DIM = 3;

void azzeramento(int tris[][DIM]) {
    for (int i = 0; i < DIM; i++) {
        for (int j = 0; j < DIM; j++) {
            tris[i][j] = 0;
        }
    }
}

char mappa(int valore) {
    if (valore == 1) {
        return 'X';
    } else if (valore == 2) {
        return 'O';
    } else {
        return ' ';
    }
}

bool controllaPosizione(int tris[][DIM], int riga, int colonna) {
    if (riga < 0 || riga >= DIM || colonna < 0 || colonna >= DIM) {
        return false; // fuori dai limiti
    }
    if (tris[riga][colonna] != 0) {
        return false; // casella già occupata
    }
    return true; // posizione valida
}

int controllaVittoria(int tris[][DIM]) {
    // Controlla righe
    for (int i = 0; i < DIM; i++) {
        if (tris[i][0] != 0 && tris[i][0] == tris[i][1] && tris[i][1] == tris[i][2]) {
            return tris[i][0]; // vittoria del giocatore
        }
    }
    // Controlla colonne
    for (int j = 0; j < DIM; j++) {
        if (tris[0][j] != 0 && tris[0][j] == tris[1][j] && tris[1][j] == tris[2][j]) {
            return tris[0][j]; // vittoria del giocatore
        }
    }
    // Controlla diagonali
    if (tris[0][0] != 0 && tris[0][0] == tris[1][1] && tris[1][1] == tris[2][2]) {
        return tris[0][0]; // vittoria del giocatore
    }
    if (tris[0][2] != 0 && tris[0][2] == tris[1][1] && tris[1][1] == tris[2][0]) {
        return tris[0][2]; // vittoria del giocatore
    }
    return 0; // nessun vincitore
}

void stampa(int tris[][DIM]) {
    for (int i = 0; i < DIM; i++) {
        for (int j = 0; j < DIM; j++) {
            std::cout << mappa(tris[i][j]);
            if (j < DIM - 1) {
                std::cout << " | ";
            }
        }
        std::cout << std::endl;
        if (i < DIM - 1) {
            std::cout << "---------" << std::endl;
        }
    }
}

int main() {


    /*
     * 1 - giocatore 1
     * 2 - giocatore 2
     * 0 - casella vuota
     */
    int tris[DIM][DIM];
    int mosse = 0, giocatore = 1;
    azzeramento(tris);

    //tris[1][1] = 1; // giocatore 1
    stampa(tris);

    while (mosse < DIM * DIM && controllaVittoria(tris) == 0) {
        int riga, colonna;
        std::cout << "Giocatore " << giocatore << ", inserisci riga e colonna (0-2): ";
        std::cin >> riga >> colonna;

        if (controllaPosizione(tris, riga, colonna)) {
            tris[riga][colonna] = giocatore;
            mosse++;
            stampa(tris);
            if (controllaVittoria(tris) == giocatore) {
                std::cout << "Giocatore " << giocatore << " vince!" << std::endl;
                break;
            }
            if (giocatore == 1) {
                // cambia giocatore
                giocatore = 2;
            } else {
                giocatore = 1;
            }
        } else {
            std::cout << "Posizione non valida. Riprova." << std::endl;
        }

    }

    if (mosse == DIM * DIM && controllaVittoria(tris) == 0) {
        std::cout << "Pareggio!" << std::endl;
    }

    return 0;
}