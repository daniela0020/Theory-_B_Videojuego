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
#include <button.h>
#include<basededatos.h>
#include<enemigovolador.h>
#include<enemigoterrestre.h>
#include<objetoestatico.h>
#include<string.h>

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
    int index;
    void menu();
//    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;

    PersonajePrincipal* player;
    QList<ObjetoMovCircular*> bolasFuego;
    QSet<int> pressedKeys;
    QList<Enemigo *>enemigosvoladores;
    QList<Enemigo *>enemigosterrestres;
    baseDeDatos *bbdd;
    QList<resorte*> resortes;
    QList<objetoEstatico *> muros;
    QList<QTimer *> timers;

    QList <Bomba *> bombas;
 


    void keyPressEvent(QKeyEvent *evento);
    void inicializacionTimers();
    void cargarObjetoEstatico(string nombreFichero,QList<objetoEstatico*> lista);
    void cargarBolas(string nombreFichero,QList<ObjetoMovCircular*> listaBolas);
    void cargarEnemigos(string nombreFichero,QList<Enemigo*> listaEnemigos);
    void cargarResortes(string nombreFichero,QList<resorte*> listaResortes);

signals:
public slots:

    void verificarPosicionPersonaje();
    void colisionResorte();
    void PlayStart();


};
template<typename T1,typename T2>
bool colision(T1 *objeto1, QList<T2 *> objeto2, int &index)
{
    bool colision=false;
   for(T2 *ite:objeto2){
       if(objeto1->collidesWithItem(ite)){
           index=objeto2.indexOf(ite);
           colision=true;
           break;
       }
   }

    return colision;
}
#endif // MAINWINDOW_H
