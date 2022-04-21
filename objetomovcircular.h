#ifndef OBJETOMOVCIRCULAR_H
#define OBJETOMOVCIRCULAR_H
#include <objetodinamico.h>

#define dt 0.001
#define Wa 90



class ObjetoMovCircular:public objetoDinamico
{
    float x,y;
    float angulo,radio,distancia;
    QPixmap *pixmap;

public:
    ObjetoMovCircular(float k,float h,float distancia);
    QRectF boundingRect() const ;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);


signals:

public slots:

    void actualizarPosicion();

};

#endif // OBJETOMOVCIRCULAR_H
