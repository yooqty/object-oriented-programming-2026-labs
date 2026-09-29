#include <fstream>
#include "personapi.h"

PersonCategory getPersonCategory(Person person) {
    PersonCategory result;

    if (2026 - person.birthyear <= 12) {
        result = PersonCategory::CHILD;
    }
    else if (2026 - person.birthyear <= 18) {
        result = PersonCategory::TEEN;
    }
    else {
        result = PersonCategory::ADULT;
    }

    return result;
}

void savePersonToFile(Person person){
	std::ofstream fileChildren("A:\\object-oriented-programming-2026-labs\\lab1\\children.txt", std::ios::app);
	std::ofstream fileTeens("A:\\object-oriented-programming-2026-labs\\lab1\\teens.txt", std::ios::app);
	std::ofstream fileAdults("A:\\object-oriented-programming-2026-labs\\lab1\\adults.txt", std::ios::app);
	
	if (getPersonCategory(person) == CHILD){
		fileChildren << person.firstname << " " <<
		              person.surname << " " <<
					  person.birthyear << "\n";             
	}
	else if (getPersonCategory(person) == TEEN){
		fileTeens << person.firstname << " " <<
		              person.surname << " " <<
					  person.birthyear << "\n";             
	}
	else if (getPersonCategory(person) == ADULT){
		fileAdults << person.firstname << " " <<
		              person.surname << " " <<
					  person.birthyear << "\n";             
	}
}