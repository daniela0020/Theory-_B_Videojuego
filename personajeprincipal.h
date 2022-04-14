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

    void activarSalto(double angulo);

    void VelocidadInicial();

    void setAng(float newAng);

    void setDireccion(bool newDerecha);

    bool getDireccion();

    void setVelocidad(float newVelocidadPaso);

    float getVelocidad() const;

    void MoveRight(float pixeles);
<<<<<<< HEAD

    void MoveLeft(float pixeles);

    void MoveUp(float pixeles);

=======
    
    void MoveLeft(float pixeles);
    
    void MoveUp(float pixeles);
    
>>>>>>> 8d7a53ce2a97f33380614d25e9257f773b663413
    void MoveDown(float pixeles);

signals:

public slots:

    void actualizarPosicion();


};



#endif // PERSONAJEPRINCIPAL_H
