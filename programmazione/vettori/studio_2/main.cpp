#include <iostream>
#include <ctime>

int main() {
    srand(time(NULL));
    const int N=10;
    int v[N],a,b,m;
    std::cout<<"inserire i 2 numeri estremi (a & b): ";
    std::cin>>a;
    std::cin>>b;

    if(a>b) {
        int temp = a;
        a = b;
        b = temp;
    }
    for(int i=0; i < N; i++){
        v[i]=rand()% (b - a + 1) + a;
    }
    m=(a+b)/2;

    for(int i=0; i < N; i++){
        if(v[i] >= a && v[i] <= m)
            std::cout<<v[i]<<" ";
    }
    std::cout<<std::endl;
    for(int i=0; i < N; i++){
        if(v[i] > m && v[i] <= b)
            std::cout<<v[i]<<" ";
    }

    return 0;
}
