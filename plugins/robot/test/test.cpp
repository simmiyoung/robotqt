#include "test.h"

#include <QGraphicsScene>
#include <QPainter>
#include <QStyleOption>

#include <math.h>

static const double Pi = 3.14159265358979323846264338327950288419717;
static double TwoPi = 2.0 * Pi;

static qreal normalizeAngle(qreal angle) {
    while (angle < 0)
        angle += TwoPi;
    while (angle > TwoPi)
        angle -= TwoPi;
    return angle;
}

Test::Test()
{
    // setting PluginBase attributes
    setName("Robot Teste!");
    setType(PluginBase::Robot);

    // we need to reset RobotInterface attributes
    angle = 0;
    speed = 0;
    startingPoint.setX(200.0);
    startingPoint.setY(200.0);

    color = QColor(qrand() % 256, qrand() % 256, qrand() % 256);

    setRotation(qrand() % (360 * 16));
}

QRectF Test::boundingRect() const {
    qreal adjust = 4;
    return QRectF(-10 - adjust, -10 - adjust,
                  20 + adjust, 20 + adjust);
}

void Test::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    painter->drawRect(-10, -10, 20, 20);
//    // wheels
//    painter->drawEllipse(-11.5, -8, 4, 6); // top-left
//    painter->drawEllipse(10, -8, 4, 6); // top-right
//    painter->drawEllipse(-11.5, 8, 4, 6); // bottom-left
//    painter->drawEllipse(11.5, 8, 4, 6); // bottom-right
//
//    // to paint the wheels
//    QPainterPath path;
//    path.addEllipse(-11.5, -8, 4, 6); // top-left
//    path.addEllipse(10, -8, 4, 6); // top-right
//    path.addEllipse(-11.5, 8, 4, 6); // bottom-left
//    path.addEllipse(11.5, 8, 4, 6); // bottom-right

    painter->fillRect(-10, -10, 20, 20, color);
//    painter->fillPath(path, QBrush(Qt::black));
}

void Test::advance(int step)
 {
     if (!step)
         // all items are notified that they can move
         return;

     // items are notified that the scene is about to change
     // Don't move too far away
     QLineF lineToCenter(QPointF(0, 0), mapFromScene(0, 0));
     if (lineToCenter.length() > 150) {
         qreal angleToCenter = ::acos(lineToCenter.dx() / lineToCenter.length());
         if (lineToCenter.dy() < 0)
             angleToCenter = TwoPi - angleToCenter;
         angleToCenter = normalizeAngle((Pi - angleToCenter) + Pi / 2);

         if (angleToCenter < Pi && angleToCenter > Pi / 4) {
             // Rotate left
             angle += (angle < -Pi / 2) ? 0.25 : -0.25;
         } else if (angleToCenter >= Pi && angleToCenter < (Pi + Pi / 2 + Pi / 4)) {
             // Rotate right
             angle += (angle < Pi / 2) ? 0.25 : -0.25;
         }
     } else if (::sin(angle) < 0) {
         angle += 0.25;
     } else if (::sin(angle) > 0) {
         angle -= 0.25;
     }

     speed += (-50 + qrand() % 100) / 100.0;

     qreal dx = ::sin(angle) * 10;

     setRotation(rotation() + dx);
     setPos(mapToParent(0, -(3 + sin(speed) * 3)));
 }

Q_EXPORT_PLUGIN2(test, Test)
