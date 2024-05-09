#ifndef __UTILITY__
#define __UTILITY__

#include <iostream>
#include <vector>

class Utility
{
public:
        static std::vector<std::string> split(const std::string &s, char delimiter);

    static int converttominutes(const std::string &timeStr);
};
#endif