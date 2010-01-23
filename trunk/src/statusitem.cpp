#include "robotcore/pluginbase.h"

#include "statusitem.h"

StatusItem::StatusItem(PluginBase *interface) :
        QTableWidgetItem(QTableWidgetItem::UserType)
{
    if (interface->getType() == PluginBase::Robot) {
        setIcon(QIcon(QPixmap(":/images/robot_item.png")));
        setText(QObject::tr("Robot: %1").arg(interface->getName()));
    }
//    else if (SensorInterface *i = dynamic_cast<SensorInterface *>(interface)) {
//        setIcon(QIcon(":/images/sensor_item.gif"));
//        setText(tr("Sensor: %1").arg(i->name));
//    }
    setTextAlignment(Qt::AlignVCenter);
    setFlags(Qt::NoItemFlags);
    setBackground(QBrush(Qt::gray));
}

QTableWidgetItem * StatusItem::clone() const
{
    return new StatusItem(*this);
}
