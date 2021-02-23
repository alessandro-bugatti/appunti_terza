#include <iostream>

using namespace std;

//Devo sapere la dimensione massima della matrice. Come?
//O me lo dice esplicitamente il testo del problema
//oppure lo deduco io dal contesto
const int MAX_R = 10;
const int MAX_C = 15;
//Se fosse quadrata me ne basterebbe uno solo
//const int MAX_DIM = 10;

//Il passaggio di matrice è brutto,
//bisogna per forza indicare il numero fisso di colonne
//e poi si passano il numero effettivo di righe e di colonne
int somma(int m[][MAX_C], int righe, int colonne)
{
    //algoritmo
}

int main()
{
    //In dichiarazione la matrice "fisicamente"
    //assume la dimensione MAX_R x MAX_C
    int m[MAX_R][MAX_C];

    //INserimento dei valori: ci sono due casi
    //Primo caso, la voglio utilizzare tutta, è quello
    //meno frequente
//    for (int i = 0; i < MAX_R; i++)
//        for (int j = 0; j < MAX_C; j++)
//        //Dipende dal testo
//            m[i][j] = rand()%1000;
//
    //Secondo caso, tipico dei problemi con il correttore
    //In input vi viene detta la parte di matrice che
    //conterrà i valori
    int R, C;
    //int m[R][C]; NOOOOO, sbagliato
    cin >> R >> C;
    //Ovviamente se fossero maggiori di MAX_R e MAX_C
    //sarebbe un problema, nei nostri problemi si suppone
    //siano valori validi
    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
        //Dipende dal testo
            m[i][j] = rand()%1000;
    //Si prosegue con l'algoritmo


    //Se chiamo la funzione definita sopra,
    //Primo caso
    // int s = somma(m, MAX_R, MAX_C);
    //Secondo caso
    int s = somma(m, R, C);

    return 0;
}
