#include <iostream>

void scambio(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}
int main() {
    int a = 5, b = 7;
    scambio(a, b);
    std::cout << a << " " << b << std::endl;
    return 0;
}