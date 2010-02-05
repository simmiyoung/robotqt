#include "sensortest.h"

#include <QGraphicsScene>
#include <QPainter>
#include <QStyleOption>

SensorTest::SensorTest()
{
    // setting PluginBase attributes
    setName(tr("Radar"));
    setType(PluginBase::Sensor);

    status = SensorInterface::ON;

    /*
     * Size representation of the scenario
     */
    color = QColor(255, 0, 0);
}

QRectF SensorTest::boundingRect() const
{
    return QRectF(-50.0 - 1.0 , -50.0 - 1.0,
                  100.0 + 2.0, 100.0 + 2.0);
}

QPainterPath SensorTest::shape() const
{
    QPainterPath path;
    path.addEllipse(QRectF(-50.0, -50.0, 100.0, 100.0));

    return path;
}

void SensorTest::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    painter->setRenderHint(QPainter::Antialiasing, true);

    QPainterPath path;
    path.addEllipse(QRectF(-50.0, -50.0, 100.0, 100.0));

    painter->drawPath(path);
    painter->fillPath(path, QBrush(color, (scene()->collidingItems(this).isEmpty()) ?
                                   Qt::Dense6Pattern : Qt::Dense2Pattern));
}

void SensorTest::turnOff()
{
    status = SensorInterface::OFF;
}

void SensorTest::turnOn()
{
    status = SensorInterface::ON;
}

Q_EXPORT_PLUGIN2(sensortest, SensorTest)
