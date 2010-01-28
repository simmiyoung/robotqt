#ifndef TESTE_H
#define TESTE_H

#include "../../../src/robotcore/robotinterface.h"

class QColor;

class Test : public QObject, public RobotInterface
{
    Q_OBJECT
    Q_INTERFACES(RobotInterface)
    Q_PROPERTY(QPointF pos READ pos WRITE setPos)
    Q_PROPERTY(qreal rotation READ rotation WRITE setRotation)

public:
    Test();

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget);

//    QPointF pos() const;
//    void setPos(const QPointF &pos);
//    qreal rotation() const;
//    void setRotation(qreal angle);

//
//protected:
//    void advance(int step);

private:
    QColor color;
};

#endif
