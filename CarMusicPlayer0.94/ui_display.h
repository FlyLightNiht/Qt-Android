/********************************************************************************
** Form generated from reading UI file 'display.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DISPLAY_H
#define UI_DISPLAY_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_display
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QLabel *label_8;
    QLabel *label_6;
    QLabel *label_7;
    QLineEdit *Kph;
    QLabel *label_4;
    QLabel *label_9;
    QLabel *label_5;
    QPushButton *pushButton;
    QLineEdit *Rev;
    QLineEdit *Temp;
    QLineEdit *Oil;
    QLineEdit *Humi;
    QLineEdit *Light;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_13;

    void setupUi(QMainWindow *display)
    {
        if (display->objectName().isEmpty())
            display->setObjectName(QStringLiteral("display"));
        display->resize(1280, 800);
        centralwidget = new QWidget(display);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, 0, 1281, 811));
        label->setStyleSheet(QStringLiteral("border-image: url(:/new/prefix1/dis_1.png);"));
        label_8 = new QLabel(centralwidget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(1030, 400, 68, 33));
        QFont font;
        font.setFamily(QStringLiteral("Arial"));
        font.setPointSize(20);
        label_8->setFont(font);
        label_8->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(427, 362, 71, 41));
        label_6->setFont(font);
        label_6->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(730, 360, 68, 33));
        label_7->setFont(font);
        label_7->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        Kph = new QLineEdit(centralwidget);
        Kph->setObjectName(QStringLiteral("Kph"));
        Kph->setGeometry(QRect(999, 440, 201, 38));
        Kph->setFont(font);
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(110, 300, 68, 33));
        label_4->setFont(font);
        label_4->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        label_9 = new QLabel(centralwidget);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(1030, 310, 68, 33));
        label_9->setFont(font);
        label_9->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(110, 410, 68, 33));
        label_5->setFont(font);
        label_5->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(1020, 10, 131, 81));
        QFont font1;
        font1.setPointSize(20);
        pushButton->setFont(font1);
        pushButton->setStyleSheet(QStringLiteral("border-image: url(:/new/prefix1/cheliangreturn.png);"));
        Rev = new QLineEdit(centralwidget);
        Rev->setObjectName(QStringLiteral("Rev"));
        Rev->setGeometry(QRect(997, 350, 201, 38));
        Rev->setFont(font);
        Temp = new QLineEdit(centralwidget);
        Temp->setObjectName(QStringLiteral("Temp"));
        Temp->setGeometry(QRect(72, 350, 221, 38));
        Temp->setFont(font);
        Oil = new QLineEdit(centralwidget);
        Oil->setObjectName(QStringLiteral("Oil"));
        Oil->setGeometry(QRect(690, 410, 211, 38));
        Oil->setFont(font);
        Humi = new QLineEdit(centralwidget);
        Humi->setObjectName(QStringLiteral("Humi"));
        Humi->setGeometry(QRect(72, 460, 221, 38));
        Humi->setFont(font);
        Light = new QLineEdit(centralwidget);
        Light->setObjectName(QStringLiteral("Light"));
        Light->setGeometry(QRect(384, 410, 211, 38));
        Light->setFont(font);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(190, 410, 101, 31));
        QFont font2;
        font2.setFamily(QStringLiteral("Arial"));
        font2.setPointSize(15);
        label_2->setFont(font2);
        label_2->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(190, 310, 72, 21));
        label_3->setFont(font2);
        label_3->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        label_10 = new QLabel(centralwidget);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(510, 360, 91, 41));
        label_10->setFont(font2);
        label_10->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        label_11 = new QLabel(centralwidget);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(810, 360, 72, 31));
        label_11->setFont(font2);
        label_11->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        label_12 = new QLabel(centralwidget);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(1100, 300, 101, 51));
        QFont font3;
        font3.setFamily(QStringLiteral("Arial Narrow"));
        font3.setPointSize(11);
        font3.setBold(true);
        font3.setWeight(75);
        label_12->setFont(font3);
        label_12->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        label_13 = new QLabel(centralwidget);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(1100, 410, 72, 21));
        QFont font4;
        font4.setFamily(QStringLiteral("Arial"));
        font4.setPointSize(11);
        label_13->setFont(font4);
        label_13->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        display->setCentralWidget(centralwidget);
        label->raise();
        pushButton->raise();
        Oil->raise();
        Humi->raise();
        Light->raise();
        label_8->raise();
        label_6->raise();
        label_7->raise();
        Kph->raise();
        label_4->raise();
        label_9->raise();
        label_5->raise();
        Rev->raise();
        Temp->raise();
        label_2->raise();
        label_3->raise();
        label_10->raise();
        label_11->raise();
        label_12->raise();
        label_13->raise();

        retranslateUi(display);

        QMetaObject::connectSlotsByName(display);
    } // setupUi

    void retranslateUi(QMainWindow *display)
    {
        display->setWindowTitle(QApplication::translate("display", "MainWindow", Q_NULLPTR));
        label->setText(QString());
        label_8->setText(QApplication::translate("display", "\351\200\237\345\272\246", Q_NULLPTR));
        label_6->setText(QApplication::translate("display", "\345\205\211\347\205\247", Q_NULLPTR));
        label_7->setText(QApplication::translate("display", "\346\262\271\351\207\217", Q_NULLPTR));
        label_4->setText(QApplication::translate("display", "\346\270\251\345\272\246", Q_NULLPTR));
        label_9->setText(QApplication::translate("display", "\350\275\254\351\200\237", Q_NULLPTR));
        label_5->setText(QApplication::translate("display", "\346\271\277\345\272\246", Q_NULLPTR));
        pushButton->setText(QString());
        label_2->setText(QApplication::translate("display", "%rh", Q_NULLPTR));
        label_3->setText(QApplication::translate("display", "\342\204\203", Q_NULLPTR));
        label_10->setText(QApplication::translate("display", "lx", Q_NULLPTR));
        label_11->setText(QApplication::translate("display", "%", Q_NULLPTR));
        label_12->setText(QApplication::translate("display", "1KR/MIN", Q_NULLPTR));
        label_13->setText(QApplication::translate("display", "KM/S", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class display: public Ui_display {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DISPLAY_H
