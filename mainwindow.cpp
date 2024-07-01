#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    name = "Новый проект";
    setWindowTitle(name);
    setting = new Settings;

    ui->listWidget->viewport()->installEventFilter(this);


    ui->listWidget->setAcceptDrops(true);
    ui->listWidget->setDragEnabled(true);
    ui->listWidget->setDragDropMode(QAbstractItemView::InternalMove);
}

MainWindow::~MainWindow()
{
    delete ui;

}


void MainWindow::on_pushButton_addCommand_clicked()
{
    Item *item = new Item;
    item->setWgtFields();

    ui->listWidget->addItem(item);
    ui->listWidget->setItemWidget(item,item->widget());


    Editor *editor = new Editor(item, WINDOW::ADDCOMMAND);
    editor->show();



}


void MainWindow::on_pushButton_delCommand_clicked()
{
    delete ui->listWidget->currentItem();
}


void MainWindow::on_pushButton_enter_clicked()
{
    int countCommand = ui->listWidget->count();
    for (int i = 0; i < countCommand; i++) {
        Item *curItem = dynamic_cast<Item *>(ui->listWidget->item(i));
        curItem->run();
    }

}

void MainWindow::onEditedCommand(int i, QString str)
{
    ui->listWidget->item(i)->setText(str);
}

bool MainWindow::eventFilter(QObject *watched, QEvent *event)
{
    int index = ui->listWidget->currentIndex().row();
    if(watched == ui->listWidget->viewport() && event->type() == QEvent::MouseButtonDblClick && index != -1 ){
        QMouseEvent *mouseEvent = static_cast<QMouseEvent*>(event);
        Q_UNUSED(mouseEvent);
        qDebug()<<"MouseButtonDblClick"<<index;

        Item *item = dynamic_cast<Item *>(ui->listWidget->currentItem());
        Editor *editor = new Editor(item,WINDOW::EDITCOMMAND);
        editor->show();
    }
    return QMainWindow::eventFilter(watched, event);



}

void MainWindow::on_action_create_triggered()       //создать
{

}


void MainWindow::on_action_open_triggered()         //открыть
{

}


void MainWindow::on_action_save_triggered()         //сохранить
{
    if (name == "Новый проект" || name == "") {
        on_action_saveAs_triggered();
    } else {
        saveP = new SaveProject(path,items());
        Q_UNUSED(saveP);
    }

}


void MainWindow::on_action_saveAs_triggered()       //сохранить как
{
    if (ui->listWidget->count() < 1) {
        QMessageBox::warning(this,"Ошибка","Необходимо создать хотя бы одну команду");
    } else {
        path = QFileDialog::getSaveFileName(this, "Save File", "/home/", "JSON Files (*.json);;All Files (*.*)");
        saveP = new SaveProject(path,items());

        Q_UNUSED(saveP);
    }


}


void MainWindow::on_action_settings_triggered()     //настройки
{
    setting->show();
}

QList<Item *> MainWindow::items()
{
    QList<Item*> list;
    for (int i = 0; i < ui->listWidget->count();i++){
        Item *item = dynamic_cast<Item*>(ui->listWidget->item(i));
        list.append(item);
    }
    qDebug()<<list;
    return list;
}

