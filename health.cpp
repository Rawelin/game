#include <QFont>
#include "health.h"
#include "score.h"
#include "game.h"

extern Game* game;

Health::Health(QGraphicsItem *parent) : QGraphicsTextItem(parent)
{
    // initialize the scire to 0;
    health = 3;

    // draw the text
    setPlainText("Energia: " + QString::number(health));  // Health: 3
    setDefaultTextColor(Qt::red);
    setFont(QFont("times", 16));
}

void Health::decrease()
{
    health--;
    setPlainText("Energia: " + QString::number(health));  // Health: 3

    if(health == 0)
    {
        game->player->crush();
    }

}

int Health::getHealth()
{
    return health;
}
