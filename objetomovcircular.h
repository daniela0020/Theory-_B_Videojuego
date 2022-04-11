#ifndef OBJETOMOVCIRCULAR_H
#define OBJETOMOVCIRCULAR_H
#include <objetodinamico.h>

#define dt 0.001
#define Wa 90

class ObjetoMovCircular:public objetoDinamico
{
    int h,k;
    float angulo,radio,distancia;

public:
    ObjetoMovCircular(int k,int h);
    QRectF boundingRect() const ;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);


signals:

public slots:

    void actualizarPosicion();

};

#endif // OBJETOMOVCIRCULAR_H
