/********************************************************************************
** Form generated from reading UI file 'startmenu.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STARTMENU_H
#define UI_STARTMENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_StartMenu
{
public:
    QTextEdit *textEdit;
    QPushButton *Next;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *name;
    QLabel *team;
    QLabel *nationality;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *nameInput;
    QLineEdit *teamInput;
    QLineEdit *nationalityInput;

    void setupUi(QDialog *StartMenu)
    {
        if (StartMenu->objectName().isEmpty())
            StartMenu->setObjectName(QStringLiteral("StartMenu"));
        StartMenu->resize(400, 300);
        textEdit = new QTextEdit(StartMenu);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(40, 180, 141, 111));
        Next = new QPushButton(StartMenu);
        Next->setObjectName(QStringLiteral("Next"));
        Next->setGeometry(QRect(280, 240, 93, 28));
        widget = new QWidget(StartMenu);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(34, 23, 321, 121));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        name = new QLabel(widget);
        name->setObjectName(QStringLiteral("name"));

        verticalLayout->addWidget(name);

        team = new QLabel(widget);
        team->setObjectName(QStringLiteral("team"));

        verticalLayout->addWidget(team);

        nationality = new QLabel(widget);
        nationality->setObjectName(QStringLiteral("nationality"));

        verticalLayout->addWidget(nationality);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        nameInput = new QLineEdit(widget);
        nameInput->setObjectName(QStringLiteral("nameInput"));

        verticalLayout_2->addWidget(nameInput);

        teamInput = new QLineEdit(widget);
        teamInput->setObjectName(QStringLiteral("teamInput"));

        verticalLayout_2->addWidget(teamInput);

        nationalityInput = new QLineEdit(widget);
        nationalityInput->setObjectName(QStringLiteral("nationalityInput"));

        verticalLayout_2->addWidget(nationalityInput);


        horizontalLayout->addLayout(verticalLayout_2);


        retranslateUi(StartMenu);

        QMetaObject::connectSlotsByName(StartMenu);
    } // setupUi

    void retranslateUi(QDialog *StartMenu)
    {
        StartMenu->setWindowTitle(QApplication::translate("StartMenu", "Dialog", nullptr));
        textEdit->setHtml(QApplication::translate("StartMenu", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:7.8pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">I will put a note here</p></body></html>", nullptr));
        Next->setText(QApplication::translate("StartMenu", "Next", nullptr));
        name->setText(QApplication::translate("StartMenu", "Your name", nullptr));
        team->setText(QApplication::translate("StartMenu", "Your team's name", nullptr));
        nationality->setText(QApplication::translate("StartMenu", "Nationality", nullptr));
    } // retranslateUi

};

namespace Ui {
    class StartMenu: public Ui_StartMenu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STARTMENU_H
