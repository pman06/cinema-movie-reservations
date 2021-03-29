#ifndef TICKET_H
#define TICKET_H

#include <QDialog>

namespace Ui {
class Ticket;
}

class Ticket : public QDialog
{
    Q_OBJECT

public:
    Ticket(QWidget *parent = 0);
    Ticket(QString, QString, QString,  QString, QString, QString, QString);
    ~Ticket();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Ticket *ui;
    QString movieTitle;
    QString movieActor;
    QString movieActress;
    QString movieTheatre;
    QString movieTime;
    QString movieDate;
    QString moviePrice;
};

#endif // TICKET_H
