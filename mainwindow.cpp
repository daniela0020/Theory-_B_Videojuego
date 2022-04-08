#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);

    this->setFixedSize(this->screen()->availableSize().width(),700);

    ui->graphicsView->setFixedSize(this->screen()->availableSize().width()-70,700);

    scene=new QGraphicsScene();

    scene->setSceneRect(0,0,ui->graphicsView->width(),ui->graphicsView->height()-150);

    ui->graphicsView->setScene(scene);

    scene->setBackgroundBrush(Qt::black);

    perso=new personaje(300,310,34,34);

    scene->addItem(perso);

    resort=new resorte(250,550,20,40,50);

    scene->addItem(resort);

    floor= new piso(0,-550,scene->width(),10);

    scene->addItem(floor);

}


void MainWindow::keyPressEvent(QKeyEvent *evento)
{
    if(evento->key()==Qt::Key_W){
        perso->MoveUp(4);

        if(colisionConMuro<personaje,resorte>(perso,resort) || colisionConMuro<personaje,piso>(perso,floor)){
        perso->MoveDown(4);
        }
    }
    else if(evento->key()==Qt::Key_S){
        perso->MoveDown(4);
        if(colisionConMuro<personaje,resorte>(perso,resort)){
        resort->activarMovimiento();
        resort->setColision(colisionConMuro<resorte,piso>(resort,floor));

        }

    }

    else if(evento->key()==Qt::Key_D){
        perso->MoveRight(4);
        if(colisionConMuro<personaje,resorte>(perso,resort)|| colisionConMuro<personaje,piso>(perso,floor)){
        perso->MoveLeft(4);
        }
    }
    else if(evento->key()==Qt::Key_A){
        perso->MoveLeft(4);
        if(colisionConMuro<personaje,resorte>(perso,resort)|| colisionConMuro<personaje,piso>(perso,floor)){
        perso->MoveRight(4);
        }
    }

}

void MainWindow::colisionResorte()
{

        if(colisionConMuro<resorte,piso>(resort,floor)){
            resort->MoveUp(4);
        }
}




