/********************************************************************************
** Form generated from reading UI file 'calendar.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CALENDAR_H
#define UI_CALENDAR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Calendar
{
public:
    QGridLayout *gridLayout;
    QPushButton *pushButton;
    QTabWidget *tabWidget;
    QWidget *tab;
    QWidget *tab_2;
    QCalendarWidget *calendarWidget;

    void setupUi(QDialog *Calendar)
    {
        if (Calendar->objectName().isEmpty())
            Calendar->setObjectName(QStringLiteral("Calendar"));
        Calendar->resize(659, 466);
        gridLayout = new QGridLayout(Calendar);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        pushButton = new QPushButton(Calendar);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        gridLayout->addWidget(pushButton, 1, 1, 1, 1);

        tabWidget = new QTabWidget(Calendar);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        tabWidget->addTab(tab_2, QString());

        gridLayout->addWidget(tabWidget, 0, 1, 1, 1);

        calendarWidget = new QCalendarWidget(Calendar);
        calendarWidget->setObjectName(QStringLiteral("calendarWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(1);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(calendarWidget->sizePolicy().hasHeightForWidth());
        calendarWidget->setSizePolicy(sizePolicy);

        gridLayout->addWidget(calendarWidget, 0, 0, 2, 1);


        retranslateUi(Calendar);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Calendar);
    } // setupUi

    void retranslateUi(QDialog *Calendar)
    {
        Calendar->setWindowTitle(QApplication::translate("Calendar", "Dialog", nullptr));
        pushButton->setText(QApplication::translate("Calendar", "Back", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("Calendar", "Tab 1", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("Calendar", "Tab 2", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Calendar: public Ui_Calendar {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CALENDAR_H
