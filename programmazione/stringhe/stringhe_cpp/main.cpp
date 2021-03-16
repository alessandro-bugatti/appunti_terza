#include <iostream>
#include <string>

using namespace std;

int conta_vocali_consonanti(string s, char c)
{

}

int main()
{
    string a, b;
    //Assegnamento
    a = "Casello";
    b = a;

    //Input: interessante notare che non c'è un limite alla
    //dimensione della stringa che potrei inserire
    cout << "Inserisci una stringa: ";
    cin >> a;

    //Output
    cout << "Stringa inserita: " << a << endl;
    cout << "L'altra stringa vale: " << b << endl;

    //Concatenazione
    string c = a + b;
    cout << "Stringa ottenuta dalla concatenazione di a con b: "
        << c << endl;

    //A differenza della somma tra numeri, non è commutativa
    c = b + " " + a;
    cout << "Stringa ottenuta dalla concatenazione di b con a: "
        << c << endl;

    //Confronti
    if (a < b)
        cout << a << " minore di " << b << endl;
    else if (a > b)
        cout << a << " maggiore di " << b << endl;
    else
        cout << a << " uguale a " << b << endl;

    //Iterazione su stringhe
    for (int i = 0; i < a.size(); i++)
        cout << a.at(i) << endl;

    return 0;
}
