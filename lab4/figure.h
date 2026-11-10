#pragma once
#include <string>

class Figure {
protected:
    std::string fileName;
    static int counter;

public:
    Figure(); // increments counter, sets fileName = "N"
    virtual ~Figure() = 0; // pure virtual destructor

    virtual void loadFromFile() = 0;
    virtual void saveToFile() const = 0;
    virtual std::string toString() = 0; // string representation (refreshes from file)

    std::string getFileName() const { return fileName; }
    static int getCounter() { return counter; }
};