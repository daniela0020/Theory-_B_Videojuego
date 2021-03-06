#include "button.h"
#include <QBrush>
#include <QGraphicsTextItem>

Button::Button(QString name,QGraphicsItem * parent)
{
    //dibujar botón
    setRect(0,0,200,50);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::darkCyan);
    setBrush(brush);

    //dibujar el texto

    text = new QGraphicsTextItem(name,this);
    int xPos = rect().width()/2 -text->boundingRect().width()/2;
    int yPos = rect().height()/2 -text->boundingRect().height()/2;
    text->setPos(xPos,yPos);

    //habilitamos el evento hover

    setAcceptHoverEvents(true);
}

void Button::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    emit clicked();
}

void Button::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::cyan);
    setBrush(brush);
}

void Button::hoverLeaveEvent(QGraphicsSceneHoverEvent *event)
{
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::darkCyan);
    setBrush(brush);
}
