#include <iostream>
using namespace std;
int main() {
    int anno;
    std::cout << "Inserisci l'anno" << std::endl;
    cin >> anno;
    if (anno%4==0 and anno%100!=0 or anno%400==0) {
        cout << "L'anno è bisestile";
    } else {
        cout << "l'anno non è bisestile";
    }
    if (anno%400==0) {
        cout << "L'anno è bisestile";
    } else if (anno%100==0) {
        cout << "l'anno non è bisestile";
    } else if (anno%4==0) {
        cout <<  "l'anno è bisestile";
    } else {
        cout << "l'anno non è bisestile";
    }
    return 0;
}

