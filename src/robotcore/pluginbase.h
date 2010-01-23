#ifndef PLUGINBASE_H
#define PLUGINBASE_H

#include <QGraphicsItem>

class QString;

class PluginBase
{
public:
    enum Type { Robot, Sensor };

    virtual ~PluginBase() {}

    void setName(const QString &_name);
    QString getName() const;

    void setType(PluginBase::Type _type);
    PluginBase::Type getType() const;

private:
    QString name;
    PluginBase::Type type;
};

#endif // PLUGINBASE_H
