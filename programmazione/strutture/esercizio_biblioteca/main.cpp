#include <iostream>
#include <fstream>

using namespace std;

struct Libro
{
    string codice;
    string titolo;
    string autore;
    int anno;
    string editore;
};

Libro inserisci_libro()
{
    Libro a;
    cout << "Inserisci il codice: ";
    getline(cin, a.codice);
    cout << "Inserisci il titolo: ";
    getline(cin, a.titolo);
    cout << "Inserisci il autore: ";
    getline(cin, a.autore);
    cout << "Inserisci il anno: ";
    string anno;
    getline(cin, anno);
    a.anno = stoi(anno);
    cout << "Inserisci il editore: ";
    getline(cin, a.editore);
    return a;
}

void menu()
{
    cout << endl << "GESTIONE LIBRI" << endl << endl;
    cout << "1 - Inserisci un libro alla collezione" << endl;
    cout << "2 - Visualizza l'elenco dei libri della collezione" << endl;
    cout << "3 - Visualizza informazioni relative a un libro a partire dal codice" << endl;
    cout << "4 - Visualizza informazioni relative a un libro a partire dal titolo" << endl;
    cout << "0 - Esci" << endl << endl;

}

void stampa(Libro v[], int quanti)
{
    cout << endl;
    for (int i = 0; i < quanti; i++)
    {
        cout << v[i].titolo << endl;
    }
}

void carica(string nome_file, Libro libri[], int &n_libri)
{
    ifstream in("libri.txt");
    if (!in)
        return;
    Libro l;
    n_libri = 0;
    while (getline(in, l.codice))
    {
        getline(in, l.titolo);
        getline(in, l.autore);
        string anno;
        getline(in, anno);
        l.anno = stoi(anno);
        getline(in, l.editore);
        libri[n_libri] = l;
        n_libri++;
    }
}

void salva(...)
{

}

int main()
{
    const int MAX_LIBRI = 100;
    Libro libri[MAX_LIBRI];
    int n_libri = 0;
    int scelta = 1;
    carica("libri.txt", libri, n_libri);
    while (scelta != 0)
    {
        menu();
        cout << "Inserisci la tua scelta: ";
        string s;
        getline(cin, s);
        scelta = stoi(s);
        system("cls");
        if (scelta == 1 && n_libri < MAX_LIBRI)
        {
            Libro temp = inserisci_libro();
            libri[n_libri] = temp;
            n_libri++;
            system("cls");
        }

        if (scelta == 2)
        {
            stampa(libri, n_libri);
            system("pause");
            system("cls");
        }

        if (scelta == 3)
        {
            cout << "Inserisci il codice: ";
            //cin >> codex;
            //libro_codice(biblioteca, codex, quanti);
            system("pause");
            system("cls");

        }

        if (scelta == 4)
        {
            cout << "Inserisci il titolo: ";
            //cin >> title;
            //libro_titolo(biblioteca, title, quanti);
            system("pause");
            system("cls");
        }

    }
    return 0;
}
