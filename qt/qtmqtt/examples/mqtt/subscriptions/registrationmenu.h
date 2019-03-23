#ifndef REGISTRATIONMENU_H
#define REGISTRATIONMENU_H

#include <QDialog>
#include "configuration.h"

namespace Ui {
class RegistrationMenu;
}

class RegistrationMenu : public QDialog
{
    Q_OBJECT

public:
    explicit RegistrationMenu(QWidget *parent = 0);
    ~RegistrationMenu();

private slots:
    void on_pushButton_Confirm_clicked();

    void on_pushButton_Cancel_clicked();

private:
    Ui::RegistrationMenu* ui;
    Configuration* m_config;
};

#endif // REGISTRATIONMENU_H
