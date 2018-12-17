#include "mainmenu.h"
#include "ui_mainmenu.h"
#include "startmenu.h"


MainMenu::MainMenu(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainMenu)
{
    ui->setupUi(this);
}

MainMenu::~MainMenu()
{
    delete ui;
}

void MainMenu::on_start_clicked()
{
    this->hide();
    startmenu->show();
}
