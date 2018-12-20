#ifndef TEAMINFO_H
#define TEAMINFO_H
#include <QDialog>
//#include "gameplayer.h"

namespace Ui {
class TeamInfo;
}

class TeamInfo : public QDialog
{
    Q_OBJECT

public:
    explicit TeamInfo(/*GamePLayer gp, */QWidget *parent = nullptr);
    ~TeamInfo();

signals:
    void backButtonClicked();

private slots:
    void on_pushButton_clicked();

private:
    Ui::TeamInfo *ui;
   // GamePLayer gameplayer;
};

#endif // TEAMINFO_H
