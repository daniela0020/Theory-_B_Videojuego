#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);


    scene=new QGraphicsScene();

    this->setFixedSize(this->screen()->availableSize().width(),this->screen()->availableSize().height());

    ui->graphicsView->setFixedSize(this->screen()->availableSize().width(),this->screen()->availableSize().height());

    scene=new QGraphicsScene();

    scene->setSceneRect(0,0,ui->graphicsView->width()-70,ui->graphicsView->height()-150);

    ui->graphicsView->setScene(scene);

    scene->setBackgroundBrush(Qt::green);

    player = new PersonajePrincipal(300,550);

    movCircular = new ObjetoMovCircular(400,410);

    scene->addItem(movCircular);

    scene->addItem(player);

    resort=new resorte(250,550,50);

    scene->addItem(resort);

    enemigovolador=new enemigoVolador(500,300);

    scene->addItem(enemigovolador);

    inicializacionTimers();


}


void MainWindow::keyPressEvent(QKeyEvent *evento)
{
     /*if(evento->key()==Qt::Key_S){
        player->MoveDown(30);
        if(resort->getCounterColision()==1){

                player->setVelocidadPaso(resort->getVelocidad());
                player->setDerecha(true);
                player->activarSalto(45);
       }
        if(colisionConMuro<PersonajePrincipal,resorte>(player,resort)){
        resort->activarMovimiento();
        resort->setCounterColision(1);
        }

    }*/

    else if(evento->key()==Qt::Key_D){
        player->MoveRight(30);
        if(colisionConMuro<PersonajePrincipal,resorte>(player,resort) ){
        player->MoveLeft(30);

        }

    }
    else if(evento->key()==Qt::Key_A){
        player->MoveLeft(30);
        if(colisionConMuro<PersonajePrincipal,resorte>(player,resort) ){
        player->MoveRight(30);

        }

    }
    if (evento->type() == QEvent::KeyPress ) {

           pressedKeys += ((QKeyEvent*)evento)->key();

           if ( pressedKeys.contains(Qt::Key_D) && pressedKeys.contains(Qt::Key_Space) )
           {
               player->setDerecha(true);
               player->activarSalto(45);
               pressedKeys.clear();
           }
           else if ( pressedKeys.contains(Qt::Key_A) && pressedKeys.contains(Qt::Key_Space) )
           {
               player->setDerecha(false);
               player->activarSalto(45);
               pressedKeys.clear();
           }
    }


}

void MainWindow::inicializacionTimers()
{
    timers.append(new QTimer());
    timers.append(new QTimer());

    for(int i=0;i<timers.size();i++){
        timers.at(i)->start(10);
    }

    connect(timers.at(0),&QTimer::timeout,this,&MainWindow::verificarPosicionPersonaje);

}

void MainWindow::verificarPosicionPersonaje()
{
    if(player->getPosy()>551){
        player->setPosy(550);
        player->timer->stop();
                //disconnect(player->timer,&QTimer::timeout,this,&PersonajePrincipal::actualizarSalto);
    }

}

void MainWindow::colisionResorte()
{

}






