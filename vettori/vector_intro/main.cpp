#include <iostream>
#include <vector>

int main() {
    std::vector<int> v;
    for (int i = 0; i < 10; ++i) {
        v.push_back(i + 1);
    }
    std::cout << "Il vettore contiene "
        << v.size() << " elementi." << std::endl;
    std::cout << v[4] << std::endl;
    std::cout << v.at(10) << std::endl;

    return 0;
}
