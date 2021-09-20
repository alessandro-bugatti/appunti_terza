#include <iostream>

using namespace std;
//numeri_giri = n;
//diametro = d;
float tachimetro(int numero_giri, float diametro)
{
    float vel_metri_minuto, vel_kilometri_ora;
    vel_metri_minuto = 3.1416*diametro*numero_giri*6;
    vel_kilometri_ora = vel_metri_minuto/1000*60;
    return vel_kilometri_ora; //ritorno il risultato
    //return diametro*numero_giri*1.0917;
}
//vel = vel_kilometri_ora;

int main()
{
    float vel;
    int n;
    float d;
    cout << "Inserisci il numero di giri: ";
    cin >> n;
    cout << "Inserisci il diametro"  << endl;
    cin >> d;
    vel = tachimetro(n, d);
    cout << "Inserisci un nuovo diametro" << endl;
    cin >> d;
    vel = tachimetro(n, d);
    cout << "La velocità vale " << vel << endl;
    return 0;
}
