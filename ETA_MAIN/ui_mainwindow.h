/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Thu Jan 1 21:20:41 2009
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QAction>
#include <QApplication>
#include <QButtonGroup>
#include <QGridLayout>
#include <QGroupBox>
#include <QHBoxLayout>
#include <QHeaderView>
#include <QLCDNumber>
#include <QLabel>
#include <QLineEdit>
#include <QMainWindow>
#include <QMenuBar>
#include <QPlainTextEdit>
#include <QProgressBar>
#include <QPushButton>
#include <QRadioButton>
#include <QSpacerItem>
#include <QSpinBox>
#include <QStatusBar>
#include <QTextEdit>
#include <QToolBar>
#include <QVBoxLayout>
#include <QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QProgressBar *progressBar;
    QPushButton *pushButton;
    QPushButton *soket_init;
    QPushButton *reset;
    QPushButton *ply_pause;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_12;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit_TRAINING_Get_File;
    QHBoxLayout *horizontalLayout_8;
    QRadioButton *training_sym_radio_file;
    QRadioButton *training_sym_radio_text;
    QPlainTextEdit *training_sym;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_2;
    QHBoxLayout *horizontalLayout_7;
    QRadioButton *data_sym_radio_file;
    QRadioButton *data_sym_radio_textbox;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLineEdit *lineEdit_DATA_Get_File;
    QPlainTextEdit *data_sym;
    QGroupBox *groupBox_4;
    QGridLayout *gridLayout_3;
    QSpacerItem *verticalSpacer;
    QTextEdit *output;
    QWidget *layoutWidget1;
    QGridLayout *gridLayout_4;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *sdr_ip;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QSpinBox *udp_tx_port;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_5;
    QSpinBox *udp_recv_port;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_6;
    QSpinBox *size_packet;
    QHBoxLayout *horizontalLayout_33;
    QLabel *label_25;
    QSpinBox *iteratoor;
    QHBoxLayout *horizontalLayout_35;
    QLabel *label_27;
    QSpinBox *write_delay;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label_9;
    QLineEdit *host_ip;
    QWidget *layoutWidget2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_7;
    QLCDNumber *lcd_packet_sent;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_8;
    QLCDNumber *lcd_packet_recvd;
    QGroupBox *groupBox_5;
    QWidget *layoutWidget_2;
    QHBoxLayout *horizontalLayout_13;
    QLabel *label_10;
    QSpinBox *eye_d_port;
    QPushButton *pushButton_3;
    QWidget *layoutWidget_4;
    QHBoxLayout *horizontalLayout_15;
    QLabel *label_12;
    QSpinBox *eye_d_port_2;
    QGroupBox *groupBox_6;
    QWidget *layoutWidget_3;
    QHBoxLayout *horizontalLayout_14;
    QLabel *label_11;
    QSpinBox *scater_plot;
    QPushButton *pushButton_4;
    QGroupBox *groupBox_3;
    QRadioButton *BPSK;
    QRadioButton *QPSK;
    QGroupBox *groupBox_7;
    QWidget *layoutWidget_5;
    QHBoxLayout *horizontalLayout_16;
    QLabel *label_13;
    QSpinBox *time_domain_port;
    QPushButton *timedomain;
    QMenuBar *menuBar;
    QStatusBar *statusBar;
    QToolBar *mainToolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(783, 495);
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        MainWindow->setFont(font);
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(50, 50, 50);\n"
"gridline-color: rgb(255, 85, 0);\n"
" "));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        progressBar = new QProgressBar(centralWidget);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setGeometry(QRect(870, 20, 20, 271));
        progressBar->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 85, 0);"));
        progressBar->setValue(24);
        progressBar->setOrientation(Qt::Vertical);
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(290, 450, 191, 23));
        pushButton->setContextMenuPolicy(Qt::NoContextMenu);
        pushButton->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 85, 0);"));
        soket_init = new QPushButton(centralWidget);
        soket_init->setObjectName(QString::fromUtf8("soket_init"));
        soket_init->setGeometry(QRect(290, 420, 191, 23));
        soket_init->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 85, 0);"));
        reset = new QPushButton(centralWidget);
        reset->setObjectName(QString::fromUtf8("reset"));
        reset->setGeometry(QRect(290, 390, 191, 23));
        reset->setStyleSheet(QString::fromUtf8("  \n"
"background-color: rgb(255, 85, 0);"));
        ply_pause = new QPushButton(centralWidget);
        ply_pause->setObjectName(QString::fromUtf8("ply_pause"));
        ply_pause->setGeometry(QRect(290, 480, 191, 23));
        ply_pause->setContextMenuPolicy(Qt::NoContextMenu);
        ply_pause->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 85, 0);"));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 10, 842, 280));
        horizontalLayout_12 = new QHBoxLayout(layoutWidget);
        horizontalLayout_12->setSpacing(6);
        horizontalLayout_12->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        horizontalLayout_12->setContentsMargins(0, 0, 0, 0);
        groupBox = new QGroupBox(layoutWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setStyleSheet(QString::fromUtf8("color: rgb(255, 85, 0);"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("MS Shell Dlg 2"));
        font1.setPointSize(8);
        font1.setBold(false);
        font1.setItalic(false);
        font1.setWeight(9);
        label->setFont(font1);
        label->setStyleSheet(QString::fromUtf8("font: 10pt \"MS Shell Dlg 2\";\n"
"font: 75 8pt \"MS Shell Dlg 2\";\n"
"font: 75 8pt \"MS Shell Dlg 2\";\n"
"font: 75 8pt \"MS Shell Dlg 2\";\n"
"background-color: rgb(74, 74, 74);\n"
"color: rgb(255, 85, 0);\n"
" "));

        horizontalLayout->addWidget(label);

        lineEdit_TRAINING_Get_File = new QLineEdit(groupBox);
        lineEdit_TRAINING_Get_File->setObjectName(QString::fromUtf8("lineEdit_TRAINING_Get_File"));
        lineEdit_TRAINING_Get_File->setStyleSheet(QString::fromUtf8("border-color: rgb(0, 0, 0);\n"
"background-color: rgb(255, 255, 255);"));

        horizontalLayout->addWidget(lineEdit_TRAINING_Get_File);


        gridLayout->addLayout(horizontalLayout, 1, 0, 1, 1);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        training_sym_radio_file = new QRadioButton(groupBox);
        training_sym_radio_file->setObjectName(QString::fromUtf8("training_sym_radio_file"));
        training_sym_radio_file->setStyleSheet(QString::fromUtf8(" \n"
"background-color: rgb(74, 74, 74);\n"
"color: rgb(255, 85, 0);\n"
" "));

        horizontalLayout_8->addWidget(training_sym_radio_file);

        training_sym_radio_text = new QRadioButton(groupBox);
        training_sym_radio_text->setObjectName(QString::fromUtf8("training_sym_radio_text"));
        training_sym_radio_text->setStyleSheet(QString::fromUtf8(" \n"
"background-color: rgb(74, 74, 74);\n"
"color: rgb(255, 85, 0);\n"
" "));

        horizontalLayout_8->addWidget(training_sym_radio_text);


        gridLayout->addLayout(horizontalLayout_8, 0, 0, 1, 1);

        training_sym = new QPlainTextEdit(groupBox);
        training_sym->setObjectName(QString::fromUtf8("training_sym"));
        training_sym->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));

        gridLayout->addWidget(training_sym, 2, 0, 1, 1);


        horizontalLayout_12->addWidget(groupBox);

        groupBox_2 = new QGroupBox(layoutWidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setStyleSheet(QString::fromUtf8("color: rgb(255, 85, 0);"));
        gridLayout_2 = new QGridLayout(groupBox_2);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        data_sym_radio_file = new QRadioButton(groupBox_2);
        data_sym_radio_file->setObjectName(QString::fromUtf8("data_sym_radio_file"));
        data_sym_radio_file->setStyleSheet(QString::fromUtf8(" \n"
"background-color: rgb(74, 74, 74);\n"
"color: rgb(255, 85, 0);\n"
" "));

        horizontalLayout_7->addWidget(data_sym_radio_file);

        data_sym_radio_textbox = new QRadioButton(groupBox_2);
        data_sym_radio_textbox->setObjectName(QString::fromUtf8("data_sym_radio_textbox"));
        data_sym_radio_textbox->setStyleSheet(QString::fromUtf8(" \n"
"background-color: rgb(74, 74, 74);\n"
"color: rgb(255, 85, 0);\n"
" "));

        horizontalLayout_7->addWidget(data_sym_radio_textbox);


        gridLayout_2->addLayout(horizontalLayout_7, 0, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font1);
        label_3->setStyleSheet(QString::fromUtf8("font: 10pt \"MS Shell Dlg 2\";\n"
"font: 75 8pt \"MS Shell Dlg 2\";\n"
"font: 75 8pt \"MS Shell Dlg 2\";\n"
"font: 75 8pt \"MS Shell Dlg 2\";\n"
"background-color: rgb(74, 74, 74);\n"
"color: rgb(255, 85, 0);\n"
" "));

        horizontalLayout_3->addWidget(label_3);

        lineEdit_DATA_Get_File = new QLineEdit(groupBox_2);
        lineEdit_DATA_Get_File->setObjectName(QString::fromUtf8("lineEdit_DATA_Get_File"));
        lineEdit_DATA_Get_File->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        horizontalLayout_3->addWidget(lineEdit_DATA_Get_File);


        gridLayout_2->addLayout(horizontalLayout_3, 1, 0, 1, 1);

        data_sym = new QPlainTextEdit(groupBox_2);
        data_sym->setObjectName(QString::fromUtf8("data_sym"));
        data_sym->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));

        gridLayout_2->addWidget(data_sym, 2, 0, 1, 1);


        horizontalLayout_12->addWidget(groupBox_2);

        groupBox_4 = new QGroupBox(layoutWidget);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        groupBox_4->setStyleSheet(QString::fromUtf8("color: rgb(255, 85, 0);"));
        gridLayout_3 = new QGridLayout(groupBox_4);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_3->addItem(verticalSpacer, 0, 0, 1, 1);

        output = new QTextEdit(groupBox_4);
        output->setObjectName(QString::fromUtf8("output"));
        output->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));

        gridLayout_3->addWidget(output, 1, 0, 1, 1);


        horizontalLayout_12->addWidget(groupBox_4);

        layoutWidget1 = new QWidget(centralWidget);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(10, 320, 252, 192));
        gridLayout_4 = new QGridLayout(layoutWidget1);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_4->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(layoutWidget1);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setStyleSheet(QString::fromUtf8("background-color: rgb(74, 74, 74);\n"
"color: rgb(255, 85, 0);\n"
" "));

        horizontalLayout_2->addWidget(label_2);

        sdr_ip = new QLineEdit(layoutWidget1);
        sdr_ip->setObjectName(QString::fromUtf8("sdr_ip"));
        sdr_ip->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
""));

        horizontalLayout_2->addWidget(sdr_ip);


        gridLayout_4->addLayout(horizontalLayout_2, 1, 0, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_4 = new QLabel(layoutWidget1);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setStyleSheet(QString::fromUtf8("background-color: rgb(74, 74, 74);\n"
"color: rgb(255, 85, 0);\n"
" "));

        horizontalLayout_4->addWidget(label_4);

        udp_tx_port = new QSpinBox(layoutWidget1);
        udp_tx_port->setObjectName(QString::fromUtf8("udp_tx_port"));
        udp_tx_port->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
""));

        horizontalLayout_4->addWidget(udp_tx_port);


        gridLayout_4->addLayout(horizontalLayout_4, 2, 0, 1, 1);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_5 = new QLabel(layoutWidget1);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setStyleSheet(QString::fromUtf8("background-color: rgb(74, 74, 74);\n"
"color: rgb(255, 85, 0);\n"
" "));

        horizontalLayout_5->addWidget(label_5);

        udp_recv_port = new QSpinBox(layoutWidget1);
        udp_recv_port->setObjectName(QString::fromUtf8("udp_recv_port"));
        udp_recv_port->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
""));

        horizontalLayout_5->addWidget(udp_recv_port);


        gridLayout_4->addLayout(horizontalLayout_5, 3, 0, 1, 1);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_6 = new QLabel(layoutWidget1);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setStyleSheet(QString::fromUtf8("background-color: rgb(74, 74, 74);\n"
"color: rgb(255, 85, 0);\n"
" "));

        horizontalLayout_6->addWidget(label_6);

        size_packet = new QSpinBox(layoutWidget1);
        size_packet->setObjectName(QString::fromUtf8("size_packet"));
        size_packet->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
""));

        horizontalLayout_6->addWidget(size_packet);


        gridLayout_4->addLayout(horizontalLayout_6, 4, 0, 1, 1);

        horizontalLayout_33 = new QHBoxLayout();
        horizontalLayout_33->setSpacing(6);
        horizontalLayout_33->setObjectName(QString::fromUtf8("horizontalLayout_33"));
        label_25 = new QLabel(layoutWidget1);
        label_25->setObjectName(QString::fromUtf8("label_25"));
        label_25->setStyleSheet(QString::fromUtf8("background-color: rgb(74, 74, 74);\n"
"color: rgb(255, 85, 0);\n"
" "));

        horizontalLayout_33->addWidget(label_25);

        iteratoor = new QSpinBox(layoutWidget1);
        iteratoor->setObjectName(QString::fromUtf8("iteratoor"));
        iteratoor->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
""));

        horizontalLayout_33->addWidget(iteratoor);


        gridLayout_4->addLayout(horizontalLayout_33, 5, 0, 1, 1);

        horizontalLayout_35 = new QHBoxLayout();
        horizontalLayout_35->setSpacing(6);
        horizontalLayout_35->setObjectName(QString::fromUtf8("horizontalLayout_35"));
        label_27 = new QLabel(layoutWidget1);
        label_27->setObjectName(QString::fromUtf8("label_27"));
        label_27->setStyleSheet(QString::fromUtf8("background-color: rgb(74, 74, 74);\n"
"color: rgb(255, 85, 0);\n"
" "));

        horizontalLayout_35->addWidget(label_27);

        write_delay = new QSpinBox(layoutWidget1);
        write_delay->setObjectName(QString::fromUtf8("write_delay"));
        write_delay->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
""));

        horizontalLayout_35->addWidget(write_delay);


        gridLayout_4->addLayout(horizontalLayout_35, 6, 0, 1, 1);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setSpacing(6);
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        label_9 = new QLabel(layoutWidget1);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setFont(font1);
        label_9->setStyleSheet(QString::fromUtf8("background-color: rgb(74, 74, 74);\n"
"font: 75 8pt \"MS Shell Dlg 2\";\n"
"font: 75 8pt \"MS Shell Dlg 2\";\n"
"color: rgb(255, 85, 0);\n"
" "));

        horizontalLayout_11->addWidget(label_9);

        host_ip = new QLineEdit(layoutWidget1);
        host_ip->setObjectName(QString::fromUtf8("host_ip"));
        host_ip->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
""));

        horizontalLayout_11->addWidget(host_ip);


        gridLayout_4->addLayout(horizontalLayout_11, 0, 0, 1, 1);

        layoutWidget2 = new QWidget(centralWidget);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(290, 320, 191, 58));
        verticalLayout = new QVBoxLayout(layoutWidget2);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        label_7 = new QLabel(layoutWidget2);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setStyleSheet(QString::fromUtf8("background-color: rgb(74, 74, 74);\n"
"color: rgb(255, 85, 0);\n"
" "));

        horizontalLayout_9->addWidget(label_7);

        lcd_packet_sent = new QLCDNumber(layoutWidget2);
        lcd_packet_sent->setObjectName(QString::fromUtf8("lcd_packet_sent"));
        lcd_packet_sent->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 170, 0);\n"
"color: rgb(0, 0, 0);"));

        horizontalLayout_9->addWidget(lcd_packet_sent);


        verticalLayout->addLayout(horizontalLayout_9);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        label_8 = new QLabel(layoutWidget2);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setStyleSheet(QString::fromUtf8("background-color: rgb(74, 74, 74);\n"
"color: rgb(255, 85, 0);\n"
" "));

        horizontalLayout_10->addWidget(label_8);

        lcd_packet_recvd = new QLCDNumber(layoutWidget2);
        lcd_packet_recvd->setObjectName(QString::fromUtf8("lcd_packet_recvd"));
        lcd_packet_recvd->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 170, 0);\n"
"color: rgb(0, 0, 0);"));

        horizontalLayout_10->addWidget(lcd_packet_recvd);


        verticalLayout->addLayout(horizontalLayout_10);

        groupBox_5 = new QGroupBox(centralWidget);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        groupBox_5->setGeometry(QRect(510, 310, 171, 111));
        groupBox_5->setStyleSheet(QString::fromUtf8(" \n"
" \n"
"color: rgb(255, 85, 0);\n"
"border-color: rgb(255, 85, 0);"));
        layoutWidget_2 = new QWidget(groupBox_5);
        layoutWidget_2->setObjectName(QString::fromUtf8("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(10, 20, 151, 22));
        horizontalLayout_13 = new QHBoxLayout(layoutWidget_2);
        horizontalLayout_13->setSpacing(6);
        horizontalLayout_13->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_13->setObjectName(QString::fromUtf8("horizontalLayout_13"));
        horizontalLayout_13->setContentsMargins(0, 0, 0, 0);
        label_10 = new QLabel(layoutWidget_2);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setStyleSheet(QString::fromUtf8("background-color: rgb(74, 74, 74);\n"
"color: rgb(255, 85, 0);\n"
" "));

        horizontalLayout_13->addWidget(label_10);

        eye_d_port = new QSpinBox(layoutWidget_2);
        eye_d_port->setObjectName(QString::fromUtf8("eye_d_port"));
        eye_d_port->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"\n"
"color: rgb(0, 0, 0);"));

        horizontalLayout_13->addWidget(eye_d_port);

        pushButton_3 = new QPushButton(groupBox_5);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(30, 80, 104, 21));
        pushButton_3->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: rgb(255, 85, 0);"));
        layoutWidget_4 = new QWidget(groupBox_5);
        layoutWidget_4->setObjectName(QString::fromUtf8("layoutWidget_4"));
        layoutWidget_4->setGeometry(QRect(10, 50, 151, 22));
        horizontalLayout_15 = new QHBoxLayout(layoutWidget_4);
        horizontalLayout_15->setSpacing(6);
        horizontalLayout_15->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_15->setObjectName(QString::fromUtf8("horizontalLayout_15"));
        horizontalLayout_15->setContentsMargins(0, 0, 0, 0);
        label_12 = new QLabel(layoutWidget_4);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setStyleSheet(QString::fromUtf8("background-color: rgb(74, 74, 74);\n"
"color: rgb(255, 85, 0);\n"
" "));

        horizontalLayout_15->addWidget(label_12);

        eye_d_port_2 = new QSpinBox(layoutWidget_4);
        eye_d_port_2->setObjectName(QString::fromUtf8("eye_d_port_2"));
        eye_d_port_2->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"\n"
"color: rgb(0, 0, 0);"));

        horizontalLayout_15->addWidget(eye_d_port_2);

        groupBox_6 = new QGroupBox(centralWidget);
        groupBox_6->setObjectName(QString::fromUtf8("groupBox_6"));
        groupBox_6->setGeometry(QRect(510, 430, 171, 101));
        groupBox_6->setStyleSheet(QString::fromUtf8(" \n"
" \n"
"color: rgb(255, 85, 0);\n"
"border-color: rgb(255, 85, 0);"));
        layoutWidget_3 = new QWidget(groupBox_6);
        layoutWidget_3->setObjectName(QString::fromUtf8("layoutWidget_3"));
        layoutWidget_3->setGeometry(QRect(10, 30, 151, 22));
        horizontalLayout_14 = new QHBoxLayout(layoutWidget_3);
        horizontalLayout_14->setSpacing(6);
        horizontalLayout_14->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_14->setObjectName(QString::fromUtf8("horizontalLayout_14"));
        horizontalLayout_14->setContentsMargins(0, 0, 0, 0);
        label_11 = new QLabel(layoutWidget_3);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setStyleSheet(QString::fromUtf8("background-color: rgb(74, 74, 74);\n"
"color: rgb(255, 85, 0);\n"
" "));

        horizontalLayout_14->addWidget(label_11);

        scater_plot = new QSpinBox(layoutWidget_3);
        scater_plot->setObjectName(QString::fromUtf8("scater_plot"));
        scater_plot->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"\n"
"color: rgb(0, 0, 0);"));

        horizontalLayout_14->addWidget(scater_plot);

        pushButton_4 = new QPushButton(groupBox_6);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(30, 60, 104, 21));
        pushButton_4->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: rgb(255, 85, 0);"));
        groupBox_3 = new QGroupBox(centralWidget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(690, 430, 171, 101));
        groupBox_3->setStyleSheet(QString::fromUtf8(" \n"
" \n"
"color: rgb(255, 85, 0);\n"
"border-color: rgb(255, 85, 0);"));
        BPSK = new QRadioButton(groupBox_3);
        BPSK->setObjectName(QString::fromUtf8("BPSK"));
        BPSK->setGeometry(QRect(10, 35, 61, 31));
        BPSK->setStyleSheet(QString::fromUtf8("background-color: rgb(74, 74, 74);\n"
"selection-color: rgb(255, 64, 172);\n"
"color: rgb(255, 85, 0);\n"
" "));
        QPSK = new QRadioButton(groupBox_3);
        QPSK->setObjectName(QString::fromUtf8("QPSK"));
        QPSK->setGeometry(QRect(89, 35, 61, 31));
        QPSK->setStyleSheet(QString::fromUtf8("background-color: rgb(74, 74, 74);\n"
"color: rgb(255, 85, 0);\n"
" "));
        groupBox_7 = new QGroupBox(centralWidget);
        groupBox_7->setObjectName(QString::fromUtf8("groupBox_7"));
        groupBox_7->setGeometry(QRect(690, 310, 171, 111));
        groupBox_7->setStyleSheet(QString::fromUtf8(" \n"
" \n"
"color: rgb(255, 85, 0);\n"
"border-color: rgb(255, 85, 0);"));
        layoutWidget_5 = new QWidget(groupBox_7);
        layoutWidget_5->setObjectName(QString::fromUtf8("layoutWidget_5"));
        layoutWidget_5->setGeometry(QRect(10, 30, 151, 22));
        horizontalLayout_16 = new QHBoxLayout(layoutWidget_5);
        horizontalLayout_16->setSpacing(6);
        horizontalLayout_16->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_16->setObjectName(QString::fromUtf8("horizontalLayout_16"));
        horizontalLayout_16->setContentsMargins(0, 0, 0, 0);
        label_13 = new QLabel(layoutWidget_5);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setStyleSheet(QString::fromUtf8("background-color: rgb(74, 74, 74);\n"
"color: rgb(255, 85, 0);\n"
" "));

        horizontalLayout_16->addWidget(label_13);

        time_domain_port = new QSpinBox(layoutWidget_5);
        time_domain_port->setObjectName(QString::fromUtf8("time_domain_port"));
        time_domain_port->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"\n"
"color: rgb(0, 0, 0);"));

        horizontalLayout_16->addWidget(time_domain_port);

        timedomain = new QPushButton(groupBox_7);
        timedomain->setObjectName(QString::fromUtf8("timedomain"));
        timedomain->setGeometry(QRect(30, 60, 104, 21));
        timedomain->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: rgb(255, 85, 0);"));
        MainWindow->setCentralWidget(centralWidget);
        pushButton->raise();
        soket_init->raise();
        reset->raise();
        ply_pause->raise();
        layoutWidget->raise();
        layoutWidget->raise();
        layoutWidget->raise();
        groupBox_5->raise();
        groupBox_6->raise();
        groupBox_3->raise();
        groupBox_7->raise();
        progressBar->raise();
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 783, 21));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        //MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
    //    pushButton->setText(QApplication::translate("MainWindow", "SEND", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_WHATSTHIS
        soket_init->setWhatsThis(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:600; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">press to init network</p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        soket_init->setText(QApplication::translate("MainWindow", "CONNECT", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_WHATSTHIS
        reset->setWhatsThis(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:600; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">press to init network</p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        reset->setText(QApplication::translate("MainWindow", "RESET", 0, QApplication::UnicodeUTF8));
        ply_pause->setText(QApplication::translate("MainWindow", "PAUSE", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("MainWindow", "TRAINING SYMBOLS", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", " Training Sym ", 0, QApplication::UnicodeUTF8));
        training_sym_radio_file->setText(QApplication::translate("MainWindow", " FILE", 0, QApplication::UnicodeUTF8));
        training_sym_radio_text->setText(QApplication::translate("MainWindow", "  TEXTBOX", 0, QApplication::UnicodeUTF8));
        training_sym->setPlainText(QApplication::translate("MainWindow", "Hello world!", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "DATA SYMBOLS", 0, QApplication::UnicodeUTF8));
        data_sym_radio_file->setText(QApplication::translate("MainWindow", " FILE", 0, QApplication::UnicodeUTF8));
        data_sym_radio_textbox->setText(QApplication::translate("MainWindow", "  TEXTBOX", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MainWindow", " Data Sym    ", 0, QApplication::UnicodeUTF8));
        groupBox_4->setTitle(QApplication::translate("MainWindow", "OUTPUT", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", " SDR IP                            ", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("MainWindow", " SEND  PORT  ", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("MainWindow", " RECEIVE PORT", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("MainWindow", " PACKET SIZE     ", 0, QApplication::UnicodeUTF8));
        label_25->setText(QApplication::translate("MainWindow", " ITERATIONS", 0, QApplication::UnicodeUTF8));
        label_27->setText(QApplication::translate("MainWindow", " WRITE DELAY", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("MainWindow", " HOST IP                          ", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("MainWindow", "               SENT", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("MainWindow", "        RECEVED", 0, QApplication::UnicodeUTF8));
        groupBox_5->setTitle(QApplication::translate("MainWindow", "EYE DIAGRAM PARM", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("MainWindow", " I PORT ", 0, QApplication::UnicodeUTF8));
        pushButton_3->setText(QApplication::translate("MainWindow", "EYE DIAGRAM", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("MainWindow", " Q PORT ", 0, QApplication::UnicodeUTF8));
        groupBox_6->setTitle(QApplication::translate("MainWindow", " SCATTER PLOT", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("MainWindow", " PORT", 0, QApplication::UnicodeUTF8));
        pushButton_4->setText(QApplication::translate("MainWindow", "SCATTER PLOT", 0, QApplication::UnicodeUTF8));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "MODULATION  ", 0, QApplication::UnicodeUTF8));
        BPSK->setText(QApplication::translate("MainWindow", "BPSK", 0, QApplication::UnicodeUTF8));
        QPSK->setText(QApplication::translate("MainWindow", "QPSK", 0, QApplication::UnicodeUTF8));
        groupBox_7->setTitle(QApplication::translate("MainWindow", "TimeDomain", 0, QApplication::UnicodeUTF8));
        label_13->setText(QApplication::translate("MainWindow", " PORT", 0, QApplication::UnicodeUTF8));
        timedomain->setText(QApplication::translate("MainWindow", "TimeDomain", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
