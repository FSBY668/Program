#ifndef SELECTIONMENU_H
#define SELECTIONMENU_H

#include "publishermenu.h"
#include "subscribermenu.h"

#include <QDialog>

namespace Ui {
class SelectionMenu;
}

class SelectionMenu : public QDialog
{
    Q_OBJECT

public:
    explicit SelectionMenu(QString userLevel, QWidget *parent = 0);
    ~SelectionMenu();

private slots:
    void on_pushButton_Publisher_clicked();

    void on_pushButton_Subscriber_clicked();

    void on_pushButton_clicked();

private:
    Ui::SelectionMenu *ui;
    PublisherMenu* publisherMenu;
    SubscriberMenu* subscriberMenu;
    QString m_userLevel;
};

#endif // SELECTIONMENU_H
