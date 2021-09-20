#include <iostream>
#include <cstring>

using namespace std;

int my_strlen(char s[])
{
    int cont = 0;
    while(s[cont] != '\0')
        cont++;
    return cont;
}

int main()
{
    char s[100];
    char t[100];

    //Input una sola parola per volta
    cout << "Inserisci una parola: ";
    cin >> s;
    cout << "Inserisci una parola: ";
    cin >> t;

    //Avrebbe un senso logico, ma non è sintatticamente corretta
    //s = t;
    //Allora devo usare una funzione di libreria
    //strncpy(s, t, 3);

    //Anche queste istruzioni non si possono fare
    //if (s < t)
    //if (s > t) ecc.
    //Per i confronti bisognerebbe usare una funzione
    //Anche la concatenazione richiede una funzione

    //Output
    cout << endl << "s: " << s << " di lunghezza: "
            << my_strlen(s) << endl;
    cout << t << endl;
    return 0;
}
