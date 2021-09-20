#include <iostream>

using namespace std;

const int N = 3;

bool predominanza(int m[][N], int r)
{
    for (int i = 0; i < r; i++)
    {
        //Controllo della riga i-esima
        int maggiore = m[i][i];
        for(int j = 0; j < N; j++)
            if (i != j && maggiore <= m[i][j])
                return false;

    }
    return true;
}

void stampa(int m[][N], int r)
{
    for (int i = 0; i < r; i++)
    {
        for(int j = 0; j < N; j++)
            cout << m[i][j] << " ";
        cout << endl;
    }
}

int main()
{
    int m[][N] = {
        {13,5,7},
        {3,15,7},
        {3,15,7}
    };
    stampa(m, N);
    if (predominanza(m, N) == true)
        cout << "La matrice è a predominanza diagonale " << endl;
    else
        cout << "La matrice non è a predominanza diagonale " << endl;
    m[2][2] = 23;
    stampa(m, N);
    if (predominanza(m, N) == true)
        cout << "La matrice è a predominanza diagonale " << endl;
    else
        cout << "La matrice non è a predominanza diagonale " << endl;

    return 0;
}
