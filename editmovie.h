#ifndef EDITMOVIE_H
#define EDITMOVIE_H
#include "databaseconnection.h"
#include <QMainWindow>



namespace Ui {
class EditMovie;
}

class EditMovie : public QMainWindow
{
    Q_OBJECT

public:
    explicit EditMovie(QWidget *parent = 0);
    ~EditMovie();

private slots:


    void on_searchButton_clicked();

    void on_cancelMovieButton_4_clicked();

    void on_searchTitleEdit_textEdited(const QString &arg1);

    void on_updateMovieButton_clicked();

private:
    Ui::EditMovie *ui;
    DatabaseConnection con;

};

#endif // EDITMOVIE_H
