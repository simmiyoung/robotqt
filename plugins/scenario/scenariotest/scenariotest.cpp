#include "scenariotest.h"

#include <QGraphicsScene>
#include <QPainter>
#include <QStyleOption>

#include <math.h>

static const double Pi = 3.14159265358979323846264338327950288419717;
static double TwoPi = 2.0 * Pi;

ScenarioTest::ScenarioTest()
{
    // setting PluginBase attributes
    setName(tr("Cenário Teste!"));
    setType(PluginBase::Scenario);

}

QRectF ScenarioTest::boundingRect() const {
//    qreal adjust = 4;
//    return QRectF(-10 - adjust, -10 - adjust,
//                  20 + adjust, 20 + adjust);
}

void ScenarioTest::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    QRectF rect(0.0, 0.0, 60.0, 60.0);
    painter->setRenderHint(QPainter::Antialiasing, true);
    painter->drawEllipse(rect);
    painter->fillRect(rect);
}

void Test::turnOff()
{
    status = SensorInterface::OFF;
}

Q_EXPORT_PLUGIN2(scenariotest, ScenarioTest)
