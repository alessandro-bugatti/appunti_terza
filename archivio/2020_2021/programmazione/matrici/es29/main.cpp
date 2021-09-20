#include <iostream>

using namespace std;

const int N = 3;

//Ricordarsi che quando si usano le matrici come
//parametro bisogna indicare il numero di colonne
//mentre il numero di righe è un parametro
bool verifica_simmetria(int m[][N], int n)
{
    for(int i = 0;i<n; i++)
        for (int j = i + 1; j < N; j++)
            if (m[i][j] != m[j][i])
                return false;
    return true;
}

int main()
{
    int v[]= {2,3,4,5};
    int m[][N] = {
        {2,3,4},
        {3,3,5},
        {4,5,4},
        {4,5,4}
    };
    if(verifica_simmetria(m, N))
        cout<< "Simmetrica" << endl;
    else
        cout << "Non simmetrica" << endl;
    return 0;
}
