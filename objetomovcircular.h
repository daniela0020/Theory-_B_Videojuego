#ifndef OBJETOMOVCIRCULAR_H
#define OBJETOMOVCIRCULAR_H
#include <objetodinamico.h>
#include <math.h>
#define dt 0.1
#define W 40

class ObjetoMovCircular:public objetoDinamico
{
    int h,k;
    float angulo,radio;

public:
    ObjetoMovCircular(int k,int h);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);


signals:

public slots:

    void actualizarPosicion();

};

#endif // OBJETOMOVCIRCULAR_H
