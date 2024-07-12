#include "settings.h"
#include "ui_settings.h"

Settings::Settings(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Settings)
{
    ui->setupUi(this);
    QIcon icon(":/resources/images/mainIcon.png");
    setWindowIcon(icon);
    setWindowTitle("Настройки");

    ip = "localhost";
    port = 13200;
}

Settings::~Settings()
{
    delete ui;
}

QString Settings::getIp()
{
    return ip;
}

int Settings::getPort()
{
    return port;
}

void Settings::on_pushButton_enter_clicked()
{
    if(ui->lineEdit_ip->text() != "" || ui->lineEdit_port->text() != "") {
        ip = ui->lineEdit_ip->text();
        port = ui->lineEdit_port->text().toInt();
    }
    this->close();
}

