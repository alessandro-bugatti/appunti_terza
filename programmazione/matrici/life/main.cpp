#include <iostream>

using namespace std;

const int DIM = 20;

void inizializza(int m[][DIM],int r, int c)
{
    for(int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            m[i][j] = 0;

    //Riproduciamo la situazione del libro
    for (int i = 0; i < 3; i++)
        m[i+3][13] = 1;
    for (int i = 10; i < 12 ; i++)
        for (int j = 3; j < 6; j++)
            m[i][j] = 1;
    for (int i = 13; i < 16 ; i++)
        for (int j = 11; j < 14; j++)
            m[i][j] = 1;
}

void stampa(int m[][DIM], int r, int c)
{
    for (int i = 0; i < r ; i++)
    {
        for (int j = 0; j < c; j++)
            cout << m[i][j] << " ";
        cout << endl;
    }
}

int main()
{
    int life[DIM][DIM];
    inizializza(life, DIM ,DIM);
    stampa(life, DIM, DIM);
    return 0;
}
