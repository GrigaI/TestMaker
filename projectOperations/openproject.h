#ifndef OPENPROJECT_H
#define OPENPROJECT_H

#include <QFile>
#include <QFileDialog>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonValue>
#include <QJsonParseError>
#include <QList>

#include "items/item.h"
#include "dialogs/editor.h"

class OpenProject
{
public:
    OpenProject(QString path);

   QList<Item*> items();
private:
    QString path;
    QString readFile();

    void parseJson();

    void item(QJsonValue value);

    QList<Item*> itemsList;
signals:

};

#endif // OPENPROJECT_H
