#include <iostream>
#include <ctime>

char genera_carattere(){
    char c = rand() % (125 - 33 - 1) + 33;
    // Se si volessero ad esempio produrre solo cifre
    // c = rand() % 10 + '0';
    return c;
}

std::string genera_password(int lunghezza){
    std::string password;
    for (int i = 0; i < lunghezza; ++i) {
        password += genera_carattere();
    }
    return password;
}

int main() {
    srand(time(NULL));
    int n;
    std::cout << "Inserisci la lunghezza della password da generare: ";
    std::cin >> n;
    std::string password = genera_password(n);
    std::cout << password << std::endl;
    return 0;
}
