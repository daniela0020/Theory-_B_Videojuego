#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    scene=new QGraphicsScene();

    ui->graphicsView->setScene(scene);

    //setWindowTitle("THEORY B");

    scene->setSceneRect(0,0,600,650);

    scene->setBackgroundBrush(Qt::green);

    player = new PersonajePrincipal(300,310);

    scene->addItem(player);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *ev)
{

    if(ev->key()==Qt::Key_A)

    {
        player->MoveLeft();

    }
    else if(ev->key()==Qt::Key_D)
    {
        player->MoveRight();

    }
    else if(ev->key()==Qt::Key_Space)
    {
        player->VelocidadInicial(45);
        player->activarMovimiento();
    }
    else if(ev->key()==Qt::Key_Z)
    {

    }
}

