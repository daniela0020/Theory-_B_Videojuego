#ifndef RESORTE_H
#define RESORTE_H



#include<math.h>
#include<objetodinamico.h>
#include<QMetaType>
#include<piso.h>

#define B 20.0
#define dt 0.1


class resorte:public objetoDinamico
{
    float alpha=0,k=0,W=0,expo=0,angu=0,velocidad=0;
    int counterTime=0;

public:
    resorte();
    resorte(float posx, float posy,float ancho, float alto,float k);
    QRectF boundingRect() const ;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) ;
    void actualizarValores();
    void activarMovimiento();

    double getVelocidad() const;



signals:
public slots:

    void actualizarPosicion();
    void sprint();

};

#endif // RESORTE_H
