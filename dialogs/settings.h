#ifndef SETTINGS_H
#define SETTINGS_H

#include <QDialog>
#include <QDebug>
#include <QTcpSocket>

#include "server/communicationserver.h"


namespace Ui {
class Settings;
}

class Settings : public QDialog
{
    Q_OBJECT

public:
    explicit Settings(QWidget *parent = nullptr);
    ~Settings();

private slots:
    void on_pushButton_enter_clicked();

private:
    Ui::Settings *ui;
    QString ip;
    int port;
    QTcpSocket* socket;
};

#endif // SETTINGS_H
