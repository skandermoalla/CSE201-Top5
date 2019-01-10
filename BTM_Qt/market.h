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

private:
    Ui::Market *ui;

signals:
    void backButtonClicked();

private slots:
    void on_pushButton_13_clicked();
};

#endif // MARKET_H
