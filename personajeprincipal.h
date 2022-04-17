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
    float velocidad = 50;
    float ang = 0;
    int vidas;
    bool direccion=true,parabolico=true,saltando=false;

public:

    PersonajePrincipal(float x, float y);

    QRectF boundingRect() const ;
    
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);

    void actualizarImagen();

    void activarSalto(double angulo, float velocidad);

    void VelocidadInicial();

    void setAng(float newAng);

    void setDireccion(bool newDerecha);

    bool getDireccion();

    void MoveRight(float pixeles);

    void MoveLeft(float pixeles);

    void MoveUp(float pixeles);

    void MoveDown(float pixeles);

    bool getParabolico() const;
    void setParabolico(bool newParabolico);

    bool getSaltando() const;
    void setSaltando(bool newSaltando);

signals:

public slots:

    void actualizarPosicion();


};



#endif // PERSONAJEPRINCIPAL_H
