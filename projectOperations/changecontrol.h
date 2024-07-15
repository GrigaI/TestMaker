#ifndef CHANGECONTROL_H
#define CHANGECONTROL_H

#include <QThread>
#include <QObject>
#include <QDebug>

class ChangeControl : public QThread
{
    Q_OBJECT
public:
    ChangeControl();

    void run();

    void setString(QString str);

    void setCurstring(QString str);
private:
    QString string="";
    QString curString="";
signals:
    void finished(bool);
};

#endif // CHANGECONTROL_H
