/********************************************************************************
** Form generated from reading UI file 'realtime_xy_plot.ui'
**
** Created: Tue 27. Jun 16:05:18 2017
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REALTIME_XY_PLOT_H
#define UI_REALTIME_XY_PLOT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QWidget>
#include <qcustomplot.h>

QT_BEGIN_NAMESPACE

class Ui_RealTime_xy_plot
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QCustomPlot *customplot;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *RealTime_xy_plot)
    {
        if (RealTime_xy_plot->objectName().isEmpty())
            RealTime_xy_plot->setObjectName(QString::fromUtf8("RealTime_xy_plot"));
        RealTime_xy_plot->resize(551, 432);
        RealTime_xy_plot->setStyleSheet(QString::fromUtf8("background-color: rgb(47, 47, 47);"));
        centralwidget = new QWidget(RealTime_xy_plot);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        customplot = new QCustomPlot(centralwidget);
        customplot->setObjectName(QString::fromUtf8("customplot"));

        gridLayout->addWidget(customplot, 0, 0, 1, 1);

        RealTime_xy_plot->setCentralWidget(centralwidget);
        menubar = new QMenuBar(RealTime_xy_plot);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 551, 21));
        RealTime_xy_plot->setMenuBar(menubar);
        statusbar = new QStatusBar(RealTime_xy_plot);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        RealTime_xy_plot->setStatusBar(statusbar);

        retranslateUi(RealTime_xy_plot);

        QMetaObject::connectSlotsByName(RealTime_xy_plot);
    } // setupUi

    void retranslateUi(QMainWindow *RealTime_xy_plot)
    {
        RealTime_xy_plot->setWindowTitle(QApplication::translate("RealTime_xy_plot", "MainWindow", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class RealTime_xy_plot: public Ui_RealTime_xy_plot {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REALTIME_XY_PLOT_H
