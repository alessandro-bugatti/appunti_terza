#include <iostream>

using namespace std;

int main() {
    int N;
    cout << "Inserisci un valore positivo > 1" << endl;
    cin >> N;
    while (N <= 1){
        cout << "Inserisci un valore positivo > 1" << endl;
        cin >> N;
    }
    for (int i = 1; i <= N; i+=2){
        cout << i << " -> " << i*i << endl;
    }
    return 0;
}

