#include <iostream>

//Esempio di stringhe in C

int main() {
    const int MAX = 10;
    char s[MAX];
    std::cout << "Inserisci una parola: ";
    std::cin >> s;
    std::cout << "La parola che hai inserito è " << s << std::endl;
    //Primo problema: cin non gestisce gli spazi
    //Questo però è un "problema" del cin più che delle stringhe C
    //Secondo problema: la parola potrebbe non essere contenuta nello spazio allocato
    s[9] = 'i';
    s[10] = 'e';
    std::cout << "La parola che hai inserito è " << s << std::endl;
            
    return 0;
}
