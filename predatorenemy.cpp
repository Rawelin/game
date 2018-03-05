#include <QTimer>
#include "predatorenemy.h"
#include "game.h"

extern Game* game;

int PredatorEnemy::static_counter = 0;

PredatorEnemy::PredatorEnemy()
{
    int random_number = rand() % 700;
    setPos(random_number, 0);

    setPicture("images/predatorenemy.png");
    setTimer(15, this);

    static_counter++;

    QMediaPlayer * music = new QMediaPlayer();
    music->setMedia(QUrl("sounds/airland.mp3"));
    music->play();

    //game->increaseCounter();
}

PredatorEnemy::~PredatorEnemy()
{

}

void PredatorEnemy::setMovement()
{

}

void PredatorEnemy::setTimer(int time, Enemy *enemy)
{
    QTimer* timer = new QTimer();
    connect(timer, SIGNAL(timeout()), enemy, SLOT(move()));
    timer->start(time);
}

void PredatorEnemy::move()
{
    setPos(x()+0, y()+5);
    remove();
}

void PredatorEnemy::remove()
{
    if(pos().y() > 600)
    {
        scene()->removeItem(this);
        delete this;
    }
}

void PredatorEnemy::resetCounter()
{
    static_counter = 0;
}

int PredatorEnemy::getCounter()
{
    return static_counter;
}
