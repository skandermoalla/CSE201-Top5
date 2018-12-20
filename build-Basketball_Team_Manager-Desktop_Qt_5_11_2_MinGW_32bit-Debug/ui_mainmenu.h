/********************************************************************************
** Form generated from reading UI file 'mainmenu.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINMENU_H
#define UI_MAINMENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainMenu
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout_2;
    QGridLayout *gridLayout;
    QPushButton *quit;
    QPushButton *start;
    QPushButton *settings;
    QPushButton *resume;

    void setupUi(QMainWindow *MainMenu)
    {
        if (MainMenu->objectName().isEmpty())
            MainMenu->setObjectName(QStringLiteral("MainMenu"));
        MainMenu->resize(400, 300);
        centralWidget = new QWidget(MainMenu);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayout_2 = new QHBoxLayout(centralWidget);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        quit = new QPushButton(centralWidget);
        quit->setObjectName(QStringLiteral("quit"));

        gridLayout->addWidget(quit, 5, 1, 1, 1);

        start = new QPushButton(centralWidget);
        start->setObjectName(QStringLiteral("start"));

        gridLayout->addWidget(start, 0, 1, 1, 1);

        settings = new QPushButton(centralWidget);
        settings->setObjectName(QStringLiteral("settings"));

        gridLayout->addWidget(settings, 2, 1, 1, 1);

        resume = new QPushButton(centralWidget);
        resume->setObjectName(QStringLiteral("resume"));

        gridLayout->addWidget(resume, 1, 1, 1, 1);


        horizontalLayout_2->addLayout(gridLayout);

        MainMenu->setCentralWidget(centralWidget);

        retranslateUi(MainMenu);

        QMetaObject::connectSlotsByName(MainMenu);
    } // setupUi

    void retranslateUi(QMainWindow *MainMenu)
    {
        MainMenu->setWindowTitle(QApplication::translate("MainMenu", "MainMenu", nullptr));
        quit->setText(QApplication::translate("MainMenu", "Quit", nullptr));
        start->setText(QApplication::translate("MainMenu", "Start", nullptr));
        settings->setText(QApplication::translate("MainMenu", "Settings", nullptr));
        resume->setText(QApplication::translate("MainMenu", "Resume", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainMenu: public Ui_MainMenu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINMENU_H
