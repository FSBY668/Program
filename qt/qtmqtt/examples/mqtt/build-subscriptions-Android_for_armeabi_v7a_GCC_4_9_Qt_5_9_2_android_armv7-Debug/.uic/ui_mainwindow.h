/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionQuit;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_4;
    QGroupBox *groupBox_login;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label_Username;
    QLineEdit *lineEdit_User;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_Password;
    QLineEdit *lineEdit_Password;
    QCheckBox *checkBox_Remember_Login;
    QPushButton *pushButton_Login;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QPushButton *pushButton_Registe;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(317, 549);
        actionQuit = new QAction(MainWindow);
        actionQuit->setObjectName(QStringLiteral("actionQuit"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout_4 = new QVBoxLayout(centralWidget);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        groupBox_login = new QGroupBox(centralWidget);
        groupBox_login->setObjectName(QStringLiteral("groupBox_login"));
        verticalLayout = new QVBoxLayout(groupBox_login);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_Username = new QLabel(groupBox_login);
        label_Username->setObjectName(QStringLiteral("label_Username"));

        horizontalLayout->addWidget(label_Username);

        lineEdit_User = new QLineEdit(groupBox_login);
        lineEdit_User->setObjectName(QStringLiteral("lineEdit_User"));
        lineEdit_User->setEchoMode(QLineEdit::Normal);

        horizontalLayout->addWidget(lineEdit_User);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_Password = new QLabel(groupBox_login);
        label_Password->setObjectName(QStringLiteral("label_Password"));

        horizontalLayout_2->addWidget(label_Password);

        lineEdit_Password = new QLineEdit(groupBox_login);
        lineEdit_Password->setObjectName(QStringLiteral("lineEdit_Password"));
        lineEdit_Password->setEchoMode(QLineEdit::Password);

        horizontalLayout_2->addWidget(lineEdit_Password);


        verticalLayout->addLayout(horizontalLayout_2);

        checkBox_Remember_Login = new QCheckBox(groupBox_login);
        checkBox_Remember_Login->setObjectName(QStringLiteral("checkBox_Remember_Login"));

        verticalLayout->addWidget(checkBox_Remember_Login);

        pushButton_Login = new QPushButton(groupBox_login);
        pushButton_Login->setObjectName(QStringLiteral("pushButton_Login"));

        verticalLayout->addWidget(pushButton_Login);

        pushButton_Login->raise();
        checkBox_Remember_Login->raise();

        verticalLayout_4->addWidget(groupBox_login);

        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        verticalLayout_2 = new QVBoxLayout(groupBox);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout_2->addWidget(label);

        pushButton_Registe = new QPushButton(groupBox);
        pushButton_Registe->setObjectName(QStringLiteral("pushButton_Registe"));

        verticalLayout_2->addWidget(pushButton_Registe);


        verticalLayout_4->addWidget(groupBox);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 317, 22));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuFile->addAction(actionQuit);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        actionQuit->setText(QApplication::translate("MainWindow", "Quit", Q_NULLPTR));
        groupBox_login->setTitle(QApplication::translate("MainWindow", "Login", Q_NULLPTR));
        label_Username->setText(QApplication::translate("MainWindow", "Username:", Q_NULLPTR));
        label_Password->setText(QApplication::translate("MainWindow", "Password:", Q_NULLPTR));
        checkBox_Remember_Login->setText(QApplication::translate("MainWindow", "remember my login until an other \n"
" user login", Q_NULLPTR));
        pushButton_Login->setText(QApplication::translate("MainWindow", "Login", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("MainWindow", "Registration", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "Do not have an account? \n"
" You can have a registration here", Q_NULLPTR));
        pushButton_Registe->setText(QApplication::translate("MainWindow", "Registration", Q_NULLPTR));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
