// Logger.cpp
#include "Logger.h"
using namespace pp;
Logger::Logger()
{
    m_file.open("log.txt", std::ios_base::app);
}
void Logger::logError(const std::string& message)
{
    m_file << "[ERROR] " << message << std::endl;
}
