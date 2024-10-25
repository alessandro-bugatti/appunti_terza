#include <iostream>

int main() {
    int a,b;
    float c,d;
    a=2;
    b=3;
    a=a+b;
    c=2.5;
    d=3.7;
    c=c+d;
    a=a+c;
    c=c+a;
    std::cout << "a= " << a << std::endl;
    std::cout << "c= " << c << std::endl;
    c=a/b;
    std::cout << "c= " << c <<std::endl;



    return 0;
}
