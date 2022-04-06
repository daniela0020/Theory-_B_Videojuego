#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    scene=new QGraphicsScene();

    ui->graphicsView->setScene(scene);

    setWindowTitle("THEORY B");

    scene->setSceneRect(0,0,567,224);
<<<<<<< HEAD

    scene->setBackgroundBrush(Qt::green);

    player = new PersonajePrincipal(50,174);

    scene->addItem(player);

=======
>>>>>>> cd6d557d414d3dd9bcda905c9d8c3f1293a97014
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *ev)
{

    if(ev->key()==Qt::Key_Left)

    {
        player->MoveLeft();

    }
    else if(ev->key()==Qt::Key_Right)
    {
        player->MoveRight();

    }
    else if(ev->key()==Qt::Key_Space)
    {
       player->actualizarSalto(0.1);
    }
    else if(ev->key()==Qt::Key_Z)
    {

    }
}

