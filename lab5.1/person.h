#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>
#include "birthdate.h"

class Person
{
public:
    std::string name;
    BirthDate birthDate;
    int height;
    double weight;

    Person();
    Person(std::string name, BirthDate bd, int height, double weight);

    void info();
};

#endif // PERSON_H