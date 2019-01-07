#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QListView>

#include "training.h"
#include "calendar.h"
#include "teaminfo.h"
#include "preparation.h"
#include "League.h"
#include "User.h"

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

public slots:
    void refresh();

private slots:
    void on_pushButton_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_5_clicked();

private:
    Ui::MainWindow *ui;
    Calendar *calendar = new Calendar;
    Training *training = new Training;
    TeamInfo *teaminfo = new TeamInfo;
    Preparation *preparation = new Preparation;
};

#endif // MAINWINDOW_H
