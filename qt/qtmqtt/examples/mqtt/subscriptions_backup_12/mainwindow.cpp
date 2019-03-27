/****************************************************************************
**
** Copyright (C) 2017 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
**
** This file is part of the examples of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** BSD License Usage
** Alternatively, you may use this file under the terms of the BSD license
** as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of The Qt Company Ltd nor the names of its
**     contributors may be used to endorse or promote products derived
**     from this software without specific prior written permission.
**
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
** $QT_END_LICENSE$
**
****************************************************************************/

#include "version.h"
#include "defines.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"

//#include <QtCore/QDateTime>
#include <QtWidgets/QMessageBox>
#include <QFile>
//#include <QFileDialog>
#include <QTextStream>
#include <QUrl>

//extern const QString configPath;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    m_config = new Configuration(QString(strConfigFilePath));

    if (ui)
    {
        ui->setupUi(this);
        setWindowTitle("Public Info" + strVersion);

        ui->checkBox_Remember_Login->setChecked(true);
        if (ui->checkBox_Remember_Login->isChecked())
        {
            QFile fileUserCache(strUserLoginCacheFile);
            if (!fileUserCache.open(QFile::ReadOnly | QFile::Text))
            {
                QMessageBox::warning(this, "title", "file not open");
            }

            QTextStream in(&fileUserCache);

            QString line = in.readLine();
            QStringList lineList = line.split(' ', QString::SkipEmptyParts);

            if (lineList.size() > 1)
            {
                ui->lineEdit_User->setText(lineList[0]);
                ui->lineEdit_Password->setText(lineList[1]);
            }

            fileUserCache.close();
        }
        else
        {
            ui->lineEdit_User->clear();
            ui->lineEdit_Password->clear();
        }

        //    connect(m_client, &QMqttClient::stateChanged, this, &MainWindow::updateLogStateChange);
        //    connect(m_client, &QMqttClient::disconnected, this, &MainWindow::brokerDisconnected);

        //    connect(m_client, &QMqttClient::messageReceived, this, [this](const QByteArray &message, const QMqttTopicName &topic) {
        //        const QString content = QDateTime::currentDateTime().toString()
        //                    + QLatin1String(" Received Topic: ")
        //                    + topic.name()
        //                    + QLatin1String(" Message: ")
        //                    + message
        //                    + QLatin1Char('\n');
        //        ui->editLog->insertPlainText(content);
        //    });

        //    connect(m_client, &QMqttClient::pingResponseReceived, this, [this]() {
        //        ui->buttonPing->setEnabled(true);
        //        const QString content = QDateTime::currentDateTime().toString()
        //                    + QLatin1String(" PingResponse")
        //                    + QLatin1Char('\n');
        //        ui->editLog->insertPlainText(content);
        //    });

        //    connect(ui->lineEditHost, &QLineEdit::textChanged, m_client, &QMqttClient::setHostname);
        //    connect(ui->spinBoxPort, QOverload<int>::of(&QSpinBox::valueChanged), this, &MainWindow::setClientPort);
        //    connect(ui->lineEditUser, &QLineEdit::textChanged, m_client, &QMqttClient::setUsername);
        //    connect(ui->lineEditPassword, &QLineEdit::textChanged, m_client, &QMqttClient::setPassword);
        //    updateLogStateChange();
    }
}

MainWindow::~MainWindow()
{
    delete ui;
    delete selectionMenu;
    delete registrationMenu;
    delete m_config;
    qApp->quit();
}

//void MainWindow::on_buttonQuit_clicked()
//{
//    QApplication::quit();
//}

//void MainWindow::updateLogStateChange()
//{
//    const QString content = QDateTime::currentDateTime().toString()
//                    + QLatin1String(": State Change")
//                    + QString::number(m_client->state())
//                    + QLatin1Char('\n');
//    ui->editLog->insertPlainText(content);
//}

//void MainWindow::setClientPort(int p)
//{
//    m_client->setPort(p);
//}

//void MainWindow::on_buttonPing_clicked()
//{
//    ui->buttonPing->setEnabled(false);
//    m_client->requestPing();
//}

void MainWindow::on_pushButton_Login_clicked()
{
    if (!ui || !m_config)
    {
        return;
    }

    bool bLoginSuccessful = false;
    QString username = ui->lineEdit_User->text();
    QString password = ui->lineEdit_Password->text();

    QString userFileName = m_config->getConfigAttribute(EConfigAttribute::eUserFilePath);
    QUrl url(userFileName);
    QFile file(url.toLocalFile());

    //QString filter = "All File (*) ;; cpp File (*.cpp) ;; header file (*.h)";
    //QString file_name = QFileDialog::getOpenFileName(this, "open a file", "/home/wenwei/Program/Qt Tutorial/Build/QFileDemo", filter);
    //QFile file(file_name);
    //QFile file("/home/wenwei/Program/QFileDemo/myfile");

    if (!file.open(QFile::ReadOnly | QFile::Text))
    {
        QMessageBox::warning(this, "title", "file not open");
    }

    QTextStream in(&file);
    while (!in.atEnd())
    {
        QString line = in.readLine();
        QStringList lineList = line.split(' ', QString::SkipEmptyParts);

        if (lineList.size() > 2)
        {
            if (username == lineList[0])
            {
                if (password == lineList[1])
                {
                    //QMessageBox::information(this, "Login", "Username and password is correct");
                    //ui->statusBar->showMessage("Username and password is correct", 5000);
                    //ui->label_3->setText("Username and password is correct");

                    //hide();

                    selectionMenu = new SelectionMenu(lineList[2], this);
                    selectionMenu->setWindowTitle("Selection Menu");
                    selectionMenu->show();
                    bLoginSuccessful = true;

                    if (ui->checkBox_Remember_Login->isChecked())
                    {
                        QFile fileUserCache(strUserLoginCacheFile);
                        if (!fileUserCache.open(QFile::WriteOnly | QFile::Text))
                        {
                            QMessageBox::warning(this, "title", "file not open");
                        }

                        QTextStream out(&fileUserCache);
                        QString text = username;
                        text += " ";
                        text += password;

                        out << text;
                        fileUserCache.flush();
                        fileUserCache.close();
                    }
                    else
                    {
                        ui->lineEdit_User->clear();
                        ui->lineEdit_Password->clear();
                    }

                    break;
                }
            }
        }
    }

    if (!bLoginSuccessful)
    {
        QMessageBox::warning(this, "Login", "Username and password is not correct");
        //ui->statusBar->showMessage("Username and password is not correct", 5000);
        //ui->label_3->setText("Username and password is not correct");
    }

    file.close();
}

void MainWindow::on_pushButton_Registe_clicked()
{
    registrationMenu = new RegistrationMenu(this);
    registrationMenu->setWindowTitle("Registration Menu");
    registrationMenu->show();
}
