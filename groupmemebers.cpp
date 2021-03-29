#include "groupmemebers.h"
#include "ui_groupmemebers.h"

GroupMemebers::GroupMemebers(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GroupMemebers)
{
    ui->setupUi(this);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
   // ui->tableWidget->horizontalHeader()->S
    ui->tableWidget->setEnabled(false);
}

GroupMemebers::~GroupMemebers()
{
    delete ui;
}

void GroupMemebers::on_closeButton_clicked()
{
    this->close();
}
