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
    void backButtonClicked(const User&);

public slots:
    void refresh(const User& );

private slots:
    void on_pushButton_15_clicked();

    void on_pushButton_14_clicked();

    void on_pushButton_13_clicked();

    void on_p1_clicked();

    void on_p2_clicked();

    void on_p3_clicked();

    void on_p4_clicked();

    void on_p5_clicked();

    void on_p6_clicked();

    void on_p7_clicked();

    void on_p8_clicked();

    void on_p9_clicked();

    void on_p10_clicked();

    void on_p11_clicked();

    void on_p12_clicked();

private:
    Ui::Preparation *ui;
    NextGame *nextgame;
    int chosen_1;
    int chosen_2;
    void Substitution();
};

#endif // PREPARATION_H
