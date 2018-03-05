#ifndef STANDARDSHIP_H
#define STANDARDSHIP_H

#include "ship.h"


class StandardShip : public Ship
{
private:
    QString path;

public:
    StandardShip();
    QString getPath()const{return path;}
};

#endif // STANDARDSHIP_H
