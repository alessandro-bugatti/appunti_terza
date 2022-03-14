#include <iostream>

using namespace std;

// ___ciao__
string trim(string s){
    //Toglie gli spazi iniziali
    while (s.size() > 0 && s.at(0) == ' '){
         s.erase(0,1);
    }
    if (s.size() == 0) return s;
    //Toglie gli spazi finali
    while (s.at(s.size() - 1) == ' '){
        s.erase(s.size() - 1, 1);
    }
    return s;
}

int main() {
    std::cout << "<" << trim(" ciao a tutti  ") << ">" << endl;
    return 0;
}
