#ifndef OBJETODINAMICO_H
#define OBJETODINAMICO_H

#include<QTimer>
#include<QObject>
#include<QGraphicsItem>
#include<QPainter>
#include<QMetaType>
#define Masa 100.0
class objetoDinamico:public QObject,public QGraphicsItem
{
public:
    //atributos publicos para su facil empleo en la herencia
    float posx=0,posy=0,alto=0;

    int ancho=0,filas=0, columnas=0;


    QTimer *timer;
    //constructuroes
    objetoDinamico();
    objetoDinamico(float posx,float posy,int ancho,int alto);

    //metodos
    void MoveRight(float pixeles);
    void MoveLeft(float pixeles);
    void MoveUp(float pixeles);
    void MoveDown(float pixeles);
    double getPosx() ;
    void setPosx(float newPosx);
    double getPosy() ;
    void setPosy(float newPosy);

    //Metodos abstractos

    virtual QRectF boundingRect() const;

    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);

signals:
public slots:

    //slot abstracto

    virtual void sprint();
    virtual void actualizarPosicion();


};

#endif // OBJETODINAMICO_H
