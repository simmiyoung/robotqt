#ifndef TESTE_H
#define TESTE_H

#include "../../../src/robotcore/scenariointerface.h"

class QColor;

class ScenarioTest : public QObject, public ScenarioInterface
{
    Q_OBJECT
    Q_INTERFACES(ScenarioInterface)

public:
    ScenarioTest();

    QRectF boundingRect() const;
    QPainterPath shape() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget);

private:
    QColor color;
};

#endif
