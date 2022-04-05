#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene=new QGraphicsScene();

       ui->graphicsView->setScene(scene);

       setWindowTitle("prueba resorte");

       scene->setSceneRect(0,0,600,650);

       scene->setBackgroundBrush(Qt::black);

       perso=new personaje(300,310);

       scene->addItem(perso);

       resort=new resorte(200,300,50);

       scene->addItem(resort);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *evento)
{
    if(evento->key()==Qt::Key_W){
        perso->MoveUp();
        if(evaluarFantasmaColisionMuro(resort)){
        perso->MoveDown();
        }
    }
    else if(evento->key()==Qt::Key_S){
        perso->MoveDown();
        if(evaluarFantasmaColisionMuro(resort)){
        resort->activarMovimiento();
        }
    }

    else if(evento->key()==Qt::Key_D){
        perso->MoveRight();
        if(evaluarFantasmaColisionMuro(resort)){
        perso->MoveLeft();
        }
    }
    else if(evento->key()==Qt::Key_A){
        perso->MoveLeft();
        if(evaluarFantasmaColisionMuro(resort)){
        perso->MoveRight();
        }
    }

}
bool MainWindow::evaluarFantasmaColisionMuro(resorte *res)
{
    bool colision=false;
    if(perso->collidesWithItem(res)){
        colision=true;
    }
    return colision;
}

