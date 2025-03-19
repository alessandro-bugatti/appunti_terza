#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    string frase, parola;
    int conta=0;
    int pos=0;

    vector<int>posizioni;

    cout << "inserisci una frase: ";
    getline(cin, frase);
    cout << "inserisci una parola: ";
    getline(cin, parola);

    while ((pos = frase.find(parola, pos)) != string::npos) {
        conta++;
        posizioni.push_back(pos);
        pos++;
    }
    cout<<"la parola è presente "<<conta<<" volte"<<endl;
    for (int i = 0; i < posizioni.size(); ++i) {
        cout<<"posizioni parola: "<<posizioni.at(i)<<endl;
    }

    return 0;
}