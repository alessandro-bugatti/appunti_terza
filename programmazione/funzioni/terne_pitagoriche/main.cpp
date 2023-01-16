#include <iostream>

void terne_pitagoriche(int N){
    int a, b, c;
    for (a = 1; a < N ; a++) {
        for (b = a + 1; b < N; b++) {
            for (c = b + 1; c < N; c++) {
                if (a*a + b*b == c*c){
                    std::cout << a << " " << b << " " << c << std::endl;
                }
            }
        }
    }




}

int main() {
    terne_pitagoriche(100);
    return 0;
}
