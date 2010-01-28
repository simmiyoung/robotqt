#include "robotcore/pluginbase.h"

#include "statusitem.h"

StatusItem::StatusItem()
{

}

StatusItem::StatusItem(PluginBase *_plugin)
{
    setPlugin(_plugin);
}

StatusItem::~StatusItem()
{
    delete plugin;
}

void StatusItem::setPlugin(PluginBase *_plugin)
{
    plugin = _plugin;

    if (plugin->getType() == PluginBase::Robot) {
        setIcon(QIcon(":/images/robot_item.png"));
        setText(QObject::tr("Robot: %1").arg(plugin->getName()));
    } else if (plugin->getType() == PluginBase::Sensor) {
        setIcon(QIcon(":/images/sensor_item.png"));
        setText(QObject::tr("Sensor: %1").arg(plugin->getName()));
    } else if (plugin->getType() == PluginBase::Scenario) {
        setIcon(QIcon(":/images/scenario_item.png"));
        setText(QObject::tr("Scenario: %1").arg(plugin->getName()));
    }
    setTextAlignment(Qt::AlignRight | Qt::AlignVCenter);
    setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
    setBackground(QBrush(Qt::white));
}

QTableWidgetItem * StatusItem::clone() const
{
    return new StatusItem(*this);
}
