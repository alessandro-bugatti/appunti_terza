#include <iostream>

int main() {
    int anno = 1900;
    if (anno % 4 == 0 && anno % 100 != 0 || anno % 400 == 0) {
        std::cout << "bisestile" << std::endl;
    }
    else {
        std::cout << "non bisestile" << std::endl;
    }

    return 0;
}
