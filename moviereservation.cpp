#include "moviereservation.h"
#include "ui_moviereservation.h"

#include <QStyle>
#include <QDesktopWidget>

MovieReservation::MovieReservation(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MovieReservation)
{
    ui->setupUi(this);
    this->setWindowTitle("Main Menu");
    this->setGeometry(
        QStyle::alignedRect(
            Qt::LeftToRight, Qt::AlignCenter, this->size(), qApp->desktop()->availableGeometry()
        )
   );
}

MovieReservation::~MovieReservation()
{
    delete ui;
}



void MovieReservation::on_addMovieButton_clicked()
{
    this->hide();
    addMovie = new AddMovie();
    addMovie->show();
}

void MovieReservation::on_viewMovieButton_clicked()
{
    this->hide();
    viewMovies = new ViewMovies;
    viewMovies->show();
}

void MovieReservation::on_registerTheatreButton_clicked()
{
    this->close();
    theater = new RegisterTheatre();
    theater->show();
}

void MovieReservation::on_movieTimeButton_clicked()
{
    this->hide();
    timeShowing = new TImeShowing();
    timeShowing->show();
}

void MovieReservation::on_reserveMovieButton_clicked()
{
    this->hide();
    reserveForm = new ReserveMovie();
    reserveForm->show();
}

void MovieReservation::on_pushButton_clicked()
{
    this->hide();
    movieForm =new EditMovie;
    movieForm->show();
}


void MovieReservation::on_nowShowingButton_clicked()
{
    this->hide();
    showingPage = new NowShowing;
    showingPage->show();
}

void MovieReservation::on_pushButton_2_clicked()
{
    this->hide();
    deleteShowing = new DeleteShowingTime;
    deleteShowing->show();
}

void MovieReservation::on_groupMembersButton_clicked()
{
    members = new GroupMemebers;
    members->show();
}
