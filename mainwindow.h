#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QGraphicsScene>
#include"personajeprincipal.h"
#include"objetomovcircular.h"
#include <QKeyEvent>
#include <QScreen>
#include <bomba.h>

#include<resorte.h>
#include<piso.h>

#include<QMetaType>



using namespace std;
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
//    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;

    PersonajePrincipal* player;
    ObjetoMovCircular* movCircular;
    
    piso * floor;
    resorte *resort;
    Bomba *bomba;
    QTimer *timer;
    void keyPressEvent(QKeyEvent *evento);
   
    template<typename T1,typename T2>
    bool colisionConMuro(T1 *objeto1, T2 *objeto2)
    {
        bool colision=false;
        if(objeto1->collidesWithItem(objeto2)){
            colision=true;
        }
        return colision;
    }

};

#endif // MAINWINDOW_H
