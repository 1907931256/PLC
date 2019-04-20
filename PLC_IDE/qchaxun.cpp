#include "qchaxun.h"
#include "ui_qchaxun.h"

QchaXun::QchaXun(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::QchaXun)
{
    ui->setupUi(this);
    this->setWindowTitle("查询");
    this->setWindowIcon(QIcon(":/imj/soSuo.png"));
}

QchaXun::~QchaXun()
{
    delete ui;
}
