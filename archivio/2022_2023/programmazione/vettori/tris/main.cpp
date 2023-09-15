#include <iostream>

const int N = 3;

char caratteri(int c){
    if (c == 0)
        return ' ';
    if (c == 1)
        return 'X';
    return 'O';
}

/*
 * O | X | O
 * _________
 * X | X |
 * ---------
 * O |   |
 */

void stampa(int tris[][N]){
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            std::cout << " " << caratteri(tris[i][j]) << " ";
            if (j < 2)
                std::cout << "|";
        }
        std::cout << std::endl;
        if (i < 2)
            std::cout << "-----------" << std::endl;
    }
}

/**
 * Funzione che inserisce una mossa, se valida
 * @param tris La matrice del tris
 * @param r la riga dove voglio inserire, prima riga 0
 * @param c la colonna dove voglio inserire, prima colonna 0
 * @param giocatore 1 o 2
 * @return true se la mossa è valida, e quindi viene fatta, false altrimenti
 */
bool fai_mossa(int tris[][N],int r, int c, int giocatore){
    if (r < 0 || r > 2)
        return false;
    if (c < 0 || c > 2)
        return false;
    if (tris[r][c] != 0)
        return false;
    tris[r][c] = giocatore;
    return true;
}

/**
 *
 * @param tris
 * @return 1 se vince il giocatore 1
 *  2 se vince il giocatore 2
 *  3 patta
 *  0 partita in corso
 */
int verifica_stato(int tris[][N]){
    //controllo delle righe
    for (int i = 0; i < N; ++i) {
        if(tris[i][0] == tris[i][1] && tris[i][0] == tris[i][2])
            return tris[i][0];
    }
    //controllo delle colonne
    for (int i = 0; i < N; ++i) {
        if(tris[0][i] == tris[1][i] && tris[0][i] == tris[2][i])
            return tris[0][i];
    }
    if (tris[0][0] == tris[1][1] && tris[1][1] == tris[2][2])
        return tris[1][1];
    if (tris[0][2] == tris[1][1] && tris[1][1] == tris[2][0])
        return tris[1][1];
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (tris[i][j] == 0)
                return 0;
        }
    }
    return 3;
}

int main() {

    //0 casella vuota
    //1 giocatore 1
    //2 giocatore 2
    int tris[N][N];
    //Azzero la matrice
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            tris[i][j] = 0;
        }
    }
    //tris[0][1] = 1;
    //tris[1][0] = 2;
    stampa(tris);

    int giocatore = 1;
    int r, c;
    while(verifica_stato(tris) == 0){
        //Input del giocatore corrente
        std::cout << "Giocatore " << giocatore << " fai la tua mossa: " << std::endl;
        std::cout << "Inserisci la riga (1-3): ";
        std::cin >> r;
        std::cout << "Inserisci la colonna (1-3): ";
        std::cin >> c;
        //Verifica della mossa e eventuale ripetizione dell'input
        while(!fai_mossa(tris, r - 1, c - 1, giocatore)){
            std::cout << "Attenzione " << giocatore << " hai sbagliato, rifai la tua mossa: " << std::endl;
            std::cout << "Inserisci la riga (1-3): ";
            std::cin >> r;
            std::cout << "Inserisci la colonna (1-3): ";
            std::cin >> c;
        }
        stampa(tris);
        //cambio turno
        if (giocatore == 1)
            giocatore = 2;
        else
            giocatore = 1;
    }
    int risultato = verifica_stato(tris);
    if (risultato == 3){
        std::cout << "Patta" << std::endl;
    }
    else {
        std::cout << "Ha vinto il giocatore " << risultato << std::endl;
    }

    return 0;
}
