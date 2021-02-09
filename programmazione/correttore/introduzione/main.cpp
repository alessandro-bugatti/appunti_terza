#include <iostream>

using namespace std;

//Esempio di soluzione di un programma al correttore
//http://80.211.111.61

int main()
{
    //MAI MAI MAI usare dell'output per chiedere qualcosa
    //all'utente

    //NO NO NO
    //cout << "Inserisci un numero" << endl;
    int N, M;
    int S, K;

    //Input: quello che dichiara il problema
    cin >> N >> M;
    //cin >> N;
    //cin >> M; uguale
    S = N + M;
    //Prima situazione: non so distinguere i pari dai dispari
    if (S % 2 == 0)
        K = N * M;
    else
        K = N - M;

    //Output preciso come richiesto
    cout << S << " " << K << endl;
    return 0;
}
