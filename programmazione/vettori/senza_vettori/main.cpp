#include <iostream>

using namespace std;

int main() {
    int a, b, c, d; //MI fermo a 4 ma sarebbero 12
    cin >> a >> b >> c >> d;
    float media = (a+b+c+d)/4.0;
    if (a > media)
        cout << "Gennaio" << endl;
    if (b > media)
        cout << "Febbraio" << endl;
    //IN questo modo non arriviamo da nessuna parte....
    return 0;
}
