#include <iostream>

using namespace std;

bool palindroma(string s)
{
    int i = 0, j = s.size() - 1;
    //Con il while
    while (i < j)
    {
        if (s.at(i) != s.at(j))
            return false;
        i++;
        j--;
    }
    //Con il for
    for (; i < j; i++)
    {
        if (s.at(i) != s.at(j))
            return false;
        j--;
    }
    //Con il for e senza un indice esplicito
    for (; i < s.size()/2; i++)
    {
        if (s.at(i) != s.at(s.size() - i - 1))
            return false;
    }

    return true;
}

bool palindroma1(string s)
{
    string t;
    for (int i = s.size() - 1; i >= 0; i--)
        t += s.at(i);
    //cout << t << endl;
    if (t == s)
        return true;
    else
        return false;
}

int main()
{
    if (palindroma1("ottetto"))
        cout << "Palindroma" << endl;
    else
        cout << "Non palindroma" << endl;
    return 0;
}
