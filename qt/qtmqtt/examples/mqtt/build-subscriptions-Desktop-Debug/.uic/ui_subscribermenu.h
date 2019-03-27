/********************************************************************************
** Form generated from reading UI file 'subscribermenu.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SUBSCRIBERMENU_H
#define UI_SUBSCRIBERMENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SubscriberMenu
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_Sub_Connect;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_Static_Sub_Topic;
    QLineEdit *lineEdit_Sub_Topic;
    QPushButton *pushButton_Subscribe;
    QPushButton *pushButton;

    void setupUi(QDialog *SubscriberMenu)
    {
        if (SubscriberMenu->objectName().isEmpty())
            SubscriberMenu->setObjectName(QStringLiteral("SubscriberMenu"));
        SubscriberMenu->resize(317, 549);
        layoutWidget = new QWidget(SubscriberMenu);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 102, 280, 301));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        pushButton_Sub_Connect = new QPushButton(layoutWidget);
        pushButton_Sub_Connect->setObjectName(QStringLiteral("pushButton_Sub_Connect"));

        horizontalLayout->addWidget(pushButton_Sub_Connect);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_Static_Sub_Topic = new QLabel(layoutWidget);
        label_Static_Sub_Topic->setObjectName(QStringLiteral("label_Static_Sub_Topic"));

        horizontalLayout_2->addWidget(label_Static_Sub_Topic);

        lineEdit_Sub_Topic = new QLineEdit(layoutWidget);
        lineEdit_Sub_Topic->setObjectName(QStringLiteral("lineEdit_Sub_Topic"));

        horizontalLayout_2->addWidget(lineEdit_Sub_Topic);


        verticalLayout->addLayout(horizontalLayout_2);

        pushButton_Subscribe = new QPushButton(layoutWidget);
        pushButton_Subscribe->setObjectName(QStringLiteral("pushButton_Subscribe"));

        verticalLayout->addWidget(pushButton_Subscribe);

        pushButton = new QPushButton(layoutWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        verticalLayout->addWidget(pushButton);


        retranslateUi(SubscriberMenu);

        QMetaObject::connectSlotsByName(SubscriberMenu);
    } // setupUi

    void retranslateUi(QDialog *SubscriberMenu)
    {
        SubscriberMenu->setWindowTitle(QApplication::translate("SubscriberMenu", "Dialog", Q_NULLPTR));
        pushButton_Sub_Connect->setText(QApplication::translate("SubscriberMenu", "Connect to Mqtt Broker", Q_NULLPTR));
        label_Static_Sub_Topic->setText(QApplication::translate("SubscriberMenu", "Subscription Topic:", Q_NULLPTR));
        pushButton_Subscribe->setText(QApplication::translate("SubscriberMenu", "Subscribe", Q_NULLPTR));
        pushButton->setText(QApplication::translate("SubscriberMenu", "Log out", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class SubscriberMenu: public Ui_SubscriberMenu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SUBSCRIBERMENU_H
