#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QGraphicsScene>
#include<QScreen>
#include"personajeprincipal.h"
#include"objetomovcircular.h"
#include <QKeyEvent>
#include <bomba.h>
#include<enemigovolador.h>
#include<resorte.h>
#include<QMetaType>
#include<basededatos.h>



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

    baseDeDatos *bbdd = new baseDeDatos();

    ObjetoMovCircular* movCircular;

    QSet<int> pressedKeys;

    enemigoVolador *enemigovolador;

    resorte *resort;

    QList<QTimer *> timers;

    QList<float*> murosHorizontales;

    Bomba *bomba;

    void keyPressEvent(QKeyEvent *evento);
    void inicializacionTimers();
   
signals:
public slots:

    void verificarPosicionPersonaje();
    void colisionResorte();


};
template<typename T1,typename T2>
bool colision(T1 *objeto1, T2 *objeto2)
{
    bool colision=false;
    if(objeto1->collidesWithItem(objeto2)){
        colision=true;
    }
    return colision;
}
#endif // MAINWINDOW_H
