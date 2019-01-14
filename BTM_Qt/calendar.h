#ifndef CALENDAR_H
#define CALENDAR_H

#include <QDialog>
#include "User.h"
#include "League.h"

namespace Ui {
class Calendar;
}

class Calendar : public QDialog
{
    Q_OBJECT

public:
    explicit Calendar(QWidget *parent = nullptr);
    explicit Calendar(User& myuser, League& myleague , QWidget *parent = nullptr);
    ~Calendar();
    User* theuser;
    League* theleague;
signals:
    //void backButtonClicked();
    void backButtonClicked(const User&);


private slots:
    void on_pushButton_clicked();

private:
    Ui::Calendar *ui;
};

#endif // CALENDAR_H
