#include <iostream>
#include <string>

int main() {
    std::string name;
    char namestr[100];

    std::cout << "Please, enter your full name: ";
    std::getline(std::cin, name);
    std::cout << "Hello, " << name << "!\n";

    std::cout << "Please, enter your full name(again): ";
    std::cin.getline(namestr, 100);
    std::cout << "Hello, " << namestr << "!\n";

    return 0;
}
