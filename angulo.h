#ifndef ANGULO_H
#define ANGULO_H
#include <QGraphicsTextItem>


class Angulo:public QGraphicsTextItem
{
public:
    unsigned short int angulo;
    Angulo();
    void SumAngulo();
    void ResAngulo();

};

#endif // ANGULO_H
