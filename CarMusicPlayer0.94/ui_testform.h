/********************************************************************************
** Form generated from reading UI file 'testform.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TESTFORM_H
#define UI_TESTFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_testform
{
public:
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_4;
    QLineEdit *lineEdit_5;
    QPushButton *pushButton;

    void setupUi(QWidget *testform)
    {
        if (testform->objectName().isEmpty())
            testform->setObjectName(QStringLiteral("testform"));
        testform->resize(400, 300);
        lineEdit = new QLineEdit(testform);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(80, 40, 113, 21));
        lineEdit_2 = new QLineEdit(testform);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(80, 90, 113, 21));
        lineEdit_3 = new QLineEdit(testform);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(80, 140, 113, 21));
        lineEdit_4 = new QLineEdit(testform);
        lineEdit_4->setObjectName(QStringLiteral("lineEdit_4"));
        lineEdit_4->setGeometry(QRect(80, 190, 113, 21));
        lineEdit_5 = new QLineEdit(testform);
        lineEdit_5->setObjectName(QStringLiteral("lineEdit_5"));
        lineEdit_5->setGeometry(QRect(80, 230, 113, 21));
        pushButton = new QPushButton(testform);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(280, 260, 93, 28));

        retranslateUi(testform);

        QMetaObject::connectSlotsByName(testform);
    } // setupUi

    void retranslateUi(QWidget *testform)
    {
        testform->setWindowTitle(QApplication::translate("testform", "Form", Q_NULLPTR));
        pushButton->setText(QApplication::translate("testform", "return", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class testform: public Ui_testform {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TESTFORM_H
