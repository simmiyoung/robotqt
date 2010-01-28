#ifndef TESTE_H
#define TESTE_H

#include "../../../src/robotcore/sensorinterface.h"

class QColor;

class Test : public QObject, public SensorInterface
{
    Q_OBJECT
    Q_INTERFACES(SensorInterface)

public:
    Test();

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget);

    /*
     * It turns on and off the object actions
     *
     * Returns true if it worked properly, false otherwise
     */
    virtual bool turnOn();
    virtual bool turnOff();

protected:
    void advance(int step);

private:
    QColor color;
};

#endif
