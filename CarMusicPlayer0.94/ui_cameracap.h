/********************************************************************************
** Form generated from reading UI file 'cameracap.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CAMERACAP_H
#define UI_CAMERACAP_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_cameracap
{
public:

    void setupUi(QWidget *cameracap)
    {
        if (cameracap->objectName().isEmpty())
            cameracap->setObjectName(QStringLiteral("cameracap"));
        cameracap->resize(1280, 800);
        cameracap->setStyleSheet(QStringLiteral(""));

        retranslateUi(cameracap);

        QMetaObject::connectSlotsByName(cameracap);
    } // setupUi

    void retranslateUi(QWidget *cameracap)
    {
        cameracap->setWindowTitle(QApplication::translate("cameracap", "Form", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class cameracap: public Ui_cameracap {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CAMERACAP_H
