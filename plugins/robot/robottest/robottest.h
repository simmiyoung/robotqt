#ifndef TESTE_H
#define TESTE_H

#include "../../../src/robotcore/robotinterface.h"

class QColor;

class RobotTest : public QObject, public RobotInterface
{
    Q_OBJECT
    Q_INTERFACES(RobotInterface)
    Q_PROPERTY(QPointF pos READ pos WRITE setPos)
    Q_PROPERTY(qreal rotation READ rotation WRITE setRotation)

public:
    RobotTest();

    QRectF boundingRect() const;
    QPainterPath shape() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget);

private:
    QColor color;
};

#endif
