#include "utility.h"
#include <vector>
#include <sstream>
#include <algorithm>

/**
 * \brief Utility::split
 *
 * This function splits the input line based on delimiter
 *
 * \param s line
 * \param delimiter delimeter
 * \return vector of strings containing the splitted strings
 */

std::vector<std::string> Utility::split(const std::string &s, char delimiter)
{
    std::vector<std::string> tokens;
    std::string token;
    std::istringstream tokenStream(s);
    while (std::getline(tokenStream, token, delimiter))
    {
        tokens.push_back(token);
    }
    return tokens;
}

/**
 * \brief Utility::converttominutes
 *
 * This function converts time from hh:mm format to minutes
 *
 * \param timestr time in hh:mm format passed as string
 * \return minutes
 */

int Utility::converttominutes(const std::string &timeStr)
{
    int hours, minutes;
    char colon;
    std::istringstream(timeStr) >> hours >> colon >> minutes;
    return hours * 60 + minutes;
}
