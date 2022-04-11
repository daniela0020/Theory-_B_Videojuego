#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QGraphicsScene>
#include"personajeprincipal.h"
#include"objetomovcircular.h"
#include <QKeyEvent>

#include<enemigovolador.h>


#include<resorte.h>


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
    QSet<int> pressedKeys;
    enemigoVolador *enemigovolador;

    resorte *resort;

    QList<QTimer *> timers;

    Bomba *bomba;
 

    void keyPressEvent(QKeyEvent *evento);
    void inicializacionTimers();
   
signals:
public slots:

    void verificarPosicionPersonaje();
    void colisionResorte();


};
template<typename T1,typename T2>
bool colisionConMuro(T1 *objeto1, T2 *objeto2)
{
    bool colision=false;
    if(objeto1->collidesWithItem(objeto2)){
        colision=true;
    }
    return colision;
}
#endif // MAINWINDOW_H
