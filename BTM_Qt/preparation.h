#ifndef PREPARATION_H
#define PREPARATION_H

#include <QDialog>

namespace Ui {
class Preparation;
}

class Preparation : public QDialog
{
    Q_OBJECT

public:
    explicit Preparation(QWidget *parent = nullptr);
    ~Preparation();

signals:
    void backButtonClicked();

private slots:
    void on_pushButton_15_clicked();

private:
    Ui::Preparation *ui;
};

#endif // PREPARATION_H
