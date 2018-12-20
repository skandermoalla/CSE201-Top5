/********************************************************************************
** Form generated from reading UI file 'preparation.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PREPARATION_H
#define UI_PREPARATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_Preparation
{
public:

    void setupUi(QDialog *Preparation)
    {
        if (Preparation->objectName().isEmpty())
            Preparation->setObjectName(QStringLiteral("Preparation"));
        Preparation->resize(667, 471);

        retranslateUi(Preparation);

        QMetaObject::connectSlotsByName(Preparation);
    } // setupUi

    void retranslateUi(QDialog *Preparation)
    {
        Preparation->setWindowTitle(QApplication::translate("Preparation", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Preparation: public Ui_Preparation {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PREPARATION_H
