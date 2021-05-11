#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    cout << n << endl;
    int a = 2;
    a += n;
    cout << a << endl;

    string m;
    cin >> m;
    cout << m << endl;
    int b = 2;
    b += stoi(m);
    cout << b << endl;
    return 0;
}
