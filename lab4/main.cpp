#include <iostream>
#include <vector>
#include <memory>
#include "rectangle.h"
#include "triangle.h"
#include <fstream>
#include <cstdio>

int main() {
    std::cout << "=== 1. Creating figures ===\n";
    Rectangle r1(0, 0, 10, 5);
    Triangle  t1(0, 0, 4, 0, 0, 3);
    Rectangle r2(1, 2, 8, 9);

    std::cout << r1.toString() << "\n";
    std::cout << t1.toString() << "\n";
    std::cout << r2.toString() << "\n";

    std::cout << "\n=== 2. External file modification and synchronization ===\n";
    {
        std::ofstream out(r1.getFileName());
        out << "100 100 200 200";
    }
    std::cout << r1.toString() << "\n";

    std::cout << "\n=== 3. Copy constructor ===\n";
    Rectangle r3 = r1; // copy: new object, new file, copied coordinates
    std::cout << "original: " << r1.toString() << "\n";
    std::cout << "copy    : " << r3.toString() << "\n";

    std::cout << "\n=== 4. Assignment operator ===\n";
    Rectangle r4(0, 0, 1, 1);
    std::string f4before = r4.getFileName();
    r4 = r1; // only coordinates are copied
    std::cout << "after assign: " << r4.toString()
              << "  (file was '" << f4before
              << "', stays '" << r4.getFileName() << "')\n";

    std::cout << "\n=== 5. Array of objects via base class pointers ===\n";
    std::vector<std::unique_ptr<Figure>> figures;
    figures.emplace_back(new Rectangle(2, 3, 7, 8));
    figures.emplace_back(new Triangle(0, 0, 5, 0, 0, 5));
    figures.emplace_back(new Rectangle(10, 10, 20, 20));
    figures.emplace_back(new Triangle(1, 1, 6, 1, 1, 6));

    for (auto& f : figures)
        std::cout << f->toString() << "\n";

    std::cout << "\n=== 6. Array of objects (stack) and synchronization ===\n";
    {
        Rectangle arr[3] = {
            Rectangle(0, 0, 1, 1),
            Rectangle(2, 2, 3, 3),
            Rectangle(4, 4, 5, 5)
        };
        arr[1].setCoords(50, 50, 60, 60);
        arr[1].saveToFile();
        {
            std::ofstream out(arr[2].getFileName());
            out << "99 99 100 100";
        }
        for (auto& r : arr)
            std::cout << r.toString() << "\n";
    } // arr is destroyed here, its files are removed

    std::cout << "\n=== 7. Total Figure objects created: "
              << Figure::getCounter() << " ===\n";

    std::cout << "\n=== 8. Destroying the vector - files are removed ===\n";
    figures.clear();
    std::cout << "Done. Check that the files have disappeared from the working folder.\n";
    return 0;
}