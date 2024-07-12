#ifndef ITEM_H
#define ITEM_H

#include <QListWidgetItem>
#include <QDebug>
#include <QObject>

#include "commands/loginrequest.h"
#include "commands/command.h"
#include "itemwidget.h"

class Item : public QListWidgetItem
{

public:
    Item();

    void clearLabel();

    void setName(QString name);

    void setTypeName(QString type);

    void setType(int type);

    void setDescription(QString description);

    void setParameters(QStringList parameters);

    void setWgtFields();

    int typeIndex();

    QString getTypeName();

    ItemWidget* widget();

    QStringList fields();

    void run(QString ip, int port);
private slots:

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
