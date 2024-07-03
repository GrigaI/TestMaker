#ifndef COMMUNICATIONSERVER_H
#define COMMUNICATIONSERVER_H

#include <QTcpServer>
#include <QObject>
#include <QTcpSocket>

class CommunicationServer : public QTcpServer
{
    Q_OBJECT
public:
    CommunicationServer(QString ip, int port);
    ~CommunicationServer();

    bool connectToServer();
private:
    QTcpSocket* sock;
    QString ip;
    int port;

private slots:
    void readyReadSlot();
};

#endif // COMMUNICATIONSERVER_H
