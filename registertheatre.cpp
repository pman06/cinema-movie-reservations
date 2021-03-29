#include "registertheatre.h"
#include "ui_registertheatre.h"
#include "moviereservation.h"

#include <QSqlQuery>
#include <QMessageBox>

RegisterTheatre::RegisterTheatre(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::RegisterTheatre)
{
    ui->setupUi(this);
    this->setWindowTitle("Register New Theatre");
}

RegisterTheatre::~RegisterTheatre()
{
    delete ui;
}

void RegisterTheatre::on_saveTheatreButton_clicked()
{
    if(!con.connOpen())
    {
        qDebug()<<"Failed to connect to the database";
        return;
    }
    else
    {
        con.connOpen();
    }

    QString theatreName = ui->nameLineEdit->text().toUpper();
    QString seatNumber = ui->seatLineEdit->text();

    if(!theatreName.isEmpty() && !seatNumber.isEmpty())
    {
        QSqlQuery qry;
        if(qry.exec("Select theatreName from Theatre where theatreName='"+theatreName+"'"))
        {
            if(qry.next())
            {
                QMessageBox::critical(this,tr("Error!"),"Theatre Already Exists");
            }
            else
            {
                qry.prepare("INSERT INTO Theatre(TheatreName,SeatNumber) values('"+theatreName+"','"+seatNumber+"')");
                if(qry.exec())
                {
                    QMessageBox::information(this,tr("Success!"),"Theatre Successfully Registered!");
                    con.connClose();
                }
                else
                {
                    QMessageBox::critical(this,tr("Error!"),qry.lastError().text());
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
        QMessageBox::critical(this,tr("Error"), tr("Please Supply All Values!"));
    }

}

void RegisterTheatre::on_backTHeatreButton_clicked()
{
    this->hide();
    MovieReservation *movie = new MovieReservation;
    movie->show();
}
