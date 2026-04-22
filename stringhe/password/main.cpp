#include <iostream>
#include <vector>

std::string genera_password(int lun) {
    std::vector<std::string> insiemi;
    insiemi.push_back("ABCDEFGH");
    insiemi.push_back("abcdefgh");
    insiemi.push_back("0123456789");
    insiemi.push_back("@#?!&");

    std::string s;
    for (int i = 0; i < lun; ++i) {
        //Scelgo a caso quale insieme di caratteri utilizzare
        int quale = rand() % insiemi.size();
        //Memorizzo la scelta fatta all'interno di una stringa
        std::string caratteri = insiemi.at(quale);
        //Scelgo a caso un caratteri di quella stringa
        s += caratteri.at(rand() % caratteri.size());
    }
    return s;
}

int main() {
    std::cout << genera_password(40) << std::endl;
    return 0;
}
