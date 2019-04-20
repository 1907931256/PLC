#include "setup_widget.h"
#include "ui_setup_widget.h"

setup_widget::setup_widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::setup_widget)
{
    ui->setupUi(this);
    this->setWindowTitle("设置");
    this->setWindowIcon(QIcon(":/imj/setup.png"));
}

setup_widget::~setup_widget()
{
    delete ui;
}

bool setup_widget::com_read()//通过cmd读取串口信息,存在串口返回true
{
    bool ret=false;
    ui->comboBox->clear();
    QString strTemp="";
    QProcess process(this);//调用外部程序的对象
    QStringList arguments;
    arguments <<"/c"<<"mode";
    process.start("cmd.exe",arguments);
    process.waitForStarted();
    process.waitForFinished();
    strTemp = QString::fromLocal8Bit(process.readAllStandardOutput());
    QMessageBox msgBox(this);
    msgBox.setText(strTemp);
    int from=strTemp.length();
    while(1){
        from=strTemp.lastIndexOf(QString("COM"),from-1);
        if(from==-1)
            break;
        ui->comboBox->addItem(strTemp.mid(from).mid(0,4));
        ret=true;
    }
    return ret;
}

void setup_widget::com_set()//设置串口
{

}

QString setup_widget::com()//返回选中的串口字符串
{
    return ui->comboBox->currentText();
}
