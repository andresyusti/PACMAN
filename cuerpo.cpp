#include "cuerpo.h"


cuerpo::cuerpo(int r_, int x, int y)
{
    r = r_;
    posx = x;
    posy = y;
    setPos(posx, posy);
}


QRectF cuerpo::boundingRect() const
{
    return QRectF(-r, -r, 2*r, 2*r);
}

void cuerpo::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::yellow);
    painter->drawEllipse(boundingRect());
}

void cuerpo::up()
{
    posy -= 1*velocidad;
    setPos(posx, posy);
}

void cuerpo::down()
{
    posy += 1*velocidad;
    setPos(posx, posy);
}

void cuerpo::left()
{
    posx -= 1*velocidad;
    setPos(posx, posy);
}

void cuerpo::right()
{
    posx += 1*velocidad;
    setPos(posx, posy);
}
