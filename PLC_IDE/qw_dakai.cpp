#include "qw_dakai.h"
#include "ui_qw_dakai.h"

QW_daKai::QW_daKai(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::QW_daKai)
{
    ui->setupUi(this);
}

QW_daKai::~QW_daKai()
{
    delete ui;
}
