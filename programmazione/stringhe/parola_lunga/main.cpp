#include <iostream>

using namespace std;

string parola_lunga(string s){
    string lunga = "";
    string temp;
    for (int i = 0; i < s.size(); i++){
        if (s.at(i) == ' '){
            if (temp.size() > lunga.size()){
                lunga = temp;
            }
            temp = "";
        }
        else{
            temp += s.at(i);
        }
    }
    return lunga;
}

int main() {
    cout << parola_lunga("Il perimetro vale 2 pigreco per il raggio") << endl;
    return 0;
}
