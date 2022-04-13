#ifndef PERSONAJEPRINCIPAL_H
#define PERSONAJEPRINCIPAL_H

#include <objetodinamico.h>
#define GR 9.8
#define Dt 0.1

class PersonajePrincipal:public objetoDinamico
{

private:
    float velocidadx;
    float velocidady;
    float velocidadInicial=50;
    float ang = 0;
    int vidas;
    bool direccion=true,parabolico=true,saltando=false;

public:

    PersonajePrincipal(double x, double y);

    QRectF boundingRect() const ;

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);

    void activarSalto(double angulo);

    void VelocidadInicial();

    void setAng(float newAng);

    void setVelocidadInicial(float newVelocidadInicial);

    float getVelocidadInicial();

    void setDireccion(bool newDireccion);

    void setParabolico(bool newParabolico);

    bool getParabolico() const;

    void setSaltando(bool newSaltando);

    bool getSaltando() const;

signals:

public slots:

    void actualizarPosicion();


};



#endif // PERSONAJEPRINCIPAL_H
