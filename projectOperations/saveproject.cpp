#include "saveproject.h"

SaveProject::SaveProject(QList<Item *> items)
{
    this->items=items;
    onSaveProjects();
}

void SaveProject::onSaveProjects()
{

    QJsonObject mainObj; //имя проекта : объект с командами
    mainObj.insert("name", "test");
    for (int i = 0; i < items.count();i++){
        mainObj.insert("command_"+QString::number(i+1),itemToJson(dynamic_cast<Item*>(items[i])));
    }
    QJsonDocument doc(mainObj);
    QString jsonStr = doc.toJson(QJsonDocument::Indented);

    QFile file;
    file.setFileName("testJson.json");
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
