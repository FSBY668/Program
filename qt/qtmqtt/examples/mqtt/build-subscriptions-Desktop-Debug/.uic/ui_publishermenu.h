/********************************************************************************
** Form generated from reading UI file 'publishermenu.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PUBLISHERMENU_H
#define UI_PUBLISHERMENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PublisherMenu
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_Pub_Connect;
    QLabel *label_Static_Pub_Message;
    QLabel *label_Static_Pub_Topic;
    QLineEdit *lineEdit_Pub_Topic;
    QPlainTextEdit *plainTextEdit_Pub_Message;
    QPushButton *pushButton_Pub_Publish;
    QPushButton *pushButton;

    void setupUi(QDialog *PublisherMenu)
    {
        if (PublisherMenu->objectName().isEmpty())
            PublisherMenu->setObjectName(QStringLiteral("PublisherMenu"));
        PublisherMenu->resize(317, 549);
        layoutWidget = new QWidget(PublisherMenu);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 44, 274, 471));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        pushButton_Pub_Connect = new QPushButton(layoutWidget);
        pushButton_Pub_Connect->setObjectName(QStringLiteral("pushButton_Pub_Connect"));

        horizontalLayout->addWidget(pushButton_Pub_Connect);


        verticalLayout->addLayout(horizontalLayout);

        label_Static_Pub_Message = new QLabel(layoutWidget);
        label_Static_Pub_Message->setObjectName(QStringLiteral("label_Static_Pub_Message"));

        verticalLayout->addWidget(label_Static_Pub_Message);

        label_Static_Pub_Topic = new QLabel(layoutWidget);
        label_Static_Pub_Topic->setObjectName(QStringLiteral("label_Static_Pub_Topic"));

        verticalLayout->addWidget(label_Static_Pub_Topic);

        lineEdit_Pub_Topic = new QLineEdit(layoutWidget);
        lineEdit_Pub_Topic->setObjectName(QStringLiteral("lineEdit_Pub_Topic"));

        verticalLayout->addWidget(lineEdit_Pub_Topic);

        plainTextEdit_Pub_Message = new QPlainTextEdit(layoutWidget);
        plainTextEdit_Pub_Message->setObjectName(QStringLiteral("plainTextEdit_Pub_Message"));

        verticalLayout->addWidget(plainTextEdit_Pub_Message);

        pushButton_Pub_Publish = new QPushButton(layoutWidget);
        pushButton_Pub_Publish->setObjectName(QStringLiteral("pushButton_Pub_Publish"));

        verticalLayout->addWidget(pushButton_Pub_Publish);

        pushButton = new QPushButton(layoutWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        verticalLayout->addWidget(pushButton);


        retranslateUi(PublisherMenu);

        QMetaObject::connectSlotsByName(PublisherMenu);
    } // setupUi

    void retranslateUi(QDialog *PublisherMenu)
    {
        PublisherMenu->setWindowTitle(QApplication::translate("PublisherMenu", "Dialog", Q_NULLPTR));
        pushButton_Pub_Connect->setText(QApplication::translate("PublisherMenu", "Connect to Mqtt Broker", Q_NULLPTR));
        label_Static_Pub_Message->setText(QApplication::translate("PublisherMenu", "Message", Q_NULLPTR));
        label_Static_Pub_Topic->setText(QApplication::translate("PublisherMenu", "Topic:", Q_NULLPTR));
        pushButton_Pub_Publish->setText(QApplication::translate("PublisherMenu", "Publish", Q_NULLPTR));
        pushButton->setText(QApplication::translate("PublisherMenu", "Log out", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class PublisherMenu: public Ui_PublisherMenu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PUBLISHERMENU_H
