#ifndef TESTE_H
#define TESTE_H

#include "../../../src/robotcore/robotinterface.h"

class QColor;

class Test : public QObject, public RobotInterface
{
    Q_OBJECT
    Q_INTERFACES(RobotInterface)

public:
    Test();

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget);

protected:
    void advance(int step);

private:
    QColor color;
};

#endif
