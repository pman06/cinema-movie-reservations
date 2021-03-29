#ifndef DELETESHOWINGTIME_H
#define DELETESHOWINGTIME_H
#include <databaseconnection.h>

#include <QMainWindow>

namespace Ui {
class DeleteShowingTime;
}

class DeleteShowingTime : public QMainWindow
{
    Q_OBJECT

public:
    explicit DeleteShowingTime(QWidget *parent = 0);
    ~DeleteShowingTime();

private slots:
    void on_dayComboBox_currentIndexChanged(const QString &arg1);

    void on_hallComboBox_currentIndexChanged(const QString &arg1);

    void on_timeComboBox_currentIndexChanged(const QString &arg1);

    void on_deleteButton_clicked();

    void on_backButton_clicked();

private:
    Ui::DeleteShowingTime *ui;
    DatabaseConnection con;
};

#endif // DELETESHOWINGTIME_H
