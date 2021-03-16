#include <iostream>

using namespace std;

bool vocale(char c)
{
    if (c == 'a' || c == 'e' ||
        c == 'i' || c == 'o' ||
        c == 'u' )
        return true;
    return false;
}

int conta_vocali_consonanti(char s[], char tipo)
{
    int vocali = 0, consonanti = 0;
    for (int i = 0; s[i] != '\0'; i++)
        if (vocale(s[i]))
            vocali++;
        else
            consonanti++;
    if (tipo == 'C')
        return consonanti;
    else if (tipo == 'V')
        return vocali;
    else
        return -1;
}


int main()
{
    cout << conta_vocali_consonanti("polenta", 'V') << endl;
    return 0;
}
