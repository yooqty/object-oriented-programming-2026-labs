#include "exception.h"

VesselException::VesselException(const std::string& message)
    : m_message(message)
{
}

const char* VesselException::what() const noexcept
{
    return m_message.c_str();
}