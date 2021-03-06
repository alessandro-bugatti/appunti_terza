#include <iostream>

using namespace std;

const int MAX_DIM = 100;

int min_somma_riga(int m[][MAX_DIM], int R, int C)
{
   int minimo = 0;
   int indice_minimo = 0;
   for (int i = 0; i < C; i++)
        minimo += m[0][i];
   for (int i = 0; i < R; i++){
        int somma = 0;
        for (int j = 0; j < C; j++)
        {
            somma += m[i][j];
        }
        if (somma < minimo)
        {
            minimo = somma;
            indice_minimo = i;
        }
    }
    return indice_minimo;
}

int main()
{

    int griglia[MAX_DIM][MAX_DIM];
    int R, C;
    //Lettura dei valori
    cin >> R >> C;
    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
            cin >> griglia[i][j];

    return 0;
}
