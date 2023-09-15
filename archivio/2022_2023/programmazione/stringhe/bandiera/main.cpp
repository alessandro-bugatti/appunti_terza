#include <iostream>

int main() {
    const int N_COLONNE = 60;
    std::string testo = "Some open source projects attract enough contributors that a community forms. A healthy open source community centers the shared values and norms of its members. While not all of these values are exactly the same from community to community, there is a set of  core values and norms that are essential in a just and equitable software commons.";
    std::cout << "Originale: " << testo << std::endl;

    int pos = N_COLONNE - 1;
    int inizio = 0;
    int fine = -1;
    while(fine + N_COLONNE < testo.size()){
        fine += N_COLONNE;
        while(testo.at(fine) != ' ')
            fine--;
        std::cout << testo.substr(inizio, fine - inizio) << std::endl;
        inizio = fine + 1;
    }
    std::cout << testo.substr(inizio) << std::endl;
    return 0;
}

