#include <iostream>
#include <string>

std::string crea_indirizzo(const std::string &username, const std::string &dominio){
    return username + '@' + dominio;
}

int main() {
    std::string username, dominio;
    username = "alessandro.bugatti";
    dominio = "gmail.com";
    std::string email = crea_indirizzo(username, dominio);
    std::cout << email << std::endl;
    std::cout << username << std::endl;
    return 0;
}
