#ifndef PREDATORENEMY_H
#define PREDATORENEMY_H

#include "enemy.h"

class PredatorEnemy :public Enemy
{
    Q_OBJECT
public:
    PredatorEnemy();
    virtual ~PredatorEnemy();
    void setMovement();
    void setTimer(int, Enemy *);
    void remove();
    void resetCounter();
    int getCounter();

public slots:
    void move();

private:
     static int static_counter;
};

#endif // PREDATORENEMY_H
