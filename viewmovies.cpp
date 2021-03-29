#include "viewmovies.h"
#include "ui_viewmovies.h"
#include "moviereservation.h"

#include <QSqlQuery>
#include <QSqlQueryModel>

ViewMovies::ViewMovies(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ViewMovies)
{
    ui->setupUi(this);
    this->setWindowTitle("View Added Movies");
}

ViewMovies::~ViewMovies()
{
    delete ui;
}

void ViewMovies::on_cancelLoadButton_clicked()
{
    this->hide();
    MovieReservation *movie = new MovieReservation();
    movie->show();
}

void ViewMovies::on_loadMoviesButton_clicked()
{
    if(!con.connOpen())
    {
        qDebug()<<"Failed to open the database";
        return;
    }
    else
    {
        con.connOpen();
    }

    QSqlQueryModel *model = new QSqlQueryModel();
    QSqlQuery qry;
    qry.prepare("SELECT * FROM Movies");

    ui->moviesTableView->setStyleSheet("");
    if(qry.exec())
    {
        model->setQuery(qry);
        ui->moviesTableView->setModel(model);
        con.connClose();
    }
    else
    {
        QMessageBox::critical(this,tr("Error"),qry.lastError().text());
    }
}
