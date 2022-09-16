#include <iostream>

using namespace std;
//Definizione di struttura
//Normalmente viene fatta prima di ogni altra cosa
//Si crea un nuovo tipo di dato
struct Persona{
    string nome;
    string cognome;
    string telefono;
};


/**
 * Stampa i dati di una persona nel modo che si ritiene opportuno
 * l'equivalente di un cout
 */
void stampa_persona(const Persona &p)
{
    //prima possibilità
    cout << "Nome: " << p.nome << endl;
    cout << "Cognome: " << p.cognome << endl;
    cout << "Telefono: " << p.telefono << endl;
    //seconda possibilità
    cout << p.nome << ", " << p.cognome << ", " << p.telefono << endl;
    //potrebbero esserci tantissime altre possibilità, dipende
    //da cosa si vuole ottenere
}

Persona leggi_persona_uno()
{
    Persona t;
    cout << "Inserisci il nome: ";
    cin >> t.nome;
    cout << "Inserisci il cognome: ";
    cin >> t.cognome;
    cout << "Inserisci il numero di telefono: ";
    cin >> t.telefono;
    return t;
}

void leggi_persona_due(Persona &t)
{
    cout << "Inserisci il nome: ";
    cin >> t.nome;
    cout << "Inserisci il cognome: ";
    cin >> t.cognome;
    cout << "Inserisci il numero di telefono: ";
    cin >> t.telefono;
}


int main() {
    //Persona è il tipo, p è la variabile di tipo Persona
    Persona p;
    //Assegnamento
    //Si può fare campo per campo, dove un campo è un attributo specifico
    //della struttura
    p.nome = "Alessandro";
    cout << p.nome.size() << endl;
    p.cognome = "Bugatti";
    p.telefono = "3333333333333333";
    //Oppure posso assegnare una variabile di tipo Persona a un'altra variabile
    //dello stesso tipo
    Persona r;
    r = p;
    cout << "Dati contenuti in p" << endl;
    stampa_persona(p);
    cout << "Dati contenuti in r" << endl;
    stampa_persona(r);
    r.nome = "Giovanni";
    cout << "Dati contenuti in r" << endl;
    stampa_persona(r);
    //Per l'I/O non si può usare direttamente il meccanismo cin e cout
    //di nuovo è necessario ricondursi ai tipi di dato nativi
    p = leggi_persona_uno();
    stampa_persona(p);
    leggi_persona_due(r);
    stampa_persona(r);
    return 0;
}
