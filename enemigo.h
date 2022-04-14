#ifndef ENEMIGO_H
#define ENEMIGO_H
#include <objetodinamico.h>

class Enemigo:public objetoDinamico
{
    float k=0,W=0,angu=0,dT=0.01;
public:
    Enemigo(float posx, float posy);
    QRectF boundingRect() const ;
signals:
public slots:
    void actualizarPosicion();
};


#endif // ENEMIGO_H
