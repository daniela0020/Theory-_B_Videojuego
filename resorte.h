#ifndef RESORTE_H
#define RESORTE_H


#include<QTimer>
#include<math.h>
#include<personaje.h>

#define B 20.0
#define dt 0.1


class resorte:public personaje
{
    double alpha=0,k=0,W=0,expo=0,angu=0;
    QTimer *time;
public:
    resorte();
    resorte(double posx, double posy,double ancho, double alto,double k);
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;
    void actualizarValores();
    void activarMovimiento();


signals:
public slots:

    void calcularPosicion();

};

#endif // RESORTE_H
