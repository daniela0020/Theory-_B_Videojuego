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
}

MainWindow::~MainWindow()
{
    delete ui;
}

