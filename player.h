#ifndef MYRECT_H
#define MYRECT_H

#include "abstractplayer.h"

class Player: public AbstractPlayer
{
    Q_OBJECT
public:
    Player();
    virtual ~Player();
    void keyPressEvent(QKeyEvent* event);

public slots:
    void spawn();
    void crush();

private:
    QMediaPlayer* bulletsound;
};

#endif // MYRECT_H
