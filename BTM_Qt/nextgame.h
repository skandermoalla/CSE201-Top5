#ifndef NEXTGAME_H
#define NEXTGAME_H
#include <QLCDNumber>
#include <QDialog>
#include<QTimer>
#include <User.h>
#include <League.h>
namespace Ui {
class NextGame;
}

class NextGame : public QDialog
{
    Q_OBJECT

public:
    explicit NextGame(QWidget *parent = nullptr);
    explicit NextGame(User& theuser, League& league, QWidget *parent = nullptr);
    ~NextGame();
public slots:
    void myfunc();//function that set and display the time
private slots:
    void on_start_clicked(); //click start function

private:
    Ui::NextGame *ui;
    QTimer *timer;
    User* myuser;
    League* myleague;
};

#endif // NEXTGAME_H
