#include <iostream>

using namespace std;

int main()
{
    const int MAX_ABITI = 1000;
    int altezze[MAX_ABITI];
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> altezze[i];
    //Primo problema: trovare il massimo delle altezze
    int massimo = altezze[0];
    for (int i = 0; i < N; i++)
    {
        if (altezze[i] > massimo)
            massimo = altezze[i];
    }
    //Seconda parte: stampare quali abiti sono stati indossati
    //dal modello di altezza massima
    for (int i = 0; i < N; i++)
    {
        if (altezze[i] == massimo)
            cout << i + 1<< endl;
    }
    return 0;
}
