#include <iostream>

using namespace std;

const int N = 3;

void azzera_tris(int m[][N], int n)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < N; j++)
            m[i][j] = 0;
}

char converti(int n)
{
    if (n == 1)
        return 'x';
    if (n == 2)
        return 'o';
    if (n == 0)
        return ' ';
}

void visualizza_tris(int m[][N], int n)
{
    /*

    x |   | o
    ---------
    o | x | x
    ---------
      |   | o
    */
    for (int i = 0 ; i < n; i++)
    {

        for (int j = 0 ; j < N; j++)
            cout << converti(m[i][j]);
        cout << endl;
    }

    //Da completare per far apparire il disegno in figura
}

//Ritorna 1 se ha vinto il giocatore 1
//Ritorna 2 se ha vinto il giocatore 2

int controllo(int m[][N], int n)
{
    /*
    if (m[0][0] == 1 && m[0][1] == 1 && m[0][2] == 1)
        return 1;
    if (m[0][0] == 2 && m[0][1] == 2 && m[0][2] == 2)
        return 2;
    */

    //Controlliamo le prime tre righe
    for (int i = 0; i < n; i++)
    {
        if (m[i][0] == m[i][1] && m[i][1] == m[i][2] &&
            m[i][0] != 0)
        return m[i][0];
    }

    //Da completare per il controllo delle colonne e delle diagonali
}

int main()
{
    //Matrice che rappresenta la griglia del tris
    int tris[N][N];
    azzera_tris(tris, N);
    tris[0][0] = 1;
    tris[0][2] = 2;
    tris[1][0] = 2;
    tris[1][1] = 1;
    tris[1][2] = 1;
    tris[2][2] = 2;
    visualizza_tris(tris, N);

    /*
    Da completare per far giocare due giocatori a turni
    Ad ogni turno il giocatore dice le coordinate di dove
    vuole piazzare il proprio simbolo, viene fatto un controllo
    per evitare che la inserisca al di fuori della griglia o
    in una casella già occupata, una volta inserito il simbolo
    si controlla se c'è stato un tris e nel caso si termina
    la partita proclamando il vincitore, altrimenti si continua
    fino a quando la griglia non si riempe senza che ci siano stati
    tris, nel qual caso è patta
    */
    return 0;
}
