#ifndef SCORE_H
#define SCORE_H

#include <QGraphicsTextItem>

class Score : public QGraphicsTextItem
{
public:
    Score(QGraphicsItem* parent = 0);
    void increaseScore(int sc);
    int getScore();
    void gameOver();

private:
    int score;
};

#endif // SCORE_H
