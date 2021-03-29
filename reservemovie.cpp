#include "reservemovie.h"
#include "ui_reservemovie.h"
#include "moviereservation.h"
#include "ticket.h"

#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QMessageBox>

#include <iostream>

//QString title = ui->tileComboBox->currentText();
ReserveMovie::ReserveMovie(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ReserveMovie)
{
    ui->setupUi(this);
    this->setWindowTitle("Book Seat and Ticket");
    if(!con.connOpen())
    {
        qDebug()<<"Failed to open the database";
        return;
    }
    else
    {
        con.connOpen();
        qDebug()<<("Connected");
    }

    QSqlQueryModel *model = new QSqlQueryModel;
    QSqlQuery qry;
    qry.prepare("SELECT MovieTitle from Movies where exists(select 1 from movietime where movietitle = movies.movietitle)");
    if(qry.exec())
    {
        model->setQuery(qry);
        ui->tileComboBox->setModel(model);
        con.connClose();
    }
    else
    {
        QMessageBox::critical(this,tr("Error!"),qry.lastError().text());
    }
    ui->statusLabel->hide();
}

ReserveMovie::~ReserveMovie()
{
    delete ui;
}

void ReserveMovie::on_tileComboBox_currentTextChanged(const QString &title)
{
    if(!con.connOpen())
    {
        qDebug()<<"Failed to open the database";
        return;
    }
    else
    {
        con.connOpen();
        qDebug()<<("Connected");
    }

    QSqlQueryModel *model = new QSqlQueryModel;
    QSqlQuery qry;
    qry.prepare("SELECT TheatreName from Theatre where exists(select theatre from movietime where Theatre = theatre.theatrename)");
    if(qry.exec())
    {
        qry.prepare("Select DISTINCT theatre from movietime where movieTItle='"+title+"'");
        if(qry.exec())
        {
            model->setQuery(qry);
            ui->theatreCcomboBox->setModel(model);
            con.connClose();
        }
        else
        {
            QMessageBox::critical(this,tr("Error!"),tr("E No Work o"));
        }
    }
    else
    {
        QMessageBox::critical(this,tr("Error!"),qry.lastError().text());
    }
}

void ReserveMovie::on_theatreCcomboBox_currentTextChanged(const QString &theatre)
{
    QString title = ui->tileComboBox->currentText();
    if(!con.connOpen())
    {
        qDebug()<<"Failed to open the database";
        return;
    }
    else
    {
        con.connOpen();
        qDebug()<<("Connected");
    }

    QSqlQueryModel *model = new QSqlQueryModel;
    QSqlQuery qry;
    qry.prepare("Select DISTINCT Day from movietime where movieTItle='"+title+"' and theatre='"+theatre+"'");
    if(qry.exec())
    {
        model->setQuery(qry);
        ui->dayComboBox->setModel(model);
        con.connClose();
    }
    else
    {
        QMessageBox::critical(this,tr("Error!"),qry.lastError().text());
    }
}



void ReserveMovie::on_backButton_clicked()
{
    this->close();
    MovieReservation *movieForm = new MovieReservation();
    movieForm->show();
}

void ReserveMovie::on_dayComboBox_currentTextChanged(const QString &day)
{
    QString title = ui->tileComboBox->currentText();
    QString theatre = ui->theatreCcomboBox->currentText();
    if(!con.connOpen())
    {
        qDebug()<<"Failed to open the database";
        return;
    }
    else
    {
        con.connOpen();
        qDebug()<<("Connected");
    }

    QSqlQueryModel *model = new QSqlQueryModel;
    QSqlQuery qry;
    qry.prepare("Select time from movietime where movieTItle='"+title+"' and theatre='"+theatre+"' and day='"+day+"'");
    if(qry.exec())
    {
        model->setQuery(qry);
        ui->timeComboBox->setModel(model);
        con.connClose();
    }
    else
    {
        QMessageBox::critical(this,tr("Error!"),qry.lastError().text());
    }
}

void ReserveMovie::on_reserveMovieButton_clicked()
{
    if(!con.connOpen())
    {
        qDebug()<<"Failed to open the database";
        return;
    }
    else
    {
        con.connOpen();
        qDebug()<<("Connected");
    }
    ui->statusLabel->hide();
    QString actor;
    QString actress;
    QString price;
    QString title = ui->tileComboBox->currentText();
    QString theatre = ui->theatreCcomboBox->currentText();
    QString day = ui->dayComboBox->currentText();
    QString time = ui->timeComboBox->currentText();
    QString status;
    if(ui->singleRadioButton->isChecked())
    {
        status= "single";
    }
    if(ui->coupleRadioButton->isChecked())
    {
        status= "couple";
    }

    int currentBookedSeats;

    if((!title.isEmpty()) && (!theatre.isEmpty()) && (!day.isEmpty()) && (!time.isEmpty()) && (!status.isEmpty()))
    {
        QSqlQuery qry;

        qry.prepare("Select * from MovieTIme where Movietitle='"+title+"' AND Theatre='"+theatre+"' AND Day='"+day+"' AND Time='"+time+"'");
        if(qry.exec())
        {
            while(qry.next())
            {
                currentBookedSeats = qry.value(4).toInt();
            }
            if(currentBookedSeats > 1)
            {
                qry.prepare("Insert into BookMovies(movietitle,theatre,day,time,ticket) values('"+title+"','"+theatre+"','"+day+"','"+time+"','"+status+"')");
                if(qry.exec())
                {
                    QMessageBox::information(this,tr("Error!"),tr("Seat Booked Successfully!"));
                    if(status=="single")
                    {
                        qry.prepare("UPDATE Movietime set Availableseats=availableseats-1 where Movietitle='"+title+"' AND Theatre='"+theatre+"' AND Day='"+day+"' AND Time='"+time+"'");
                        price = "1,000(Single)";
                    }
                    else
                    {
                        qry.prepare("UPDATE Movietime set Availableseats=availableseats-2 where Movietitle='"+title+"' AND Theatre='"+theatre+"' AND Day='"+day+"' AND Time='"+time+"'");
                        price = "1500(Couple)";
                    }
                    if(qry.exec())
                    {
                        if(qry.exec("Select * from movies where movietitle='"+title+"'"))
                        {
                            if(qry.next())
                            {
                                actor = qry.value(5).toString();
                                actress =  qry.value(6).toString();
                                Ticket *ticketForm = new Ticket(title, actor, actress, theatre, time, day, price);
                                ticketForm->setModal(true);
                                ticketForm->exec();
                                con.connClose();
                            }
                            else
                                QMessageBox::critical(this,"ERROR",qry.lastError().text());
                        }
                        else
                        {
                            QMessageBox::critical(this,"ERROR",qry.lastError().text());
                        }
                    }
                }
                else
                {
                    QMessageBox::critical(this,tr("Error!"),qry.lastError().text());
                }
            }
            else
            {
                QMessageBox::information(this,"Error","No More Seats Available at the Theatre");
            }
        }
        else
        {
            QMessageBox::information(this,"Error","Didnt");
        }
    }
    else
    {
        ui->statusLabel->show();
    }
}
