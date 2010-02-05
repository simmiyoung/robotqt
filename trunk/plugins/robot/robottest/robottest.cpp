#include "robottest.h"

#include <QGraphicsScene>
#include <QPainter>
#include <QStyleOption>

RobotTest::RobotTest()
{
    // setting PluginBase attributes
    setName(tr("Outro robo teste"));
    setType(PluginBase::Robot);

    // we need to reset RobotInterface attributes
    startingPoint.setX(-100.0);
    startingPoint.setY(-100.0);
    startAngle = qrand() % 360;

    // random robot color
    color = QColor(qrand() % 256, qrand() % 256, qrand() % 256);

    // setting rotation just for fun
    setRotation(startAngle);
}

QRectF RobotTest::boundingRect() const
{
    qreal adjust = 4;
    return QRectF(-10 - adjust, -10 - adjust,
                  20 + adjust, 20 + adjust);
}

QPainterPath RobotTest::shape() const
{
    QPainterPath path;
    path.addRect(-10, -10, 20, 20);
    return path;
}

void RobotTest::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setRenderHint(QPainter::Antialiasing, true);
    painter->drawRect(-10, -10, 20, 20);
    painter->fillRect(-10, -10, 20, 20, color);
}

Q_EXPORT_PLUGIN2(robottest, RobotTest)
