#include <iostream>
#include <cmath>

using namespace std;


//Definizione di una funzione
//La prima parte è il tipo del valore di ritorno
//cioè cosa vi da in cambio la funzione per quello che le avete dato
//La seconda parte è il nome della funzione, che deve esprimere
//quello che fa
//Tra le parentesi tonde viene inserito la cosa che diamo alla funzione
//in questo caso il numero da elevare al quadrato
double elevamento_al_quadrato(double n)
{
    //y = f(n) dove f è l'elevamento al quadrato
    //Corpo delle funzione
    //Variabile di appoggio, anche tante
    double quadrato;
    //Esecuzione del compito che deve svolgere la funzione
    quadrato = n * n;
    //return è la parola chiave che indica cosa bisogna dare a chi
    //ha fornito il dato in ingresso
    return quadrato;
}

/**
formaggio caseificazione(latte l)
{
    istruzioni per produrre il formaggio
    return formaggio
}
*/

int main()
{
    double a, b;
    cout << "Inserisci a: ";
    cin >> a;
    cout << "Inserisci b: ";
    cin >> b;
    double q = elevamento_al_quadrato(a);
    cout << "Il quadrato vale: " << q << endl;
    double r = sqrt(a);
    cout << "La radice vale: " << r << endl;
    r = sqrt(b);
    cout << "La radice vale: " << r << endl;

    return 0;
}
