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

    titleText->setPos(this->width()/2 -titleText->boundingRect().width()/2,150);
    scene->addItem(titleText);

    //Crear botones

    Button * playButton = new Button(QString("Nueva partida"));
    playButton->setPos(this->width()/2-playButton->boundingRect().width()/2,275);
    Button * loadButton = new Button(QString("Cargar partida"));
    loadButton->setPos(this->width()/2-loadButton->boundingRect().width()/2,350);
    //crear hilos
    connect(playButton,SIGNAL(clicked()),this,SLOT(ClickNuevaPartida()));
    connect(loadButton,SIGNAL(clicked()),this,SLOT(ClickcargarPartida()));
    //mostrar en escena
    scene->addItem(playButton);
    scene->addItem(loadButton);
}


void MainWindow::keyPressEvent(QKeyEvent *evento)
{

    if(evento->key()==Qt::Key_D){
        player->MoveRight(10);
        player->setDireccion(true);
        }
        if(player->getSaltando()){
            player->setParabolico(false);
        }
        if(colisionMuros(index)&& player->getPosy()>muros.at(index)->getPosy()){
            player->MoveLeft(30);
        }



    else if(evento->key()==Qt::Key_A){
        player->MoveLeft(30);
        player->setDireccion(false);

        if((colisionMuros(index)&& player->getPosy()>muros.at(index)->getPosy())){
            player->MoveRight(30);
        }
        if(player->getSaltando()){
            player->setParabolico(false);
        }

    }

    else if(evento->key()==Qt::Key_Space){

        player->activarSalto(angulo->angulo,60);
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
    else if (evento->key()==Qt::Key_K){
        if (angulo->angulo<90){
            angulo->SumAngulo();
        }

    }
    else if (evento->key()==Qt::Key_M){
        if (angulo->angulo>0){
            angulo->ResAngulo();
        }
    }
    else if(evento->key()==Qt::Key_Escape){
            GuardarPartida();
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
        player->MoveRight(30);
        if(player->getSaltando()){
            player->setParabolico(false);
        }
    }
    else if(player->getPosx()>3360){
        player->MoveLeft(30);
        if(player->getSaltando()){
            player->setParabolico(false);
        }
    }
   if (player->getPosx()>30 && player->getPosx()<2448){

       scene->setSceneRect(player->getPosx()-50,0,969,500);
       time->setX(player->getPosx());
       vida->setX(player->getPosx());
       angulo->setX(player->getPosx());

   }
   if (player->getPosx()>3200 && player->getPosy()>= 357){
           //hacer metodo para el segundo nivel de partida
           scene->clear();
           QImage imgBackground(":imagenes/escenario-2.png");
           QBrush background(imgBackground);
           scene->setBackgroundBrush(background);


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

//    if(colisionEnemigos() || colisionBolasFuego()){
//        if(vida->getVidas()>0){
//            vida->decrease();
//            player->establecerPosicion(15,457);
//        }else{
//            this->menu();
//        }
//    }

}

void MainWindow::NuevaPartida()
{
    scene->clear();
    //w2->deleteLater();
    QImage imgBackground(":imagenes/escenario-1.png");
    QBrush background(imgBackground);
    scene->setBackgroundBrush(background);


    player = new PersonajePrincipal(15,457);
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
    //cargar objetos en el mapa
    cargarObjetoEstatico("muros.txt",muros);
    cargarBolas("bolasFuego.txt",bolasFuego);
    cargarEnemigos("enemigos.txt",enemigos);
    cargarResortes("resortes.txt",resortes);

    inicializacionTimers();

}

void MainWindow::ClickNuevaPartida()
{
     w2 = new QMainWindow(this);
     w2->setGeometry(100,100,1000,550);
     graphicsView = new QGraphicsView(new QGraphicsScene(),w2);
     graphicsView->setGeometry(0,0,1000,550);
     graphicsView->show();

     Usuario = new QTextEdit(w2);
     Usuario->setGeometry(QRect(330, 130, 221, 41));
     Usuario->setPlaceholderText("Usuario");
     Contrasena = new QTextEdit(w2);
     Contrasena->setGeometry(QRect(330, 190, 221, 41));
     Contrasena->setPlaceholderText("Contraseña");

     pushButton = new QPushButton(QString("Play"),w2);
     pushButton->setGeometry(QRect(410, 270, 80, 25));
     w2->show();
     connect(pushButton,SIGNAL(clicked()),this,SLOT(verificarNuevaPartida()));

}

void MainWindow::ClickcargarPartida()
{
    w2 = new QMainWindow(this);
    w2->setGeometry(0,0,1000,550);
    graphicsView = new QGraphicsView(new QGraphicsScene(),w2);
    graphicsView->setGeometry(0,0,1000,550);
    graphicsView->show();

    Usuario = new QTextEdit(w2);
    Usuario->setGeometry(QRect(330, 130, 221, 41));
    Usuario->setPlaceholderText("Usuario");
    Contrasena = new QTextEdit(w2);
    Contrasena->setGeometry(QRect(330, 190, 221, 41));
    Contrasena->setPlaceholderText("Contraseña");

    pushButton = new QPushButton(QString("Play"),w2);
    pushButton->setGeometry(QRect(410, 270, 80, 25));
    w2->show();
    connect(pushButton,SIGNAL(clicked()),this,SLOT(verificarPartidaGuardada()));

}

void MainWindow::partidaGuardada()
{
    scene->clear();
    float posx,posy;
    short int tiempo,vidas,mapa;
    string archivoMuros,archivoBolas,archivoResortes,archivoEnemigos;
    bbdd->getPartida(Usuario->toPlainText(), mapa, posx,posy,tiempo,vidas);
    w2->deleteLater();
    if (mapa == 1){
        QImage imgBackground(":imagenes/escenario-1.png");
        QBrush background(imgBackground);
        scene->setBackgroundBrush(background);
        archivoMuros = "muros.txt";
        archivoBolas = "bolasFuego.txt";
        archivoEnemigos = "enemigos.txt";
        archivoResortes = "resortes.txt";
    }else if (mapa==2){
        QImage imgBackground(":imagenes/escenario-2.png");
        QBrush background(imgBackground);
        scene->setBackgroundBrush(background);
        archivoMuros = "muros2.txt";
        archivoBolas = "bolasFuego2.txt";
        archivoEnemigos = "enemigos2.txt";
        archivoResortes = "resortes2.txt";
    }


    player = new PersonajePrincipal(posx,posy);
    scene->addItem(player);

    // Tiempo
    time = new  Tiempo();
    time->setX(player->getPosx());
    time->setTiempo(tiempo);
    scene->addItem(time);

    //vidas

    vida = new Vidas();
    vida->setPos(player->getPosx(),vida->y()+25);
    vida->setVidas(vidas);
    scene->addItem(vida);

    //Ángulo

    angulo = new Angulo();
    angulo->setPos(player->getPosx(),angulo->y()+50);
    scene->addItem(angulo);


    cargarObjetoEstatico(archivoMuros,muros);
    cargarBolas(archivoBolas,bolasFuego);
    cargarEnemigos(archivoEnemigos,enemigos);
    cargarResortes(archivoResortes,resortes);
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

void MainWindow::GuardarPartida()
{
    bbdd->setPartida(Usuario->toPlainText(),Contrasena->toPlainText(),player->getNivel(), player->getPosx(), player->getPosy(), time->getTiempo(),vida->getVidas());
    menu();
}

void MainWindow::verificarNuevaPartida()
{
    if (!bbdd->verificarDatos(Usuario->toPlainText())){
        connect(pushButton,SIGNAL(clicked()),this,SLOT(NuevaPartida()));
    }
    else{
        w2->deleteLater();
        ClickNuevaPartida();
    }
}

void MainWindow::verificarPartidaGuardada()
{
    if (bbdd->verificarContrasena(Usuario->toPlainText(),Contrasena->toPlainText())){
        connect(pushButton,SIGNAL(clicked()),this,SLOT(partidaGuardada()));
    }
    else{
        w2->deleteLater();
        ClickcargarPartida();
    }

}








