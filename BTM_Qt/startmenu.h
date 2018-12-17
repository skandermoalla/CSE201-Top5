#ifndef STARTMENU_H
#define STARTMENU_H
#include "teaminfo.h"
//#include "gameplayer.h"
#include <QDialog>
#include"mainwindow.h"

namespace Ui {
class StartMenu;
}

class StartMenu : public QDialog
{
    Q_OBJECT

public:
    explicit StartMenu(QWidget *parent = nullptr);
    ~StartMenu();

private slots:
    void on_Next_clicked();

private:
    Ui::StartMenu *ui;
    TeamInfo *teaminfo;
    MainWindow *mainwindow = new MainWindow;
};

#endif // STARTMENU_H
