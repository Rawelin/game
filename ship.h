#ifndef SHIP_H
#define SHIP_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include <QTimer>
#include <QGraphicsScene>
#include <QDebug>
#include <QtWidgets>

class Ship : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    explicit Ship(QGraphicsItem * parent = 0);
    virtual QString getPath()const = 0;
    void setPicture(QString path);

signals:

public slots:
};

#endif // SHIP_H
