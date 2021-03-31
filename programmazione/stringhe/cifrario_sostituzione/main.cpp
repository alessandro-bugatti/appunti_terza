#include <iostream>

using namespace std;

char conversione(char c, string chiave)
{
    return chiave.at(c - 'a');
}

int main()
{
    string chiave = "wqertyuiopasdfghjklzxcvbnm";

    /*
    Idea di partenza
    'a' -> 'r'
    'b' -> 'g'
    'c' -> 'h'
    'd' -> 'a'
    ecc.*/
    /*
    Implementazione scorretta
    if (s.at(i) == 'a')
        s.at(i) = 'r';
    ecc. ecc.*/
    cout << conversione('b', chiave)<< endl;
    return 0;
}
