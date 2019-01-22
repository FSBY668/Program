#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
//    ui->comboBox->addItem("Mark");
//    ui->comboBox->addItem("John");
//    ui->comboBox->addItem("July");

//    ui->comboBox->addItem(QIcon(":/rec/img/mosquitto-16x16.png"), "Mark");
//    ui->comboBox->addItem(QIcon(":/rec/img/mosquitto-16x16.png"), "John");
//    ui->comboBox->addItem(QIcon(":/rec/img/mosquitto-16x16.png"), "July");

    for (int i = 0; i < 10; i++)
    {
        ui->comboBox->addItem(QIcon(":/rec/img/mosquitto-16x16.png"), QString::number(i) + "name");
    }

    ui->comboBox->insertItem(3, QIcon(":/rec/img/mosquitto-16x16.png"), "new Text");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QMessageBox::information(this, "title", ui->comboBox->currentText());
}
