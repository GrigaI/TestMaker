#include "saveproject.h"

SaveProject::SaveProject(QString name, QList<Item *> items) : QObject()
{
    this->items=items;
    this->name=name;
    onSaveProjects();
}

void SaveProject::onSaveProjects()
{
    QJsonObject mainObj; //имя проекта : ...
    mainObj.insert("name", QFileInfo(name).fileName());
    for (int i = 0; i < items.count();i++){
        Item* item = dynamic_cast<Item*>(items[i]);
        mainObj.insert("command_"+QString::number(i+1),itemToJson(item));

    }
    QJsonDocument doc(mainObj);
    QString jsonStr = doc.toJson(QJsonDocument::Indented);

    QFile file;
    file.setFileName(name+".json");
    file.open(QIODevice::WriteOnly | QIODevice::Text);
    QTextStream stream(&file);
    stream << jsonStr;
    file.close();

    qDebug()<<items;
}

QJsonObject SaveProject::itemToJson(Item* item)
{
    QStringList list = item->fields();

    QJsonObject mainObj;
    mainObj.insert("name",list[0]);
    mainObj.insert("type",list[1]);
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
