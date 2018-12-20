/********************************************************************************
** Form generated from reading UI file 'teaminfo.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TEAMINFO_H
#define UI_TEAMINFO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TeamInfo
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *teamn;
    QLabel *coachn;
    QLabel *division;
    QPushButton *pushButton;

    void setupUi(QDialog *TeamInfo)
    {
        if (TeamInfo->objectName().isEmpty())
            TeamInfo->setObjectName(QString::fromUtf8("TeamInfo"));
        TeamInfo->resize(400, 300);
        layoutWidget = new QWidget(TeamInfo);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(100, 30, 191, 71));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        teamn = new QLabel(layoutWidget);
        teamn->setObjectName(QString::fromUtf8("teamn"));

        verticalLayout->addWidget(teamn);

        coachn = new QLabel(layoutWidget);
        coachn->setObjectName(QString::fromUtf8("coachn"));

        verticalLayout->addWidget(coachn);

        division = new QLabel(layoutWidget);
        division->setObjectName(QString::fromUtf8("division"));

        verticalLayout->addWidget(division);

        pushButton = new QPushButton(TeamInfo);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(260, 250, 114, 32));

        retranslateUi(TeamInfo);

        QMetaObject::connectSlotsByName(TeamInfo);
    } // setupUi

    void retranslateUi(QDialog *TeamInfo)
    {
        TeamInfo->setWindowTitle(QApplication::translate("TeamInfo", "Dialog", nullptr));
        teamn->setText(QString());
        coachn->setText(QString());
        division->setText(QString());
        pushButton->setText(QApplication::translate("TeamInfo", "Back", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TeamInfo: public Ui_TeamInfo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEAMINFO_H
