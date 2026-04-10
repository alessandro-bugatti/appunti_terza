#include <iostream>

// int main() {
//     const int DIM = 30;
//     char s1[DIM], s2[DIM];
//     std::cout << "Inserisci due parole: ";
//     std::cin >> s1 >> s2;
//     //non si può fare, perchè non ha senso
//     /*if (s1 < s2) {
//         "s1 viene prima di s2";
//     }*/
//     int i;
//     for (i = 0; s1[i] != '\0' || s2[i] != '\0'; ++i) {
//         std::cout << "Giro " << (i+1) << std::endl;
//         if (s1[i] < s2[i]) {
//             std::cout << s1 << " viene prima di " << s2;
//             break;
//         }
//         if (s1[i] > s2[i]) {
//             std::cout << s2 << " viene prima di " << s1;
//             break;
//         }
//     }
//     if (s1[i] == '\0' && s2[i] == '\0') {
//         std::cout << "Le due parole sono uguali";
//     }
//     return 0;
// }

int main() {
    std::string s1, s2;
    std::cout << "Inserisci due parole: ";
    std::cin >> s1 >> s2;
    if (s1 < s2) {
        std::cout << s1 << " viene prima di " << s2 << std::endl;
    }else if (s2 < s1) {
        std::cout << s2 << " viene prima di " << s1 << std::endl;
    }
    else {
        std::cout << "Sono uguali" << std::endl;
    }
    return 0;
}
