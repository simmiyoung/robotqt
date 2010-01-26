#include "robotcore/pluginbase.h"

#include "statusitem.h"

StatusItem::StatusItem()
{

}

StatusItem::StatusItem(PluginBase *plugin)
{
    setPlugin(plugin);
}

void StatusItem::setPlugin(PluginBase *plugin)
{
    if (plugin->getType() == PluginBase::Robot) {
        setIcon(QIcon(QPixmap(":/images/robot_item.png")));
        setText(QObject::tr("Robot: %1").arg(plugin->getName()));
    }
    else if (plugin->getType() == PluginBase::Sensor) {
        setIcon(QIcon(QPixmap(":/images/sensor_item.png")));
        setText(QObject::tr("Sensor: %1").arg(plugin->getName()));
    }
    setTextAlignment(Qt::AlignRight | Qt::AlignVCenter);
    setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
    setBackground(QBrush(Qt::white));
}

QTableWidgetItem * StatusItem::clone() const
{
    return new StatusItem(*this);
}
