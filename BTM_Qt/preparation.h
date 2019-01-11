#ifndef PREPARATION_H
#define PREPARATION_H

#include <QDialog>
#include"User.h"
#include"League.h"
#include"nextgame.h"

namespace Ui {
class Preparation;
}

class Preparation : public QDialog
{
    Q_OBJECT

public:
    explicit Preparation(QWidget *parent = nullptr);
    explicit Preparation(User& theuser,League& league, QWidget *parent = nullptr);
    User* myuser;
    League* myleague;
    ~Preparation();

signals:
    void backButtonClicked();

public slots:

private slots:
    void on_pushButton_15_clicked();

    void on_pushButton_14_clicked();

private:
    Ui::Preparation *ui;
    NextGame *nextgame;
};

#endif // PREPARATION_H
