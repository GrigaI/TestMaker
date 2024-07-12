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
    CommunicationServer();
    ~CommunicationServer();

    bool connectToServer();
    void writeMessage(QByteArray arr);
private:
    QTcpSocket* sock;
    QString ip;
    int port;

private slots:
    void readyReadSlot();
signals:
    void parseFinished(bool);

};

#endif // COMMUNICATIONSERVER_H
