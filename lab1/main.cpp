#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "personapi.h"


int main() {
	
	std::cout << "Hello World" << '\n';
	
    std::ifstream file("A:\\object-oriented-programming-2026-labs\\lab1\\persons.txt");
    
    std::string line;

    while (std::getline(file,line)) {
        std::string word;
        Person person;

    std::stringstream ss(line);
    ss >> person.firstname;
    ss >> person.surname;
    ss >> word;
    person.birthyear = std::stoi(word);

    std::cout << person.firstname << " " <<
                person.surname << " " <<
                person.birthyear << " " <<
                getPersonCategory(person) << "\n";
    savePersonToFile(person);
    }

    return 0;
}