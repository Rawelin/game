#ifndef STANDARDENEMY_H
#define STANDARDENEMY_H

#include "enemy.h"

class StandardEnemy : public Enemy
{
    Q_OBJECT
public:
    StandardEnemy();
    virtual ~StandardEnemy();
    void remove();
    void setMovement();
    void setTimer(int, Enemy *);
    void resetCounter();
    int getCounter();


public slots:
    void move();

private:
    static int static_counter;
    bool flagX, flagY;
};

#endif // STANDARDENEMY_H
