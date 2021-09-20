/*
Autore: Leporati Marco
Il programma genera un numero da 1 a 1000 e l'utente deve
indovinarlo. Il programma fornisce dei suggerimenti e conta
il numero di tentativi fatti.
*/

#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
int main()
{
    int n_computer, tentativi=1, n, diff;
    srand(time(NULL));
    n_computer = rand()%1000 + 1;
    cout << "Indovina il numero che il computer ha generato." <<
        endl << "Il numero va da 1 a 1000. Buona fortuna!" <<
        endl << endl;
    cout << "Inserisci un numero da 1 a 1000: ";
    cin >> n;
    while(n!=n_computer)
    {
        if(n>n_computer) diff=n-n_computer;
            else diff=n_computer-n;
        if(diff>800)
            cout << "Oceano.";
        else if(diff>600)
            cout << "Mare.";
        else if(diff>400&&diff<=600)
            cout << "Lago.";
        else if(diff>200&&diff<=400)
            cout << "Acqua.";
        else if(diff>100&&diff<=200)
            cout << "Fuochino.";
        else if(diff>25&&diff<=100)
            cout << "Fuoco.";
        else if(diff>5&&diff<=25)
            cout << "Falo'.";
        else if(diff>0&&diff<=5)
        cout << "Incendio";
        cout << endl << "Ritenta.";
        cout << endl << endl << "Inserisci un numero da 1 a 1000: ";
        cin >> n;
        tentativi++;
    }
    cout  << endl << "Ce l'hai fatta! Hai impiegato " <<
        tentativi << " tentativi per indovinare il numero." <<
        endl << "Il numero era il " << n_computer << "." << endl <<
        endl;
    return 0;
}
