#include "registrationmenu.h"
#include "ui_registrationmenu.h"
#include <QFile>
//#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>
#include <QUrl>

RegistrationMenu::RegistrationMenu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RegistrationMenu)
{
    ui->setupUi(this);
}

RegistrationMenu::~RegistrationMenu()
{
    delete ui;
}

void RegistrationMenu::on_pushButton_Confirm_clicked()
{
    bool isUserNameEmpty = ui->lineEdit_Username->text().isEmpty();
    bool isPasswordEmpty = ui->lineEdit_Password->text().isEmpty();
    bool isRepeatPasswordEmpty = ui->lineEdit_Repeat_Password->text().isEmpty();
    bool isUserLevelSelected = ui->radioButton_NormalUser->isChecked() || ui->radioButton_Organisation->isChecked();
    if (isUserNameEmpty || isPasswordEmpty || isRepeatPasswordEmpty || !isUserLevelSelected)
    {
        QMessageBox::warning(this, "Registration Error", "check your input");
        return;
    }
    if (ui->lineEdit_Password->text() != ui->lineEdit_Repeat_Password->text())
    {
        QMessageBox::warning(this, "Registration Error", "check your input Passwords");
        return;
    }

    // file path can be moved to the config file
    QUrl url("file:///home/wenwei/Program/qt/qtmqtt/examples/mqtt/subscriptions/user");
    QFile file(url.toLocalFile());
    if (!file.open(QFile::WriteOnly | QFile::Text | QIODevice::Append))
    {
        QMessageBox::warning(this, "title", "file not open");
    }

    QTextStream out(&file);
    QString text = ui->lineEdit_Username->text();
    text += " ";
    text += ui->lineEdit_Password->text();
    text += " ";

    if (ui->radioButton_Organisation->isChecked())
    {
        text += "1000";
    }
    else if (ui->radioButton_NormalUser->isChecked())
    {
        text += "100";
    }
    text += "\n";

    out << text;
    file.flush();
    file.close();

    close();
}

void RegistrationMenu::on_pushButton_Cancel_clicked()
{
    close();
}
