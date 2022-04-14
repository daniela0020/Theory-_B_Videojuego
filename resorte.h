#ifndef RESORTE_H
#define RESORTE_H




#include<objetodinamico.h>
#include<QMetaType>
#define B 20.0
#define dT 1


class resorte:public objetoDinamico
{
    float k=0,W=0,angu=0,velocidad=0;
    int counterTime=0;
    bool activado=false;


public:

    resorte();
    resorte(float posx, float posy,float k);
    QRectF boundingRect() const ;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) ;
    void actualizarValores();
    void activarMovimiento();
    void cambiarForma();

    float getVelocidad() const;
<<<<<<< HEAD
=======
    bool getActivado() const ;
    void setActivado(bool newActivado);
>>>>>>> 8d7a53ce2a97f33380614d25e9257f773b663413



    bool getActivado() const;
    void setActivado(bool newActivado);

signals:
public slots:

    void actualizarPosicion();
    void sprint();

};

#endif // RESORTE_H
