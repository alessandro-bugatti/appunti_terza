#include <iostream>
// Riccardo Cadenelli 3AI
using namespace std;

int copia_intervallo(int V[], int n, int V_2[],
                     int minimo, int massimo)
 {
     int copiati = 0;
     for(int j = 0; j < n; j ++)
     {
          if(V[j] < massimo && V[j] > minimo)
          {
              V_2[copiati] = V[j];
              copiati++;
          }
     }
     return copiati;

 }


int main()
{
    const int N = 10;
    int minimo, massimo;
    int V[N], V_2[N];
    cout << "Inserisci il valore minimo e massimo" << endl;
    cin >> minimo >> massimo;
    for(int i = 0; i < N; i++)
    {
        V[i] = rand()%100;
    }
    cout << "Primo vettore: " << V[0];
    for(int i = 1; i < N; i++)
        cout << " - " << V[i];
    int copiati = copia_intervallo(V, N, V_2, minimo, massimo);
    if (copiati > 0)
        cout << endl << "Secondo vettore: " << V_2[0];
    else
        cout << endl << "Il secondo vettore è vuoto" << endl;
    for(int i = 1; i < copiati; i++)
        cout << "  -  " << V_2[i] ;
    return 0;
}

