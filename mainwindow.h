#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <iostream>
#include <string>
#include "sprites.h"
#include <pared.h>
#include <moneda.h>
#include <QPainter>
#include <QGraphicsItem>
#include <QRectF>
#include <QDesktopWidget>
#include <QDebug>
#include <QGraphicsScene>
#include <QKeyEvent>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    QList<pared *> muros;
    QList<moneda *> monedas;

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;



    sprites *personaje;

    float x, y, ancho, alto;
    int puntajes = 0;

    void keyPressEvent(QKeyEvent *evento);
};
#endif // MAINWINDOW_H
