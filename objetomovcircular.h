#ifndef OBJETOMOVCIRCULAR_H
#define OBJETOMOVCIRCULAR_H
#include <objetodinamico.h>

#define dt 0.001
#define Wa 90



class ObjetoMovCircular:public objetoDinamico
{
    int x,y;
    float angulo,radio,distancia;

public:
    ObjetoMovCircular(int k,int h,int distancia);
    QRectF boundingRect() const ;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);


signals:

public slots:

    void actualizarPosicion();

};

#endif // OBJETOMOVCIRCULAR_H
