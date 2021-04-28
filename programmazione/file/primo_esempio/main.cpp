#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    string s;
    //input file stream
    //Apertura del file
    ifstream in("input2.txt");
    //Qui andrebbe un controllo per vedere se l'apertura è andata
    //a buon fine
    if (!in)
    {
        cout << "Non sono riuscito ad aprire il file" << endl;
        return -1;
    }
    //Successivamente all'apertura faccio le operazioni che m'interessano
    string a;
    in >> a;
    cout << a;
    cin >> a;
    cout << a;
    //Quando il file non serve più lo si chiude
    in.close();

    //output file stream
    //Apertura del file
    ofstream out("output.txt");
    ofstream out2("output2.txt");

    //Successivamente all'apertura faccio le operazioni che m'interessano
    out << a << " " << a << endl;

    //Quando il file non serve più lo si chiude
    out.close();
    out2.close();

    return 0;
}
