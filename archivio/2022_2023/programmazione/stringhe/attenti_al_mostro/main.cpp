#include <iostream>

bool ricerca(const std::string &s, char c){
    for (int i = 0; i < s.size(); ++i) {
        if (c == s.at(i))
            return true;
    }
    return false;
}

void svela(std::string &visibile, char c, const std::string &segreta){
    for (int i = 0; i < segreta.size(); ++i) {
        if (segreta.at(i) == c)
            visibile.at(i) = c;
    }
}

int main() {
    std::string segreta = "cancello";
    std::string visibile;
    for (int i = 0; i < segreta.size(); ++i) {
        visibile += '_';
    }

    int errori = 0;
    std::cout << ricerca(segreta, 'c') << std::endl;
    std::cout << ricerca(segreta, 's') << std::endl;
    svela(visibile, 'c', segreta);
    svela(visibile, 'l', segreta);
    std::cout << visibile << std::endl;

    return 0;
}
