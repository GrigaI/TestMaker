#include "item.h"

Item::Item() : QListWidgetItem()
{
    wgt= new ItemWidget();
    setSizeHint(wgt->sizeHint());
}

void Item::clearLabel()
{
    wgt->clearLabel();
}

void Item::setName(QString name)
{
    this->name=name;
    wgt->setName(name);
}

void Item::setTypeName(QString type)
{
    this->typeName=type;
    wgt->setTypeName(type);
}

void Item::setType(int type)
{
    this->type = type;
}

void Item::setDescription(QString description)
{
    this->description=description;
}

void Item::setParameters(QStringList parameters)
{
    this->parameters=parameters;
}

void Item::setWgtFields()
{
    wgt->setName(name);
    wgt->setTypeName(typeName);
}

int Item::typeIndex()
{
    return type;
}

QString Item::getTypeName()
{
    return typeName;
}

ItemWidget *Item::widget()
{
    return wgt;
}

QStringList Item::fields()
{
    QStringList list;
    list.append(name);
    list.append(QString::number(type));
    list.append(description);
    list.append(parameters);
    qDebug()<<list;
    return list;
}

void Item::run()
{

    switch(typeIndex()) {
    case TYPES::AUTORIZATION: {
        LoginRequest *loginReq = new LoginRequest(parameters);
        loginReq->run(wgt);

        break;
    }
    case TYPES::SECONDTYPE: {
        qDebug()<<"vtoroy tip";
        break;
    }
    case TYPES::THIRDTYPE: {
        qDebug()<<"tretiy tip";
    }
    }
}


