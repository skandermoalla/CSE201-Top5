#ifndef TRAINING_H
#define TRAINING_H
#pragma once
#include <QDialog>
#include "League.h"
#include "User.h"
#include <QLabel>

//#include "mainwindow.h"
namespace Ui {
class Training;
}

class Training : public QDialog
{
    Q_OBJECT

public:
    explicit Training(QWidget *parent = nullptr);
    explicit Training(User& theuser,League& league, QWidget *parent = nullptr);
    explicit Training(User& theuser,League& league, QWidget &parent);
    User* myuser;
    League* myleague;
    ~Training();

signals:
    void backButtonClicked();

private slots:
    void on_pushButton_5_clicked();
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();

private:
    Ui::Training *ui;
};

#endif // TRAINING_H
