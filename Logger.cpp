#include "Logger.h"

Logger::Logger(): m_file("log.txt", std::ios_base::app)
{
}

Logger& Logger::getInstance()
{
    static Logger instance;
    return instance;
}

void Logger::logError(const std::string& message)
{
    m_file << "[ERROR] " << message << std::endl;
}
