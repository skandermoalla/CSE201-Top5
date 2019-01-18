#ifndef MAINMENU_H
#define MAINMENU_H
#include "startmenu.h"
#include <QMainWindow>

namespace Ui {
class MainMenu;
}

class MainMenu : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainMenu(QWidget *parent = nullptr);
    ~MainMenu();

private slots:
    void on_start_clicked();
    void on_resume_clicked();
    void on_quit_clicked();

private:
    Ui::MainMenu *ui;
    StartMenu *startmenu = new StartMenu();
    MainWindow *mainwindow;
};

#endif // MAINMENU_H
