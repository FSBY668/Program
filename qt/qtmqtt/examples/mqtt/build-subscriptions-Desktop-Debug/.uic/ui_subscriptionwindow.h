/********************************************************************************
** Form generated from reading UI file 'subscriptionwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SUBSCRIPTIONWINDOW_H
#define UI_SUBSCRIPTIONWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SubscriptionWindow
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLabel *labelSub;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLabel *labelStatus;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLabel *labelQoS;
    QPlainTextEdit *plainTextEdit;
    QPushButton *pushButton;

    void setupUi(QWidget *SubscriptionWindow)
    {
        if (SubscriptionWindow->objectName().isEmpty())
            SubscriptionWindow->setObjectName(QStringLiteral("SubscriptionWindow"));
        SubscriptionWindow->resize(317, 549);
        layoutWidget = new QWidget(SubscriptionWindow);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(9, 10, 301, 531));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        labelSub = new QLabel(layoutWidget);
        labelSub->setObjectName(QStringLiteral("labelSub"));

        horizontalLayout->addWidget(labelSub);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_2->addWidget(label_2);

        labelStatus = new QLabel(layoutWidget);
        labelStatus->setObjectName(QStringLiteral("labelStatus"));

        horizontalLayout_2->addWidget(labelStatus);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_3->addWidget(label_3);

        labelQoS = new QLabel(layoutWidget);
        labelQoS->setObjectName(QStringLiteral("labelQoS"));

        horizontalLayout_3->addWidget(labelQoS);


        verticalLayout->addLayout(horizontalLayout_3);

        plainTextEdit = new QPlainTextEdit(layoutWidget);
        plainTextEdit->setObjectName(QStringLiteral("plainTextEdit"));

        verticalLayout->addWidget(plainTextEdit);

        pushButton = new QPushButton(layoutWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        verticalLayout->addWidget(pushButton);


        retranslateUi(SubscriptionWindow);

        QMetaObject::connectSlotsByName(SubscriptionWindow);
    } // setupUi

    void retranslateUi(QWidget *SubscriptionWindow)
    {
        SubscriptionWindow->setWindowTitle(QApplication::translate("SubscriptionWindow", "Form", Q_NULLPTR));
        label->setText(QApplication::translate("SubscriptionWindow", "Subscription:", Q_NULLPTR));
        labelSub->setText(QApplication::translate("SubscriptionWindow", "TextLabel", Q_NULLPTR));
        label_2->setText(QApplication::translate("SubscriptionWindow", "Status:", Q_NULLPTR));
        labelStatus->setText(QApplication::translate("SubscriptionWindow", "TextLabel", Q_NULLPTR));
        label_3->setText(QApplication::translate("SubscriptionWindow", "QoS:", Q_NULLPTR));
        labelQoS->setText(QApplication::translate("SubscriptionWindow", "TextLabel", Q_NULLPTR));
        pushButton->setText(QApplication::translate("SubscriptionWindow", "Unsubscribe", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class SubscriptionWindow: public Ui_SubscriptionWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SUBSCRIPTIONWINDOW_H
