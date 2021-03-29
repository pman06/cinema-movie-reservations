#include "ticket.h"
#include "ui_ticket.h"

#include <QPainter>
#include <QPrintDialog>
#include <QPrinter>


#include <iostream>

Ticket::Ticket(QWidget *parent):
    QDialog(parent),
    ui(new Ui::Ticket)
{
    ui->setupUi(this);
}

Ticket::Ticket(QString title, QString actor, QString actress, QString theatre, QString time, QString date, QString price):
    ui(new Ui::Ticket), movieTitle(title),movieActor(actor),movieActress(actress), movieTheatre(theatre), movieTime(time),movieDate(date), moviePrice(price)
{
    ui->setupUi(this);

    ui->movieLabel->setText(movieTitle);
    ui->actorLabel->setText(movieActor);
    ui->actressLabel->setText(movieActress);
    ui->dayLabel->setText(movieDate);
    ui->theatreLabel->setText(movieTheatre);
    ui->timeLabel->setText(movieTime);
    ui->priceLabel->setText(moviePrice);
}


Ticket::~Ticket()
{
    delete ui;
}

void Ticket::on_pushButton_clicked()
{
    ui->pushButton->hide();
    QPrinter printer;
    printer.setColorMode(QPrinter::Color);

    QPrintDialog dialog(&printer,this);
    if(dialog.exec()==QDialog::Rejected) return;
    QWidget::render(&printer);
}
