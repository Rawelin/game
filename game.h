#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QtWidgets>
#include <QGraphicsScene>
#include "abstractplayer.h"
#include "player.h"
#include "score.h"
#include "health.h"
#include "enemy.h"
#include "predatorenemy.h"
#include "standardenemy.h"

class Game : public QGraphicsView
{
    Q_OBJECT
public:
    Game();

    AbstractPlayer* player;             //TODO make setters and getters
    Score* score;
    Health* health;

    void increaseCounter() {counter++;}
    void decreaseCounter() {counter--;}
    void increaseEnemyHit() {enemy_hit++;}
    void createScene();

    int getcounter(){return counter;}


public slots:
    void createEnemy();
    void runGame();

private:
    QGraphicsScene* scene;
    int counter;
    int enemy_hit;
};

#endif // GAME_H
