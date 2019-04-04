#ifndef TESTFORM_H
#define TESTFORM_H

#include <QWidget>
#include <QSettings>

namespace Ui {
class testform;
}

class testform : public QWidget
{
    Q_OBJECT

public:
    explicit testform(QWidget *parent = 0);
    ~testform();

private slots:
    void on_pushButton_clicked();

private:
    Ui::testform *ui;
   QSettings* m_IniFile;
};

#endif // TESTFORM_H
