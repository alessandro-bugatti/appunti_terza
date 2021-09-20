/**
    L'algoritmo per il calcolo del CRC è preso da
    questa pagina
    https://en.wikipedia.org/wiki/Cyclic_redundancy_check#Computation
    e implementato in modo che sia il più fedele possibile
    a quanto mostrato
*/

#include <iostream>
#include <string>

using namespace std;

//Funziona che implementa lo xor tra due caratteri che
//possono assumere solo i valori 0 e 1
char Xor(char a, char b)
{
    if (a == b)
        return '0';
    return '1';
}

//Funzione che controlla se s è composta solo da zeri
//serve a determinare la fine dell'algoritmo
bool zero(string s, int len)
{
    for (int i = 0; i < len; i++)
        if (s.at(i) == '1')
            return false;
    return true;
}

//Funzione che implementa la divisione tra polinomi
//Il parametro pos indica da che posizione deve
//partire il divisore rispetto al dividendo
string divide(string input, string polynomial, int pos)
{
    string result = input;
    //cout << "Passaggio" << endl;
    //cout << input << endl;
    for (int i = 0; i < polynomial.size(); i++)
        result.at(pos + i) = Xor(input.at(pos + i), polynomial.at(i));
    //cout << result << endl;
    return result;
}

string crc(string input, string polynomial)
{
    //Variabile che serve a "spostare" il divisore nella
    //posizione del primo 1 del dividendo
    int pos = 0;
    //Lunghezza iniziale della stringa di bit prima
    //del padding
    int len = input.size();
    //Padding della stringa di input, si aggiungono
    //tanti zeri quanto sono i bit che compongono la
    //stringa polinomyal - 1
    for (int i = 0; i < polynomial.size() - 1; i++)
        input += '0';
    //Fino a quando il dividendo non arriva a zero
    while (!zero(input, len))
    {
        //Trova l'1 più a sinistra nel dividendo
        pos = input.find('1', pos);
        //Fa la divisione e il risultato lo rimette
        //nel dividendo
        input = divide(input, polynomial, pos);
    }
    return input.substr(len);
}

using namespace std;

int main()
{
    //Esempio di Wikipedia
    cout << crc("11010011101100", "1011") << endl;
    return 0;
}
