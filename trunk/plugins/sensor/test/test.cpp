#include "test.h"

#include <QGraphicsScene>
#include <QPainter>
#include <QStyleOption>

#include <math.h>

static const double Pi = 3.14159265358979323846264338327950288419717;
static double TwoPi = 2.0 * Pi;

Test::Test()
{
    // setting PluginBase attributes
    setName(tr("Radar"));
    setType(PluginBase::Sensor);

    // we need to reset SensorInterface attributes
    status = SensorInterface::ON;
}

QRectF Test::boundingRect() const {
//    qreal adjust = 4;
//    return QRectF(-10 - adjust, -10 - adjust,
//                  20 + adjust, 20 + adjust);
}

void Test::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    QRectF rect(0.0, 0.0, 60.0, 60.0);
    painter->setRenderHint(QPainter::Antialiasing, true);
    painter->drawEllipse(rect);
    painter->fillRect(rect);
}

void Test::turnOff()
{
    status = SensorInterface::OFF;
}

void Test::turnOn()
{
    status = SensorInterface::ON;
}

void Test::advance(int step)
{
    if (!step) {
        // all items are notified that they can move
        return;
    } else if (status == SensorInterface::ON) {
        // items are notified that the scene is about to change

    }
}

Q_EXPORT_PLUGIN2(test, Test)
