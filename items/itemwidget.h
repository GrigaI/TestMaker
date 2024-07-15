#ifndef ITEMWIDGET_H
#define ITEMWIDGET_H

#include <QWidget>
#include <QDebug>
#include <QPixmap>
#include "dialogs/informationdialog.h"

namespace Ui {
class ItemWidget;
}

class ItemWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ItemWidget(QWidget *parent = nullptr);
    ~ItemWidget();

    void setName(QString name);

    void setTypeName(QString type);

    void setColor(bool is);

    void clearLabel();

    void appendInfoText(QString html);

private slots:


    void on_toolButton_clicked();

private:
    Ui::ItemWidget *ui;
    InformationDialog *infoDialog;
signals:
    void editingStart();

};

#endif // ITEMWIDGET_H
