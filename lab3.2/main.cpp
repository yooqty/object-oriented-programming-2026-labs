#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include "decart.h"
#include "sphera.h"

int main()
{
    Decart d1, d2(3, 4, 5);
    Sphera s1, s2(0.5, 1, 10);

    d1 = s2;   // sphera -> decart
    std::cout << "d1 = " << d1 << "\n";
    s1 = d2;   // decart -> sphera
    std::cout << "s1 = " << s1 << "\n";

    std::ifstream fin("data.txt");
    if (!fin)
    {
        std::cerr << "Could not open the data file!\n";
        return 1;
    }

    std::vector<Sphera> pts;
    pts.reserve(1000);
    double lat, lon;
    while (fin >> lat >> lon)
    {
        pts.push_back(Sphera(lon, lat, 6371000.0));
    }
    fin.close();
    std::cout << "Loaded points: " << pts.size() << "\n";

    double maxBig = -1;
    size_t bi = 0, bj = 0;
    for (size_t i = 0; i < pts.size(); ++i)
        for (size_t j = i + 1; j < pts.size(); ++j)
        {
            double d = Sphera::bigCircleDistance(pts[i], pts[j]);
            if (d > maxBig) { maxBig = d; bi = i; bj = j; }
        }

    std::cout << "\nMaximum distance along the Earth's surface:\n"
              << "  " << maxBig << " m\n"
              << "  Point A: " << pts[bi] << "\n"
              << "  Point B: " << pts[bj] << "\n";

    double maxEucl = -1;
    size_t ei = 0, ej = 0;
    for (size_t i = 0; i < pts.size(); ++i)
        for (size_t j = i + 1; j < pts.size(); ++j)
        {
            double d = Decart::euclideanDistance(pts[i], pts[j]);
            if (d > maxEucl) { maxEucl = d; ei = i; ej = j; }
        }

    std::cout << "\nMaximum Euclidean distance (chord):\n"
              << "  " << maxEucl << " m\n"
              << "  Point A: " << pts[ei] << "\n"
              << "  Point B: " << pts[ej] << "\n";

    return 0;
}