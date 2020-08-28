#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();
 private slots:

    void __slot_get_error_msg(char  *pmsg);
private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H
