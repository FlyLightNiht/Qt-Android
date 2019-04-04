/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLabel *label_9;
    QPushButton *set_button;
    QLabel *label_3;
    QLabel *label_8;
    QLabel *label_2;
    QLabel *label_14;
    QPushButton *video_button;
    QPushButton *media_player_button;
    QPushButton *data_button;
    QLabel *label;
    QLabel *label_4;
    QLabel *label_warningT;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1280, 800);
        MainWindow->setStyleSheet(QStringLiteral(""));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        label_9 = new QLabel(centralWidget);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(640, 240, 491, 90));
        label_9->setStyleSheet(QString::fromUtf8("font: 75 italic 36pt \"Lucida Handwriting\";\n"
"border-image: url(:/new/prefix1/alpha.png);\n"
"font: 36pt \"\345\215\216\346\226\207\346\245\267\344\275\223\";"));
        label_9->setAlignment(Qt::AlignCenter);
        set_button = new QPushButton(centralWidget);
        set_button->setObjectName(QStringLiteral("set_button"));
        set_button->setGeometry(QRect(100, 540, 141, 121));
        set_button->setStyleSheet(QStringLiteral("border-image: url(:/new/prefix1/no.png);"));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(170, 320, 281, 81));
        QFont font;
        font.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font.setPointSize(20);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        label_3->setFont(font);
        label_3->setStyleSheet(QString::fromUtf8("font: 20pt \"\351\273\221\344\275\223\";"));
        label_3->setAlignment(Qt::AlignCenter);
        label_8 = new QLabel(centralWidget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(1060, 10, 71, 41));
        label_8->setStyleSheet(QStringLiteral("border-image: url(:/new/prefix1/wifi.png);"));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(180, 210, 261, 101));
        label_2->setFont(font);
        label_2->setStyleSheet(QString::fromUtf8("font: 20pt \"\351\273\221\344\275\223\";"));
        label_2->setAlignment(Qt::AlignCenter);
        label_14 = new QLabel(centralWidget);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(1120, 10, 81, 41));
        label_14->setStyleSheet(QStringLiteral("border-image: url(:/new/prefix1/oil.png);"));
        video_button = new QPushButton(centralWidget);
        video_button->setObjectName(QStringLiteral("video_button"));
        video_button->setGeometry(QRect(1010, 550, 141, 121));
        video_button->setStyleSheet(QStringLiteral("border-image: url(:/new/prefix1/no.png);"));
        media_player_button = new QPushButton(centralWidget);
        media_player_button->setObjectName(QStringLiteral("media_player_button"));
        media_player_button->setGeometry(QRect(790, 550, 141, 121));
        media_player_button->setStyleSheet(QStringLiteral("border-image: url(:/new/prefix1/no.png);"));
        data_button = new QPushButton(centralWidget);
        data_button->setObjectName(QStringLiteral("data_button"));
        data_button->setGeometry(QRect(320, 540, 141, 121));
        data_button->setStyleSheet(QStringLiteral("border-image: url(:/new/prefix1/no.png);"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(-30, 0, 1311, 771));
        label->setStyleSheet(QStringLiteral("border-image: url(:/new/prefix1/num3.png);"));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(1160, 0, 111, 61));
        QFont font1;
        font1.setPointSize(26);
        label_4->setFont(font1);
        label_4->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        label_4->setAlignment(Qt::AlignCenter);
        label_warningT = new QLabel(centralWidget);
        label_warningT->setObjectName(QStringLiteral("label_warningT"));
        label_warningT->setGeometry(QRect(60, 10, 61, 41));
        label_warningT->setStyleSheet(QStringLiteral(""));
        MainWindow->setCentralWidget(centralWidget);
        label->raise();
        media_player_button->raise();
        label_9->raise();
        set_button->raise();
        label_3->raise();
        label_8->raise();
        label_2->raise();
        label_14->raise();
        video_button->raise();
        data_button->raise();
        label_4->raise();
        label_warningT->raise();
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1280, 23));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        label_9->setText(QString());
        set_button->setText(QString());
        label_3->setText(QApplication::translate("MainWindow", "TextLabel", Q_NULLPTR));
        label_8->setText(QString());
        label_2->setText(QApplication::translate("MainWindow", "TextLabel", Q_NULLPTR));
        label_14->setText(QString());
        video_button->setText(QString());
        media_player_button->setText(QString());
        data_button->setText(QString());
        label->setText(QString());
        label_4->setText(QApplication::translate("MainWindow", "10%", Q_NULLPTR));
        label_warningT->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
