#include <iostream>

using namespace std;

void scambio(string &s1, string &s2)
{
    string temp;
    temp = s1;
    s1 = s2;
    s2 = temp;
}

int main()
{
    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;
    if (s1 < s2)
        scambio(s1, s2);
    if (s1 < s3)
        scambio(s1, s3);
    if (s2 < s3)
        scambio(s2, s3);
    cout << s1 << " " << s2 << " " << s3 << endl;
    return 0;
}
