#ifndef SETTHRESHOLD_H
#define SETTHRESHOLD_H

#include <QWidget>
#include <QSettings>
namespace Ui {
class setthreshold;
}

class setthreshold : public QWidget
{
    Q_OBJECT

public:
    explicit setthreshold(QWidget *parent = 0);
    ~setthreshold();

private slots:
    void on_pushButton_2_clicked();
    void buttonNumslot(int bn);



    void on_pushButton_x_clicked();

    void on_pushButton_clear_clicked();


    void on_pushButton_clicked();

private:
    Ui::setthreshold *ui;
    QSettings* m_IniFile;

};

#endif // SETTHRESHOLD_H
