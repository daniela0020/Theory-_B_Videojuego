#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QKeyEvent>
#include<personaje.h>
#include<resorte.h>
#include<piso.h>
#include<QTimer>
#include<QMetaType>



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

    personaje *perso;
    piso * floor;
    resorte *resort;
    QTimer *timer;
    void keyPressEvent(QKeyEvent *evento);
    void colisionResorte();
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
