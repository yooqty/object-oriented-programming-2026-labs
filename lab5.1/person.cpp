#include "person.h"

Person::Person()
{
    name = "NO NAME";
    birthDate = BirthDate();
    height = 0;
    weight = 0.0;
}

Person::Person(std::string name, BirthDate bd, int h, double w)
    : name(name), birthDate(bd), height(h), weight(w)
{
}

void Person::info()
{
    std::cout << name << "\t" << birthDate
              << "\t" << height << "\t" << weight << "\n";
}