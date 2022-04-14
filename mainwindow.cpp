#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);


    scene=new QGraphicsScene(0,0,969,500);


    ui->graphicsView->setScene(scene);


}

void MainWindow::menu()
{
    scene->clear();
    //setBackgroundBrush(QBrush(QImage("")));
    QGraphicsTextItem * titleText = new QGraphicsTextItem(QString("Theory B"));
    QFont titleFont("comic sans",50);
    titleText->setFont(titleFont);

    int txPos = this->width()/2 -titleText->boundingRect().width()/2;
    int tyPos = 150;
    titleText->setPos(txPos,tyPos);
    scene->addItem(titleText);

    //Crear botones

    Button * playButton = new Button(QString("Nueva partida"));
    int bxPos = this->width()/2-playButton->boundingRect().width()/2;
    int byPos = 275;
    playButton->setPos(bxPos,byPos);
    connect(playButton,SIGNAL(clicked()),this,SLOT(PlayStart()));
    scene->addItem(playButton);

    Button * loadButton = new Button(QString("Cargar partida"));
    int lxPos = this->width()/2-loadButton->boundingRect().width()/2;
    int lyPos = 350;
    loadButton->setPos(lxPos,lyPos);
    //connect(playButton,SIGNAL(clicked()),this,SLOT(start()));
    scene->addItem(loadButton);
}


void MainWindow::keyPressEvent(QKeyEvent *evento)
{

    if(evento->key()==Qt::Key_D){
        player->MoveRight(10);
        player->setDireccion(true);
        if(player->getSaltando())player->setParabolico(false);

        scene->setSceneRect(player->getPosx()-150,0,969,500);

        if(colision<PersonajePrincipal,resorte>(player,resortes,index) || colision<PersonajePrincipal,objetoEstatico>(player,muros,index)){

        player->MoveLeft(10);

        }

    }
    else if(evento->key()==Qt::Key_A){
        player->MoveLeft(10);
        player->setDireccion(false);
        if(player->getSaltando())player->setParabolico(false);
        scene->setSceneRect(player->getPosx()-150,0,969,500);

       if(colision<PersonajePrincipal,resorte>(player,resortes,index) || colision<PersonajePrincipal,objetoEstatico>(player,muros,index)){

        player->MoveRight(10);

        }

    }

    else if(evento->key()==Qt::Key_Space){

         player->activarSalto(70);
         scene->setSceneRect(player->getPosx()-150,0,969,500);

    }
    else if (evento->key()==Qt::Key_F){
        bomba = new Bomba(player->getPosx(),player->getPosy());

        if (player->getDireccion()){
            bomba->setDerecha(true);
        }
        else{
            bomba->setDerecha(false);

        }
        scene->addItem(bomba);
        bomba->activarMovimiento(70);

    }


}



void MainWindow::verificarPosicionPersonaje()
{
    if(player->getPosy()>458){
        player->setPosy(457);
        player->timer->stop();
        player->setSaltando(false);
        player->setParabolico(true);

    }
    else if(player->getPosx()<14){
        player->setPosx(15);
        if(player->getSaltando()){
            player->setParabolico(false);
        }
    }
    if(colision<PersonajePrincipal,objetoEstatico>(player,muros,index)){

             player->MoveUp(1);
             player->timer->stop();
             player->setSaltando(false);


    }
    if(colision<PersonajePrincipal,resorte>(player,resortes,index)){
        resortes.at(index)->activarMovimiento();
        player->setSaltando(false);
        player->setParabolico(true);
        player->activarSalto(70);

    }

}



void MainWindow::colisionResorte()
{

}

void MainWindow::PlayStart()
{
    scene->clear();

    QImage imgBackground(":imagenes/escenario-1.png");

    QBrush background(imgBackground);

    scene->setBackgroundBrush(background);

    player = new PersonajePrincipal(15,380);

    movCircular = new ObjetoMovCircular(410,450,50);

    scene->addItem(movCircular);

    scene->addItem(player);

    resortes.append(new resorte(600 ,366,50));

    scene->addItem(resortes.back());

    enemigosvoladores.append(new enemigoVolador(500,300));

    enemigosterrestres.append( new enemigoTerrestre(400,550));

    scene->addItem(enemigosvoladores.back());

    scene->addItem(enemigosterrestres.back());

    inicializacionTimers();

    cargarObstaculosEstaticos();
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

void MainWindow::cargarObstaculosEstaticos()
{
    bbdd = new baseDeDatos();
    bbdd->getStaticObjects("muros.txt",muros);
    for(objetoEstatico *ite:muros){
        scene->addItem(ite);
    }

}








