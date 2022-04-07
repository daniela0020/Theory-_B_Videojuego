#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    scene=new QGraphicsScene();

    this->setFixedSize(this->screen()->availableSize().width(),700);

    ui->graphicsView->setFixedSize(this->screen()->availableSize().width()-70,700);

    scene=new QGraphicsScene();

    scene->setSceneRect(0,0,ui->graphicsView->width(),ui->graphicsView->height()-150);

    ui->graphicsView->setScene(scene);

    scene->setBackgroundBrush(Qt::green);


    //setWindowTitle("THEORY B");

    //scene->setSceneRect(0,-590,600,650);

    // scene->setBackgroundBrush(Qt::green);

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
        player->MoveLeft(30);

    }
    else if(ev->key()==Qt::Key_D)
    {
        player->MoveRight(30);

    }
    else if(ev->key()==Qt::Key_Space)
    {
        player->activarSalto(45);
    }
    else if(ev->key()==Qt::Key_Z)
    {

    }
}

