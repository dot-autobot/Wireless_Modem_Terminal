/********************************************************************************
** Form generated from reading UI file 'realtime_timedomain.ui'
**
** Created: Tue 27. Jun 16:04:41 2017
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REALTIME_TIMEDOMAIN_H
#define UI_REALTIME_TIMEDOMAIN_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QSlider>
#include <QtGui/QStatusBar>
#include <QtGui/QWidget>
#include <qcustomplot.h>

QT_BEGIN_NAMESPACE

class Ui_realtime_timedomain
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QDoubleSpinBox *scalling_factor;
    QCustomPlot *customplot;
    QSlider *xmax_var;
    QSlider *xmin_var;
    QPushButton *push_play_pause;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *realtime_timedomain)
    {
        if (realtime_timedomain->objectName().isEmpty())
            realtime_timedomain->setObjectName(QString::fromUtf8("realtime_timedomain"));
        realtime_timedomain->resize(716, 375);
        realtime_timedomain->setStyleSheet(QString::fromUtf8("background-color: rgb(58, 58, 58);"));
        centralwidget = new QWidget(realtime_timedomain);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setStyleSheet(QString::fromUtf8("color: rgb(255, 85, 0);"));

        horizontalLayout->addWidget(label);

        scalling_factor = new QDoubleSpinBox(centralwidget);
        scalling_factor->setObjectName(QString::fromUtf8("scalling_factor"));
        scalling_factor->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        horizontalLayout->addWidget(scalling_factor);


        gridLayout->addLayout(horizontalLayout, 2, 3, 1, 1);

        customplot = new QCustomPlot(centralwidget);
        customplot->setObjectName(QString::fromUtf8("customplot"));

        gridLayout->addWidget(customplot, 0, 0, 1, 4);

        xmax_var = new QSlider(centralwidget);
        xmax_var->setObjectName(QString::fromUtf8("xmax_var"));
        xmax_var->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(xmax_var, 1, 2, 1, 1);

        xmin_var = new QSlider(centralwidget);
        xmin_var->setObjectName(QString::fromUtf8("xmin_var"));
        xmin_var->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(xmin_var, 1, 0, 1, 1);

        push_play_pause = new QPushButton(centralwidget);
        push_play_pause->setObjectName(QString::fromUtf8("push_play_pause"));
        push_play_pause->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 85, 0);"));

        gridLayout->addWidget(push_play_pause, 2, 1, 1, 1);

        realtime_timedomain->setCentralWidget(centralwidget);
        customplot->raise();
        xmax_var->raise();
        xmin_var->raise();
        push_play_pause->raise();
        menubar = new QMenuBar(realtime_timedomain);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 716, 21));
        realtime_timedomain->setMenuBar(menubar);
        statusbar = new QStatusBar(realtime_timedomain);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        realtime_timedomain->setStatusBar(statusbar);

        retranslateUi(realtime_timedomain);

        QMetaObject::connectSlotsByName(realtime_timedomain);
    } // setupUi

    void retranslateUi(QMainWindow *realtime_timedomain)
    {
        realtime_timedomain->setWindowTitle(QApplication::translate("realtime_timedomain", "MainWindow", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("realtime_timedomain", "scale", 0, QApplication::UnicodeUTF8));
        push_play_pause->setText(QApplication::translate("realtime_timedomain", "PAUSE", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class realtime_timedomain: public Ui_realtime_timedomain {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REALTIME_TIMEDOMAIN_H
