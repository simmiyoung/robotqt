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
    StatusItem(PluginBase *plugin);

    void setPlugin(PluginBase *plugin);

    QTableWidgetItem * clone() const;
};

#endif // STATUSITEM_H
