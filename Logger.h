#pragma once

#include <iostream>
#include <fstream>
#include <string>

class Logger
{
public:
    static Logger& getInstance();

    void logError(const std::string& message);

private:
    Logger();
    std::ofstream m_file;
};
