#include "nowshowing.h"
#include "ui_nowshowing.h"
#include "moviereservation.h"

#include <QSqlQuery>
#include <QMessageBox>
#include <QSqlQueryModel>
#include <QTreeWidget>


QSqlQueryModel *model = new QSqlQueryModel;

NowShowing::NowShowing(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::NowShowing)
{
    ui->setupUi(this);

    ui->tableWidget->verticalHeader()->setDefaultSectionSize(70);
    
    if(!con.connOpen())
    {
        return;
    }
    else
    {
        con.connOpen();
    }

    QSqlQuery qry;
    qry.prepare("Select TheatreName from Theatre");

    if(qry.exec())
    {
        model->setQuery(qry);
        ui->hallsComboBox->setModel(model);
    }
    else
    {
        QMessageBox::critical(this,"Error", qry.lastError().text());
    }
}

NowShowing::~NowShowing()
{
    delete ui;
    con.connClose();
}

void NowShowing::on_backButton_clicked()
{
    this->close();
    MovieReservation *win = new MovieReservation;
    win->show();
}

void NowShowing::on_hallsComboBox_currentIndexChanged(const QString &arg1)
{
    for(int i =0; i<6; i++)
    {
        for(int j = 0; j <7; j++)
            ui->tableWidget->setItem(i,j,new QTableWidgetItem(""));
    }
    QString hallName = ui->hallsComboBox->currentText();
    QSqlQuery qry;

    if(qry.exec("Select * from MovieTime  where Theatre = '"+hallName+"'"))
    {
        while(qry.next())
        {
            //populate Sunday column
            if(qry.value(2).toString()=="Sunday" && qry.value(3).toString()=="12:00 noon")
            {
                ui->tableWidget->setItem(0,0, new QTableWidgetItem(qry.value(0).toString()));
            }
            else if(qry.value(2).toString()=="Sunday" && qry.value(3).toString()=="02:00 pm")
            {
                ui->tableWidget->setItem(1,0, new QTableWidgetItem(qry.value(0).toString()));
            }
            else if(qry.value(2).toString()=="Sunday" && qry.value(3).toString()=="04:00 pm")
            {
                ui->tableWidget->setItem(2,0, new QTableWidgetItem(qry.value(0).toString()));
            }
            else if(qry.value(2).toString()=="Sunday" && qry.value(3).toString()=="06:00 pm")
            {
                ui->tableWidget->setItem(3,0, new QTableWidgetItem(qry.value(0).toString()));
            }
            else if(qry.value(2).toString()=="Sunday" && qry.value(3).toString()=="08:00 pm")
            {
                ui->tableWidget->setItem(4,0, new QTableWidgetItem(qry.value(0).toString()));
            }
            else if(qry.value(2).toString()=="Sunday" && qry.value(3).toString()=="10:00 pm")
            {
                ui->tableWidget->setItem(5,0, new QTableWidgetItem(qry.value(0).toString()));
            }

            //populate Monday column
            if(qry.value(2).toString()=="Monday" && qry.value(3).toString()=="12:00 noon")
            {
                ui->tableWidget->setItem(0,1, new QTableWidgetItem(qry.value(0).toString()));
            }
            else if(qry.value(2).toString()=="Monday" && qry.value(3).toString()=="02:00 pm")
            {
                ui->tableWidget->setItem(1,1, new QTableWidgetItem(qry.value(0).toString()));
            }
            else if(qry.value(2).toString()=="Monday" && qry.value(3).toString()=="04:00 pm")
            {
                ui->tableWidget->setItem(2,1, new QTableWidgetItem(qry.value(0).toString()));
            }
            else if(qry.value(2).toString()=="Monday" && qry.value(3).toString()=="06:00 pm")
            {
                ui->tableWidget->setItem(3,1, new QTableWidgetItem(qry.value(0).toString()));
            }
            else if(qry.value(2).toString()=="Monday" && qry.value(3).toString()=="08:00 pm")
            {
                ui->tableWidget->setItem(4,1, new QTableWidgetItem(qry.value(0).toString()));
            }
            else if(qry.value(2).toString()=="Monday" && qry.value(3).toString()=="10:00 pm")
            {
                ui->tableWidget->setItem(5,1, new QTableWidgetItem(qry.value(0).toString()));
            }

            //populate Tuesday column
            if(qry.value(2).toString()=="Tuesday" && qry.value(3).toString()=="12:00 noon")
            {
                ui->tableWidget->setItem(0,2, new QTableWidgetItem(qry.value(0).toString()));
            }
            else if(qry.value(2).toString()=="Tuesday" && qry.value(3).toString()=="02:00 pm")
            {
                ui->tableWidget->setItem(1,2, new QTableWidgetItem(qry.value(0).toString()));
            }
            else if(qry.value(2).toString()=="Tuesday" && qry.value(3).toString()=="04:00 pm")
            {
                ui->tableWidget->setItem(2,2, new QTableWidgetItem(qry.value(0).toString()));
            }
            else if(qry.value(2).toString()=="Tuesday" && qry.value(3).toString()=="06:00 pm")
            {
                ui->tableWidget->setItem(3,2, new QTableWidgetItem(qry.value(0).toString()));
            }
            else if(qry.value(2).toString()=="Tuesday" && qry.value(3).toString()=="08:00 pm")
            {
                ui->tableWidget->setItem(4,2, new QTableWidgetItem(qry.value(0).toString()));
            }
            else if(qry.value(2).toString()=="Tuesday" && qry.value(3).toString()=="10:00 pm")
            {
                ui->tableWidget->setItem(5,2, new QTableWidgetItem(qry.value(0).toString()));
            }

            //populate Wednesday column
            if(qry.value(2).toString()=="Wednesday" && qry.value(3).toString()=="12:00 noon")
            {
                ui->tableWidget->setItem(0,3, new QTableWidgetItem(qry.value(0).toString()));
            }
            else if(qry.value(2).toString()=="Wednesday" && qry.value(3).toString()=="02:00 pm")
            {
                ui->tableWidget->setItem(1,3, new QTableWidgetItem(qry.value(0).toString()));
            }
            else if(qry.value(2).toString()=="Wednesday" && qry.value(3).toString()=="04:00 pm")
            {
                ui->tableWidget->setItem(2,3, new QTableWidgetItem(qry.value(0).toString()));
            }
            else if(qry.value(2).toString()=="Wednesday" && qry.value(3).toString()=="06:00 pm")
            {
                ui->tableWidget->setItem(3,3, new QTableWidgetItem(qry.value(0).toString()));
            }
            else if(qry.value(2).toString()=="Wednesday" && qry.value(3).toString()=="08:00 pm")
            {
                ui->tableWidget->setItem(4,3, new QTableWidgetItem(qry.value(0).toString()));
            }
            else if(qry.value(2).toString()=="Wednesday" && qry.value(3).toString()=="10:00 pm")
            {
                ui->tableWidget->setItem(5,3, new QTableWidgetItem(qry.value(0).toString()));
            }

            //populate Thursday column
            if(qry.value(2).toString()=="Thursday" && qry.value(3).toString()=="12:00 noon")
            {
                ui->tableWidget->setItem(0,4, new QTableWidgetItem(qry.value(0).toString()));
            }
            else if(qry.value(2).toString()=="Thursday" && qry.value(3).toString()=="02:00 pm")
            {
                ui->tableWidget->setItem(1,4, new QTableWidgetItem(qry.value(0).toString()));
            }
            else if(qry.value(2).toString()=="Thursday" && qry.value(3).toString()=="04:00 pm")
            {
                ui->tableWidget->setItem(2,4, new QTableWidgetItem(qry.value(0).toString()));
            }
            else if(qry.value(2).toString()=="Thursday" && qry.value(3).toString()=="06:00 pm")
            {
                ui->tableWidget->setItem(3,4, new QTableWidgetItem(qry.value(0).toString()));
            }
            else if(qry.value(2).toString()=="Thursday" && qry.value(3).toString()=="08:00 pm")
            {
                ui->tableWidget->setItem(4,4, new QTableWidgetItem(qry.value(0).toString()));
            }
            else if(qry.value(2).toString()=="Thursday" && qry.value(3).toString()=="10:00 pm")
            {
                ui->tableWidget->setItem(5,4, new QTableWidgetItem(qry.value(0).toString()));
            }
            //populate Friday column
            if(qry.value(2).toString()=="Friday" && qry.value(3).toString()=="12:00 noon")
            {
                ui->tableWidget->setItem(0,5, new QTableWidgetItem(qry.value(0).toString()));
            }
            else if(qry.value(2).toString()=="Friday" && qry.value(3).toString()=="02:00 pm")
            {
                ui->tableWidget->setItem(1,5, new QTableWidgetItem(qry.value(0).toString()));
            }
            else if(qry.value(2).toString()=="Friday" && qry.value(3).toString()=="04:00 pm")
            {
                ui->tableWidget->setItem(2,5, new QTableWidgetItem(qry.value(0).toString()));
            }
            else if(qry.value(2).toString()=="Friday" && qry.value(3).toString()=="06:00 pm")
            {
                ui->tableWidget->setItem(3,5, new QTableWidgetItem(qry.value(0).toString()));
            }
            else if(qry.value(2).toString()=="Friday" && qry.value(3).toString()=="08:00 pm")
            {
                ui->tableWidget->setItem(4,5, new QTableWidgetItem(qry.value(0).toString()));
            }
            else if(qry.value(2).toString()=="Friday" && qry.value(3).toString()=="10:00 pm")
            {
                ui->tableWidget->setItem(5,5, new QTableWidgetItem(qry.value(0).toString()));
            }

            //populate Saturday column
            if(qry.value(2).toString()=="Saturday" && qry.value(3).toString()=="12:00 noon")
            {
                ui->tableWidget->setItem(0,6, new QTableWidgetItem(qry.value(0).toString()));
            }
            else if(qry.value(2).toString()=="Saturday" && qry.value(3).toString()=="02:00 pm")
            {
                ui->tableWidget->setItem(1,6, new QTableWidgetItem(qry.value(0).toString()));
            }
            else if(qry.value(2).toString()=="Saturday" && qry.value(3).toString()=="04:00 pm")
            {
                ui->tableWidget->setItem(2,6, new QTableWidgetItem(qry.value(0).toString()));
            }
            else if(qry.value(2).toString()=="Saturday" && qry.value(3).toString()=="06:00 pm")
            {
                ui->tableWidget->setItem(3,6, new QTableWidgetItem(qry.value(0).toString()));
            }
            else if(qry.value(2).toString()=="Saturday" && qry.value(3).toString()=="08:00 pm")
            {
                ui->tableWidget->setItem(4,6, new QTableWidgetItem(qry.value(0).toString()));
            }
            else if(qry.value(2).toString()=="Saturday" && qry.value(3).toString()=="10:00 pm")
            {
                ui->tableWidget->setItem(5,6, new QTableWidgetItem(qry.value(0).toString()));
            }
        }
    }
    else
    {
        QMessageBox::critical(this,"Error",qry.lastError().text());
    }
}
