#include <iostream>

using namespace std;

//Esercizio 1
void Tabellina(int N)
{
    const int limite = 10;
    int prodotto;
    int i;
    for (i = 1; i <= limite; ++i) {
        prodotto = i * N;
        cout << prodotto << " ";
    }
}

//Esercizio 2

double pendolo(double P){
    const double g = 9.81;
    const double PI = 3.1415;
    double L = g * (P*P) / (4*PI*PI);
    return L;
}

//Esercizio 3
int Mediano(int a, int b, int c)
{
    if (a <= b && a >= c)
        return a;
    //CI sono altri 5 if con le altre possibilità
}

//Esercizio 4

bool primi(int a, int b)
{
    //Il limite del ciclo sarebbe meglio impostarlo
    //al minore dei due parametri, ma anche uno a caso,
    //in questo caso a, produce il risultato corretto
    for (int i = 2; i <= a; ++i) {
        if(a % i == 0 && b % i == 0)
            return false;
    }
    return true;
}

//Esercizio 5
void terne(int N)
{
    for (int i = 1; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) {
            for (int k = j + 1; k < N; ++k) {
                if (i * i + j * j == k * k)
                    cout << "(" << i << "," << j << "," << k << ")" << endl;
            }

        }

    }
}

int fattoriale(int N)
{
    int f = 1;
    for (int i = 1; i <= N; ++i) {
        f *= i;
    }
    return f;
}

double e(int N)
{
    double risultato = 1;
    for (int i = 1; i < N ; ++i) {
        risultato += 1.0/ fattoriale(i);
    }
    return risultato;
}

int main() {
    //Qui si può scrivere qualcosa per testare le funzioni,
    //ma non è richiesto nel compito
    return 0;
}
