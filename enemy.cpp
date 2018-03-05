#include "enemy.h"
#include <stdlib.h>


Enemy::Enemy(QGraphicsItem *parent) : QObject(), QGraphicsPixmapItem(parent)
{

}

Enemy::~Enemy()
{

}

void Enemy::setPicture(QString path)
{
    setPixmap(QPixmap(path));
    setTransformOriginPoint(50,50);
}





