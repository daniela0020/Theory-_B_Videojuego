#ifndef ENEMIGOVOLADOR_H
#define ENEMIGOVOLADOR_H

#include<objetodinamico.h>

class enemigoVolador:public objetoDinamico
{
     float k=0,W=0,angu=0,dT=0.01;
public:
    enemigoVolador();
    enemigoVolador(float posx,float posy);

    QRectF boundingRect() const ;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);

signals:
public slots:
    void actualizarPosicion();
};

#endif // ENEMIGOVOLADOR_H
