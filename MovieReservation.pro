#-------------------------------------------------
#
# Project created by QtCreator 2018-04-09T05:54:56
#
#-------------------------------------------------

QT       += core gui sql printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MovieReservation
TEMPLATE = app


SOURCES += main.cpp\
        moviereservation.cpp \
    addmovie.cpp \
    databaseconnection.cpp \
    viewmovies.cpp \
    registertheatre.cpp \
    timeshowing.cpp \
    reservemovie.cpp \
    ticket.cpp \
    editmovie.cpp \
    nowshowing.cpp \
    deleteshowingtime.cpp \
    groupmemebers.cpp

HEADERS  += moviereservation.h \
    addmovie.h \
    databaseconnection.h \
    viewmovies.h \
    registertheatre.h \
    timeshowing.h \
    reservemovie.h \
    ticket.h \
    editmovie.h \
    nowshowing.h \
    deleteshowingtime.h \
    groupmemebers.h

FORMS    += moviereservation.ui \
    addmovie.ui \
    viewmovies.ui \
    registertheatre.ui \
    timeshowing.ui \
    reservemovie.ui \
    ticket.ui \
    editmovie.ui \
    nowshowing.ui \
    deleteshowingtime.ui \
    groupmemebers.ui

RESOURCES += \
    resources.qrc
