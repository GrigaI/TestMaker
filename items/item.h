#ifndef ITEM_H
#define ITEM_H

#include <QListWidgetItem>
#include <QDebug>

#include "commands/loginrequest.h"
#include "commands/command.h"
#include "itemwidget.h"

class Item : public QListWidgetItem
{
public:
    Item();

    void setName(QString name);

    void setTypeName(QString type);

    void setType(int type);

    void setDescription(QString description);

    void setParameters(QStringList parameters);

    void setWgtFields();

    int typeIndex();

    ItemWidget* widget();

    QStringList fields();

    void run();
private:
    QString name;
    QString typeName;
    int type;
    QString description;
    QStringList parameters;

    ItemWidget *wgt;
signals:

};

#endif // ITEM_H
