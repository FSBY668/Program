/********************************************************************************
** Form generated from reading UI file 'registrationmenu.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTRATIONMENU_H
#define UI_REGISTRATIONMENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RegistrationMenu
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_5;
    QVBoxLayout *verticalLayout;
    QLabel *label_Static_Username;
    QLineEdit *lineEdit_Username;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_Static_Password;
    QLineEdit *lineEdit_Password;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_Static_Repeat_Password;
    QLineEdit *lineEdit_Repeat_Password;
    QVBoxLayout *verticalLayout_4;
    QRadioButton *radioButton_Organisation;
    QRadioButton *radioButton_NormalUser;
    QPushButton *pushButton_Confirm;
    QPushButton *pushButton_Cancel;

    void setupUi(QDialog *RegistrationMenu)
    {
        if (RegistrationMenu->objectName().isEmpty())
            RegistrationMenu->setObjectName(QStringLiteral("RegistrationMenu"));
        RegistrationMenu->resize(317, 549);
        layoutWidget = new QWidget(RegistrationMenu);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(30, 50, 251, 451));
        verticalLayout_5 = new QVBoxLayout(layoutWidget);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label_Static_Username = new QLabel(layoutWidget);
        label_Static_Username->setObjectName(QStringLiteral("label_Static_Username"));

        verticalLayout->addWidget(label_Static_Username);

        lineEdit_Username = new QLineEdit(layoutWidget);
        lineEdit_Username->setObjectName(QStringLiteral("lineEdit_Username"));

        verticalLayout->addWidget(lineEdit_Username);


        verticalLayout_5->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label_Static_Password = new QLabel(layoutWidget);
        label_Static_Password->setObjectName(QStringLiteral("label_Static_Password"));

        verticalLayout_2->addWidget(label_Static_Password);

        lineEdit_Password = new QLineEdit(layoutWidget);
        lineEdit_Password->setObjectName(QStringLiteral("lineEdit_Password"));
        lineEdit_Password->setEchoMode(QLineEdit::Password);

        verticalLayout_2->addWidget(lineEdit_Password);


        verticalLayout_5->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        label_Static_Repeat_Password = new QLabel(layoutWidget);
        label_Static_Repeat_Password->setObjectName(QStringLiteral("label_Static_Repeat_Password"));

        verticalLayout_3->addWidget(label_Static_Repeat_Password);

        lineEdit_Repeat_Password = new QLineEdit(layoutWidget);
        lineEdit_Repeat_Password->setObjectName(QStringLiteral("lineEdit_Repeat_Password"));
        lineEdit_Repeat_Password->setEchoMode(QLineEdit::Password);

        verticalLayout_3->addWidget(lineEdit_Repeat_Password);


        verticalLayout_5->addLayout(verticalLayout_3);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        radioButton_Organisation = new QRadioButton(layoutWidget);
        radioButton_Organisation->setObjectName(QStringLiteral("radioButton_Organisation"));

        verticalLayout_4->addWidget(radioButton_Organisation);

        radioButton_NormalUser = new QRadioButton(layoutWidget);
        radioButton_NormalUser->setObjectName(QStringLiteral("radioButton_NormalUser"));

        verticalLayout_4->addWidget(radioButton_NormalUser);


        verticalLayout_5->addLayout(verticalLayout_4);

        pushButton_Confirm = new QPushButton(layoutWidget);
        pushButton_Confirm->setObjectName(QStringLiteral("pushButton_Confirm"));

        verticalLayout_5->addWidget(pushButton_Confirm);

        pushButton_Cancel = new QPushButton(layoutWidget);
        pushButton_Cancel->setObjectName(QStringLiteral("pushButton_Cancel"));

        verticalLayout_5->addWidget(pushButton_Cancel);


        retranslateUi(RegistrationMenu);

        QMetaObject::connectSlotsByName(RegistrationMenu);
    } // setupUi

    void retranslateUi(QDialog *RegistrationMenu)
    {
        RegistrationMenu->setWindowTitle(QApplication::translate("RegistrationMenu", "Dialog", Q_NULLPTR));
        label_Static_Username->setText(QApplication::translate("RegistrationMenu", "User Name (Email):", Q_NULLPTR));
        label_Static_Password->setText(QApplication::translate("RegistrationMenu", "Password:", Q_NULLPTR));
        label_Static_Repeat_Password->setText(QApplication::translate("RegistrationMenu", "Repeat Password:", Q_NULLPTR));
        radioButton_Organisation->setText(QApplication::translate("RegistrationMenu", "Organisation (Publisher)", Q_NULLPTR));
        radioButton_NormalUser->setText(QApplication::translate("RegistrationMenu", "Normal User (Subscriber)", Q_NULLPTR));
        pushButton_Confirm->setText(QApplication::translate("RegistrationMenu", "Confirm", Q_NULLPTR));
        pushButton_Cancel->setText(QApplication::translate("RegistrationMenu", "Cancel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class RegistrationMenu: public Ui_RegistrationMenu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTRATIONMENU_H
