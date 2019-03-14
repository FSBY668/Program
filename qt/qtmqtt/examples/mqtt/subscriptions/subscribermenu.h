#ifndef SUBSCRIBERMENU_H
#define SUBSCRIBERMENU_H

#include <QDialog>

namespace Ui {
class SubscriberMenu;
}

class SubscriberMenu : public QDialog
{
    Q_OBJECT

public:
    explicit SubscriberMenu(QWidget *parent = 0);
    ~SubscriberMenu();

private:
    Ui::SubscriberMenu *ui;
};

#endif // SUBSCRIBERMENU_H
