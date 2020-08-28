/********************************************************************************
** Form generated from reading UI file 'eyediagram.ui'
**
** Created: Tue 27. Jun 16:04:58 2017
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EYEDIAGRAM_H
#define UI_EYEDIAGRAM_H

#include <QtCore/QVariant>
#include <QAction>
#include <QApplication>
#include <QButtonGroup>
#include <QDoubleSpinBox>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QHeaderView>
#include <QLabel>
#include <QMainWindow>
#include <QMenuBar>
#include <QPushButton>
#include <QSpinBox>
#include <QStatusBar>
#include <QWidget>
#include <qcustomplot.h>

QT_BEGIN_NAMESPACE

class Ui_EyeDiagram
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QCustomPlot *eyecutomplot;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QDoubleSpinBox *ALPHA;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_6;
    QDoubleSpinBox *XMIN;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_7;
    QSpinBox *XMAX;
    QHBoxLayout *horizontalLayout_8;
    QLabel *YMIN_____;
    QDoubleSpinBox *YMIN;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_9;
    QDoubleSpinBox *YMAX;
    QPushButton *pushButton;
    QDoubleSpinBox *var;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *EyeDiagram)
    {
        if (EyeDiagram->objectName().isEmpty())
            EyeDiagram->setObjectName(QString::fromUtf8("EyeDiagram"));
        EyeDiagram->resize(592, 456);
        EyeDiagram->setStyleSheet(QString::fromUtf8("background-color: rgb(57, 57, 57);"));
        centralwidget = new QWidget(EyeDiagram);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        eyecutomplot = new QCustomPlot(centralwidget);
        eyecutomplot->setObjectName(QString::fromUtf8("eyecutomplot"));

        gridLayout->addWidget(eyecutomplot, 0, 0, 1, 7);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setStyleSheet(QString::fromUtf8("color: rgb(255, 85, 0);"));

        horizontalLayout->addWidget(label);

        ALPHA = new QDoubleSpinBox(centralwidget);
        ALPHA->setObjectName(QString::fromUtf8("ALPHA"));
        ALPHA->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        horizontalLayout->addWidget(ALPHA);


        gridLayout->addLayout(horizontalLayout, 1, 0, 1, 1);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setStyleSheet(QString::fromUtf8("color: rgb(255, 85, 0);"));

        horizontalLayout_6->addWidget(label_6);

        XMIN = new QDoubleSpinBox(centralwidget);
        XMIN->setObjectName(QString::fromUtf8("XMIN"));
        XMIN->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        horizontalLayout_6->addWidget(XMIN);


        gridLayout->addLayout(horizontalLayout_6, 1, 1, 1, 1);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setStyleSheet(QString::fromUtf8("color: rgb(255, 85, 0);"));

        horizontalLayout_7->addWidget(label_7);

        XMAX = new QSpinBox(centralwidget);
        XMAX->setObjectName(QString::fromUtf8("XMAX"));
        XMAX->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        horizontalLayout_7->addWidget(XMAX);


        gridLayout->addLayout(horizontalLayout_7, 1, 2, 1, 1);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        YMIN_____ = new QLabel(centralwidget);
        YMIN_____->setObjectName(QString::fromUtf8("YMIN_____"));
        YMIN_____->setStyleSheet(QString::fromUtf8("color: rgb(255, 85, 0);"));

        horizontalLayout_8->addWidget(YMIN_____);

        YMIN = new QDoubleSpinBox(centralwidget);
        YMIN->setObjectName(QString::fromUtf8("YMIN"));
        YMIN->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        horizontalLayout_8->addWidget(YMIN);


        gridLayout->addLayout(horizontalLayout_8, 1, 3, 1, 1);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        label_9 = new QLabel(centralwidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setStyleSheet(QString::fromUtf8("color: rgb(255, 85, 0);"));

        horizontalLayout_9->addWidget(label_9);

        YMAX = new QDoubleSpinBox(centralwidget);
        YMAX->setObjectName(QString::fromUtf8("YMAX"));
        YMAX->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        horizontalLayout_9->addWidget(YMAX);


        gridLayout->addLayout(horizontalLayout_9, 1, 4, 1, 1);

        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 85, 0);"));

        gridLayout->addWidget(pushButton, 1, 6, 1, 1);

        var = new QDoubleSpinBox(centralwidget);
        var->setObjectName(QString::fromUtf8("var"));
        var->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        gridLayout->addWidget(var, 1, 5, 1, 1);

        EyeDiagram->setCentralWidget(centralwidget);
        menubar = new QMenuBar(EyeDiagram);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 592, 21));
        EyeDiagram->setMenuBar(menubar);
        statusbar = new QStatusBar(EyeDiagram);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        EyeDiagram->setStatusBar(statusbar);

        retranslateUi(EyeDiagram);

        QMetaObject::connectSlotsByName(EyeDiagram);
    } // setupUi

    void retranslateUi(QMainWindow *EyeDiagram)
    {
//        EyeDiagram->setWindowTitle(QApplication::translate("EyeDiagram", "MainWindow", 0, QApplication::UnicodeUTF8));
  //      label->setText(QApplication::translate("EyeDiagram", "ALPHA", 0, QApplication::UnicodeUTF8));
   //     label_6->setText(QApplication::translate("EyeDiagram", "XMIN", 0, QApplication::UnicodeUTF8));
    //    label_7->setText(QApplication::translate("EyeDiagram", "XMAX", 0, QApplication::UnicodeUTF8));
     //   YMIN_____->setText(QApplication::translate("EyeDiagram", "YMIN", 0, QApplication::UnicodeUTF8));
      //  label_9->setText(QApplication::translate("EyeDiagram", "YMAX", 0, QApplication::UnicodeUTF8));
       // pushButton->setText(QApplication::translate("EyeDiagram", "UPDATE", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class EyeDiagram: public Ui_EyeDiagram {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EYEDIAGRAM_H
