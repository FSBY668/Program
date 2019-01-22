#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QFile file("/home/wenwei/Program/Qt Tutorial/Build/QFileDemo/myfile");
    if (!file.open(QFile::WriteOnly | QFile::Text))
    {
        QMessageBox::warning(this, "title", "file not open");
    }

    QTextStream out(&file);
    QString text = ui->plainTextEdit->toPlainText();
    out << text;
    file.flush();
    file.close();
}

void MainWindow::on_pushButton_2_clicked()
{
    QString filter = "All File (*) ;; cpp File (*.cpp) ;; header file (*.h)";
    QString file_name = QFileDialog::getOpenFileName(this, "open a file", "/home/wenwei/Program/Qt Tutorial/Build/QFileDemo", filter);
    QFile file(file_name);
    //QFile file("/home/wenwei/Program/QFileDemo/myfile");
    if (!file.open(QFile::ReadOnly | QFile::Text))
    {
        QMessageBox::warning(this, "title", "file not open");
    }

    QTextStream in(&file);
    QString text = in.readAll();
    ui->plainTextEdit->setPlainText(text);
    file.close();
}
