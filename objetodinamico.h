#ifndef OBJETODINAMICO_H
#define OBJETODINAMICO_H

#include<QTimer>
#include<QObject>
#include<QGraphicsItem>
#include<QPainter>
#include<QMetaType>
#include<math.h>
#define Masa 100.0
#define PI 3.141516
class objetoDinamico:public QObject,public QGraphicsItem
{
public:
    //atributos publicos para su facil empleo en la herencia
    float posx=0,posy=0,alto=0,velocidadPaso=8;

    int ancho=0,filas=0, columnas=0;



    QTimer *timer;
    //constructuroes
    objetoDinamico();
    objetoDinamico(float posx,float posy,int ancho,int alto);

    //metodos
    float getPosx() ;
    void setPosx(float newPosx);
    float getPosy() ;
    void setPosy(float newPosy);

    //Metodos abstractos



signals:
public slots:

    //slot abstracto

    virtual void sprint();
    virtual void actualizarPosicion();


};

#endif // OBJETODINAMICO_H
