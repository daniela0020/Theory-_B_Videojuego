#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QKeyEvent>
#include<personaje.h>
#include<resorte.h>
#include<QTimer>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;

    personaje *perso;

    resorte *resort;
    QTimer *timer;
    void keyPressEvent(QKeyEvent *evento);
    bool evaluarFantasmaColisionMuro(resorte *resorte);
};
#endif // MAINWINDOW_H
