#ifndef MARKET_H
#define MARKET_H

#include <QDialog>
#include "User.h"
#include "League.h"
namespace Ui {
class Market;
}

class Market : public QDialog
{
    Q_OBJECT

public:
    explicit Market(QWidget *parent = nullptr);
    explicit Market(User& theuser, League& theleague, QWidget *parent = nullptr);
    ~Market();
    User* myuser;
    League* myleague;
private:
    Ui::Market *ui;

signals:
    //void backButtonClicked();
    void backButtonClicked(const User&);

private slots:
    void on_pushButton_13_clicked();
};

#endif // MARKET_H
