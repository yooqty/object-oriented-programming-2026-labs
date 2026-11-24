#include "processor.h"
#include "parser.h"
#include "exception.h"

#include <fstream>
#include <iostream>

void processDataFile(const std::string& filePath, Statistics& stats)
{
    std::ifstream in(filePath);
    if (!in.is_open())
    {
        std::cerr << "[ERROR] Cannot open data file: " << filePath << "\n";
        ++stats.invalidRecords;
        return;
    }

    std::string line;
    long lineNumber = 0;

    while (std::getline(in, line))
    {
        ++lineNumber;

        // skip empty lines
        if (line.find_first_not_of(" \t\r\n") == std::string::npos)
            continue;

        ++stats.totalRecords;

        try
        {
            Record rec = parseRecord(line, lineNumber);

            ++stats.validRecords;

            // track vessel with maximum speed
            if (!stats.hasMaxSpeed || rec.speedRaw > stats.maxSpeedRaw)
            {
                stats.hasMaxSpeed    = true;
                stats.maxSpeedRaw    = rec.speedRaw;
                stats.maxSpeedVessel = rec.vesselId;
            }

            // track record with maximum data age
            if (!stats.hasMaxAge || rec.ageMinutes > stats.maxAgeMinutes)
            {
                stats.hasMaxAge     = true;
                stats.maxAgeMinutes = rec.ageMinutes;
                stats.maxAgeRecord  = rec;
            }
        }
        catch (const VesselException& ex)
        {
            ++stats.invalidRecords;
            std::cerr << "[EXCEPTION] " << filePath << ": " << ex.what() << "\n";
        }
        catch (const std::exception& ex)
        {
            // safety net for any unexpected library exception
            ++stats.invalidRecords;
            std::cerr << "[EXCEPTION] " << filePath
                      << " (line " << lineNumber << "): " << ex.what() << "\n";
        }
    }
}

void printReport(const Statistics& stats)
{
    std::cout << "\n===== Summary report =====\n";
    std::cout << "Total records processed : " << stats.totalRecords   << "\n";
    std::cout << "Valid records           : " << stats.validRecords   << "\n";
    std::cout << "Invalid records         : " << stats.invalidRecords << "\n";

    if (stats.hasMaxSpeed)
    {
        std::cout << "Vessel with max speed   : ID " << stats.maxSpeedVessel
                  << ", speed " << (stats.maxSpeedRaw / 10.0) << " knots\n";
    }
    else
    {
        std::cout << "Vessel with max speed   : no valid data\n";
    }

    if (stats.hasMaxAge)
    {
        const Record& r = stats.maxAgeRecord;
        std::cout << "Record with max age     : "
                  << "index=" << r.index
                  << " vesselId=" << r.vesselId
                  << " lat=" << r.latitude
                  << " lon=" << r.longitude
                  << " speed=" << r.speedKnots()
                  << " course=" << r.course
                  << " age=" << r.ageMinutes << " min"
                  << " dateTime=" << r.dateTime
                  << "\n";
    }
    else
    {
        std::cout << "Record with max age     : no valid data\n";
    }
}