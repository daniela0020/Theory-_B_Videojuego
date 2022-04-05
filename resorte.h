#ifndef RESORTE_H
#define RESORTE_H

#include<QGraphicsItem>
#include<QPainter>
#include<QObject>
#include<QTimer>
#include<math.h>


#define B 20.0
#define dt 0.1


class resorte:public QObject, public QGraphicsItem
{
    double posx=0,posy=0,ancho=0,alto=0,Masa=100.0,alpha=0,k=0,W=0,expo=0,angu=0;
    QTimer *time;
public:
    resorte();
    resorte(double posx, double posy,double k);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);


    void actualizarValores();
    void activarMovimiento();
    float getPosy() const;
    void setMasa(float newMasa);


    double getPosx() const;
signals:
public slots:

    void calcularPosicion();

};

#endif // RESORTE_H
