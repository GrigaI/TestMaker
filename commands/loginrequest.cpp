#include "loginrequest.h"

LoginRequest::LoginRequest(QStringList parameters)
{
    this->parameters=parameters;
}

void LoginRequest::run()
{
    qDebug()<<"Параметры: "<<parameters;
}
