#include "editor.h"
#include "ui_editor.h"

Editor::Editor(Item *item,WINDOW window, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Editor)
{
    ui->setupUi(this);
    QIcon icon(":/resources/images/mainIcon.png");
    setWindowIcon(icon);
    setWindowFlag(Qt::FramelessWindowHint,1);
    this->item=item;
    this->window=window;
    ui->comboBox_type->clear();
    ui->comboBox_type->addItems(com.cmbList());
    switch (window) {
    case 0: {
        openAdd();

        break;
    }
    case 1: {
        openEditor();
        break;
    }
    }

    connect(ui->comboBox_type,SIGNAL(currentIndexChanged(int)),this,SLOT(cmbBoxCurrentIndexChanged(int)));

}

Editor::~Editor()
{
    delete ui;
}

void Editor::setCurIndex(int index)
{
    ui->stackedWidget->setCurrentIndex(index);
}

int Editor::curBtnClicked()
{
    return curButton;
}

void Editor::on_pushButton_enter_clicked()
{
    name = ui->lineEdit_name->text();
    description = ui->plainTextEdit->toPlainText();

    QStringList list;
    int index = ui->comboBox_type->currentIndex();
    switch (index){
    case TYPES::AUTORIZATION:{
        list.append(ui->lineEdit_login->text());
        list.append(ui->lineEdit_pass->text());
        break;
    }
    case TYPES::SECONDTYPE:{
        break;
    }
    case TYPES::THIRDTYPE:{
        break;
    }
    }



    item->setName(name);
    item->setTypeName(ui->comboBox_type->currentText());
    item->setType(ui->comboBox_type->currentIndex());
    item->setDescription(description);
    item->setToolTip(description);
    item->setParameters(list);
    item->clearLabel();

    this->close();

    curButton = 1;
}

void Editor::on_pushButton_cancel_clicked()
{

   if(window == WINDOW::ADDCOMMAND)  delete item;
    this->close();
    curButton = 0;
}

void Editor::cmbBoxCurrentIndexChanged(int index)
{
    switch (index) {
    case 0: {
        ui->stackedWidget->setCurrentIndex(0);
        qDebug()<<"index combo box 0";
        break;
    }
    case 1: {
        ui->stackedWidget->setCurrentIndex(1);
        qDebug()<<"index combo box 1";
        break;
    }
    case 2: {
        ui->stackedWidget->setCurrentIndex(2);
        qDebug()<<"index combo box 2";
        break;
    }

    }
}

void Editor::openAdd()
{
    ui->pushButton_enter->setText("Добавить");
    ui->label_windowName->setText("Добавить команду");
}

void Editor::openEditor()
{
    ui->pushButton_enter->setText("Изменить");
    ui->label_windowName->setText("Редактировать команду");
    setFields();
}

void Editor::setFields()
{
    int index = item->typeIndex();
    QStringList list = item->fields();
    ui->lineEdit_name->setText(list[0]);

    ui->plainTextEdit->setPlainText(list[2]);

    ui->comboBox_type->setCurrentIndex(index);
    item->setTypeName(ui->comboBox_type->currentText());
    ui->stackedWidget->setCurrentIndex(index);

    switch (index){
    case TYPES::AUTORIZATION: {
        ui->lineEdit_login->setText(list[3]);
        ui->lineEdit_pass->setText(list[4]);
    break;
    }
    }
}
