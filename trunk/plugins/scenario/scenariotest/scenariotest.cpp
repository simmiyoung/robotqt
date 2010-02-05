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
    scenarioSize = QSizeF(600.0, 600.0);

    color = QColor(qrand() % 256, qrand() % 256, qrand() % 256);
}

QRectF ScenarioTest::boundingRect() const
{
    return scenarioRect;
}

QPainterPath ScenarioTest::shape() const
{
    QPainterPath path;
    path.addRect(QRectF(0.0, 0.0, 60.0, 60.0));
    path.addRect(QRectF(-300.0, -280.0, 60.0, 60.0));
    path.addRect(QRectF(200.0, 50.0, 30.0, 15.0));
    return path;
}

void ScenarioTest::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    QVector<QRectF> v(4);
    QRectF block1(0.0, 0.0, 60.0, 60.0);
    QRectF block2(-300.0, -280.0, 60.0, 60.0);
    QRectF block3(200.0, 50.0, 30.0, 15.0);
    QRectF border(-300.0, -300.0, 600.0, 600.0);

    v << block1 << block2 << block3 << border;

    painter->setRenderHint(QPainter::Antialiasing, true);
    painter->drawRects(v);
    painter->fillRect(block1, color);
    painter->fillRect(block2, color);
    painter->fillRect(block3, color);
}

Q_EXPORT_PLUGIN2(scenariotest, ScenarioTest)
