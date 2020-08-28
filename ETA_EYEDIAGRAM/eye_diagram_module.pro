#-------------------------------------------------
#
# Project created by QtCreator 2017-05-02T12:07:03
#
#-------------------------------------------------

QT       += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport
TARGET = eye_diagram_module
TEMPLATE = app
#LIBS +=  -lpthread
QT += network
 QT += testlib
SOURCES += main.cpp\
           udpsok.cpp \
           qcustomplot.cpp \
           queue.cpp \
           eyediagram.cpp \
           matrix_engin.cpp \
           sinc_filters.cpp \
           eye_engine.cpp


HEADERS  +=  udpsok.h \
             qcustomplot.h \
             realtime_xy_plot.h \
             queue.h \
             eyediagram.h \
             matrix_engin.h \
             sinc_filters.h \
             eye_engine.h\
             header.h\


FORMS    += eyediagram.ui\


