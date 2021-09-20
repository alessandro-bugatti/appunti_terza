/*
Data l'altezza iniziale di un'onda,
e considerando che ogni kilometro diminuisce del 10%
stabilire dopo quanti kilometri divenda più bassa di un centimetro
*/

#include <iostream>

using namespace std;

int main()
{
    //Dichiarazione delle variabile
    float altezza;
    int kilometri = 0; //Inizializzazione a zero
    //cout << kilometri << endl;
    cout << "Inserisci l'altezza in metri: ";
    cin >> altezza;
    while (altezza >= 0.01)
    {

        altezza = altezza * 0.9; //altezza *= 0.9;
        kilometri++; //kilometri = kilometri + 1;
        cout << "Dopo " << kilometri << " kilometri l'altezza è diventata di "
            << altezza*100 << " centimetri." << endl;
    }
    cout << "L'onda finisce dopo " << kilometri << " chilometri.";
    cout << "L'altezza diventa " << altezza << endl;
    return 0;
}








