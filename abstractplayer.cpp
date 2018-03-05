#include "abstractplayer.h"
#include "standardship.h"
#include "intrudership.h"

AbstractPlayer::AbstractPlayer(QGraphicsItem *parent) : QObject(), QGraphicsPixmapItem(parent)
{

}
AbstractPlayer::~AbstractPlayer()
{
    delete ship;
}

void AbstractPlayer::setShip(Ship *sh)
{
    ship = sh;
    path = ship->getPath();
    setPixmap(QPixmap(path));
}

void AbstractPlayer::setWeapon(Weapon *we)
{
    weapon1 = we;
    scene()->addItem(weapon1);
    weapon1->setPos(x() + 6 , y() + 10);
}

void AbstractPlayer::setDoubleWeapon(Weapon *we1, Weapon *we2)
{
    weapon1 = we1;
    scene()->addItem(weapon1);
    weapon1->setPos(x() + 6 , y() + 10);

    weapon2 = we2;
    scene()->addItem(weapon2);
    weapon2->setPos(x() + 36 , y() + 10);
}
