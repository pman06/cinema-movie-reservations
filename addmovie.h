#ifndef ADDMOVIE_H
#define ADDMOVIE_H
#include "databaseconnection.h"

#include <QMainWindow>

#include <QMessageBox>

namespace Ui {
class AddMovie;
}

class AddMovie : public QMainWindow
{
    Q_OBJECT

public:
    explicit AddMovie(QWidget *parent = 0);
    ~AddMovie();

private slots:
    void on_saveMovieButton_clicked();

    void on_cancelMovieButton_clicked();

private:
    Ui::AddMovie *ui;
    DatabaseConnection con;

};

#endif // ADDMOVIE_H
