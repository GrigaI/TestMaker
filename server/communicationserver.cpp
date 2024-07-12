#include "communicationserver.h"

CommunicationServer::CommunicationServer(QString ip, int port) : QTcpServer()
{
    this->ip=ip;
    this->port=port;


}

CommunicationServer::CommunicationServer()
{
    ip = "127.0.0.1";
    port=13200;
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

void CommunicationServer::writeMessage(QByteArray arr)
{
    sock->write(arr);
}

void CommunicationServer::readyReadSlot()
{

        int messageSize = 0;
        sock->read((char*)&messageSize, sizeof(&messageSize));

        qDebug()<<"message size: "<<messageSize;

        if(messageSize == 260) {
            emit parseFinished(true);
        } else {
            emit parseFinished(false);
        }
}
