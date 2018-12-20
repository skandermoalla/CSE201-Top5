/********************************************************************************
** Form generated from reading UI file 'nextgame.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEXTGAME_H
#define UI_NEXTGAME_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_NextGame
{
public:
    QLabel *quater;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *sub;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *start;
    QListWidget *listWidget;
    QListWidget *listWidget_2;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *away_name;
    QLCDNumber *away_score;
    QLabel *time;
    QVBoxLayout *verticalLayout_2;
    QLabel *away_name_2;
    QLCDNumber *away_score_2;

    void setupUi(QDialog *NextGame)
    {
        if (NextGame->objectName().isEmpty())
            NextGame->setObjectName(QStringLiteral("NextGame"));
        NextGame->resize(933, 604);
        quater = new QLabel(NextGame);
        quater->setObjectName(QStringLiteral("quater"));
        layoutWidget = new QWidget(NextGame);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(210, 520, 495, 30));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        sub = new QPushButton(layoutWidget);
        sub->setObjectName(QStringLiteral("sub"));

        horizontalLayout->addWidget(sub);

        pushButton_2 = new QPushButton(layoutWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        horizontalLayout->addWidget(pushButton_2);

        pushButton_3 = new QPushButton(layoutWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        horizontalLayout->addWidget(pushButton_3);

        pushButton_4 = new QPushButton(layoutWidget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));

        horizontalLayout->addWidget(pushButton_4);

        start = new QPushButton(layoutWidget);
        start->setObjectName(QStringLiteral("start"));

        horizontalLayout->addWidget(start);

        listWidget = new QListWidget(NextGame);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setGeometry(QRect(0, 130, 171, 341));
        listWidget_2 = new QListWidget(NextGame);
        listWidget_2->setObjectName(QStringLiteral("listWidget_2"));
        listWidget_2->setGeometry(QRect(760, 140, 171, 341));
        widget = new QWidget(NextGame);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(230, 0, 471, 131));
        horizontalLayout_2 = new QHBoxLayout(widget);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        away_name = new QLabel(widget);
        away_name->setObjectName(QStringLiteral("away_name"));

        verticalLayout->addWidget(away_name);

        away_score = new QLCDNumber(widget);
        away_score->setObjectName(QStringLiteral("away_score"));

        verticalLayout->addWidget(away_score);


        horizontalLayout_2->addLayout(verticalLayout);

        time = new QLabel(widget);
        time->setObjectName(QStringLiteral("time"));

        horizontalLayout_2->addWidget(time);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        away_name_2 = new QLabel(widget);
        away_name_2->setObjectName(QStringLiteral("away_name_2"));

        verticalLayout_2->addWidget(away_name_2);

        away_score_2 = new QLCDNumber(widget);
        away_score_2->setObjectName(QStringLiteral("away_score_2"));

        verticalLayout_2->addWidget(away_score_2);


        horizontalLayout_2->addLayout(verticalLayout_2);


        retranslateUi(NextGame);

        QMetaObject::connectSlotsByName(NextGame);
    } // setupUi

    void retranslateUi(QDialog *NextGame)
    {
        NextGame->setWindowTitle(QApplication::translate("NextGame", "Dialog", nullptr));
        quater->setText(QApplication::translate("NextGame", "Quater", nullptr));
        sub->setText(QApplication::translate("NextGame", "Substitutions", nullptr));
        pushButton_2->setText(QApplication::translate("NextGame", "PushButton", nullptr));
        pushButton_3->setText(QApplication::translate("NextGame", "PushButton", nullptr));
        pushButton_4->setText(QApplication::translate("NextGame", "PushButton", nullptr));
        start->setText(QApplication::translate("NextGame", "Start ", nullptr));
        away_name->setText(QString());
        time->setText(QApplication::translate("NextGame", "TextLabel", nullptr));
        away_name_2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class NextGame: public Ui_NextGame {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEXTGAME_H
