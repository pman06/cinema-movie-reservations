#ifndef NOWSHOWING_H
#define NOWSHOWING_H

#include "databaseconnection.h"
#include <QMainWindow>

namespace Ui {
class NowShowing;
}

class NowShowing : public QMainWindow
{
    Q_OBJECT

public:
    explicit NowShowing(QWidget *parent = 0);
    ~NowShowing();

private slots:


    void on_backButton_clicked();

    void on_hallsComboBox_currentIndexChanged(const QString &arg1);

private:
    Ui::NowShowing *ui;
    DatabaseConnection con;
};

#endif // NOWSHOWING_H
