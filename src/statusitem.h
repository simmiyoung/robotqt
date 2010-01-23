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
    StatusItem(PluginBase *interface);

    QTableWidgetItem * clone() const;
};

#endif // STATUSITEM_H
