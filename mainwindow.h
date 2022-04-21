#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include<ui_ventana.h>
#include<ventana.h>
#include <QMainWindow>
#include<QGraphicsScene>
#include<QScreen>
#include"personajeprincipal.h"
#include"objetomovcircular.h"
#include <QKeyEvent>
#include <bomba.h>
#include <QLineEdit>
#include <QLabel>
#include <button.h>
#include <tiempo.h>
#include<vidas.h>
#include<angulo.h>
#include<enemigo.h>
#include<basededatos.h>
#include<objetoEstatico.h>
#include<resorte.h>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QGraphicsView>
#include <QPushButton>
#include <QTextEdit>
#include <QtWidgets/QWidget>




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
    int index;
    short int nivel =0;
//    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    QGraphicsScene *scene2;
    QMainWindow *w2;
    QMainWindow *w3;
    PersonajePrincipal* player;
    QList<ObjetoMovCircular*> bolasFuego;
    QList<Enemigo *>enemigos;
    baseDeDatos *bbdd;
    QList<resorte*> resortes;
    QList<objetoEstatico *> muros;
    QList<QTimer *> timers;
    QList <Bomba *> bombas;

    Ui_Ventana * ventana;
    Tiempo * time;
    Vidas * vida;
    Angulo * angulo;

    QGraphicsView *graphicsView;
    QTextEdit *Usuario;
    QTextEdit *Contrasena;
    QPushButton *pushButton;
 

    void keyPressEvent(QKeyEvent *evento);
    void inicializacionTimers();
    void cargarObjetoEstatico(string nombreFichero,QList<objetoEstatico*> &lista);
    void cargarBolas(string nombreFichero,QList<ObjetoMovCircular*> &listaBolas);
    void cargarEnemigos(string nombreFichero,QList<Enemigo*> &listaEnemigos);
    void cargarResortes(string nombreFichero,QList<resorte*> &listaResortes);
    bool colisionMuros(int &index);
    bool colisionEnemigos();
    bool colisionBolasFuego();
    bool colisionResortes(int &index);
    void cargarObjetos(string archivoMuros,string archivoBolas, string archivoResortes,string archivoEnemigos);
    void siguientePartida();
    void creditos();


signals:
public slots:

    void verificarPosicionPersonaje();
    void NuevaPartida();
    void ClickNuevaPartida();
    void ClickcargarPartida();
    void partidaGuardada();
    void verificarNuevaPartida();
    void verificarPartidaGuardada();
    void evaluarPosicionBombas();





};

#endif // MAINWINDOW_H
