#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "temperature_conversion.h"

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
    class mqtt_tempconv *tempconv;
    int rc;

    mosqpp::lib_init();

    tempconv = new mqtt_tempconv("tempconv", "localhost", 1883);

    while (1)
    {
        rc = tempconv->loop();
        if (rc)
        {
            tempconv->reconnect();
        }
    }

    mosqpp::lib_cleanup();
}
