#ifndef PERSONAJEPRINCIPAL_H
#define PERSONAJEPRINCIPAL_H
#include <QPainter>
#include <QGraphicsItem>

#include <objetodinamico.h>
#define GR 9.8
#define Dt 0.1

class PersonajePrincipal:public objetoDinamico
{

private:
    float velocidadx;
    float velocidady;
    float velocidadPaso = 30;
    int vidas;
    bool derecha=true;

public:
    PersonajePrincipal(double x, double y);

    QRectF boundingRect() const ;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);

    float ang = 0;

    void actualizarImagen();

    void activarSalto(double angulo);

    void VelocidadInicial();

    void setAng(float newAng);

    void setDerecha(bool newDerecha);



    void setVelocidadPaso(float newVelocidadPaso);

signals:

public slots:

    void actualizarPosicion();


};



#endif // PERSONAJEPRINCIPAL_H
