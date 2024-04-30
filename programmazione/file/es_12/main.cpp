#include <fstream>
#include <iostream>

std::string inverti(const std::string& str) {
    std::string s;
    for (int i = str.size() - 1; i >= 0; --i) {
        s += str.at(i);
    }
    return s;
}

int main() {
    std::ifstream in("input.txt");
    std::ofstream out("output.txt");
    if (!in || !out) {
        return 1;
    }
    std::string s;
    while(std::getline(in, s)) {
        out << inverti(s) << std::endl;
    }
    in.close();
    out.close();
    return 0;
}
