#ifndef ITEMWIDGET_H
#define ITEMWIDGET_H

#include <QWidget>

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

private slots:
    void on_toolButton_clicked();

private:
    Ui::ItemWidget *ui;
signals:
    void editingStart();

};

#endif // ITEMWIDGET_H
