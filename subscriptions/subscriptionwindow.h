#ifndef SUBSCRIPTIONWINDOW_H
#define SUBSCRIPTIONWINDOW_H

#include <QDialog>

namespace Ui {
class SubscriptionWindow;
}

class SubscriptionWindow : public QDialog
{
    Q_OBJECT

public:
    explicit SubscriptionWindow(QWidget *parent = 0);
    ~SubscriptionWindow();

private:
    Ui::SubscriptionWindow *ui;
};

#endif // SUBSCRIPTIONWINDOW_H
