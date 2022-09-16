#include <iostream>

using namespace std;

int main() {
    int N, M;
    cout << "Inserisci due numeri interi, con il primo minore del secondo: ";
    cin >> N >> M;
    while (N >= M)
    {
        cout << "Inserisci due numeri interi, con il primo minore del secondo: ";
        cin >> N >> M;
    }
    //Se N è dispari viene reso pari
    if (N % 2 == 1)
        N++;
    for (int i = N; i <=M ; i = i + 2) {
        cout << i << endl;
    }
    return 0;
}