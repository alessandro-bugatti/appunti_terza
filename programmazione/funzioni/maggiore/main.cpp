#include <iostream>

int maggiore(int a, int b) {
    if (a > b) {
        return a;
    }
    else {
        return b;
    }
}

int maggiore2(int a, int b) {
    int m;
    if (a > b) {
        m = a;
    }
    else {
        m = b;
    }
    return m;
}

// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
int main() {
    int uno, due;
    std::cout << "Inserisci un numero:";
    std::cin >> uno;
    std::cout << "Inserisci un numero:";
    std::cin >> due;
    int r;
    r = maggiore(uno, due);
    std::cout << "Il maggiore è " << r << std::endl;
    r = maggiore2(due, uno);
    std::cout << "Il maggiore è " << r << std::endl;
    return 0;
}

// TIP See CLion help at <a
// href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>.
//  Also, you can try interactive lessons for CLion by selecting
//  'Help | Learn IDE Features' from the main menu.