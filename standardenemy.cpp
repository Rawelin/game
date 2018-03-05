#include "standardenemy.h"
#include "game.h"

extern Game *game;

int StandardEnemy::static_counter = 0;

StandardEnemy::StandardEnemy()
{
    flagY = true;
    flagX = true;

    setPos(100, 0);

    game->increaseCounter();

    setPicture("images/standardenemy.png");
    setTimer(30, this);

    static_counter++;

}

StandardEnemy::~StandardEnemy()
{

}

void StandardEnemy::move()
{
    setMovement();

    if(flagX == true && flagY == true)
        setPos(x()+0, y()+5);
    if(flagX == true && flagY == false)
        setPos(x()+5, y()+0);
    if(flagX == false && flagY == false)
        setPos(x()+0, y()-5);
    if(flagX == false && flagY == true)
       setPos(x()-5, y()+0);

    remove();
}

void StandardEnemy::remove()
{
    if(pos().y() > 700)
    {
        scene()->removeItem(this);
        delete this;
    }
}

void StandardEnemy::setMovement()
{
    if(this->pos().y() == 400)
        flagY = false;
    if(this->pos().x() == 600)
        flagX = false;
    if(this->pos().y() == 100)
        flagY = true;
    if(this->pos().x() == 200)
        flagX = true;
}

void StandardEnemy::setTimer(int time, Enemy *enemy)
{
    QTimer* timer = new QTimer();
    connect(timer, SIGNAL(timeout()), enemy, SLOT(move()));
    timer->start(time);
}

void StandardEnemy::resetCounter()
{
    static_counter = 0;
}

int StandardEnemy::getCounter()
{
    return static_counter;
}
