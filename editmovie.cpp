#include "editmovie.h"
#include "ui_editmovie.h"
#include "moviereservation.h"

#include <QSqlQuery>
#include <QMessageBox>

EditMovie::EditMovie(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::EditMovie)
{
    ui->setupUi(this);
    this->setWindowTitle("Edit Movie Details");
    ui->statusLabel->hide();
    if(!con.connOpen())
    {
        qDebug()<<"Failed to open the database";
        return;
    }
    else
    {
        con.connOpen();
    }
}

EditMovie::~EditMovie()
{
    delete ui;
    con.connClose();
}


void EditMovie::on_searchButton_clicked()
{
    QString title = ui->searchTitleEdit->text().toUpper();

    if(!title.isEmpty())
    {
        QSqlQuery qry;
        qry.prepare("SELECT * FROM Movies where MovieTitle='"+title+"'");
        if(qry.exec())
        {
            if(qry.next())
            {
                ui->titleEdit->setText(qry.value(0).toString());
                ui->yearLineEdit->setText(qry.value(1).toString());
                ui->ratingComboBox->setCurrentText(qry.value(2).toString());
                ui->genreComboBox->setCurrentText(qry.value(3).toString());
                ui->descriptionTextEdit->setText(qry.value(4).toString());
                ui->leadActorEdit->setText(qry.value(5).toString());
                ui->leadActressEdit->setText(qry.value(6).toString());
            }
            else
            {
                QMessageBox::critical(this,"Error","Movie Not In Database!");
            }
        }
        else
        {
            QMessageBox::critical(this,"Error",qry.lastError().text());
        }
    }
    else
    {
        ui->statusLabel->show();
    }
}

void EditMovie::on_cancelMovieButton_4_clicked()
{
    this->close();
    MovieReservation *form = new MovieReservation();
    form->show();
}

void EditMovie::on_searchTitleEdit_textEdited(const QString &arg1)
{
    ui->statusLabel->hide();
}

void EditMovie::on_updateMovieButton_clicked()
{
    QSqlQuery qry;
    QString title = ui->titleEdit->text().toUpper();
    QString year = ui->yearLineEdit->text();
    QString rating = ui->ratingComboBox->currentText();
    QString genre = ui->genreComboBox->currentText();
    QString description = ui->descriptionTextEdit->toPlainText();
    QString leadActor = ui->leadActorEdit->text();
    QString leadActress = ui->leadActressEdit->text();

    qry.prepare("UPDATE Movies set MovieTitle = '"+title+"',Year='"+year+"',Rating='"+rating+"',genre='"+genre+"',Description='"+description+"',leadActor='"+leadActor+"',leadActress='"+leadActress+"' where MovieTitle='"+title+"'");
    if(qry.exec())
    {
        QMessageBox::information(this,"Saved","Movie Updated");

        ui->titleEdit->clear();
        ui->yearLineEdit->clear();
        ui->ratingComboBox->clear();
        ui->genreComboBox->clear();
        ui->descriptionTextEdit->clear();
        ui->leadActorEdit->clear();
        ui->leadActressEdit->clear();
        ui->searchTitleEdit->clear();
    }
    else
    {
        QMessageBox::critical(this,"Error",qry.lastError().text());
    }
}
