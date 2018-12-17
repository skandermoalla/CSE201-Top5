#ifndef TRAINING_H
#define TRAINING_H

#include <QDialog>

namespace Ui {
class Training;
}

class Training : public QDialog
{
    Q_OBJECT

public:
    explicit Training(QWidget *parent = nullptr);
    ~Training();

signals:
    void backButtonClicked();

private slots:
    void on_pushButton_5_clicked();

private:
    Ui::Training *ui;
};

#endif // TRAINING_H
