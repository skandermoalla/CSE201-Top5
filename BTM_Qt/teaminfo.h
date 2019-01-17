#ifndef TEAMINFO_H
#define TEAMINFO_H
#include <QDialog>
#include "User.h"
#include "League.h"


namespace Ui {
class TeamInfo;
}

class TeamInfo : public QDialog
{
    Q_OBJECT

public:
    explicit TeamInfo(QWidget *parent = nullptr);
    explicit TeamInfo(User& theuser, League& A, QWidget *parent = nullptr);
    ~TeamInfo();

signals:
    void backButtonClicked();

private slots:
    void on_pushButton_clicked();

private:
    Ui::TeamInfo *ui;
    User* myuser;
    League* myleague;

};

#endif // TEAMINFO_H
