#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <exception>
#include <string>

class VesselException : public std::exception
{
public:
    explicit VesselException(const std::string& message);

    const char* what() const noexcept override;

private:
    std::string m_message;
};

#endif // EXCEPTION_H