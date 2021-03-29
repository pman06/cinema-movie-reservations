#include "deleteshowingtime.h"
#include "ui_deleteshowingtime.h"
#include "moviereservation.h"
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QMessageBox>


DeleteShowingTime::DeleteShowingTime(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::DeleteShowingTime)
{
    ui->setupUi(this);
    if(!con.connOpen())
    {
        return;
    }
    else
    {
        con.connOpen();
    }

    QSqlQuery qry;
    QSqlQueryModel *model = new QSqlQueryModel();

    qry.prepare("Select TheatreName from Theatre");
    if(qry.exec())
    {
        model->setQuery(qry);
        ui->hallComboBox->setModel(model);
    }
    else
    {
        QMessageBox::critical(this,"Error",""+qry.lastError().text());
    }
}

DeleteShowingTime::~DeleteShowingTime()
{
    delete ui;
    con.connClose();
}

void DeleteShowingTime::on_dayComboBox_currentIndexChanged(const QString &arg1)
{
    QString theatre = ui->hallComboBox->currentText();
    QString day = ui->dayComboBox->currentText();
    QSqlQuery qry;
    QSqlQueryModel *model = new QSqlQueryModel();

    qry.prepare("Select  Time from MovieTime where Theatre = '"+theatre+"' and DAY = '"+day+"' order by day desc");
    if(qry.exec())
    {
        model->setQuery(qry);
        ui->timeComboBox->setModel(model);
    }
    else
    {
        QMessageBox::critical(this,"Error",""+qry.lastError().text());
    }
}

void DeleteShowingTime::on_hallComboBox_currentIndexChanged(const QString &arg1)
{
    QString theatre = ui->hallComboBox->currentText();

    QSqlQuery qry;
    QSqlQueryModel *model = new QSqlQueryModel();

    qry.prepare("Select DISTINCT Day from MovieTime where Theatre = '"+theatre+"' order by day desc");
    if(qry.exec())
    {
        model->setQuery(qry);
        ui->dayComboBox->setModel(model);
    }
    else
    {
        QMessageBox::critical(this,"Error",""+qry.lastError().text());
    }
}

void DeleteShowingTime::on_timeComboBox_currentIndexChanged(const QString &arg1)
{
    QString theatre = ui->hallComboBox->currentText();
    QString day = ui->dayComboBox->currentText();
    QString time = ui->timeComboBox->currentText();

    QSqlQuery qry;


    qry.prepare("Select * from MovieTime where Theatre = '"+theatre+"' and DAY = '"+day+"' and time ='"+time+"'");
    if(qry.exec())
    {
        if(qry.next())
        {
            ui->titleLabel->setText(qry.value(0).toString());
        }
        else
        {
            ui->titleLabel->setText("");
        }
    }
    else
    {
        QMessageBox::critical(this,"Error",""+qry.lastError().text());
    }
}

void DeleteShowingTime::on_deleteButton_clicked()
{
    QMessageBox msgBox;
    msgBox.setText("Do you want to Delete This Showing Time?");
    QPushButton *dele = msgBox.addButton(tr("Delete"),QMessageBox::ActionRole);
    QPushButton *cancel = msgBox.addButton(QMessageBox::Abort);

    msgBox.exec();

    if(msgBox.clickedButton()== dele)
    {
        QString theatre = ui->hallComboBox->currentText();
        QString day = ui->dayComboBox->currentText();
        QString time = ui->timeComboBox->currentText();
        QSqlQuery qry;
        qry.prepare("Delete from MovieTime where Theatre = '"+theatre+"' and DAY = '"+day+"' and time ='"+time+"'");
        if(qry.exec())
        {
            qry.prepare("Delete from BookMovies where Theatre = '"+theatre+"' and DAY = '"+day+"' and time ='"+time+"'");
            if(qry.exec())
            {
                QMessageBox::information(this,tr("Deleted"),tr("Showing Time Deleted!"));
                ui->dayComboBox->clear();
                ui->timeComboBox->clear();
            }
            else
            {
                QMessageBox::critical(this,tr("Error"),qry.lastError().text());
            }
        }
        else
        {
            QMessageBox::critical(this,tr("Error"),qry.lastError().text());
        }

    }
    else if(msgBox.clickedButton()== cancel)
    {
        return;
    }
}

void DeleteShowingTime::on_backButton_clicked()
{
    this->close();
    MovieReservation *form = new MovieReservation;
    form->show();
}
