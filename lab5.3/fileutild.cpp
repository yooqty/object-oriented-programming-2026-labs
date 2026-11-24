#include "fileutils.h"
#include "exception.h"

#include <fstream>
#include <sstream>

std::vector<std::string> readConfigFile(const std::string& configPath)
{
    std::ifstream in(configPath);
    if (!in.is_open())
    {
        throw VesselException("Cannot open configuration file: " + configPath);
    }

    std::vector<std::string> paths;
    std::string line;
    while (std::getline(in, line))
    {
        // trim whitespace
        const auto begin = line.find_first_not_of(" \t\r\n");
        if (begin == std::string::npos)
            continue; // skip blank lines
        const auto end = line.find_last_not_of(" \t\r\n");
        paths.push_back(line.substr(begin, end - begin + 1));
    }

    if (paths.empty())
    {
        throw VesselException("Configuration file contains no data file paths: " +
                              configPath);
    }

    return paths;
}