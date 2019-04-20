#ifndef SETUP_WIDGET_H
#define SETUP_WIDGET_H

#include <QWidget>
#include<QString>
#include<QProcess>
#include<QMessageBox>

namespace Ui {
class setup_widget;
}

class setup_widget : public QWidget
{
    Q_OBJECT

public:
    explicit setup_widget(QWidget *parent = 0);
    ~setup_widget();
    bool com_read();//通过cmd读取串口信息
    void com_set();//设置串口
    QString com();//返回选中的串口字符串
private:
    Ui::setup_widget *ui;
};

#endif // SETUP_WIDGET_H
