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

void ItemWidget::on_toolButton_clicked()
{
    emit editingStart();
}

