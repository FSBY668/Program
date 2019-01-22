#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QListWidgetItem* item = new QListWidgetItem(QIcon(":/res/img/mosquitto-16x16.png"), "Mark");
    QListWidgetItem* item_2 = new QListWidgetItem(QIcon(":/res/img/mosquitto-16x16.png"), "John");
    QListWidgetItem* item_3 = new QListWidgetItem(QIcon(":/res/img/mosquitto-16x16.png"), "July");

    ui->listWidget->addItem(item);
    ui->listWidget->addItem(item_2);
    ui->listWidget->addItem(item_3);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
//    QMessageBox::information(this, "title", ui->listWidget->currentItem()->text());

    ui->listWidget->currentItem()->setBackgroundColor(Qt::red);
    ui->listWidget->currentItem()->setForeground(Qt::white);
}
