#include "openproject.h"

OpenProject::OpenProject(QString path)
{
    this->path=path;
    parseJson();
}

QList<Item *> OpenProject::items()
{
    return itemsList;
}

QString OpenProject::readFile()
{
    QString fileStr;
    QFile file;
    file.setFileName(path);
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    fileStr = file.readAll();
    file.close();
    return fileStr;
}

void OpenProject::parseJson()
{
    QJsonParseError error;
    QJsonDocument doc = QJsonDocument::fromJson(readFile().toUtf8(), &error);
    qDebug()<< "Error: " << error.errorString() << error.offset << error.error;

    QJsonObject mainObj = doc.object();
    QStringList keys = mainObj.keys();

    for (int i = 0; i < keys.count();i++){
        QJsonValue val = mainObj.value(keys[i]);
        item(val);
    }

}

void OpenProject::item(QJsonValue value)
{

    Item *item = new Item;
    QString name = value["name"].toString();
    item->setName(name);

    qDebug()<<"type: "<<value["type"].toInt();
    int type = value["type"].toInt();

    item->setType(type);

    if (type == 0) {
        QStringList list = value["parameters"].toVariant().toStringList();
        item->setParameters(list);
    }

    QString description = value["description"].toString();
    item->setDescription(description);

    qDebug()<< name << type << description;


    itemsList.append(item);
    Editor *editor = new Editor(item,WINDOW::EDITCOMMAND);
    item->setWgtFields();
}
