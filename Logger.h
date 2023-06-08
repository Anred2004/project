// Logger.h
#pragma once
#include <iostream>
#include <fstream>
#include <string>
class Logger
{
public:
    Logger();
    void logError(const std::string& message);
   
private:
    std::ofstream m_file;
};
