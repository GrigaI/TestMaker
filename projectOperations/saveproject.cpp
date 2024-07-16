#include "saveproject.h"

SaveProject::SaveProject(QString path, QList<Item *> items) : QObject()
{
    this->items=items;
    this->path=path;
    onSaveProjects();
}

QString SaveProject::jsonToString(QList<Item *> curItems)
{
    QJsonObject mainObj; //имя проекта : ...

    for (int i = 0; i < curItems.count();i++){
        Item* item = dynamic_cast<Item*>(curItems[i]);
        mainObj.insert("command_"+QString::number(i+1),itemToJson(item));

    }
    QJsonDocument doc(mainObj);
    QString jsonStr = doc.toJson(QJsonDocument::Indented);
    qDebug()<<jsonStr;
    return jsonStr;
}

void SaveProject::onSaveProjects()
{
    QFile file;
    file.setFileName(path);
    file.open(QIODevice::WriteOnly | QIODevice::Text);
    QTextStream stream(&file);
    stream << jsonToString(items);
    file.close();

    qDebug()<<items;
}

QJsonObject SaveProject::itemToJson(Item* item)
{
    QStringList list = item->fields();

    QJsonObject mainObj;
    mainObj.insert("name",list[0]);
    mainObj.insert("type",list[1].toInt());
    mainObj.insert("description",list[2]);
    if (list.count() > 3) {
        QJsonArray arr;
        for (int i = 3; i < list.count();i++) {
            qDebug() <<QString(list[i]);
            arr.append(list[i]);
        }
        mainObj.insert("parameters",arr);
    }
    return mainObj;
}
