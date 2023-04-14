#include <iostream>

int conta_ripetizioni(char c, int pos, const std::string& s){
    int conta = 0;
    while (/*pos < s.size() && */s.at(pos) == c){
        pos++;
        conta++;
    }
    return conta;
}

int main() {
    std::string s = "ffffgcfff";
    std::cout << conta_ripetizioni('f', 6, s) << std::endl;
    return 0;
}
