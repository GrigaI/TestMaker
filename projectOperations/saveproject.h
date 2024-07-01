#ifndef SAVEPROJECT_H
#define SAVEPROJECT_H

#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonValue>
#include <QFile>
#include <QTextStream>
#include <QObject>
#include <QDebug>
#include <QFileInfo>

#include "items/item.h"

class SaveProject : public QObject
{
    Q_OBJECT
public:
    SaveProject(QString name, QList<Item*> items);

private:
    QList<Item*> items;
    void onSaveProjects();
    QJsonObject itemToJson(Item* item);
    QString name;

};

#endif // SAVEPROJECT_H
