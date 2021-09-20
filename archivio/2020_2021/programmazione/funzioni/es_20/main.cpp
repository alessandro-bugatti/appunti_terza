#include <iostream>

using namespace std;

void converti(int R, int G, int B, int &C, int &Magenta, int &Y)
{
    C = 255 - R;
    Magenta = 255 - G;
    Y = 255 - B;
}

int main()
{
    int R, G, B, Celeste, M, Y;
    cout << "Inserisci le tre componenti di colore: ";
    cin >> R >> G >> B;
    converti(R, G, B, Celeste, M, Y);
    cout << "Il colore convertito diventa (";
    cout << Celeste << "," << M << "," << Y << ")" << endl;

    return 0;
}
