//Autore: Medici Manuel

#include <iostream>

using namespace std;
void media_tre_punti(float v[], float v_medio[], int lunghezza)
{
    v_medio[0] = (v[0]*2 + v[1])/3;
    v_medio[lunghezza-1] = (v[lunghezza-1]*2 + v[lunghezza-2])/3;
    for(int i = 1; i < lunghezza-1; i++)
    {
        v_medio[i] = (v[i-1] + v[i] + v[i+1])/3;
    }
}
int main()
{
    const int lunghezza = 5;
    float valore, v[lunghezza],v_medio[lunghezza];
    for(int i = 0; i< lunghezza; i++)
    {
//    cout << "inserisci il valore nella "<<i+1<<" posizione: ";
//    cin >> valore;
//    v[i] = valore;
        v[i] = rand()%100;
        cout << v[i] << endl;
     }
    media_tre_punti(v, v_medio, lunghezza);
    cout << "Dopo la media: " << endl;
    for(int i = 0; i< lunghezza; i++)
        cout<<v_medio[i]<<endl;
    return 0;
}
