#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QRect desktop = QApplication::desktop()->screenGeometry();
    x = desktop.x();
    y = desktop.y();
    ancho = 1500; //desktop.width();
    alto = 700; //desktop.height();

    scene = new QGraphicsScene(x, y, ancho, alto);

    //scene->setBackgroundBrush(QPixmap(":/imagenes/mapa pacman prueba.png"));
    ui->graphicsView->setScene(scene);
    ui->puntaje->setText(QString::number(puntajes));


    muros.push_back(new pared(30, 226, 112, 112)); scene->addItem(muros.back());
    muros.push_back(new pared(60, 90, 150, 200)); scene->addItem(muros.back());

    monedas.push_back(new moneda(5,250,300));scene->addItem(monedas.back());
    monedas.push_back(new moneda(5,200,300));scene->addItem(monedas.back());

    personaje = new sprites();

    scene->addItem(personaje);

    personaje->setPos(73, 73);
}

void MainWindow::keyPressEvent(QKeyEvent *evento){
    if(evento->key() == Qt::Key_A){
        personaje->left();
        for (int i = 0;i < monedas.size();i++) {
                    if(personaje->collidesWithItem(monedas.at(i))){
                        scene->removeItem(monedas.at(i));
                        monedas.removeAt(i);
                        puntajes = puntajes+150;
                        ui->puntaje->setText((QString::number(puntajes)));
                    }
                }
        for (int i = 0;i < muros.size();i++) {
                    if(personaje->collidesWithItem(muros.at(i))){
                        personaje->right();
                    }
        }
    }
    if(evento->key() == Qt::Key_D){
        personaje->right();
        for (int i = 0;i < monedas.size();i++) {
                    if(personaje->collidesWithItem(monedas.at(i))){
                        scene->removeItem(monedas.at(i));
                        monedas.removeAt(i);
                        puntajes=puntajes+50;
                        ui->puntaje->setText((QString::number(puntajes)));
                    }
                }
        for (int i = 0;i < muros.size();i++){
            if(personaje->collidesWithItem(muros.at(i))){
                personaje->left();
            }
        }
    }
    if(evento->key() == Qt::Key_W){
        personaje->up();
        for (int i = 0;i < monedas.size();i++) {
                   if(personaje->collidesWithItem(monedas.at(i))){
                       scene->removeItem(monedas.at(i));
                       monedas.removeAt(i);
                       puntajes=puntajes+50;
                       ui->puntaje->setText((QString::number(puntajes)));
                   }
               }
        for (int i = 0;i < muros.size();i++){
            if(personaje->collidesWithItem(muros.at(i))){
                personaje->down();
            }
        }
    }
    if(evento->key() == Qt::Key_S){
        personaje->down();
        for (int i = 0;i < monedas.size();i++) {
                   if(personaje->collidesWithItem(monedas.at(i))){
                       scene->removeItem(monedas.at(i));
                       monedas.removeAt(i);
                       puntajes=puntajes+50;
                       ui->puntaje->setText((QString::number(puntajes)));
                   }
               }
        for (int i = 0;i < muros.size();i++){
            if(personaje->collidesWithItem(muros.at(i))){
                personaje->up();
            }
        }
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

