#-------------------------------------------------
#
# Project created by QtCreator 2017-06-01T11:43:50
#
#-------------------------------------------------
 
QT       += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport
TARGET = TimeDomain
TEMPLATE = app

LIBS +=  -lpthread
QT += network
 QT += testlib


SOURCES +=  main.cpp\
            realtime_timedomain.cpp\
            queue.cpp\
            qcustomplot.cpp\
            udpsok.cpp
		   
		   
HEADERS  +=   realtime_timedomain.h\
              queue.h\
              qcustomplot.h\
              udpsok.h\

			 
FORMS    +=  realtime_timedomain.ui\
