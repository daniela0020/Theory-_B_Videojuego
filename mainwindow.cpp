#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);


    scene=new QGraphicsScene(0,0,969,500);


    ui->graphicsView->setScene(scene);


    //player = new PersonajePrincipal(300,550);

    //movCircular = new ObjetoMovCircular(400,410);

    //scene->addItem(movCircular);

    //scene->addItem(player);


    //resort=new resorte(250,550,50);

    //scene->addItem(resort);

    //enemigovolador=new enemigoVolador(500,300);

    //scene->addItem(enemigovolador);

    //inicializacionTimers();


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
        player->MoveRight(30);
        player->setDerecha(true);
        scene->setSceneRect(player->getPosx()-50,0,969,500);

        if(colisionConMuro<PersonajePrincipal,resorte>(player,resort)){

        player->MoveLeft(30);

        }

    }
    else if(evento->key()==Qt::Key_A){
        player->MoveLeft(30);
        player->setDerecha(false);
        scene->setSceneRect(player->getPosx()-50,0,969,500);

       if(colisionConMuro<PersonajePrincipal,resorte>(player,resort) ){

        player->MoveRight(30);

        }

    }

    else if(evento->key()==Qt::Key_Space){

         player->activarSalto(45);
         scene->setSceneRect(player->getPosx()-50,0,969,500);

    }
    else if (evento->key()==Qt::Key_F){
        bomba = new Bomba(player->getPosx(),player->getPosy());
        if (player->getDerecha()){
            bomba->setDerecha(true);
        }
        else{
            bomba->setDerecha(false);

        }
        scene->addItem(bomba);
        bomba->activarMovimiento(70);

    }
    else if (evento->key()==Qt::Key_Up){

    }

}



void MainWindow::verificarPosicionPersonaje()
{
    if(player->getPosy()>551){
        player->setPosy(550);
        player->timer->stop();

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

    //setBackgroundBrush(QBrush(QImage("")));
    player = new PersonajePrincipal(300,300);
    movCircular = new ObjetoMovCircular(400,410);

    scene->addItem(movCircular);

    scene->addItem(player);


    resort=new resorte(250,550,50);

    scene->addItem(resort);

    enemigovolador=new enemigoVolador(500,300);
    enemigoterrestre = new enemigoTerrestre(400,550);

    scene->addItem(enemigovolador);
    scene->addItem(enemigoterrestre);

    inicializacionTimers();
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







