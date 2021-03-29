#include "timeshowing.h"
#include "ui_timeshowing.h"
#include "moviereservation.h"
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <iostream>

int seatNumber;

TImeShowing::TImeShowing(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TImeShowing)
{

    ui->setupUi(this);
    this->setWindowTitle("Add Time Showing");

    if(!con.connOpen())
    {
        qDebug()<<"Failed to open the database";
        return;
    }
    else
    {
        con.connOpen();
    }

    QSqlQueryModel *model = new QSqlQueryModel;
    QSqlQueryModel *model2 = new QSqlQueryModel;

    QSqlQuery qry;

    qry.prepare("Select MovieTitle from Movies");
    if(qry.exec())
    {
        model->setQuery(qry);
        ui->titleComboBox->setModel(model);
    }
    else
    {
        QMessageBox::critical(this,tr("Error"),qry.lastError().text());
    }


    qry.prepare("Select TheatreName from Theatre");
    if(qry.exec())
    {
        model2->setQuery(qry);
        ui->theatreComboBox->setModel(model2);
        con.connClose();
    }
    else
    {
        QMessageBox::critical(this,tr("Error"),qry.lastError().text());
    }
}

TImeShowing::~TImeShowing()
{
    delete ui;
}

void TImeShowing::on_registerButton_clicked()
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

    QString title = ui->titleComboBox->currentText();
    QString theatre = ui->theatreComboBox->currentText();
    QString day = ui->dayComboBox->currentText();
    QString time = ui->timeComboBox->currentText();
    QString seatNumber;

    QSqlQuery qry;
    qry.prepare("Select * From Theatre where TheatreName='"+theatre+"'");
    if(qry.exec())
    {
        while(qry.next())
        {
            seatNumber = qry.value(2).toString();
        }
    }
    else
    {
        QMessageBox::critical(this,tr("Errorrrrrr"),tr("Didnt o"));
    }


    qry.prepare("SELECT * FROM MOVIETIME WHERE Theatre='"+theatre+"' AND Day='"+day+"' AND Time='"+time+"'");
    if(qry.exec())
    {
        int count = 0;
        while(qry.next())
        {
            count++;
        }

        if(count > 0)
        {
            QMessageBox::critical(this,tr("Error"),tr("A Movie Is Showing At Current Time\n In This Theatre!"));
        }
        else
        {
            qry.prepare("INSERT INTO MOVIETIME(MovieTitle,Theatre,Day,Time,AvailableSeats) values('"+title+"','"+theatre+"','"+day+"','"+time+"','"+seatNumber+"')");
            if(qry.exec())
            {
                QMessageBox::information(this,tr("Saved"),"Successfully Saved");
                con.connClose();
            }
            else
            {
                QMessageBox::critical(this,tr("Error"),qry.lastError().text());
            }
        }
    }
    else
    {
        QMessageBox::critical(this,tr("Error"),qry.lastError().text());
    }
}

void TImeShowing::on_cancelButton_clicked()
{
    this->hide();
    MovieReservation *movie = new MovieReservation();
    movie->show();
}
