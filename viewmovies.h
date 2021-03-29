#ifndef VIEWMOVIES_H
#define VIEWMOVIES_H
#include "databaseconnection.h"

#include <QMainWindow>

namespace Ui {
class ViewMovies;
}

class ViewMovies : public QMainWindow
{
    Q_OBJECT

public:
    explicit ViewMovies(QWidget *parent = 0);
    ~ViewMovies();

private slots:
    void on_cancelLoadButton_clicked();

    void on_loadMoviesButton_clicked();

private:
    Ui::ViewMovies *ui;
    DatabaseConnection con;
};

#endif // VIEWMOVIES_H
