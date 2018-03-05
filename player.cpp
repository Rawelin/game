#include "bullet.h"
#include "standardenemy.h"
#include "standardship.h"
#include "intrudership.h"
#include "player.h"
#include "game.h"

extern Game* game;

Player::Player()
{
    setShip(new IntruderShip());

    QTimer *timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(crush()));
    timer->start(100);
}

Player::~Player()
{

}

void Player::keyPressEvent(QKeyEvent *event)
{
    // move the player left and right
    if(event->key() == Qt::Key_Left)
     {
        if(pos().x() > 0)                              // zapobiega wychodzeniu poza ekran
            setPos(x()-10, y());
     }

    else if(event->key() == Qt::Key_Right)
    {
        if(pos().x() + 50 < 800)                     // zapobiega wychodzeniu poza ekran
            setPos(x()+10, y());
    }

    else if(event->key() == Qt::Key_Up)
        setPos(x(), y()-10);
    else if(event->key() == Qt::Key_Down)
        setPos(x(), y()+10);

     else if(event->key() == Qt::Key_Space)
        setDoubleWeapon(new Bullet(), new Bullet());

}

void Player::spawn()
{

}

void Player::crush()
{
    // if player colides with enemy, destroy both
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for(int i = 0, n = colliding_items.size(); i < n; ++i)
    {
        if(typeid(*(colliding_items[i])) == typeid(StandardEnemy) || typeid(*(colliding_items[i])) == typeid(PredatorEnemy))
        {

            QMediaPlayer * music = new QMediaPlayer();
            music->setMedia(QUrl("sounds/explosion.mp3"));
            music->play();

            // remove them both

            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);
            // delete them both
            delete colliding_items[i];
            delete this;
            game->score->gameOver();
            return;
        }
    }
}
