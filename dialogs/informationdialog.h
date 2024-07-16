#ifndef INFORMATIONDIALOG_H
#define INFORMATIONDIALOG_H

#include <QDialog>
#include <QDebug>
#include <QDateTime>

namespace Ui {
class InformationDialog;
}

class InformationDialog : public QDialog
{
    Q_OBJECT

public:
    explicit InformationDialog(QWidget *parent = nullptr);
    ~InformationDialog();

    void setText(QString str);
private:
    Ui::InformationDialog *ui;
    QString htmlStr;
};

#endif // INFORMATIONDIALOG_H
