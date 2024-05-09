#ifndef __VISITOR__
#define __VISITOR__

class Visitor
{
private:
    int entertime;
    int exittime;

public:
    Visitor(int entertime, int exittime);

    int getentertime() const;

    int getexittime() const;
};
#endif