#include <iostream>

using namespace std;

const int N = 100;

int m[N][N];

int main()
{
    int R, C;
    //ASSOLUTAMENTE NO ALTRO OUTPUT QUANDO FATE
    //PROBLEMI CON IL CORRETTORE
    //cout << "Inserisci le righe e le colonne: ";
    cin >> R >> C;
    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
            cin >> m[i][j];
    /*Soluzione che prende metà del punteggio
    int r_minore;
    if (m[0][0] + m[0][1] < m[1][0] + m[1][1])
        r_minore = 0;
    else
        r_minore = 1;

    int c_minore;
    if (m[0][0] + m[1][0] < m[0][1] + m[1][1])
        c_minore = 0;
    else
        c_minore = 1;
    cout << r_minore + 1 << " "  << c_minore + 1 << endl;
    */
    //Trovo la riga minore
    int r_minore = 0;
    int minore = 0;
    //Inizializziamo il minore
    for (int i = 0; i < C; i++)
        minore += m[0][i];
    //Ricerca della riga di somma minima
    for (int i = 0; i < R; i++)
    {
        int somma = 0;
        for (int j = 0; j < C; j++)
            somma += m[i][j];
        if (somma < minore)
        {
            minore = somma;
            r_minore = i;
        }
    }
    //Trovo la colonna minore
    int c_minore = 0;
    minore = 0;
    //Inizializziamo il minore
    for (int i = 0; i < R; i++)
        minore += m[i][0];
    //Ricerca della colonna di somma minima
    for (int i = 0; i < C; i++)
    {
        int somma = 0;
        for (int j = 0; j < R; j++)
            somma += m[j][i];
        if (somma < minore)
        {
            minore = somma;
            c_minore = i;
        }
    }
    cout << r_minore + 1 << " "  << c_minore + 1 << endl;

    return 0;
}
