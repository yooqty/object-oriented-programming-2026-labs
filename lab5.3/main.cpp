#include "exception.h"
#include "fileutils.h"
#include "processor.h"

#include <iostream>
#include <string>

int main(int argc, char* argv[])
{
    const std::string configPath = (argc > 1) ? argv[1] : "config.txt";

    Statistics stats;

    try
    {
        const std::vector<std::string> dataFiles = readConfigFile(configPath);

        for (const std::string& filePath : dataFiles)
        {
            std::cout << "Processing file: " << filePath << "\n";
            processDataFile(filePath, stats);
        }

        printReport(stats);
    }
    catch (const VesselException& ex)
    {
        std::cerr << "[FATAL] " << ex.what() << "\n";
        return 1;
    }
    catch (const std::exception& ex)
    {
        std::cerr << "[FATAL] Unexpected error: " << ex.what() << "\n";
        return 2;
    }

    return 0;
}