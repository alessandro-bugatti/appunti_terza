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

int regole(int m[][DIM], int i, int j)
{
    int stato = m[i][j];
    int n_vicini_vivi = 0;
    //Possibilità Scolari
    for (int r = i - 1; r <= i + 1; r++)
        for (int s = j - 1; s <= j + 1; s++)
            //Esclude la casella centrale
            if (!(r == i && s == j)) //i = 10, j = 10, r = 10, s = 10
                if (m[r][s] == 1)
                    n_vicini_vivi++;
    //Possibilità Leporati
//    n_vicini_vivi += m[i-1][j-1];
//    n_vicini_vivi += m[i-1][j];
//    n_vicini_vivi += m[i-1][j+1];
//    ecc. ecc.
    //Se volessi togliere l'if che esclude la casella centrale
    //basterebbe mettere
    //n_vicini_vivi -= stato;

    //Cella morta con 3 vicini -> cella viva
    if ( stato == 0 && n_vicini_vivi == 3)
        return 1;
    //Cella viva con 2 o 3 vicini -> cella viva
    if (stato == 1 && (n_vicini_vivi == 2 || n_vicini_vivi == 3))
        return 1;
    //Cella viva con meno di 2 vicini o più di 3 vicini -> cella morta
    if (stato == 1 && (n_vicini_vivi < 2 || n_vicini_vivi > 3))
        return 0;
    return 0;
}

void evolvi(int m[][DIM], int a[][DIM], int r, int c)
{
    //Esploriamo tutta la matrice
    for (int i = 1; i < r - 1; i++)
        for (int j = 1; j < c - 1; j++)
    {
        a[i][j] = regole(m, i, j);
    }
    //NOOOOOOOO
    //m = a;

    //Ricopio i valori di a nella matrice originale m
    for (int i = 1; i < r - 1; i++)
        for (int j = 1; j < c - 1; j++)
            m[i][j] = a[i][j];
}

int main()
{
    int life[DIM][DIM];
    int appoggio[DIM][DIM];
    //Esempio con le prime due situazioni
    inizializza(life, DIM ,DIM);
    inizializza(appoggio, DIM, DIM);
    cout << "Situazione iniziale" << endl;
    stampa(life, DIM, DIM);
    cout << "Primo passo" << endl;
    evolvi(life, appoggio, DIM, DIM);
    stampa(appoggio, DIM, DIM);
    //Avanzamento manuale della simulazione
    //Riparto da capo
    inizializza(life, DIM ,DIM);
    inizializza(appoggio, DIM, DIM);
    int avanza = 1;
    int passi = 0;
    while (avanza == 1)
    {
        cout << "Passo: " << passi << endl;
        stampa(life, DIM, DIM);
        cout << "Inserisci 1 per continuare, 0 per terminare" << endl;
        cin >> avanza;
        evolvi(life, appoggio, DIM, DIM);
        passi++;
    }
    return 0;
}
