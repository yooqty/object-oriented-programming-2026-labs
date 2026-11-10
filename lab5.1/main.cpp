#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include "templates.h"
#include "person.h"

using namespace std;

int main()
{
    ifstream fin("students.txt");
    if (!fin.is_open()) {
        cerr << "Cannot open students.txt\n";
        return 1;
    }

    vector<Person> people;
    string line;
    while (getline(fin, line)) {
        if (line.empty()) continue;
        istringstream iss(line);
        string surname, firstName, patronymic, dateStr;
        int h;
        double w;
        if (!(iss >> surname >> firstName >> patronymic >> dateStr >> h >> w)) {
            cerr << "Bad line: " << line << "\n";
            continue;
        }
        string fullName = surname + " " + firstName + " " + patronymic;
        people.push_back(Person(fullName, BirthDate(dateStr), h, w));
    }
    fin.close();

    int n = (int)people.size();
    cout << "Number of people in the file: " << n << "\n\n";
    if (n == 0) return 0;

    // arrays of parameters
    BirthDate* dates  = new BirthDate[n];
    int* heights      = new int[n];
    double* weights   = new double[n];
    for (int i = 0; i < n; i++) {
        dates[i]   = people[i].birthDate;
        heights[i] = people[i].height;
        weights[i] = people[i].weight;
    }

    // min / max / range
    cout << "=== Birth date ===\n";
    cout << "min: " << minValue(dates, n) << "\n";
    cout << "max: " << maxValue(dates, n) << "\n";
    cout << "avg (in days): " << avgValue(dates, n) << "\n";
    cout << "range (in days): " << (maxValue(dates, n) - minValue(dates, n)) << "\n\n";

    cout << "=== Height ===\n";
    cout << "min: " << minValue(heights, n) << " cm\n";
    cout << "max: " << maxValue(heights, n) << " cm\n";
    cout << "avg: " << avgValue(heights, n) << " cm\n";
    cout << "range: " << valueRange(heights, n) << " cm\n\n";

    cout << "=== Weight ===\n";
    cout << "min: " << minValue(weights, n) << " kg\n";
    cout << "max: " << maxValue(weights, n) << " kg\n";
    cout << "avg: " << avgValue(weights, n) << " kg\n";
    cout << "range: " << valueRange(weights, n) << " kg\n\n";

    // normative ranges 
    BirthDate loDate("01.01.2014");
    BirthDate hiDate("31.12.2015");
    int loH = 130, hiH = 150;
    double loW = 30.0, hiW = 45.0;

    cout << "=== Normative ranges ===\n";
    cout << "Birth date: [" << loDate << "; " << hiDate << "]\n";
    cout << "Height: [" << loH << "; " << hiH << "] cm\n";
    cout << "Weight: [" << loW << "; " << hiW << "] kg\n\n";

    int inDate = countInRange(dates, n, loDate, hiDate);
    int inH    = countInRange(heights, n, loH, hiH);
    int inW    = countInRange(weights, n, loW, hiW);

    cout << "Within norm by birth date: " << inDate << " of " << n << "\n";
    cout << "Within norm by height:     " << inH    << " of " << n << "\n";
    cout << "Within norm by weight:     " << inW    << " of " << n << "\n\n";

    // list of students outside the norm
    cout << "=== Students outside the norm by at least one parameter ===\n";
    for (int i = 0; i < n; i++) {
        bool okD = isInRange(people[i].birthDate, loDate, hiDate);
        bool okH = isInRange(people[i].height, loH, hiH);
        bool okW = isInRange(people[i].weight, loW, hiW);
        if (!okD || !okH || !okW) {
            people[i].info();
            cout << "  Reasons: ";
            if (!okD) cout << "birth date; ";
            if (!okH) cout << "height; ";
            if (!okW) cout << "weight; ";
            cout << "\n";
        }
    }

    delete[] dates;
    delete[] heights;
    delete[] weights;

    return 0;
}