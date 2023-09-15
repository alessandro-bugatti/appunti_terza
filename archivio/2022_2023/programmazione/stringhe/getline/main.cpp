#include <iostream>

int main() {
    std::string s;
    int n;
    //std::cin >> s >> n;
    //std::cout << s << n << std::endl;
    std::cout << "Inserisci un numero: " ;
    std::getline(std::cin, s);
    n = std::stoi(s);
    std::cout << "Inserisci una frase: ";
    //std::cin >> s; non adatta
    std::getline(std::cin, s);

    std::cout << s << " , " << n << std::endl;


    return 0;
}
