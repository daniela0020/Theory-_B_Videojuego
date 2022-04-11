#ifndef BOMBA_H
#define BOMBA_H
#include <objetodinamico.h>

#define GR 9.8
#define dt 0.1


class Bomba:public objetoDinamico
{
    float velocidadx;
    float velocidady;
    float velocidadInicial =90;
    bool derecha = true;
public:
    Bomba(float x,float y);

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);

    float ang = 0;

    void VelocidadInicial();
    void activarMovimiento(float ang);

signals:

public slots:

    void actualizarPosicion();

public:
    Bomba();
    void setDerecha(bool newDerecha);
};
#endif // BOMBA_H
