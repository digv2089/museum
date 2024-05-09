#include "museum.h"

/**
 * \brief Museum::addvisitor
 *
 * This function maintains the count of the vistors at entry and exit times.
 *
 * \param visitor visitor object
 * \return void.
 */

void Museum::addvisitor(const Visitor &visitor)
{
    countvisitors[visitor.getentertime()]++;
    countvisitors[visitor.getexittime() + 1]--; // visitor already left by now
    countvisitors[visitor.getexittime()] = 0;   // to include the leaving time of visitor
}

/**
 * \brief Museum::findmaxvisitortimeperiod
 *
 * This function contains the logic to find the time period containing the maximum visitors
 *
 * \param none
 * \return starttime , endtime during which we noticed maximum visitor count and vistor count
 */

std::pair<std::pair<int, int>, int> Museum::findmaxvisitortimeperiod() const
{
    int maxvisitor = 0;
    int currentvisitor = 0;
    int maxstarttime = 0;
    int maxendtime = 0;

    for (const auto &entry : countvisitors)
    {
        currentvisitor += entry.second;
        if (currentvisitor > maxvisitor)
        {
            maxvisitor = currentvisitor;
            maxstarttime = entry.first;
            maxendtime = entry.first;
        }
        else if (currentvisitor == maxvisitor && maxvisitor != 0)
        {
            maxendtime = entry.first;
        }
    }

    return {{maxstarttime, maxendtime}, maxvisitor};
}
