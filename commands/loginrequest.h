#ifndef LOGINREQUEST_H
#define LOGINREQUEST_H

#include <QStringList>
#include <QDebug>
class LoginRequest
{
public:
    LoginRequest(QStringList parameters);

    void run();
private:
    QStringList parameters;
};

#endif // LOGINREQUEST_H
