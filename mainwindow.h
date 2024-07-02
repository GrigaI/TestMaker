#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStringListModel>
#include <QObject>
#include <QEvent>
#include <QListView>
#include <QMouseEvent>
#include <QListWidgetItem>
#include <QMessageBox>
#include <QFileDialog>
#include <QFileInfo>


#include "dialogs/editor.h"
#include "dialogs/settings.h"
#include "items/item.h"
#include "projectOperations/saveproject.h"
#include "projectOperations/openproject.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    bool eventFilter(QObject *watched, QEvent *event);

private slots:
    void on_pushButton_addCommand_clicked();

    void on_pushButton_delCommand_clicked();

    void on_pushButton_enter_clicked();

    void onEditedCommand(int i,QString str);

    void on_action_create_triggered();

    void on_action_open_triggered();

    void on_action_save_triggered();

    void on_action_saveAs_triggered();

    void on_action_settings_triggered();



private:
    Ui::MainWindow *ui;
    Settings *setting;

    QList<Item*> items();
    QString name;
    QString path;
    SaveProject *saveP;
    OpenProject *openP;
    void setItems(QList<Item*> list);
signals:

};
#endif // MAINWINDOW_H
