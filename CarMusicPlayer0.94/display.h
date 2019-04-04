#ifndef DISPLAY_H
#define DISPLAY_H

#include <QMainWindow>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <QTimer>
#include <QString>

namespace Ui {
class display;
}

class display : public QMainWindow
{
    Q_OBJECT

public:
    explicit display(QWidget *parent = 0);
    ~display();
    void dht11_init();

    QTimer *qtimer;
    float light;

private slots:
    void on_pushButton_clicked();
    void data();

private:
    Ui::display *ui;
};

#endif // DISPLAY_H
