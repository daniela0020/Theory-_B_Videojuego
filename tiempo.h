#ifndef TIEMPO_H
#define TIEMPO_H
#include <QGraphicsTextItem>
#include<QTimer>


class Tiempo:public QGraphicsTextItem
{
    unsigned short int tiempo;
public:
    Tiempo();
    unsigned short int getTiempo();

    QTimer *timer;

    void setTiempo(unsigned short newTiempo);

signals:
public slots:
    void decrease();
};

#endif // TIEMPO_H
