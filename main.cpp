#include "moviereservation.h"
#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MovieReservation w;

    w.show();


    return a.exec();
}
