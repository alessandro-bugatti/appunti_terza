#include <iostream>
#include <fstream>

int main() {
    std::ofstream out("ascii.txt");
    std::ofstream out2("ascii2.txt");
    if(!out || !out2) {
        std::cout<<"Errore durante l'apertura del file" << std::endl;
        return 1;
    }

    for (int i = 33; i <= 126; ++i){
        out << i << "\t" << (char)i << "\t";
        if((i+1) % 3 == 0) {
            out << std::endl;
        }

    }

    int distanza = (126-33)/3;
    //Non è detto che vengano stampati tutti, perchè vengono
    //stampati solo quelli che formano delle "triplette"
    //se ne avanzano uno o due non vengono stampati
    for (int i = 33; i < 33 + distanza; ++i){
        out2 << i << "\t" << (char)i << "\t";
        out2 << i+distanza << "\t" << (char)(i+distanza) << "\t";
        out2 << i+distanza*2 << "\t" << (char)(i+distanza*2) << "\t" << std::endl;


    }

    out.close();

    return 0;
}
