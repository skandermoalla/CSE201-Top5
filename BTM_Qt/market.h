#ifndef MARKET_H
#define MARKET_H

#include <QDialog>

namespace Ui {
class Market;
}

class Market : public QDialog
{
    Q_OBJECT

public:
    explicit Market(QWidget *parent = nullptr);
    ~Market();

private:
    Ui::Market *ui;
};

#endif // MARKET_H
