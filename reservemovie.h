#ifndef RESERVEMOVIE_H
#define RESERVEMOVIE_H
#include "databaseconnection.h"


#include <QMainWindow>

namespace Ui {
class ReserveMovie;
}

class ReserveMovie : public QMainWindow
{
    Q_OBJECT

public:
    explicit ReserveMovie(QWidget *parent = 0);
    ~ReserveMovie();

private slots:
    void on_tileComboBox_currentTextChanged(const QString &arg1);

    void on_theatreCcomboBox_currentTextChanged(const QString &arg1);

    void on_backButton_clicked();

    void on_dayComboBox_currentTextChanged(const QString &arg1);

    void on_reserveMovieButton_clicked();

private:
    Ui::ReserveMovie *ui;
    DatabaseConnection con;

};

#endif // RESERVEMOVIE_H
