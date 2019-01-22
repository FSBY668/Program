#include "mysecdialog.h"
#include "ui_mysecdialog.h"

MySecDialog::MySecDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MySecDialog)
{
    ui->setupUi(this);
}

MySecDialog::~MySecDialog()
{
    delete ui;
}
