#include "changecontrol.h"

ChangeControl::ChangeControl() : QThread()
{

}

void ChangeControl::run()
{
    qDebug()<<"str: "<< string;
    qDebug()<<"curStr: "<< curString;
    if (string == curString) {
        emit finished(true);
    } else {
        finished(false);
    }
}

void ChangeControl::setString(QString str)
{
    string = str;
}

void ChangeControl::setCurstring(QString str)
{
    curString = str;
}
