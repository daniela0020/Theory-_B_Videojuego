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
    float alturaMax=350;    
    bool direccion=true,parabolico=true,saltando=false,subiendo=false;
    QPixmap *pixmap;
    QTimer *timer2;


public:

    PersonajePrincipal(float x, float y);

    QRectF boundingRect() const ;
    
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);

    void actualizarImagen();

    void VelocidadInicial();

    void setAng(float newAng);

    void setDireccion(bool newDerecha);

    bool getDireccion();

    void setVelocidad(float newVelocidadPaso);

    float getVelocidad() const;

    void MoveRight(float pixeles);
    
    void MoveLeft(float pixeles);
    
    void MoveUp(float pixeles);
    
    void MoveDown(float pixeles);

    void activarSalto(float angulo, float velocidad);

    bool getParabolico() const;
    void setParabolico(bool newParabolico);

    bool getSaltando() const;
    void setSaltando(bool newSaltando);

    int getVidas() const;
    void setVidas(int newVidas);

    bool getSubiendo() const;
    void setSubiendo(bool newSubiendo);

    void establecerPosicion(float posx,float posy);


signals:

public slots:

    void actualizarPosicion();
    void sprint();


};



#endif // PERSONAJEPRINCIPAL_H
