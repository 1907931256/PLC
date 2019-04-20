#include "qout.h"
#include "ui_qout.h"
#include "QDebug"
Qout::Qout(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Qout)
{
    ui->setupUi(this);
}

Qout::~Qout()
{
    delete ui;
}

QLabel *Qout::label()//返回应用程序输出框中的字符串的指针
{
    ui->scrollArea->verticalScrollBar()->setValue(ui->scrollArea->verticalScrollBar()->maximumHeight());
    return (ui->label);
}

QLabel *Qout::label2()//返回应用程序输出框中的字符串的指针
{
    ui->scrollArea_2->verticalScrollBar()->setValue(ui->scrollArea_2->verticalScrollBar()->maximumHeight());
    return (ui->label_2);
}

void Qout::setCurrentIndex(int n)//设置显示的输出窗口
{
     ui->tabWidget->setCurrentIndex(n);
}

void Qout::on_tabWidget_currentChanged(int index)//通过这个槽函数实现将点击tab窗口变成清楚字符串的按钮
{
    switch(index){
    case 2:
        ui->tabWidget->setCurrentIndex(this->jiu);
        ui->label->setText("");
        break;
    case 3:
        ui->tabWidget->setCurrentIndex(this->jiu);
        ui->label_2->setText("");
        break;
    }
}

void Qout::on_tabWidget_tabBarClicked(int index)//记录tab窗口切换前的窗口，与上面这个函数配合
{
    this->jiu=ui->tabWidget->currentIndex();
}
