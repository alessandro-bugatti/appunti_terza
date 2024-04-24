#include <iostream>
#include <sstream>
#include <vector>

std::vector<std::string> split(const std::string& s, char delimiter = ' ')
{
    std::stringstream in(s);
    std::string temp;
    std::vector<std::string> v;
    while(getline(in, temp, delimiter))
        v.push_back(temp);
    return v;
}


int main()
{

    return 0;
}
