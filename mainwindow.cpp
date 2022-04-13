#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);

    scene=new QGraphicsScene(0,0,969,499);

    QImage imgBackground(":/imagenes/mapa1.png");

    QBrush background(imgBackground);

    scene->setBackgroundBrush(background);

    ui->graphicsView->setScene(scene);

    player = new PersonajePrincipal(40,390);

    movCircular = new ObjetoMovCircular(400,410);

    scene->addItem(movCircular);

    scene->addItem(player);

    resort=new resorte(250,550,50);

    scene->addItem(resort);

    enemigovolador=new enemigoVolador(500,300);

    scene->addItem(enemigovolador);

    inicializacionTimers();

    bbdd->getStaticObjects<float>("murosHorizontales.txt","muros",murosHorizontales);


}


void MainWindow::keyPressEvent(QKeyEvent *evento)
{

    if(evento->key()==Qt::Key_D){
        player->MoveRight();
        player->setParabolico(false);
        if(colision<PersonajePrincipal,resorte>(player,resort)){

        player->MoveLeft();

        }

    }
    else if(evento->key()==Qt::Key_A){
        player->MoveLeft();
        player->setParabolico(false);
       if(colision<PersonajePrincipal,resorte>(player,resort) ){

        player->MoveRight();

        }

    }

    if (evento->type() == QEvent::KeyPress ) {

           pressedKeys += ((QKeyEvent*)evento)->key();

           if ( pressedKeys.contains(Qt::Key_A) && pressedKeys.contains(Qt::Key_Space) )
           {

               player->setParabolico(true);
               player->setDireccion(false);
               player->activarSalto(70);
               pressedKeys.clear();
           }
           else if ( pressedKeys.contains(Qt::Key_D) && pressedKeys.contains(Qt::Key_Space) )
           {

               player->setParabolico(true);
               player->setDireccion(true);
               player->activarSalto(70);
               pressedKeys.clear();
           }
           else if ( pressedKeys.contains(Qt::Key_A) && pressedKeys.contains(Qt::Key_F) )
           {
               bomba = new Bomba(player->getPosx(),player->getPosy());
               bomba->setDerecha(false);
               scene->addItem(bomba);
               bomba->activarMovimiento(70);
               pressedKeys.clear();
           }
           else if ( pressedKeys.contains(Qt::Key_D) && pressedKeys.contains(Qt::Key_F) )
           {
               bomba = new Bomba(player->getPosx(),player->getPosy());
               bomba->setDerecha(true);
               scene->addItem(bomba);
               bomba->activarMovimiento(70);
               pressedKeys.clear();
           }
    }
}



void MainWindow::verificarPosicionPersonaje()
{
    if(player->getPosy()>492){
        player->setPosy(492);
        player->timer->stop();

        player->setSaltando(false);
             
    }
    for(int i=0;i<murosHorizontales.size()-3;i++){
        murosHorizontales.at(i);
    }

}

void MainWindow::colisionResorte()
{
    if(colision<PersonajePrincipal,resorte>(player,resort)&& resort->getActivado()){
        player->setVelocidadInicial(player->getVelocidadInicial()+resort->getVelocidad());
        player->setParabolico(true);
        player->activarSalto(70);
    }
    if(colision<PersonajePrincipal,resorte>(player,resort)&&player->getPosy()<resort->getPosy() && !resort->getActivado()){
        resort->activarMovimiento();
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
    connect(timers.at(1),&QTimer::timeout,this,&MainWindow::colisionResorte);
}







