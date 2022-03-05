#include <iostream>
#include <string>
#include <cstring>

using namespace std;
int main() {
    /*
    const int LUNGHEZZA = 100;
    //Dichiarazione di una stringa C
    char stringaC[LUNGHEZZA];
    //Dichiarazione di una stringa C++
    string stringaCpp;
    //Inizializzazione di una stringa C
    //Se la variabile esiste già
    //stringaC = "Ciao"; //Così NON si può
    stringaC[0] = 'C';
    stringaC[1] = 'i';
    stringaC[2] = 'a';
    stringaC[3] = 'o';
    stringaC[4] = '\0';
    strncpy(stringaC, "Ciao", LUNGHEZZA - 1);
    //Se invece la variabile non esiste
    char stringaC2[] = "Ciao";

    //Inizializzazione di una stringa C++
    //Se esiste già
    stringaCpp = "Ciao";
    //Se non esiste
    string stringaCpp2 = "Ciao";

    //Input/output di parole singole
    cin >> stringaC;
    cout << "Stringa in stile C " << stringaC << endl;

    cin >> stringaCpp;
    cout << "Stringa in stile C++ " << stringaCpp << endl;

    //Concatenazione in C
    char risultato[100];
    char nome[20];
    strncpy(risultato, "Ciao", 99);
    cout << "Inserisci il tuo nome: ";
    cin >> nome;
    strncat(risultato, " ", 99);
    strncat(risultato, nome, 99);
    cout << risultato << endl;

    //Concatenazione in C++
    string risultatoCpp;
    string nomeCpp;
    cout << "Inserisci il tuo nome: ";
    cin >> nomeCpp;
    //risultatoCpp = "Ciao ";
    //risultatoCpp += nomeCpp;
    risultatoCpp = "Ciao " + nomeCpp;
    cout << risultatoCpp << endl;
    for (int i = 0; i < 10; ++i) {
        risultatoCpp += "-" + nomeCpp;
    }
    cout << risultatoCpp << endl;
    */
    //Confronto in C
    char primaC[] = "albero";
    char secondaC[] = "casa";

    //Se la stringa primaC viene prima della stringa secondaC
    if (strncmp(primaC, secondaC, 100) < 0){
        cout << primaC << " viene prima di " << secondaC << endl;
    }
    else if (strncmp(primaC, secondaC, 100) > 0){
        cout << secondaC << " viene prima di " << primaC << endl;
    }
    else
        cout << "Sono uguali" << endl;

    return 0;
}
