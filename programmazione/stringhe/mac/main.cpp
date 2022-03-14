#include <iostream>

using namespace std;

bool isHex(char c){
    if (c >= '0' && c <= '9')
        return true;
    c = tolower(c);
    if (c >= 'a' && c <= 'f')
        return true;
    return false;
}

/**
 * Verifica se una stringa è un indirizzo MAC formalmente
 * corretto, cioè formato da 12 cifre esadecimali
 * @param mac_address
 * @return true se è corretto, false altrimenti
 */
bool isMac(string mac_address){
    if(mac_address.size() != 12)
        return false;
    for (int i = 0; i < mac_address.size(); ++i) {
        if (isHex(mac_address.at(i)) == false)
            return false;
    }
    return true;
}

int main() {
    if (isMac("123456789aBc") == true)
        cout << "Il MAC è valido" << endl;
    else
        cout << "Il MAC non è valido" << endl;
    return 0;
}
