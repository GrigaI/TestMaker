#ifndef EDITOR_H
#define EDITOR_H

#include <QDialog>
#include <QDebug>
#include "items/item.h"
#include "commands/command.h"
#include "commands/loginrequest.h"
//#include "projectOperations/changecontrol.h"
//#include "items/itemwidget.h"

enum WINDOW {
    ADDCOMMAND,
    EDITCOMMAND
};

namespace Ui {
class Editor;
}

class Editor : public QDialog
{
    Q_OBJECT

public:
    explicit Editor(Item *item, WINDOW window,QWidget *parent = nullptr);
    ~Editor();
    void showEditor(WINDOW);

    void setCurIndex(int index);

    int curBtnClicked();
private slots:
    void on_pushButton_enter_clicked();

    void on_pushButton_cancel_clicked();

    void cmbBoxCurrentIndexChanged(int index);

private:
    Ui::Editor *ui;
    Item *item;
    Command com;
    QString name;
    int type;
    QString description;

    int curButton = 0;

    WINDOW window;


    void openAdd();

    void openEditor();

    void setFields();
signals:
    void edited();
};

#endif // EDITOR_H
