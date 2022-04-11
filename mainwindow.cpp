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

    scene->setSceneRect(0,0,ui->graphicsView->width()-70,ui->graphicsView->height()-150);

    ui->graphicsView->setScene(scene);

    scene->setBackgroundBrush(Qt::green);

    player = new PersonajePrincipal(300,310);

    movCircular = new ObjetoMovCircular(400,410);

    bomba = new Bomba(500,510);

    scene->addItem(movCircular);

    scene->addItem(player);




    resort=new resorte(250,550,20,40,50);

    scene->addItem(resort);

    floor= new piso(0,-550,scene->width(),10);

    scene->addItem(floor);


}


void MainWindow::keyPressEvent(QKeyEvent *evento)
{
    if(evento->key()==Qt::Key_W){
        player->MoveUp(30);

        if(colisionConMuro<PersonajePrincipal,resorte>(player,resort) || colisionConMuro<PersonajePrincipal,piso>(player,floor)){
        player->MoveDown(30);
        }
    }
    else if(evento->key()==Qt::Key_S){
        player->MoveDown(30);
        if(colisionConMuro<PersonajePrincipal,resorte>(player,resort)){
        resort->activarMovimiento();
        resort->setColision(colisionConMuro<resorte,piso>(resort,floor));

        }
        if(colisionConMuro<PersonajePrincipal,resorte>(player,resort) || colisionConMuro<PersonajePrincipal,piso>(player,floor)){
        player->MoveUp(30);
        }
    }

    else if(evento->key()==Qt::Key_D){
        player->MoveRight(30);
        scene->setSceneRect(player->getPosx(),50,ui->graphicsView->width()-70,ui->graphicsView->height()-150);
        if(colisionConMuro<PersonajePrincipal,resorte>(player,resort) || colisionConMuro<PersonajePrincipal,piso>(player,floor)){
        player->MoveLeft(30);
        }
    }
    else if(evento->key()==Qt::Key_A){
        player->MoveLeft(30);
       if(colisionConMuro<PersonajePrincipal,resorte>(player,resort) || colisionConMuro<PersonajePrincipal,piso>(player,floor)){
        player->MoveRight(30);
        }
    }
    else if(evento->key()==Qt::Key_Space){
        player->activarSalto(45);

       if( colisionConMuro<PersonajePrincipal,piso>(player,floor)){
           player->timer->stop();
           player->setPosy(-540);
       }
    }
    else if(evento->key()==Qt::Key_M){
        bomba->setPosx(player->getPosx()+10);
        bomba->setPosy(player->getPosy()+10);
        scene->addItem(bomba);
        bomba->activarMovimiento(45);


    }

}







