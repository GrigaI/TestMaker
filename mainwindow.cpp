#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    name = "Новый проект";
    setWindowTitle(name);
    QIcon icon(":/resources/images/mainIcon.png");
    setWindowIcon(icon);
    control = new ChangeControl;
    control->setString(saveP->jsonToString(items()));

    connect(control,SIGNAL(finished(bool)),this,SLOT(changeControll(bool)));


    setting = new Settings();

    ui->listWidget->viewport()->installEventFilter(this);


    ui->listWidget->setAcceptDrops(true);
    ui->listWidget->setDragEnabled(true);
    ui->listWidget->setDragDropMode(QAbstractItemView::InternalMove);
}

MainWindow::~MainWindow()
{
        delete ui;
}


void MainWindow::on_pushButton_addCommand_clicked()             //кнопка добавить
{
    Item *item = new Item;
    item->setWgtFields();

    ui->listWidget->addItem(item);
    ui->listWidget->setItemWidget(item,item->widget());


    Editor *editor = new Editor(item, WINDOW::ADDCOMMAND);
    editor->exec();

    control->setCurstring(saveP->jsonToString(items()));
    control->start();



}


void MainWindow::on_pushButton_delCommand_clicked()                 //кнопка удалить
{
    delete ui->listWidget->currentItem();
    control->setCurstring(saveP->jsonToString(items()));
    control->start();
}


void MainWindow::on_pushButton_enter_clicked()                      //кнопка запустить
{
    int countCommand = ui->listWidget->count();
    for (int i = 0; i < countCommand; i++) {
        Item *curItem = dynamic_cast<Item *>(ui->listWidget->item(i));
        curItem->run(setting->getIp(), setting->getPort());
    }

}

void MainWindow::onEditedCommand(int i, QString str)
{
    ui->listWidget->item(i)->setText(str);
}

bool MainWindow::eventFilter(QObject *watched, QEvent *event)           //дабл клик
{
    int index = ui->listWidget->currentIndex().row();
    if(watched == ui->listWidget->viewport() && event->type() == QEvent::MouseButtonDblClick && index != -1 ){
        QMouseEvent *mouseEvent = static_cast<QMouseEvent*>(event);
        Q_UNUSED(mouseEvent);
        qDebug()<<"MouseButtonDblClick"<<index;

        Item *item = dynamic_cast<Item *>(ui->listWidget->currentItem());
        Editor *editor = new Editor(item,WINDOW::EDITCOMMAND);
        editor->exec();

        control->setCurstring(saveP->jsonToString(items()));
        control->start();
    }
    return QMainWindow::eventFilter(watched, event);



}

void MainWindow::on_action_create_triggered()       //создать
{
    if (saveChange == 1) {
        int answer = QMessageBox::warning(this,"Внимание!", "Все несохраненные удаления будут удалены!","Продолжить","Отмена");
        if(answer == 0) {
            createNewProject();
        }
    } else {
        createNewProject();
    }
}


void MainWindow::on_action_open_triggered()         //открыть
{
    if (saveChange == 1) {
        int answer = QMessageBox::warning(this,"Внимание!", "Все несохраненные удаления будут удалены!","Продолжить","Отмена");
        if(answer == 0) {
            path = QFileDialog::getOpenFileName(this, "Open File", "/home/", "JSON Files (*.json)");
            openFile(path);
        }
    } else {
        path = QFileDialog::getOpenFileName(this, "Open File", "/home/", "JSON Files (*.json)");
        openFile(path);
    }

}


void MainWindow::on_action_save_triggered()         //сохранить
{
    if (saveChange == 0) return;
    if (name == "Новый проект" || name == "") {
        on_action_saveAs_triggered();
    } else {
        saveP = new SaveProject(path,items());
        openFile(path);

    }

}


void MainWindow::on_action_saveAs_triggered()       //сохранить как
{
    if (ui->listWidget->count() < 1) {
        QMessageBox::warning(this,"Ошибка","Необходимо создать хотя бы одну команду");
    } else {
        path = QFileDialog::getSaveFileName(this, "Save File", "/home/", "JSON Files (*.json);;All Files (*.*)");
        saveP = new SaveProject(path+".json",items());
        openFile(path);

    }


}


void MainWindow::on_action_settings_triggered()     //настройки
{
    setting->show();
}

void MainWindow::changeControll(bool is)
{
    qDebug()<<name;
    if(is) {
        setWindowTitle(name);
        saveChange = 0;
    } else {
        setWindowTitle(name+"*");
        saveChange = 1;
    }
}

void MainWindow::setItems(QList<Item *> list)
{
    for (int i = 0; i < list.count();i++){
        ui->listWidget->addItem(list[i]);
        ui->listWidget->setItemWidget(list[i],list[i]->widget());
    }
}

void MainWindow::deleteItems()
{
    while (ui->listWidget->count() != 0) {
        Item* item = dynamic_cast<Item*>(ui->listWidget->item(0));
        delete item;
    }



}

void MainWindow::closeEvent(QCloseEvent *event)
{
    if (saveChange == 1) {
        int answer = QMessageBox::warning(this,"Внимание!", "Все несохраненные данные будут удалены!","Выйти","Отмена");
        if(answer == 0) {
            event->accept();
        } else {
            event->ignore();
        }
    }
}

void MainWindow::openFile(QString path_)
{
    path = path_;
    deleteItems();


    openP = new OpenProject(path);
    //int lastPoint = path.lastIndexOf(".");
    //path = path.left(lastPoint);

    setItems(openP->items());
    QFileInfo file(path);
    name = file.fileName();
    int lastPoint = name.lastIndexOf(".");
    name = name.left(lastPoint);
    setWindowTitle(name);

    control->setString(openP->openedStr());
    saveChange = 0;
}

void MainWindow::createNewProject()
{
    deleteItems();
    name = "Новый проект";
    path = "";
    setWindowTitle(name);
    control->setString("");
    saveChange = 0;
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

