/********************************************************************************
** Form generated from reading UI file 'selectionmenu.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SELECTIONMENU_H
#define UI_SELECTIONMENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SelectionMenu
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton_Publisher;
    QPushButton *pushButton_Subscriber;
    QPushButton *pushButton;

    void setupUi(QDialog *SelectionMenu)
    {
        if (SelectionMenu->objectName().isEmpty())
            SelectionMenu->setObjectName(QStringLiteral("SelectionMenu"));
        SelectionMenu->resize(317, 549);
        layoutWidget = new QWidget(SelectionMenu);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(50, 110, 221, 321));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton_Publisher = new QPushButton(layoutWidget);
        pushButton_Publisher->setObjectName(QStringLiteral("pushButton_Publisher"));

        verticalLayout->addWidget(pushButton_Publisher);

        pushButton_Subscriber = new QPushButton(layoutWidget);
        pushButton_Subscriber->setObjectName(QStringLiteral("pushButton_Subscriber"));

        verticalLayout->addWidget(pushButton_Subscriber);

        pushButton = new QPushButton(layoutWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        verticalLayout->addWidget(pushButton);


        retranslateUi(SelectionMenu);

        QMetaObject::connectSlotsByName(SelectionMenu);
    } // setupUi

    void retranslateUi(QDialog *SelectionMenu)
    {
        SelectionMenu->setWindowTitle(QApplication::translate("SelectionMenu", "Dialog", Q_NULLPTR));
        pushButton_Publisher->setText(QApplication::translate("SelectionMenu", "Publisher", Q_NULLPTR));
        pushButton_Subscriber->setText(QApplication::translate("SelectionMenu", "Subscriber", Q_NULLPTR));
        pushButton->setText(QApplication::translate("SelectionMenu", "Log out", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class SelectionMenu: public Ui_SelectionMenu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SELECTIONMENU_H
