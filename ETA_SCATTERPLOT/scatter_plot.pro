#-------------------------------------------------
#
# Project created by QtCreator 2017-05-03T11:59:31
#
#-------------------------------------------------

QT       += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport
TARGET = scatter_plot
TEMPLATE = app

LIBS +=  -lpthread
QT += network
 QT += testlib

SOURCES += main.cpp\
           udpsok.cpp \
           qcustomplot.cpp \
           queue.cpp \
           realtime_xy_plot.cpp

HEADERS  +=  udpsok.h \
             qcustomplot.h \
             realtime_xy_plot.h \
             queue.h \
             header.h\



FORMS    +=  realtime_xy_plot.ui
