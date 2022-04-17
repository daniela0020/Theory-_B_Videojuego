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

        scene->setSceneRect(player->getPosx()-100,0,969,500);

        if(colision<PersonajePrincipal,objetoEstatico>(player,muros,index)){

        player->MoveLeft(10);

        }

    }
    else if(evento->key()==Qt::Key_A){
        player->MoveLeft(10);
        player->setDireccion(false);
        if(player->getSaltando())player->setParabolico(false);
        scene->setSceneRect(player->getPosx()-100,0,969,500);

       if(colision<PersonajePrincipal,objetoEstatico>(player,muros,index)){

        player->MoveRight(10);

        }

    }

    else if(evento->key()==Qt::Key_Space){

         player->activarSalto(70,40);
         scene->setSceneRect(player->getPosx()-100,0,969,500);

    }
    else if (evento->key()==Qt::Key_F){
        bombas.append( new Bomba(player->getPosx(),player->getPosy()));

        if (player->getDireccion()){
            bombas.back()->setDerecha(true);
        }
        else{
            bombas.back()->setDerecha(false);

        }
        scene->addItem(bombas.back());
        bombas.back()->activarMovimiento(30);

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
    if(player->getPosx()<14){
        player->MoveRight(3);
        if(player->getSaltando()){
            player->setParabolico(false);
        }
    }
    else if(player->getPosx()>3360){
        player->MoveLeft(3);
        if(player->getSaltando()){
            player->setParabolico(false);
        }
    }
    if(colision<PersonajePrincipal,objetoEstatico>(player,muros,index)){

        if(player->getPosy()>=muros.at(index)->getPosy()){

            player->setParabolico(false);

        }else if(player->getPosy()<=muros.at(index)->getPosy()){
                player->MoveUp(1);
                player->timer->stop();
                player->setSaltando(false);
                player->setParabolico(true);
        }




    }

    if(colision<PersonajePrincipal,resorte>(player,resortes,index) && !resortes.at(index)->getActivado()){

        resortes.at(index)->activarMovimiento();
        player->setSaltando(false);
        player->setDireccion(true);
        player->setParabolico(true);
        player->activarSalto(70,80);

    }


}





void MainWindow::PlayStart()
{
    scene->clear();

    QImage imgBackground(":imagenes/escenario-1.png");

    QBrush background(imgBackground);

    scene->setBackgroundBrush(background);

    player = new PersonajePrincipal(15,380);

    scene->addItem(player);

    cargarObjetoEstatico("muros.txt",muros);

    cargarBolas("bolasFuego.txt",bolasFuego);

    cargarEnemigos("enemigos.txt",enemigos);

    cargarResortes("resortes.txt",resortes);

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

void MainWindow::cargarObjetoEstatico(string nombreFichero, QList<objetoEstatico *> &lista)
{

    bbdd->getStaticObjects(nombreFichero,lista);
    for(objetoEstatico *ite:lista){
        scene->addItem(ite);
    }
}

void MainWindow::cargarBolas(string nombreFichero, QList<ObjetoMovCircular*> &listaBolas)
{
    bbdd->getBolasFuego(nombreFichero,listaBolas);
    for(ObjetoMovCircular *ite:listaBolas){
        scene->addItem(ite);
    }
}

void MainWindow::cargarEnemigos(string nombreFichero, QList<Enemigo *> &listaEnemigos)
{
    bbdd->getEnemigos(nombreFichero,listaEnemigos);
    for(Enemigo *ite:listaEnemigos){
        scene->addItem(ite);
    }
}

void MainWindow::cargarResortes(string nombreFichero, QList<resorte *> &listaResortes)
{
    bbdd->getResortes(nombreFichero,listaResortes);
    for(resorte *ite:listaResortes){
        scene->addItem(ite);
    }
}




