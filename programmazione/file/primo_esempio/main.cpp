#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    string s;
    //input file stream
    //Apertura del file
    ifstream in("input.txt");
    //Qui andrebbe un controllo per vedere se l'apertura è andata
    //a buon fine

    //Successivamente all'apertura faccio le operazioni che m'interessano
    int a;
    in >> a;
    cout << a;
    cin >> a;
    cout << a;
    //Quando il file non serve più lo si chiude
    in.close();
    return 0;
}
