#ifndef BULLET_H
#define BULLET_H

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QObject>
#include "weapon.h"

class Bullet :public Weapon
{
    Q_OBJECT
public:
    Bullet();
public slots:
    void move();

};

#endif // BULLET_H
