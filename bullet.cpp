#include "bullet.h"
#include "game.h"

extern Game* game;

Bullet::Bullet()
{
    // draw graphic
    setPicture("images/bullet.png");
    //conect
    QTimer* timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));

    timer->start(30);
}

void Bullet::move()
{
    crush();
    // move bullet up
    setPos(x()+0, y()-10);
    if(pos().y() < 0)
    {
        scene()->removeItem(this);
        delete this;
    }
}
