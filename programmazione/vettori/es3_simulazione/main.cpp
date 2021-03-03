#include <iostream>

using namespace std;

int main()
{
    //Questa è la richiesta dell'esercizio
//    const int N = 1000;
//    int v[N];
//    for (int i = 0; i < N; i++)
//        v[i] = rand()%20 - 10;

    //Così lo facciamo noi per testare
    int v[] = {2, -3, 7, 9, 4, 12, -2, -5, 2, 9, 13, -9, 8, 6, 56};
    int N = sizeof(v)/sizeof(int);
    //Contatore che serve a contare i positivi consecutivi
    int cont = 0;
    for (int i = 0; i < N; i++)
    {
        //Soluzione non corretta, ma che contiene
        //dei germogli di un'idea corretta
        //if (v[i] > 0 && v[i+1] > 0 && v[i+2] > 0)
        //    cout << v[i] << " " << v[i+1] << " "
        //    << v[i+2] << " ";
        if (v[i] > 0)
        {
            //Incremento il contatore per tenere conto della
            //lunghezza della sequenza di positivi consecutivi
            cont++;
        }
        else
        {
            //Verifico se la sequenza trovata finora è più
            //lunga o almeno uguale a 3
            if (cont >= 3)
            {
                for (int j = i - cont; j < i; j++)
                    cout << v[j] << " ";
            }
            //Azzero il contatore perchè la sequenza è finita
            cont = 0;
        }
    }

    //Stampa un'eventuale cosa di positivi consecutivi
    //Questo ultimo pezzo valeva 0.25 punti perchè era difficile
    //da notare
    if (cont >= 3)
    {
        for (int j = N - cont; j < N; j++)
            cout << v[j] << " ";
    }
    return 0;
}
