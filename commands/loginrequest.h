#ifndef LOGINREQUEST_H
#define LOGINREQUEST_H

#include <QStringList>
#include <QDebug>
#include <QTcpSocket>
#include <QDataStream>
#include "items/itemwidget.h"

#include "server/communicationserver.h"

class LoginRequest : public QObject
{
    Q_OBJECT
public:
    LoginRequest(QStringList parameters);

    void run(ItemWidget *wgt);
private:
    QStringList parameters;
    QTcpSocket *socket;
    ItemWidget *wgt;
private slots:
    void onPasreFinished(bool is);

signals:
    void parseFinished(bool);
};

#endif // LOGINREQUEST_H
