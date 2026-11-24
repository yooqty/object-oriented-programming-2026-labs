#include "parser.h"
#include "exception.h"

#include <cassert>
#include <sstream>
#include <vector>
#include <algorithm>

namespace {

// remove leading/trailing whitespace.
std::string trim(const std::string& s)
{
    const auto begin = s.find_first_not_of(" \t\r\n");
    if (begin == std::string::npos)
        return "";
    const auto end = s.find_last_not_of(" \t\r\n");
    return s.substr(begin, end - begin + 1);
}

// convert a string to a long
long toLong(const std::string& field, const std::string& name, long lineNumber)
{
    try
    {
        std::size_t pos = 0;
        long value = std::stol(field, &pos);
        if (pos != field.size())
            throw std::invalid_argument("trailing characters");
        return value;
    }
    catch (const std::exception&)
    {
        throw VesselException("Line " + std::to_string(lineNumber) +
                              ": invalid numeric value in field '" + name +
                              "' -> '" + field + "'");
    }
}

// convert a string to a double
double toDouble(const std::string& field, const std::string& name, long lineNumber)
{
    try
    {
        std::size_t pos = 0;
        double value = std::stod(field, &pos);
        if (pos != field.size())
            throw std::invalid_argument("trailing characters");
        return value;
    }
    catch (const std::exception&)
    {
        throw VesselException("Line " + std::to_string(lineNumber) +
                              ": invalid floating-point value in field '" + name +
                              "' -> '" + field + "'");
    }
}

} // namespace

Record parseRecord(const std::string& line, long lineNumber)
{
    std::istringstream iss(line);
    std::vector<std::string> tokens;
    std::string token;
    while (iss >> token)
        tokens.push_back(token);

    assert(tokens.size() != 0 || line.empty());

    if (tokens.size() != 9)
    {
        throw VesselException("Line " + std::to_string(lineNumber) +
                              ": invalid record format (expected 9 fields, got " +
                              std::to_string(tokens.size()) + ")");
    }

    Record r;

    r.index      = toLong(tokens[0], "index", lineNumber);
    r.vesselId   = static_cast<int>(toLong(tokens[1], "vessel id", lineNumber));
    r.latitude   = toDouble(tokens[2], "latitude", lineNumber);
    r.longitude  = toDouble(tokens[3], "longitude", lineNumber);
    r.speedRaw   = static_cast<int>(toLong(tokens[4], "speed", lineNumber));
    r.course     = static_cast<int>(toLong(tokens[5], "course", lineNumber));
    r.ageMinutes = static_cast<int>(toLong(tokens[6], "age", lineNumber));
    r.dateTime   = tokens[7] + " " + tokens[8];

    // validate latitude range
    if (r.latitude < -90.0 || r.latitude > 90.0)
    {
        throw VesselException("Line " + std::to_string(lineNumber) +
                              ": latitude out of range [-90, 90] -> " +
                              std::to_string(r.latitude));
    }

    // validate longitude range
    if (r.longitude < -180.0 || r.longitude > 180.0)
    {
        throw VesselException("Line " + std::to_string(lineNumber) +
                              ": longitude out of range [-180, 180] -> " +
                              std::to_string(r.longitude));
    }

    // validate speed: raw value > 400 means > 40 knots
    if (r.speedRaw > 400)
    {
        throw VesselException("Line " + std::to_string(lineNumber) +
                              ": speed too high (" +
                              std::to_string(r.speedKnots()) +
                              " knots, limit is 40)");
    }

    // validate course range
    if (r.course < 0 || r.course > 359)
    {
        throw VesselException("Line " + std::to_string(lineNumber) +
                              ": course out of range [0, 359] -> " +
                              std::to_string(r.course));
    }

    return r;
}