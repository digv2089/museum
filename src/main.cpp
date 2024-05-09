#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#include "museum.h"
#include "utility.h"


/**
 * \brief main
 *
 * This function reads the input file [test file] 
 * calls utitlity class functions to split the lines from input 
 * calls visitor class functions to record visitor count , entry and exit times
 * calls museum class funtions to find the time period having maximum visitors and print the desired output  
 * 
 * \param none
 * \return 0 
 */


int main(int argc, char *argv[])
{
    //open the test file visitors.txt 
    std::ifstream ifile("visitors.txt");
    if (!ifile.is_open())
    {
        std::cerr << "Unable to open input file.\n";
        return 1;
    }

    Museum museum;

    // Read visiting times from the input file and add visitors to the museum
    std::string line;
    while (std::getline(ifile, line))
    {
        std::vector<std::string> times = Utility::split(line, ',');
        if (times.size() != 2)
        {
            std::cerr << "Invalid input format.\n";
            return 1;
        }
        int entertime = Utility::converttominutes(times[0]);
        int exittime = Utility::converttominutes(times[1]);
        Visitor visitor(entertime, exittime);
        museum.addvisitor(visitor);
    }

    auto maxvisitorperiod = museum.findmaxvisitortimeperiod();

    // Output the result
    std::cout << maxvisitorperiod.first.first / 60 << ':' << maxvisitorperiod.first.first % 60 << '-'
              << maxvisitorperiod.first.second / 60 << ':' << maxvisitorperiod.first.second % 60 << ';'
              << maxvisitorperiod.second << std::endl;

    return 0;
}
