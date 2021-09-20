#include <iostream>

using namespace std;

//Dimensioni della matrice
const int N = 4, M = 3;

int massimo(int m[][M], int n_righe, int &riga, int &colonna)
{
    riga = colonna = 0;
    int massimo_attuale = m[riga][colonna];
    for (int i = 0; i < n_righe; i++)
    {
        for (int j = 0; j < M; j++)
            if (m[i][j] > massimo_attuale)
            {
                massimo_attuale = m[i][j];
                riga = i;
                colonna = j;
            }
    }
    return massimo_attuale;
}

int main()
{

    //Dichiarazione della matrice
    int matrice[N][M];
    int riga, colonna, elemento_massimo;
    //IL ciclo esterno seleziona una riga
    for (int i = 0; i < N; i++)
    {
        //Il ciclo interno valora sulla riga selezionata
        //e si muove sulle colonne
        for (int j = 0; j < M; j++)
        {
            matrice[i][j] = rand()%100;
            cout << matrice[i][j] << "  ";
        }
        cout << endl;
    }
    elemento_massimo = massimo(matrice, N, riga, colonna);
    cout << "L'elemento massimo vale " << elemento_massimo
        << " che si trova in posizione " << riga <<
        " - " << colonna << endl;
    return 0;
}
