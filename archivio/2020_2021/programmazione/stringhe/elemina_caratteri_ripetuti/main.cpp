#include <iostream>

using namespace std;

string elimina_caratteri_ripetuti(string s)
{
    for (int i = 0; i < s.size(); i++)
    {
        //s = "abate";
        char carattere = s.at(i);
        int pos = s.find(carattere, i + 1);
        while (pos != string::npos){
            s.erase(pos, 1);
            pos = s.find(carattere, pos);
        }
    }
    return s;
}

int main()
{
    cout << elimina_caratteri_ripetuti("nanna") << endl;
    return 0;
}
