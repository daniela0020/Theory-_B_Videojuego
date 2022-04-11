#ifndef PERSONAJEPRINCIPAL_H
#define PERSONAJEPRINCIPAL_H
#include <math.h>
#include <objetodinamico.h>
#define GR 9.8
#define dt 0.1

class PersonajePrincipal:public objetoDinamico
{

private:
    float velocidadx;
    float velocidady;
    float velocidadPaso = 30;
    int vidas;

public:
    PersonajePrincipal(double x, double y);

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);


    float ang = 0;

    void actualizarImagen();

    void activarSalto(double angulo);

    void VelocidadInicial();

    void setAng(float newAng);

signals:

public slots:

    void actualizarSalto();


};

#endif // PERSONAJEPRINCIPAL_H
