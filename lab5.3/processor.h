#ifndef PROCESSOR_H
#define PROCESSOR_H

#include "record.h"
#include <string>
#include <vector>

struct Statistics
{
    long totalRecords = 0; // all lines attempted
    long validRecords = 0; // successfully parsed records
    long invalidRecords = 0; // records that raised exceptions

    bool hasMaxSpeed = false;
    int maxSpeedVessel = 0; // vessel ID with maximum speed
    int maxSpeedRaw = 0;

    bool hasMaxAge = false;
    int maxAgeMinutes = 0;
    Record maxAgeRecord;
};

// processes one data file, updating the statistics object
// exceptions from individual records are caught and counted here
void processDataFile(const std::string& filePath, Statistics& stats);

void printReport(const Statistics& stats);

#endif // PROCESSOR_H