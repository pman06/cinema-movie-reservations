#ifndef REGISTERTHEATRE_H
#define REGISTERTHEATRE_H
#include "databaseconnection.h"
#include <QMainWindow>

namespace Ui {
class RegisterTheatre;
}

class RegisterTheatre : public QMainWindow
{
    Q_OBJECT

public:
    explicit RegisterTheatre(QWidget *parent = 0);
    ~RegisterTheatre();

private slots:
    void on_saveTheatreButton_clicked();

    void on_backTHeatreButton_clicked();

private:
    Ui::RegisterTheatre *ui;
    DatabaseConnection con;
};

#endif // REGISTERTHEATRE_H
