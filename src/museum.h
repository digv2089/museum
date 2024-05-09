#ifndef __MUSEUM__
#define __MUSEUM__

#include "visitor.h"
#include <iostream>
#include <map>

class Museum
{
private:
    std::map<int, int> countvisitors;
public:    
    void addvisitor(const Visitor &visitor);

    std::pair<std::pair<int, int>, int> findmaxvisitortimeperiod() const;
};
#endif