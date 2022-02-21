#include <iostream>

using namespace std;

const int N = 3;
/**
 * Resetta la griglia del tris mettendo 0 in ogni casella
 * @param m La griglia del tris
 * @param r Numero di righe, che sarà sempre 3
 */
void resetta(int m[][N], int r)
{
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < N; ++j) {
            m[i][j] = 0;
        }
    }
}

char mappa(int n){
    if (n == 0)
        return ' ';
    if (n == 1)
        return 'o';
    if (n == 2)
        return 'x';
}

/**
 * Stampa della griglia
 * @param m
 * @param r
    | x | o
  ---------
  x | o |
  ---------
  x | o | x
 */
void stampa(int m[][N], int r)
{
    for (int i = 0; i < r; ++i) {
        cout << mappa(m[i][0]) << " ";
        for (int j = 1 ; j < N; ++j) {
            cout << "| " << mappa(m[i][j]) << " ";
        }
        cout << endl;
        if (i < 2)
            cout << "----------" << endl;

    }
}

bool inserisci(int m[][N], int r, int riga, int colonna, int giocatore)
{
    if (riga < 0)
        return false;
    if (riga >= r)
        return false;
    if (colonna < 0)
        return false;
    if (colonna >= N)
        return false;
    if (m[riga][colonna] != 0)
        return false;
    m[riga][colonna] = giocatore;
    return true;
}

void cambia_giocatore(int &giocatore)
{
    if (giocatore == 1)
        giocatore = 2;
    else
        giocatore = 1;
}

int main() {
    int tris[N][N];
    int giocatore = 1;

    resetta(tris, N);
    stampa(tris, N);
    while(1)
    {
        int riga, colonna;
        cout << "Giocatore " << giocatore << " tocca a te." << endl;
        cout << "Inserisci la riga: ";
        cin >> riga;
        cout << "Inserisci la colonna:";
        cin >> colonna;
        while(inserisci(tris, N, riga - 1, colonna - 1, giocatore) != true)
        {
            cout << "Hai sbagliato, rifai" << endl;
            cout << "Inserisci la riga: ";
            cin >> riga;
            cout << "Inserisci la colonna:";
            cin >> colonna;
        }
        stampa(tris, N);
        cambia_giocatore(giocatore);
    }

    stampa(tris, N);
    return 0;
}
