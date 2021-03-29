#ifndef GROUPMEMEBERS_H
#define GROUPMEMEBERS_H

#include <QMainWindow>

namespace Ui {
class GroupMemebers;
}

class GroupMemebers : public QMainWindow
{
    Q_OBJECT

public:
    explicit GroupMemebers(QWidget *parent = 0);
    ~GroupMemebers();

private slots:
    void on_closeButton_clicked();

private:
    Ui::GroupMemebers *ui;
};

#endif // GROUPMEMEBERS_H
