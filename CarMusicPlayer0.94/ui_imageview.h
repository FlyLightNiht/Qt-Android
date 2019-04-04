/********************************************************************************
** Form generated from reading UI file 'imageview.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IMAGEVIEW_H
#define UI_IMAGEVIEW_H

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
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_imageview
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton_7;
    QPushButton *pushButton_5;
    QPushButton *pushButton_3;
    QLabel *label;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_4;
    QPushButton *pushButton_6;
    QPushButton *pushButton_8;
    QLabel *label_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *imageview)
    {
        if (imageview->objectName().isEmpty())
            imageview->setObjectName(QStringLiteral("imageview"));
        imageview->resize(1280, 800);
        centralwidget = new QWidget(imageview);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        pushButton_7 = new QPushButton(centralwidget);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));
        pushButton_7->setGeometry(QRect(990, 50, 80, 80));
        pushButton_7->setStyleSheet(QStringLiteral("border-image: url(:/new/prefix1/smaller.png);"));
        pushButton_5 = new QPushButton(centralwidget);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setGeometry(QRect(740, 50, 80, 80));
        pushButton_5->setStyleSheet(QStringLiteral("border-image: url(:/new/prefix1/vert2.png);"));
        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(350, 50, 80, 80));
        pushButton_3->setStyleSheet(QStringLiteral("border-image: url(:/new/prefix1/nextone.png);"));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(120, 160, 991, 561));
        label->setMaximumSize(QSize(16777215, 16777215));
        label->setStyleSheet(QStringLiteral(""));
        label->setScaledContents(true);
        label->setWordWrap(false);
        label->setOpenExternalLinks(true);
        label->setTextInteractionFlags(Qt::LinksAccessibleByMouse);
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(210, 50, 80, 80));
        pushButton->setStyleSheet(QStringLiteral("border-image: url(:/new/prefix1/closeimage.png);"));
        pushButton->setAutoDefault(false);
        pushButton->setFlat(false);
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(490, 50, 80, 80));
        pushButton_2->setStyleSheet(QStringLiteral("border-image: url(:/new/prefix1/former.png);"));
        pushButton_4 = new QPushButton(centralwidget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(620, 50, 80, 80));
        pushButton_4->setStyleSheet(QStringLiteral("border-image: url(:/new/prefix1/vert1.png);"));
        pushButton_6 = new QPushButton(centralwidget);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setGeometry(QRect(860, 50, 80, 80));
        pushButton_6->setStyleSheet(QStringLiteral("border-image: url(:/new/prefix1/bigger.png);"));
        pushButton_8 = new QPushButton(centralwidget);
        pushButton_8->setObjectName(QStringLiteral("pushButton_8"));
        pushButton_8->setGeometry(QRect(80, 50, 80, 80));
        pushButton_8->setStyleSheet(QStringLiteral("border-image: url(:/new/prefix1/open.png);"));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(0, 0, 1271, 761));
        label_2->setStyleSheet(QStringLiteral("border-image: url(:/new/prefix1/backgrd.png);"));
        imageview->setCentralWidget(centralwidget);
        label_2->raise();
        pushButton_7->raise();
        pushButton_5->raise();
        pushButton_3->raise();
        label->raise();
        pushButton->raise();
        pushButton_2->raise();
        pushButton_4->raise();
        pushButton_6->raise();
        pushButton_8->raise();
        menubar = new QMenuBar(imageview);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1280, 26));
        imageview->setMenuBar(menubar);
        statusbar = new QStatusBar(imageview);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        imageview->setStatusBar(statusbar);

        retranslateUi(imageview);

        QMetaObject::connectSlotsByName(imageview);
    } // setupUi

    void retranslateUi(QMainWindow *imageview)
    {
        imageview->setWindowTitle(QApplication::translate("imageview", "MainWindow", Q_NULLPTR));
        pushButton_7->setText(QString());
        pushButton_5->setText(QString());
        pushButton_3->setText(QString());
        label->setText(QString());
        pushButton->setText(QString());
        pushButton_2->setText(QString());
        pushButton_4->setText(QString());
        pushButton_6->setText(QString());
        pushButton_8->setText(QString());
        label_2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class imageview: public Ui_imageview {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IMAGEVIEW_H
