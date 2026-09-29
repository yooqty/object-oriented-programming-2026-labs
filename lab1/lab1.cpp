#include <iostream>
#include <fstream>
#include <string>


int main() {
    std::ifstream file("A:\\object-oriented-programming-2026-labs\\lab1\\persons.txt");
    std::string line;

    while (std::getline(file,line)) {
        std::cout << line << '\n';
    }
}