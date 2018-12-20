/********************************************************************************
** Form generated from reading UI file 'market.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MARKET_H
#define UI_MARKET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_Market
{
public:

    void setupUi(QDialog *Market)
    {
        if (Market->objectName().isEmpty())
            Market->setObjectName(QString::fromUtf8("Market"));
        Market->resize(400, 300);

        retranslateUi(Market);

        QMetaObject::connectSlotsByName(Market);
    } // setupUi

    void retranslateUi(QDialog *Market)
    {
        Market->setWindowTitle(QApplication::translate("Market", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Market: public Ui_Market {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MARKET_H
