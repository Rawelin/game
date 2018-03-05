#ifndef ENEMY_H
#define ENEMY_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include <QTimer>
#include <QGraphicsScene>
#include <QDebug>

class Enemy :public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Enemy(QGraphicsItem * parent = 0);
    virtual ~Enemy();
    virtual void setMovement() = 0;
    virtual void remove() = 0;
    virtual void resetCounter() = 0;
    virtual int getCounter() = 0;

    void setPicture(QString path);

public slots:
    virtual void move() = 0;

private:
  //  bool flagX, flagY;

};

#endif // ENEMY_H
