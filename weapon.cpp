#include <QTimer>
#include <QGraphicsScene>
#include <QDebug>
#include <QList>
#include <typeinfo>
#include "standardenemy.h"
#include "weapon.h"
#include "game.h"

extern Game* game;

Weapon::Weapon(QGraphicsItem *parent) : QObject(), QGraphicsPixmapItem(parent)
{

}

Weapon::~Weapon()
{

}

void Weapon::crush()
{
    // if bullet colides with enemy, destroy both
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for(int i = 0, n = colliding_items.size(); i < n; ++i)
    {
        if(typeid(*(colliding_items[i])) == typeid(StandardEnemy))
        {
            // increase the score
            game->score->increaseScore(200);

            // decrease the enemy counter
            game->decreaseCounter();

            // increase enemy hit

            game->increaseEnemyHit();

            QMediaPlayer * music = new QMediaPlayer();
            music->setMedia(QUrl("sounds/explosion.mp3"));
            music->play();

            // remove them both
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);
            // delete them both
            delete colliding_items[i];
            delete this;
            return;
        }
        if(typeid(*(colliding_items[i])) == typeid(PredatorEnemy))
        {
            // increase the score
            game->score->increaseScore(1000);

            // decrease the enemy counter
            game->decreaseCounter();

            // increase enemy hit

            game->increaseEnemyHit();

            QMediaPlayer * music = new QMediaPlayer();
            music->setMedia(QUrl("sounds/explosion.mp3"));
            music->play();

          /*  QMovie *movie = new QMovie("animation/exploding2.gif");
            QLabel *processLabel = new QLabel();
            scene()->addWidget(processLabel);
            processLabel->setMovie(movie);
            movie->start();
           */

            // remove them both
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);
            // delete them both
            delete colliding_items[i];
            delete this;
            return;
        }
    }
}

void Weapon::setPicture(QString path)
{
    setPixmap(QPixmap(path));
    setTransformOriginPoint(50,50);
}
