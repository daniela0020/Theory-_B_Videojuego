#ifndef BOMBA_H
#define BOMBA_H
#include <objetodinamico.h>

#define GR 9.8
#define dt 0.1


class Bomba:public objetoDinamico
{
    float velocidadx;
    float velocidady;
    float velocidad =90;
    bool derecha = true;
public:
    Bomba();
    Bomba(float x,float y);
    void setDerecha(bool newDerecha);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);

    float ang = 0;

    void VelocidadInicial();
    void activarMovimiento(float ang);

signals:

public slots:

    void actualizarPosicion();

};
#endif // BOMBA_H
