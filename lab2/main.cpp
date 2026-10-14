#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "mytime.h"

// Parse a time string "HH:MM:SS" into a MyTime object
MyTime parseTime(const std::string& s) {
    int h = 0, m = 0, sec = 0;
    char colon1, colon2;
    std::istringstream iss(s);
    iss >> h >> colon1 >> m >> colon2 >> sec;
    return MyTime(h, m, sec);
}

int main() {
	
	MyTime t1, t2(1,10,25), t3(1,5,10);
	t1.info();
	t2.info();
	t3.info();
	
	t1 = t2.add(10);
	t1.info();
	
	t2.info();
	
	t1 = t2.add(t3);
	t1.info();
	
	t2.info();
	
	
	// Check subtraction and midnight overflow
    MyTime t4(23, 59, 50);
    t4.add(20);
    std::cout << "23:59:50 + 20 sec = ";
    t4.info();

    MyTime t5(0, 0, 10);
    t5.sub(20);
    std::cout << "00:00:10 - 20 sec = ";
    t5.info();

    std::cout << "Seconds from the start of the day for 01:10:25 = "
              << t2.toSeconds() << "\n\n";
    
    std::cout << "=== Flights within the given interval ===\n";

    // Interval
    MyTime from(12, 00, 00);
    MyTime to(13, 30, 00);
    std::cout << "Interval: ";
    from.info();
    std::cout << " ... ";
    to.info();
    std::cout << "\n";

    std::ifstream fin("schedule.txt");
    if (!fin.is_open()) {
        std::cout << "Could not open file schedule.txt\n";
        return 1;
    }

    std::string line;
    while (std::getline(fin, line)) {
        if (line.empty()) continue;

        std::istringstream iss(line);
        std::string flight, destination, timeStr;
        iss >> flight >> destination >> timeStr;

        if (timeStr.empty()) continue;

        MyTime t = parseTime(timeStr);

        if (t >= from && t <= to) {
            std::cout << flight << " " << destination << " ";
            t.info();
        }
    }

    fin.close();
    
	return 0;
}
