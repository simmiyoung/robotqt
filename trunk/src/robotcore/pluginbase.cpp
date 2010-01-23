#include <QString>

#include "pluginbase.h"

void PluginBase::setName(const QString &_name)
{
    name = _name;
}

QString PluginBase::getName() const
{
    return name;
}

void PluginBase::setType(PluginBase::Type _type)
{
    type = _type;
}

PluginBase::Type PluginBase::getType() const
{
    return type;
}
