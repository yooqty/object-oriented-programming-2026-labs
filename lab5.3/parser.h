#ifndef PARSER_H
#define PARSER_H

#include "record.h"
#include <string>

// parses a single line of a trajectory file into a record.
// throws VesselException on any validation failure.
Record parseRecord(const std::string& line, long lineNumber);

#endif // PARSER_H