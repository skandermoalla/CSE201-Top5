#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QListView>
#pragma once
#include "data.h"
#include "training.h"
#include "calendar.h"
#include "teaminfo.h"
#include "market.h"
#include "League.h"
#include "User.h"
#include "nextgame.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    explicit MainWindow(User& theuser, League& A,QWidget *parent = nullptr);
    ~MainWindow();
    Team team;
    User* myuser;
    League* myleague;

public slots:
    void refresh(const User& );

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

private:
    Ui::MainWindow *ui;
    Calendar *calendar;
    Training *training;
    TeamInfo *teaminfo;
    Market *market;
    NextGame *nextgame;
};

#endif // MAINWINDOW_H
