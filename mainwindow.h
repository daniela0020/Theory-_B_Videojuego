#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QGraphicsScene>
#include<QScreen>
#include"personajeprincipal.h"
#include"objetomovcircular.h"
#include <QKeyEvent>
#include <bomba.h>
<<<<<<< HEAD


#include<enemigovolador.h>

=======
#include <button.h>

#include<enemigovolador.h>
#include<enemigoterrestre.h>
>>>>>>> 8d7a53ce2a97f33380614d25e9257f773b663413


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
    void menu();
//    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;

    PersonajePrincipal* player;
    ObjetoMovCircular* movCircular;
    QSet<int> pressedKeys;
    enemigoVolador *enemigovolador;
    enemigoTerrestre *enemigoterrestre;

    resorte *resort;

    QList<QTimer *> timers;

    Bomba *bomba;
 


    void keyPressEvent(QKeyEvent *evento);
    void inicializacionTimers();

signals:
public slots:

    void verificarPosicionPersonaje();
    void colisionResorte();
    void PlayStart();


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
