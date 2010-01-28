#ifndef STATUSITEM_H
#define STATUSITEM_H

#include <QTableWidgetItem>

class PluginBase;

/*
 * Subclassing QTableWidgetItem to costumized Item.
 */
class StatusItem : public QTableWidgetItem
{
public:
    StatusItem();
    StatusItem(PluginBase *_plugin);

    ~StatusItem();

    void setPlugin(PluginBase *_plugin);

    QTableWidgetItem * clone() const;

private:
    PluginBase * plugin;
};

#endif // STATUSITEM_H
