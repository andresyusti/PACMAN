#ifndef CUERPO_H
#define CUERPO_H


#include <QGraphicsItem>
#include <QPainter>
#include <sprites.h>


class cuerpo: public QGraphicsItem
{

    int r;
    int posx,posy;
    int velocidad = 7;
    sprites *spriet;

public:
    cuerpo(int r_, int x, int y);



    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);
    void up();
    void down();
    void left();
    void right();
};

#endif // CUERPO_H
