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
    scene->addItem(playButton);
    connect(playButton,SIGNAL(clicked()),this,SLOT(NuevaPartida()));

    Button * loadButton = new Button(QString("Cargar partida"));
    int lxPos = this->width()/2-loadButton->boundingRect().width()/2;
    int lyPos = 350;
    loadButton->setPos(lxPos,lyPos);
    //connect(playButton,SIGNAL(clicked()),this,SLOT(start()));
    scene->addItem(loadButton);
}


void MainWindow::keyPressEvent(QKeyEvent *evento)
{
    static bool escena2 = false;
    if(evento->key()==Qt::Key_D){
        player->MoveRight(10);
        player->setDireccion(true);
        if (player->getPosx()<2448){
            scene->setSceneRect(player->getPosx()-50,0,969,500);
            time->setX(player->getPosx());
            vida->setX(player->getPosx());
            angulo->setX(player->getPosx());
        }
        else if (player->getPosx()>=3270){
            player->MoveLeft(30);
        }
        if(player->getSaltando()){
                    player->setParabolico(false);
        }
        if(colisionMuros(index)&& player->getPosy()>muros.at(index)->getPosy()){
            player->MoveLeft(30);
        }

        if (player->getPosx()>3200 && player->getPosy()>= 357){
            if (!escena2){
                scene->clear();
                QImage imgBackground(":imagenes/escenario-2.png");
                QBrush background(imgBackground);

                scene->setBackgroundBrush(background);

                //setBackgroundBrush(QBrush(QImage("")));
                player = new PersonajePrincipal(50,379);


                scene->addItem(player);

                // Tiempo
                time = new  Tiempo();
                scene->addItem(time);

                //vidas

                vida = new Vidas();
                vida->setPos(vida->x(),vida->y()+25);
                scene->addItem(vida);

                //Ángulo

                angulo = new Angulo();
                angulo->setPos(player->getPosx(),angulo->y()+50);
                scene->addItem(angulo);





                inicializacionTimers();
                escena2 = true;
            }


        }

    }
    else if(evento->key()==Qt::Key_A){
        player->MoveLeft(30);
        player->setDireccion(false);

        if (player->getPosx()>30 && player->getPosx()<2448){

            scene->setSceneRect(player->getPosx()-50,0,969,500);
            time->setX(player->getPosx());
            vida->setX(player->getPosx());
            angulo->setX(player->getPosx());


        }
        else if(player->getPosx()<=30){
            player->MoveRight(30);
        }
        if(player->getSaltando()){
             player->setParabolico(false);
        }
        if(colisionMuros(index)&& player->getPosy()>muros.at(index)->getPosy()){
            player->MoveRight(30);
        }

    }

    else if(evento->key()==Qt::Key_Space){

         player->activarSalto(angulo->angulo,50);
         if (player->getPosx()>30 && player->getPosx()<2448){
             scene->setSceneRect(player->getPosx()-50,0,969,500);
             time->setX(player->getPosx());
             vida->setX(player->getPosx());
             angulo->setX(player->getPosx());

         }
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
        bombas.back()->activarMovimiento(angulo->angulo);


    }
    if (evento->key()==Qt::Key_K){
        if (angulo->angulo<90){
            angulo->SumAngulo();
        }

    }
    else if (evento->key()==Qt::Key_M){
        if (angulo->angulo>0){
            angulo->ResAngulo();
        }
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
    if(player->getSaltando()){

        if(player->getSubiendo() && colisionMuros(index) && player->getPosy()>muros.at(index)->getPosy()){

            player->setParabolico(false);

        }else if(!player->getSubiendo() && colisionMuros(index)){
            player->MoveUp(1);
            player->timer->stop();
            player->setSaltando(false);
            player->setParabolico(true);
        }

    }
    if(!player->getSaltando() && !colisionMuros(index) && player->getPosy()<457)
    {
        player->setParabolico(false);
        player->activarSalto(0,40);
    }
    else if(!player->getParabolico() && colisionMuros(index) && player->getPosy()<muros.at(index)->getPosy()){
        player->MoveUp(1);
        player->timer->stop();
        player->setSaltando(false);
        player->setParabolico(true);
    }


    if(colisionResortes(index) && !resortes.at(index)->getActivado()){

        resortes.at(index)->activarMovimiento();
        player->setSaltando(false);
        player->setDireccion(true);
        player->setParabolico(true);
        player->activarSalto(angulo->angulo,80);

    }

    if(colisionEnemigos() || colisionBolasFuego()){
        if(vida->getVidas()>0){
            vida->decrease();
            player->establecerPosicion(15,457);
        }else{
            this->PlayStart();
        }
    }

}

void MainWindow::PlayStart()
{
    scene->clear();
    QImage imgBackground(":imagenes/escenario-1.png");
    QBrush background(imgBackground);
    player = new PersonajePrincipal(15,457);

    scene->setBackgroundBrush(background);

    //setBackgroundBrush(QBrush(QImage("")));
    scene->addItem(player);

    // Tiempo
    time = new  Tiempo();
    time->setX(player->getPosx());
    scene->addItem(time);

    //vidas

    vida = new Vidas();
    vida->setPos(player->getPosx(),vida->y()+25);
    scene->addItem(vida);

    //Ángulo

    angulo = new Angulo();
    angulo->setPos(player->getPosx(),angulo->y()+50);

    scene->addItem(angulo);

    cargarObjetoEstatico("muros.txt",muros);

    cargarBolas("bolasFuego.txt",bolasFuego);

    cargarEnemigos("enemigos.txt",enemigos);

    cargarResortes("resortes.txt",resortes);

    inicializacionTimers();
}

void MainWindow::NuevaPartida()
{
     scene->clear();
     //scene=new QGraphicsScene(0,0,969,500);
     ventana->graphicsView->setScene(scene);

     ventana->Usuario->setPlaceholderText("Usuario");
     ventana->Contrasena->setPlaceholderText("Contraseña");

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

bool MainWindow::colisionMuros(int &index)
{
    bool colision=false;
    for(objetoEstatico *ite:muros){
        if(player->collidesWithItem(ite)){
            index=muros.indexOf(ite);
            colision=true;
            break;
        }
    }

    return colision;
}

bool MainWindow::colisionEnemigos()
{
    bool colision=false;
    for(Enemigo *ite:enemigos){
        if(player->collidesWithItem(ite)){
            colision=true;
            break;
        }
    }

    return colision;
}

bool MainWindow::colisionBolasFuego()
{
    bool colision=false;
    for(ObjetoMovCircular *ite:bolasFuego){
        if(player->collidesWithItem(ite)){
            colision=true;
            break;
        }
    }

    return colision;
}

bool MainWindow::colisionResortes(int &index)
{
    bool colision=false;
    for(resorte *ite:resortes){
        if(player->collidesWithItem(ite)){
            index=resortes.indexOf(ite);
            colision=true;
            break;
        }
    }

    return colision;
}








