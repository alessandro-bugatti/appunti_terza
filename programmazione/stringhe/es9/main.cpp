#include <iostream>

bool exa (const std::string &s) {
    if (s.size()>10||s.size()<3) {
        return false;
    }
    if (s.at(0)!='0') {
        return false;
    }
    if (!(s.at(1)=='x'|| s.at(1)=='X')) {    // if (s.at(1)!='x'&& s.at(1)!='X'))

        return false;
    }

    for (int i = 2; i < s.size(); ++i) {
        if (!(s.at(i)>='A'&& s.at(i)<='F'||
            s.at(i)>='a'&& s.at(i)<='f'||
            s.at(i)>='0'&& s.at(i)<='9')) {
            return false;
            }
    }
    return true;
}

int main() {
    std::cout << exa("0xfffffff") << std::endl;
    std::cout << exa("0xffffffg") << std::endl;

    return 0;
}