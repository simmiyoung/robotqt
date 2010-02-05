#ifndef TESTE_H
#define TESTE_H

#include "../../../src/robotcore/sensorinterface.h"

class QColor;

class SensorTest : public QObject, public SensorInterface
{
    Q_OBJECT
    Q_INTERFACES(SensorInterface)

public:
    SensorTest();

    QRectF boundingRect() const;
    QPainterPath shape() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget);

    void turnOn();
    void turnOff();

private:
    QColor color;
};

#endif
