/********************************************************************************
** Form generated from reading UI file 'carmusic.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CARMUSIC_H
#define UI_CARMUSIC_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CarMusic
{
public:
    QWidget *centralwidget;
    QLabel *label_4;
    QDockWidget *dockWidget_playlist;
    QWidget *dockWidgetContents;
    QGridLayout *gridLayout_2;
    QTableWidget *tableWidget_playlist;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout_video;
    QPushButton *pushButton_mode;
    QLabel *label_2;
    QLabel *label;
    QSlider *horizontalSlider_volume;
    QSlider *horizontalSlider_process;
    QLabel *label_time;
    QPushButton *pushButton_below;
    QPushButton *pushButton_play;
    QPushButton *pushButton_next;
    QPushButton *pushButton_2;
    QPushButton *pushButton;
    QPushButton *pushButton_return;
    QLabel *label_5;
    QPushButton *pushButton_delete;
    QPushButton *pushButton_deleteal;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_warning;
    QLabel *label_10;

    void setupUi(QMainWindow *CarMusic)
    {
        if (CarMusic->objectName().isEmpty())
            CarMusic->setObjectName(QStringLiteral("CarMusic"));
        CarMusic->resize(1281, 811);
        centralwidget = new QWidget(CarMusic);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(-10, 0, 1301, 801));
        label_4->setStyleSheet(QStringLiteral("border-image: url(:/new/prefix1/backbroad.png);"));
        dockWidget_playlist = new QDockWidget(centralwidget);
        dockWidget_playlist->setObjectName(QStringLiteral("dockWidget_playlist"));
        dockWidget_playlist->setGeometry(QRect(930, 60, 261, 501));
        dockWidget_playlist->setStyleSheet(QStringLiteral("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(0, 0, 0, 255), stop:1 rgba(255, 255, 255, 255));"));
        dockWidgetContents = new QWidget();
        dockWidgetContents->setObjectName(QStringLiteral("dockWidgetContents"));
        gridLayout_2 = new QGridLayout(dockWidgetContents);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        tableWidget_playlist = new QTableWidget(dockWidgetContents);
        if (tableWidget_playlist->columnCount() < 2)
            tableWidget_playlist->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget_playlist->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget_playlist->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        tableWidget_playlist->setObjectName(QStringLiteral("tableWidget_playlist"));
        tableWidget_playlist->setContextMenuPolicy(Qt::CustomContextMenu);
        tableWidget_playlist->setStyleSheet(QStringLiteral(""));
        tableWidget_playlist->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableWidget_playlist->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContentsOnFirstShow);
        tableWidget_playlist->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableWidget_playlist->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableWidget_playlist->setShowGrid(true);
        tableWidget_playlist->setGridStyle(Qt::SolidLine);
        tableWidget_playlist->setWordWrap(false);
        tableWidget_playlist->horizontalHeader()->setCascadingSectionResizes(false);
        tableWidget_playlist->horizontalHeader()->setDefaultSectionSize(70);
        tableWidget_playlist->horizontalHeader()->setProperty("showSortIndicator", QVariant(false));
        tableWidget_playlist->horizontalHeader()->setStretchLastSection(true);
        tableWidget_playlist->verticalHeader()->setCascadingSectionResizes(false);

        gridLayout_2->addWidget(tableWidget_playlist, 0, 1, 1, 1);

        dockWidget_playlist->setWidget(dockWidgetContents);
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(30, 60, 761, 371));
        verticalLayout_video = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout_video->setObjectName(QStringLiteral("verticalLayout_video"));
        verticalLayout_video->setContentsMargins(0, 0, 0, 0);
        pushButton_mode = new QPushButton(centralwidget);
        pushButton_mode->setObjectName(QStringLiteral("pushButton_mode"));
        pushButton_mode->setGeometry(QRect(520, 470, 171, 61));
        pushButton_mode->setStyleSheet(QLatin1String("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(0, 0, 0, 255), stop:1 rgba(255, 255, 255, 255));\n"
"color: rgb(255, 255, 255);"));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(530, 480, 31, 31));
        label_2->setStyleSheet(QStringLiteral("border-image: url(:/new/prefix1/music1.png);"));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(730, 510, 51, 91));
        label->setStyleSheet(QStringLiteral("border-image: url(:/new/prefix1/horn.png);"));
        horizontalSlider_volume = new QSlider(centralwidget);
        horizontalSlider_volume->setObjectName(QStringLiteral("horizontalSlider_volume"));
        horizontalSlider_volume->setGeometry(QRect(790, 510, 100, 31));
        horizontalSlider_volume->setMinimumSize(QSize(100, 0));
        horizontalSlider_volume->setMaximumSize(QSize(100, 16777215));
        horizontalSlider_volume->setMaximum(100);
        horizontalSlider_volume->setOrientation(Qt::Horizontal);
        horizontalSlider_process = new QSlider(centralwidget);
        horizontalSlider_process->setObjectName(QStringLiteral("horizontalSlider_process"));
        horizontalSlider_process->setGeometry(QRect(280, 490, 191, 22));
        horizontalSlider_process->setStyleSheet(QStringLiteral(""));
        horizontalSlider_process->setOrientation(Qt::Horizontal);
        label_time = new QLabel(centralwidget);
        label_time->setObjectName(QStringLiteral("label_time"));
        label_time->setGeometry(QRect(170, 480, 101, 41));
        QFont font;
        font.setPointSize(13);
        label_time->setFont(font);
        label_time->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
""));
        pushButton_below = new QPushButton(centralwidget);
        pushButton_below->setObjectName(QStringLiteral("pushButton_below"));
        pushButton_below->setGeometry(QRect(260, 580, 121, 121));
        pushButton_below->setStyleSheet(QStringLiteral("border-image: url(:/new/prefix1/button2.png);"));
        pushButton_play = new QPushButton(centralwidget);
        pushButton_play->setObjectName(QStringLiteral("pushButton_play"));
        pushButton_play->setGeometry(QRect(440, 570, 151, 151));
        pushButton_play->setStyleSheet(QStringLiteral("border-image: url(:/new/prefix1/musicc1.png);"));
        pushButton_next = new QPushButton(centralwidget);
        pushButton_next->setObjectName(QStringLiteral("pushButton_next"));
        pushButton_next->setGeometry(QRect(650, 580, 121, 121));
        pushButton_next->setStyleSheet(QStringLiteral("border-image: url(:/new/prefix1/button.png);"));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(40, 520, 141, 51));
        pushButton_2->setStyleSheet(QLatin1String("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(0, 0, 0, 255), stop:1 rgba(255, 255, 255, 255));\n"
"color: rgb(255, 255, 255);"));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(40, 590, 141, 51));
        pushButton->setStyleSheet(QLatin1String("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(0, 0, 0, 255), stop:1 rgba(255, 255, 255, 255));\n"
"color: rgb(255, 255, 255);\n"
""));
        pushButton_return = new QPushButton(centralwidget);
        pushButton_return->setObjectName(QStringLiteral("pushButton_return"));
        pushButton_return->setGeometry(QRect(40, 660, 141, 61));
        pushButton_return->setStyleSheet(QLatin1String("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(0, 0, 0, 255), stop:1 rgba(255, 255, 255, 255));\n"
"color: rgb(255, 255, 255);\n"
""));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(930, 50, 281, 521));
        pushButton_delete = new QPushButton(centralwidget);
        pushButton_delete->setObjectName(QStringLiteral("pushButton_delete"));
        pushButton_delete->setGeometry(QRect(1090, 580, 91, 71));
        pushButton_delete->setStyleSheet(QStringLiteral("border-image: url(:/new/prefix1/garbage1.png);"));
        pushButton_deleteal = new QPushButton(centralwidget);
        pushButton_deleteal->setObjectName(QStringLiteral("pushButton_deleteal"));
        pushButton_deleteal->setGeometry(QRect(950, 580, 91, 71));
        pushButton_deleteal->setStyleSheet(QStringLiteral("border-image: url(:/new/prefix1/garbage1.png);"));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(960, 650, 81, 51));
        QFont font1;
        font1.setPointSize(12);
        label_6->setFont(font1);
        label_6->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(1100, 650, 81, 51));
        label_7->setFont(font1);
        label_7->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        label_warning = new QLabel(centralwidget);
        label_warning->setObjectName(QStringLiteral("label_warning"));
        label_warning->setGeometry(QRect(721, 10, 51, 41));
        label_warning->setStyleSheet(QStringLiteral(""));
        label_10 = new QLabel(centralwidget);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(40, 10, 691, 31));
        QFont font2;
        font2.setPointSize(15);
        label_10->setFont(font2);
        label_10->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        CarMusic->setCentralWidget(centralwidget);
        label_4->raise();
        label_5->raise();
        dockWidget_playlist->raise();
        verticalLayoutWidget->raise();
        pushButton_mode->raise();
        label_2->raise();
        label->raise();
        horizontalSlider_volume->raise();
        horizontalSlider_process->raise();
        label_time->raise();
        pushButton_below->raise();
        pushButton_play->raise();
        pushButton_next->raise();
        pushButton_2->raise();
        pushButton->raise();
        pushButton_return->raise();
        pushButton_delete->raise();
        pushButton_deleteal->raise();
        label_6->raise();
        label_7->raise();
        label_warning->raise();
        label_10->raise();

        retranslateUi(CarMusic);

        QMetaObject::connectSlotsByName(CarMusic);
    } // setupUi

    void retranslateUi(QMainWindow *CarMusic)
    {
        CarMusic->setWindowTitle(QApplication::translate("CarMusic", "MainWindow", Q_NULLPTR));
        label_4->setText(QString());
        dockWidget_playlist->setWindowTitle(QApplication::translate("CarMusic", "\346\222\255\346\224\276\345\210\227\350\241\250", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem = tableWidget_playlist->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("CarMusic", "\346\255\214\346\233\262", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget_playlist->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("CarMusic", "\346\227\266\351\227\264", Q_NULLPTR));
        pushButton_mode->setText(QApplication::translate("CarMusic", "\345\215\225\346\233\2621\346\254\241", Q_NULLPTR));
        label_2->setText(QString());
        label->setText(QString());
        label_time->setText(QApplication::translate("CarMusic", "--:--", Q_NULLPTR));
        pushButton_below->setText(QString());
        pushButton_play->setText(QString());
        pushButton_next->setText(QString());
        pushButton_2->setText(QApplication::translate("CarMusic", "\351\200\211\346\213\251\351\237\263\344\271\220", Q_NULLPTR));
        pushButton->setText(QApplication::translate("CarMusic", "\346\222\255\346\224\276\345\210\227\350\241\250", Q_NULLPTR));
        pushButton_return->setText(QApplication::translate("CarMusic", "\350\277\224\345\233\236", Q_NULLPTR));
        label_5->setText(QString());
        pushButton_delete->setText(QString());
        pushButton_deleteal->setText(QString());
        label_6->setText(QApplication::translate("CarMusic", "\346\270\205\347\251\272\345\210\227\350\241\250", Q_NULLPTR));
        label_7->setText(QApplication::translate("CarMusic", "\345\210\240\351\231\244\345\215\225\346\233\262", Q_NULLPTR));
        label_warning->setText(QString());
        label_10->setText(QApplication::translate("CarMusic", "111111", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class CarMusic: public Ui_CarMusic {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CARMUSIC_H
