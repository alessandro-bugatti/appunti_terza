#include <iostream>

using namespace std;

int main()
{
    string s = "Stringa di esempio.";
    //Stringa originale
    cout << s << endl;
    //Cancella dall posizione 7 in poi (7 incluso)
    s.erase(7);
    cout << s << endl;

    s = "Stringa di esempio.";
    s.erase(7, 3);
    cout << s << endl;

    s = "Strnga d esempo.";
    int pos = s.find("i");
    while(pos != string::npos)
    {
        s.erase(pos, 1);
        pos = s.find("i");
    }
    cout << s << endl;

    s = "Stringa di esempio.";
    string t = "";
    for (int i = 0; i < s.size(); i++)
        if (s.at(i) != 'i')
            t += s.at(i);
    s = t;
    cout << s << endl;

    //Esempio di substr
    s = "Stringa di esempio.";
    t = s.substr(5, 6);
    cout << t << endl;

     //Esempio di replace
    s = "Stringa di esempio.";
    s.replace(11, 7, "prova");
    cout << s << endl;

    //Stringa stile C
    char r[100];

    return 0;
}
