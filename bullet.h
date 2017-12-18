#ifndef BULLET_H
#define BULLET_H

#include <QObject>
#include <QGraphicsPixmapItem>

class bullet : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    //constructor
    bullet(int x,int y);

public slots:
    void fly();
};

#endif // BULLET_H
