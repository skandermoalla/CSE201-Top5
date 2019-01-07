#ifndef TRAINING_H
#define TRAINING_H

#include <QDialog>
#include "League.h"
#include "User.h"

namespace Ui {
class Training;
}

class Training : public QDialog
{
    Q_OBJECT

public:
    explicit Training(QWidget *parent = nullptr);
    explicit Training(User& theuser,League& league, QWidget *parent = nullptr);
    ~Training();

signals:
    void backButtonClicked();

public slots:
    void refresh();

private slots:
    void on_pushButton_5_clicked();

private:
    Ui::Training *ui;
};

#endif // TRAINING_H
