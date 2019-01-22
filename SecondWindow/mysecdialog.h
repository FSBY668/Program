#ifndef MYSECDIALOG_H
#define MYSECDIALOG_H

#include <QDialog>

namespace Ui {
class MySecDialog;
}

class MySecDialog : public QDialog
{
    Q_OBJECT

public:
    explicit MySecDialog(QWidget *parent = 0);
    ~MySecDialog();

private:
    Ui::MySecDialog *ui;
};

#endif // MYSECDIALOG_H
