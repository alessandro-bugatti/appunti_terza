#include <iostream>
std::string inverti(const std::string &s) {
    std::string risultato;
    for (int i = s.size() - 1; i >= 0; i--) {
        risultato += s.at(i);
    }
    return risultato;
}

int main() {
    std::string S;
    std::string V;
    std::string V_i;

    std::cin >> S >> V;
    V_i = inverti(V);
    int pos = S.find(V);
    if(pos != std::string::npos) {
        S.erase(pos, V.size());
        std::cout << S << std::endl;
    }else if(S.find(V_i) != std::string::npos) {
        pos = S.find(V_i);
        S.erase(pos, V.size());
        std::cout << S << std::endl;
    }else {
        std::cout<<"La parola " << S << " non contiene al suo interno " << V << std::endl;
    }

}
