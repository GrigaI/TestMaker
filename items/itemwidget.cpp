#include "itemwidget.h"
#include "ui_itemwidget.h"

ItemWidget::ItemWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ItemWidget)
{
    ui->setupUi(this);

}

ItemWidget::~ItemWidget()
{
    delete ui;
}

void ItemWidget::setName(QString name)
{
    ui->label_name->setText(name);
}

void ItemWidget::setTypeName(QString type)
{
    ui->label_type->setText(type);
}

void ItemWidget::setColor(bool is)
{
    qDebug()<<"changeColor"<<is;
    if(is) {
        //ui->label_status->setStyleSheet("background-color:#058C2A");
        QPixmap pix(":/img/resources/images/check_mark.png");
        int w = ui->label_status->width();
        int h = ui->label_status->height();

        ui->label_status->setPixmap(pix.scaled(w,h, Qt::KeepAspectRatio));

    } else {
        //ui->label_status->setStyleSheet("background-color:#bf4040");
        QPixmap pix(":/img/resources/images/red_cross.png");
        int w = ui->label_status->width();
        int h = ui->label_status->height();

        ui->label_status->setPixmap(pix.scaled(w,h, Qt::KeepAspectRatio));
    }
}

void ItemWidget::clearLabel()
{
    ui->label_status->clear();
}

