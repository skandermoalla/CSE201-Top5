#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QListView>

#include "data.h"
#include "training.h"
#include "calendar.h"
#include "teaminfo.h"
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

private slots:
    void on_pushButton_clicked();
    void on_pushButton_3_clicked();

    //void MainWindow::on_listView_indexesMoved(const QModelIndexList &indexes);

    void on_pushButton_4_clicked();

private:
    Ui::MainWindow *ui;
    Calendar *calendar = new Calendar;
    Training *training = new Training;
    TeamInfo *teaminfo = new TeamInfo; //= new TeamInfo(GamePLayer );
    //QListView *listView;
};

#endif // MAINWINDOW_H
