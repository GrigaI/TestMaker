#ifndef ITEMWIDGET_H
#define ITEMWIDGET_H

#include <QWidget>
#include <QDebug>
#include <QPixmap>

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

private slots:


private:
    Ui::ItemWidget *ui;
signals:
    void editingStart();

};

#endif // ITEMWIDGET_H
