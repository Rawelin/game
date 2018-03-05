#include "ship.h"

Ship::Ship(QGraphicsItem *parent) : QObject(), QGraphicsPixmapItem(parent)
{

}

void Ship::setPicture(QString path)
{
    setPixmap(QPixmap(path));
    setTransformOriginPoint(50,50);
}
