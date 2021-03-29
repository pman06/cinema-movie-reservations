#include "addmovie.h"
#include "ui_addmovie.h"
#include "moviereservation.h"
#include <iostream>
#include <QSqlQuery>


AddMovie::AddMovie(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AddMovie)
{
    ui->setupUi(this);
    this->setWindowTitle("Add Movie");
    QRegExp reg("[A-Z]{1,30}");
    QRegExpValidator val(reg,0);
    ui->titleLineEdit->setValidator(&val);
}

AddMovie::~AddMovie()
{
    delete ui;
}

void AddMovie::on_saveMovieButton_clicked()
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

    QString title = ui->titleLineEdit->text().toUpper();
    QString year = ui->yearLineEdit->text();
    QString rating = ui->ratingComboBox->itemText(ui->ratingComboBox->currentIndex());
    QString genre = ui->genreComboBox->itemText(ui->genreComboBox->currentIndex());
    QString leadActor = ui->leadActorEdit->text();
    QString leadActress = ui->leadActressEdit->text();
    QString description = ui->descriptionTextEdit->toPlainText();

    if((!title.isEmpty()) && (!year.isEmpty()) && (!leadActor.isEmpty()) && (!leadActress.isEmpty()) && (!rating.isEmpty()) && (!genre.isEmpty()) && (!description.isEmpty()))
    {
        QSqlQuery qry;
        qry.prepare("Select * from movies where movietitle='"+title+"' AND year='"+year+"' AND rating='"+rating+"' and genre='"+genre+"' and Description='"+description+"'");
        if(qry.exec())
        {
            int count = 0;
            while(qry.next())
            {
                count++;
            }

            if(count==0)
            {
                qry.prepare("INSERT INTO MOVIES(Movietitle,year,rating,genre,description,leadActor,leadActress) values('"+title+"','"+year+"','"+rating+"','"+genre+"','"+description+"','"+leadActor+"','"+leadActress+"')");
                if(qry.exec())
                {
                    QMessageBox::information(this,tr("Saved"),tr("Movie Saved Successfully!"));
                    con.connClose();
                }
                else
                {
                    QMessageBox::critical(this,tr("Error"),"Not Added");
                }
            }
            else
            {
                QMessageBox::critical(this,tr("Error!"),tr("Movie is already Added!"));
            }
        }
        else
        {
            QMessageBox::critical(this,tr("Error"), qry.lastError().text());
        }
    }
    else
    {
        QMessageBox::critical(this,tr("Error"), tr("Please Supply All Values!"));
    }
}

void AddMovie::on_cancelMovieButton_clicked()
{
    this->hide();
    MovieReservation *movie = new MovieReservation();
    movie->show();
}
