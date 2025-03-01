#include <iostream>

const int DIM = 3;

void riempi (int tris[][DIM]){
    for (int i=0; i<DIM; ++i){
        for (int j=0; j<DIM; ++j){
            tris[i][j]=0;
        }
    }
}

char converti(int n) {
    if (n == 1) {
        return 'X';
    }
    if (n == 2) {
        return 'O';
    }
    return ' ';
}

bool mossa_valida(int tris[][DIM], int r, int c) {
    if (r < 0 || r >= DIM)
        return false;
    if (c < 0 || c >= DIM)
        return false;
    if (tris[r][c] != 0)
        return false;
    return true;
}

void stampa(int tris[][DIM]) {
    for (int i = 0; i < DIM; ++i) {
        for (int j = 0; j < DIM; ++j) {
            std::cout << " " << converti(tris[i][j]) << " ";
            if (j != DIM - 1) {
                std::cout << "|";
            }
        }
        std::cout << std::endl;
        if (i != DIM - 1) {
            for (int j = 0; j < DIM*4 - 1; ++j) {
                std::cout << "-";
            }
            std::cout << std::endl;
        }
    }
}

int verifica_stato(int tris[][DIM]) {

    //Controlla le righe, se c'è un tris ritorna il
    //valore del giocatore che l'ha fatto
    for (int i = 0; i < DIM; ++i) {
        if (tris[i][0] == tris[i][1] &&
            tris[i][1]== tris[i][2] &&
            tris[i][0] != 0){
        return tris[i][0];
        }
    }
    //Controlla le colonne, se c'è un tris ritorna il
    //valore del giocatore che l'ha fatto
    for (int i = 0; i < DIM; ++i) {
        if (tris[0][i] == tris[1][i] &&
            tris[1][i]== tris[2][i] &&
            tris[0][i] != 0){
            return tris[0][i];
            }
    }
    //Prima diagonale
    if (tris[0][0] == tris[1][1] &&
            tris[1][1]== tris[2][2] &&
            tris[0][0] != 0){
            return tris[0][0];
    }
    //Prima diagonale
    if (tris[0][2] == tris[1][1] &&
            tris[1][1]== tris[2][0] &&
            tris[0][2] != 0){
                return tris[0][2];
            }
    for (int i = 0; i < DIM; ++i) {
        for (int j = 0; j < DIM; ++j) {
            if (tris[i][j] == 0){
                return 0;
            }
        }
    }
    return 3; //pareggio
}

int main() {
    int tris[DIM][DIM];
    riempi (tris);
    /*
    stampa(tris);
    tris[1][1] = 1;
    tris[1][2] = 2;
    stampa(tris);
    std::cout << verifica_stato(tris) << std::endl;
    tris[0][1] = 1;
    tris[2][1] = 1;
    stampa(tris);
    std::cout << verifica_stato(tris) << std::endl;*/
    std::cout << "GIOCO DEL TRIS"<< std::endl;
    int stato = verifica_stato(tris);
    int giocatore = 1;
    while (stato == 0) {
        int r, c;
        stampa(tris);
        std::cout << "Turno del giocatore " << giocatore << std::en3
        dl;
        std::cout << "Inserisci la riga (1-3): ";
        std::cin >> r;
        std::cout << "Inserisci la colonna (1-3): ";
        std::cin >> c;
        while (mossa_valida(tris, r - 1, c - 1) == false) {
            std::cout << "Attenzione, la mossa inserita non è valida" << std::endl;
            std::cout << "Inserisci la riga (1-3): ";
            std::cin >> r;
            std::cout << "Inserisci la colonna (1-3): ";
            std::cin >> c;
        }
        tris[r - 1][c - 1] = giocatore;
        if (giocatore == 1) {
            giocatore = 2;
        }
        else {
            giocatore = 1;
        }
        stato = verifica_stato(tris);
    }
    stampa(tris);
    if (stato == 1) {
        std::cout << "Vince il giocatore 1" << std::endl;
    }
    else if (stato == 2) {
        std::cout << "Vince il giocatore 2" << std::endl;
    }
    else {
        std::cout << "Pareggio" << std::endl;
    }

    return 0;
}