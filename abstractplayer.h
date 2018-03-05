#ifndef ABSTRACTPLAYER_H
#define ABSTRACTPLAYER_H

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QObject>
#include <QMediaPlayer>
#include <QGraphicsTextItem>
#include "ship.h"
#include "bullet.h"
#include "weapon.h"

class AbstractPlayer: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    AbstractPlayer(QGraphicsItem* parent = 0);
    virtual ~AbstractPlayer();
    virtual void crush() = 0;
    void setShip(Ship *);
    void setWeapon(Weapon *);
    void setDoubleWeapon(Weapon *, Weapon *);

private:
    Ship *ship;
    Weapon *weapon1, *weapon2;
    QString path;
};

#endif // ABSTRACTPLAYER_H
