#ifndef QOUT_H
#define QOUT_H

#include <QWidget>
#include<QLabel>
#include<QScrollBar>
namespace Ui {
class Qout;
}

class Qout : public QWidget
{
    Q_OBJECT

public:
    explicit Qout(QWidget *parent = 0);
    ~Qout();
    QLabel* label();
    QLabel* label2();
    void setCurrentIndex(int n);

private slots:
    void on_tabWidget_tabBarClicked(int index);

    void on_tabWidget_currentChanged(int index);

private:
    Ui::Qout *ui;
    int jiu=0;//保存tab窗口切换前的窗口号

};
#endif
