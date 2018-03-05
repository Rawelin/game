#ifndef INTRUDERSHIP_H
#define INTRUDERSHIP_H

#include "ship.h"

class IntruderShip : public Ship
{
private:
    QString path;

public:
    IntruderShip();
    QString getPath()const{return path;}
};

#endif // INTRUDERSHIP_H
