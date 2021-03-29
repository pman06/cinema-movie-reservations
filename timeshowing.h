#ifndef TIMESHOWING_H
#define TIMESHOWING_H
#include "databaseconnection.h"

#include <QMainWindow>

namespace Ui {
class TImeShowing;
}

class TImeShowing : public QMainWindow
{
    Q_OBJECT

public:
    explicit TImeShowing(QWidget *parent = 0);
    ~TImeShowing();

private slots:
    void on_registerButton_clicked();

    void on_cancelButton_clicked();

private:
    Ui::TImeShowing *ui;
    DatabaseConnection con;
};

#endif // TIMESHOWING_H
