#ifndef PERSONAJEPRINCIPAL_H
#define PERSONAJEPRINCIPAL_H
#include <QPainter>
#include <QGraphicsItem>
#include <math.h>
#define MASA 70
#define GR 9.8
#define dt 0.1

class PersonajePrincipal : public QGraphicsItem
{
private:
    float posicionx;
    float posiciony;
    float velocidadx;
    float velocidady;
    //float aceleracionx;
    //float aceleraciony;
    float velocidadPaso = 4;
    //float dt;
    int ancho;
    int alto;
    int vidas;

    int filas=0, columnas=0;
public:
    PersonajePrincipal(float x, float y);

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);

    void MoveRight();
    void MoveLeft();

    void setPosy(int value);

    void setPosx(int value);

    float getPosx() const;

    float ang;

    float getPosy() const;

    void actualizarSalto(float velInicial);

    void actualizarImagen();
};

#endif // PERSONAJEPRINCIPAL_H
