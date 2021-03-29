#ifndef MOVIERESERVATION_H
#define MOVIERESERVATION_H
#include "addmovie.h"
#include "viewmovies.h"
#include "registertheatre.h"
#include "reservemovie.h"
#include "timeshowing.h"
#include "editmovie.h"
#include "nowshowing.h"
#include "deleteshowingtime.h"
#include "groupmemebers.h"

#include <QMainWindow>

namespace Ui {
class MovieReservation;
}

class MovieReservation : public QMainWindow
{
    Q_OBJECT

public:
    explicit MovieReservation(QWidget *parent = 0);
    ~MovieReservation();

private slots:


    void on_addMovieButton_clicked();

    void on_viewMovieButton_clicked();

    void on_registerTheatreButton_clicked();

    void on_movieTimeButton_clicked();

    void on_reserveMovieButton_clicked();

    void on_pushButton_clicked();

    void on_nowShowingButton_clicked();

    void on_pushButton_2_clicked();

    void on_groupMembersButton_clicked();

private:
    Ui::MovieReservation *ui;
    AddMovie *addMovie;
    ViewMovies *viewMovies;
    RegisterTheatre *theater;
    TImeShowing *timeShowing;
    ReserveMovie *reserveForm;
    EditMovie *movieForm;
    NowShowing *showingPage;
    DeleteShowingTime *deleteShowing;
    GroupMemebers *members;
};

#endif // MOVIERESERVATION_H
