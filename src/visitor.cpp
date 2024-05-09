#include "visitor.h"

Visitor::Visitor(int entertime, int exittime)
    : entertime(entertime), exittime(exittime) {}

/**
 * \brief Visitor::getentertime
 *
 * This function gets the entry time of visitor
 *
 * \param none
 * \return entry time in minutes
 */

int Visitor::getentertime() const
{
    return entertime;
}

/**
 * \brief Visitor::getexittime
 *
 * This function gets the exit time of the visitor
 *
 * \param none
 * \return exit time in minutes
 */

int Visitor::getexittime() const
{
    return exittime;
}
