#ifndef VIDAS_H
#define VIDAS_H
#include <QGraphicsTextItem>

class Vidas:public QGraphicsTextItem
{
    unsigned short int vidas;
public:
    Vidas();
    unsigned short int getVidas();

signals:
public slots:
    void decrease();
};

#endif // VIDAS_H
