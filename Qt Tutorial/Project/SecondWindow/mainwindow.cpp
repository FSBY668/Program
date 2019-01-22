#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete secDialog;
}

void MainWindow::on_pushButton_clicked()
{
//    MySecDialog secDialog;
//    secDialog.setModal(true);
//    secDialog.exec();

    hide();

    secDialog = new MySecDialog(this);
    secDialog->show();
}
