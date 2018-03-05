#ifndef WEAPON_H
#define WEAPON_H

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QObject>

class Weapon :public QObject, public QGraphicsPixmapItem
{
public:
    Weapon(QGraphicsItem* parent = 0);
    virtual ~Weapon();
    void crush();
    void setPicture(QString path);
};

#endif // WEAPON_H
