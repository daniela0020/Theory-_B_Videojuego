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

    scene=new QGraphicsScene();

    scene->setSceneRect(0,0,ui->graphicsView->width()-70,ui->graphicsView->height()-150);

    ui->graphicsView->setScene(scene);

    scene->setBackgroundBrush(Qt::green);

    player = new PersonajePrincipal(300,310);

    movCircular = new ObjetoMovCircular(400,410);

    scene->addItem(movCircular);

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

