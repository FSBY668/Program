#ifndef PUBLISHERMENU_H
#define PUBLISHERMENU_H

#include <QDialog>

namespace Ui {
class PublisherMenu;
}

class PublisherMenu : public QDialog
{
    Q_OBJECT

public:
    explicit PublisherMenu(QWidget *parent = 0);
    ~PublisherMenu();

private:
    Ui::PublisherMenu *ui;
};

#endif // PUBLISHERMENU_H
