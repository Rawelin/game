#include <QFont>
#include "score.h"

Score::Score(QGraphicsItem *parent) : QGraphicsTextItem(parent)
{
    // initialize the score to 0;
    score = 0;

    // draw the text
    setPlainText("Punkty: " + QString::number(score));  // Score: 0
    setDefaultTextColor(Qt::blue);
    setFont(QFont("times", 16));

}

void Score::increaseScore(int sc)
{
    score += sc;
    setPlainText("Punkty: " + QString::number(score));  // Score: 1
}

int Score::getScore()
{
    return score;
}

void Score::gameOver()
{
    setPos(300, 200);
    setPlainText("GAME OVER\n");
    setDefaultTextColor(Qt::red);
    setFont(QFont("times", 35));
}

