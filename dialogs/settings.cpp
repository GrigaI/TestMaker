#include "settings.h"
#include "ui_settings.h"

Settings::Settings(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Settings)
{
    ui->setupUi(this);
    setWindowTitle("Настройки");
}

Settings::~Settings()
{
    delete ui;
}

void Settings::on_pushButton_enter_clicked()
{

}

