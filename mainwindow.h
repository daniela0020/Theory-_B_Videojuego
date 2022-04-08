#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QGraphicsScene>
#include"personajeprincipal.h"
#include"objetomovcircular.h"
#include <QKeyEvent>
#include <QScreen>

using namespace std;
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
    PersonajePrincipal* player;
    ObjetoMovCircular* movCircular;
    void keyPressEvent(QKeyEvent *ev);


};
#endif // MAINWINDOW_H
