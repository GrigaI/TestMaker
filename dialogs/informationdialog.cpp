#include "informationdialog.h"
#include "ui_informationdialog.h"

InformationDialog::InformationDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InformationDialog)
{
    ui->setupUi(this);
}

InformationDialog::~InformationDialog()
{
    delete ui;
}

void InformationDialog::setText(QString str)
{
    QString curTime = QDateTime::currentDateTime().toString("dd.MM.yyyy HH:mm:ss");
    htmlStr = htmlStr + "<br>["+curTime+"] " + str + "</br>";
    ui->textBrowser->clear();
    ui->textBrowser->insertHtml(htmlStr);
}
