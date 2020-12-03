#include "sprites.h"

sprites::sprites(QObject *parent) : QObject(parent)
{
    timer = new QTimer();
    filas = 0;
    columnas = 0;

    ancho = 75;
    alto = 75;

    posicion = 0;


    pixmap = new QPixmap(":/imagenes/PACMAN 2.0.png");

    timer->start(70);
    connect(timer, &QTimer::timeout, this, &sprites::actualizacion);
}


void sprites::actualizacion()
{
    columnas += 75;
    if(columnas >= 300){
        columnas = 0;
    }
    this->update(-ancho/2, -alto/2, ancho, alto);
}


QRectF sprites::boundingRect() const
{
    return QRectF(-ancho/2, -alto/2, ancho, alto);
}

void sprites::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(-ancho/2, -alto/2, *pixmap, columnas, posicion, ancho, alto);
}

void sprites::up()
{
    posy -= 1*velocidad;
    posicion = 150;
    setPos(posx, posy);
}

void sprites::down()
{
    posy += 1*velocidad;
    posicion = 225;
    setPos(posx, posy);
}

void sprites::left()
{
    posx -= 1*velocidad;
    posicion = 75;
    setPos(posx, posy);
}

void sprites::right()
{
    posx += 1*velocidad;
    posicion = 0;
    setPos(posx, posy);
}
