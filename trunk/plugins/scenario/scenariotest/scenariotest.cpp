#include "scenariotest.h"

#include <QGraphicsScene>
#include <QPainter>
#include <QStyleOption>

ScenarioTest::ScenarioTest()
{
    // setting PluginBase attributes
    setName(tr("Cenario Teste!"));
    setType(PluginBase::Scenario);

    // setting ScenarioInterface attributes
    scenarioRect = QRectF(-300.0, -300.0, 600.0, 600.0);

    /*
     * Size representation of the scenario
     */
    enum sizeType { Centimeter, Meter, Kilometer };
    type = ScenarioInterface::Meter;
    scenarioSize = QSizeF(10.0, 10.0);

    color = QColor(qrand() % 256, qrand() % 256, qrand() % 256);
}

QRectF ScenarioTest::boundingRect() const
{
    return scenarioRect;
}

QPainterPath ScenarioTest::shape() const
{
    QPolygonF polygon;
    polygon << QPointF(150.0, -300.0) << QPointF(300.0, -300.0) << QPointF(300.0, 0.0)
            << QPointF(250.0, 0.0) << QPointF(250.0, -250.0) << QPointF(150.0, -250.0)
            << QPointF(150.0, -300.0);

    QPainterPath path;
    path.addRect(-15.0, -15.0, 30.0, 30.0);
    path.addRect(-300.0, -300.0, 20.0, 30.0);
    path.addRect(200.0, 50.0, 30.0, 100.0);
    path.addPolygon(polygon);

    return path;
}

void ScenarioTest::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    painter->setRenderHint(QPainter::Antialiasing, true);

    QPolygonF polygon1;
    polygon1 << QPointF(150.0, -300.0) << QPointF(300.0, -300.0) << QPointF(300.0, 0.0)
            << QPointF(250.0, 0.0) << QPointF(250.0, -250.0) << QPointF(150.0, -250.0)
            << QPointF(150.0, -300.0);
    QPolygonF polygon2;
    polygon2 << QPointF(-150.0, 300.0) << QPointF(-300.0, 300.0) << QPointF(-300.0, 0.0)
            << QPointF(-250.0, 0.0) << QPointF(-250.0, 250.0) << QPointF(-150.0, 250.0)
            << QPointF(-150.0, 300.0);

    QPainterPath path;
    path.addRect(-15.0, -15.0, 30.0, 30.0);
    path.addRect(-300.0, -300.0, 20.0, 30.0);
    path.addRect(200.0, 50.0, 30.0, 100.0);
    path.addPolygon(polygon1);
    path.addPolygon(polygon2);

    QRectF border(-300.0, -300.0, 600.0, 600.0);

    painter->drawRect(border);
    painter->drawPath(path);
    painter->fillPath(path, color);
}

Q_EXPORT_PLUGIN2(scenariotest, ScenarioTest)
