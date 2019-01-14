#ifndef TACTICS_H
#define TACTICS_H

#include <QDialog>

namespace Ui {
class Tactics;
}

class Tactics : public QDialog
{
    Q_OBJECT

public:
    explicit Tactics(QWidget *parent = nullptr);
    ~Tactics();

private:
    Ui::Tactics *ui;
};

#endif // TACTICS_H
