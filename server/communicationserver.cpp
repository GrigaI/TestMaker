#include "communicationserver.h"

CommunicationServer::CommunicationServer(QString ip, int port) : QTcpServer()
{
    this->ip=ip;
    this->port=port;

    sock = new QTcpSocket;
    connect(sock,SIGNAL(readyRead()),this,SLOT(readyReadSlot()));
}

CommunicationServer::~CommunicationServer()
{

}

bool CommunicationServer::connectToServer()
{

    sock->connectToHost(ip,port);
    sock->waitForConnected(1000);
    if(sock->state() == QTcpSocket::ConnectedState) {
            qDebug()<<"Connection success";
            return true;
        }
        else
        {
        qDebug()<<"Connection error";
            return false;
    }
}

void CommunicationServer::readyReadSlot()
{
    while(sock->bytesAvailable()>=sizeof(int)){
        int messageSize = 0;
        sock->read((char*)&messageSize, sizeof(&messageSize));

        qDebug()<<"message size: "<<messageSize;

        while(sock->bytesAvailable() < messageSize){
            sock->waitForReadyRead(1);

        }
            QByteArray messagePack = sock->read(messageSize);
            qDebug()<<"message pack: "<<messagePack;
            //QJsonObject messageJsonObject = QJsonDocument::fromJson(messagePack).object();
            //emit packGetted(messageJsonObject);
            //qDebug()<<"message json onj :  "<<messageJsonObject;



           // qDebug()<<"readAll: "<<parentSocket->readAll();

        }
}
