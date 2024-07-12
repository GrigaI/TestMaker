#include "loginrequest.h"

LoginRequest::LoginRequest(QStringList parameters) : QObject()
{
    this->parameters=parameters;

}

void LoginRequest::run(ItemWidget *wgt, QString ip, int port)
{
    this->wgt=wgt;
    qDebug()<<"Параметры: "<<parameters;
    CommunicationServer *server = new CommunicationServer(ip, port);
    connect(server,SIGNAL(parseFinished(bool)),this,SLOT(onPasreFinished(bool)));

    server->connectToServer();

    quint32 type = 0;
    QString login = parameters[0];
    QString pass = parameters[1];

    QByteArray byteArr;
    QDataStream writer(&byteArr, QIODevice::WriteOnly);
    writer.setByteOrder(QDataStream::LittleEndian);

    writer << type;
    writer << login.toUtf8();
    writer << pass.toUtf8().toBase64();

    QByteArray outArray;
    QDataStream outStream(&outArray, QIODevice::WriteOnly);
    outStream.setByteOrder(QDataStream::LittleEndian);
    outStream << byteArr;
    server->writeMessage(outArray);
}

void LoginRequest::onPasreFinished(bool is)
{
    wgt->setColor(is);
}
