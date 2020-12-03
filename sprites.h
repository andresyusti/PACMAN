#ifndef SPRITES_H
#define SPRITES_H

#include <QObject>
#include <QGraphicsItem>
#include <QTimer>
#include <QPixmap>
#include <QPainter>

class sprites: public QObject, public QGraphicsItem
{
public:
    explicit sprites(QObject *parent = nullptr);

    QTimer * timer;
    QPixmap * pixmap;

    float filas, columnas;
    float ancho, alto;
    float posicion;

    int posx = 73,posy = 73;
    int velocidad = 7;

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    void up();
    void down();
    void left();
    void right();

signals:

public slots:
    void actualizacion();
};

#endif // SPRITES_H
