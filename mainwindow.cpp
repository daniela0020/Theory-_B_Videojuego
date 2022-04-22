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
void MainWindow::ClickNuevaPartida()
{

    w2 = new QMainWindow(this);
    w2->setGeometry(150,90,1000,550);
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
    w2->setGeometry(150,90,1000,550);
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
void MainWindow::NuevaPartida()
{
    scene->clear();
    w2->close();
    nivel=1;
    QImage imgBackground(":imagenes/escenario-1.png");
    QBrush background(imgBackground);
    scene->setBackgroundBrush(background);


    player = new PersonajePrincipal(30,355);
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
    cargarObjetos("muros.txt","bolasFuego.txt","resortes.txt","enemigos.txt");
    inicializacionTimers();

}
void MainWindow::partidaGuardada()
{
    scene->clear();
    w2->close();
    float posx,posy;
    short int tiempo,vidas,mapa;
    string archivoMuros,archivoBolas,archivoResortes,archivoEnemigos;
    bbdd->getPartida(Usuario->toPlainText(), mapa, posx,posy,tiempo,vidas);
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

    nivel=mapa;
    player = new PersonajePrincipal(posx,posy);
    scene->addItem(player);

    // Tiempo
    time = new  Tiempo();
    time->setX(player->getPosx());
    time->setTiempo(tiempo);
    scene->addItem(time);


    //vidas
    vida= new Vidas();
    vida->setPos(player->getPosx(),vida->y()+25);
    vida->setVidas(vidas);
    scene->addItem(vida);

    //Ángulo
    angulo = new Angulo();
    angulo->setPos(player->getPosx(),angulo->y()+50);
    scene->addItem(angulo);


    cargarObjetos(archivoMuros,archivoBolas,archivoResortes,archivoEnemigos);
    inicializacionTimers();
}

void MainWindow::siguientePartida()
{
    scene->clear();
    string archivoMuros,archivoBolas,archivoResortes,archivoEnemigos;
    if (nivel == 2){
        QImage imgBackground(":imagenes/escenario-2.png");
        QBrush background(imgBackground);
        scene->setBackgroundBrush(background);
        archivoMuros = "muros2.txt";
        archivoBolas = "bolasFuego2.txt";
        archivoEnemigos = "enemigos2.txt";
        archivoResortes = "resortes2.txt";
    }

    player= new PersonajePrincipal(20,432);
    scene->addItem(player);

    // Tiempo
    time = new  Tiempo();
    time->setX(player->getPosx());
    scene->addItem(time);

    //vidas

    vida = new Vidas();
    vida->setPos(player->getPosx(),vida->y()+25);
    vida->setVidas(vida->getVidas());
    scene->addItem(vida);

    //Ángulo

    angulo = new Angulo();
    angulo->setPos(player->getPosx(),angulo->y()+50);
    scene->addItem(angulo);


    cargarObjetos(archivoMuros,archivoBolas,archivoResortes,archivoEnemigos);
}

void MainWindow::creditos()
{
    w2 = new QMainWindow(this);
    w2->setGeometry(150,90,1000,550);
    QGraphicsScene *scenen= new QGraphicsScene(0,0,1000,550);
    graphicsView = new QGraphicsView(scenen,w2);
    graphicsView->setGeometry(0,0,1000,550);
    graphicsView->show();

    QGraphicsTextItem * titleText = new QGraphicsTextItem(QString("Theory B"));
    QGraphicsTextItem * desarrollador1 = new QGraphicsTextItem(QString("Daniela Alvares Bernal"));
    QGraphicsTextItem * desarrollador2 = new QGraphicsTextItem(QString("Edisson Chamorro Coral"));
    QFont titleFont("comic sans",50);
    QFont devFont("comic sans",20);
    titleText->setFont(titleFont);
    desarrollador1->setFont(devFont);
    desarrollador2->setFont(devFont);

    titleText->setPos(this->width()/2 -titleText->boundingRect().width()/2,150);
    desarrollador1->setPos(this->width()/2 -titleText->boundingRect().width()/2,250);
    desarrollador2->setPos(this->width()/2 -titleText->boundingRect().width()/2,290);
    scenen->addItem(titleText);
    scenen->addItem(desarrollador1);
    scenen->addItem(desarrollador2);
    if(w2->isHidden())this->close();

}

void MainWindow::keyPressEvent(QKeyEvent *evento)
{

    if(evento->key()==Qt::Key_D){
        player->MoveRight(4);
        player->setDireccion(true);
    }
    if(player->getSaltando()){
        player->setParabolico(false);
    }
    if(colisionMuros(index)&& player->getPosy()>muros.at(index)->getPosy()){
        player->MoveLeft(4);
    }



    else if(evento->key()==Qt::Key_A){
        player->MoveLeft(4);
        player->setDireccion(false);

        if((colisionMuros(index)&& player->getPosy()>muros.at(index)->getPosy())){
            player->MoveRight(4);
        }
        if(player->getSaltando()){
            player->setParabolico(false);
        }

    }

    else if(evento->key()==Qt::Key_Space){

        player->activarSalto(angulo->angulo,70);
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
        bbdd->setPartida(Usuario->toPlainText(),Contrasena->toPlainText(),nivel, player->getPosx(), player->getPosy(), time->getTiempo(),vida->getVidas());
        //menu();
        this->close();
    }

}




void MainWindow::verificarPosicionPersonaje()
{
    if(player->getPosy()>458 && nivel==1){//condicional para que no pase del piso
        player->setPosy(457);
        player->timer->stop();
        player->setSaltando(false);
        player->setParabolico(true);

    }
    if(player->getPosy()>433 && nivel==2){
        player->setPosy(432);
        player->timer->stop();
        player->setSaltando(false);
        player->setParabolico(true);
    }

    if(player->getPosx()<14){//condicional para que no pase de los limites del mapa
        player->MoveRight(30);
        if(player->getSaltando()){
            player->setParabolico(false);
        }
    }
    if(player->getPosx()>3360){
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


    if (player->getPosx()>3200 && nivel==1){//cuando llega al final de la partida
        nivel++;
        siguientePartida();
    }
    else if(player->getPosx()>3200 && nivel==2){
        creditos();
    }

    if(player->getSaltando()){//colisiones con los muros

        if(player->getSubiendo() && colisionMuros(index) && player->getPosy()>muros.at(index)->getPosy()){

            player->setParabolico(false);

        }else if(!player->getSubiendo() && colisionMuros(index)){
            player->MoveUp(1);
            player->timer->stop();
            player->setSaltando(false);
            player->setParabolico(true);
        }

    }
    if(!player->getSaltando() && !colisionMuros(index) && player->getPosy()<457 && nivel==1)
    {
        player->setParabolico(false);
        player->activarSalto(0,40);
    }
    else if(!player->getSaltando() && !colisionMuros(index) && player->getPosy()<432 && nivel==2){
        player->setParabolico(false);
        player->activarSalto(0,40);
    }

    if(!player->getParabolico() && colisionMuros(index) && player->getPosy()<muros.at(index)->getPosy()){
        player->MoveUp(1);
        player->timer->stop();
        player->setSaltando(false);
        player->setParabolico(true);
    }

    if(colisionResortes(index) && !resortes.at(index)->getActivado()){//colisiones con los objetos dinamicos

        resortes.at(index)->activarMovimiento();
        player->setSaltando(false);
        player->setDireccion(true);
        player->setParabolico(true);
        player->activarSalto(angulo->angulo,90);

    }

    if(colisionEnemigos() || colisionBolasFuego()){
        if(vida->getVidas()>0){
            vida->decrease();
            if(nivel==1){
                player->establecerPosicion(15,457);
            }else{
                player->establecerPosicion(20,432);
            }
        }else{
            this->close();
        }
    }
    if(time->getTiempo()==0){
        if(vida!=0){
            vida->decrease();
            if(nivel==1){
                player->establecerPosicion(15,457);
            }else{
                player->establecerPosicion(20,432);
            }
        }
        else{
            this->close();
        }
    }
    if( vida->getVidas()==0){
        this->close();
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
    connect(timers.at(1),&QTimer::timeout,this,&MainWindow::evaluarPosicionBombas);
}
void MainWindow::cargarObjetoEstatico(string nombreFichero, QList<objetoEstatico *> &lista)
{
    lista.clear();
    bbdd->getStaticObjects(nombreFichero,lista);
    for(objetoEstatico *ite:lista){
        scene->addItem(ite);
    }
}

void MainWindow::cargarBolas(string nombreFichero, QList<ObjetoMovCircular*> &listaBolas)
{
    listaBolas.clear();
    bbdd->getBolasFuego(nombreFichero,listaBolas);
    for(ObjetoMovCircular *ite:listaBolas){
        scene->addItem(ite);
    }
}

void MainWindow::cargarEnemigos(string nombreFichero, QList<Enemigo *> &listaEnemigos)
{
    listaEnemigos.clear();
    bbdd->getEnemigos(nombreFichero,listaEnemigos);
    for(Enemigo *ite:listaEnemigos){
        scene->addItem(ite);
    }
}

void MainWindow::cargarResortes(string nombreFichero, QList<resorte *> &listaResortes)
{
    listaResortes.clear();
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

void MainWindow::cargarObjetos(string archivoMuros, string archivoBolas, string archivoResortes, string archivoEnemigos)
{
    cargarObjetoEstatico(archivoMuros,muros);
    cargarBolas(archivoBolas,bolasFuego);
    cargarEnemigos(archivoEnemigos,enemigos);
    cargarResortes(archivoResortes,resortes);
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

void MainWindow::evaluarPosicionBombas()
{
    QList<Enemigo*>::iterator iteE=enemigos.begin();
    QList<Bomba*>::iterator iteB=bombas.begin();

    for(Bomba *iteBomba:bombas){
        if((iteBomba->getPosy()>458 && nivel==1) || (iteBomba->getPosy()>433 && nivel==2)){
            scene->removeItem(iteBomba);
            bombas.erase(iteB);


        }
        for(iteE=enemigos.begin();iteE!=enemigos.end();iteE++){


            if(iteBomba->collidesWithItem((*iteE))){
                scene->removeItem(*iteE);
                enemigos.erase(iteE);
                scene->removeItem(iteBomba);
                bombas.erase(iteB);


            }

        }
        iteB++;

    }
}


