#include "dialog.h"
#include "ui_dialog.h"
#include "mainwindow.h"
Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    setWindowTitle("erro msg");
    ui->lable_error_msg->setText(" ");
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::__slot_get_error_msg(char *pmsg)
{
ui->lable_error_msg->setText(pmsg);

}
