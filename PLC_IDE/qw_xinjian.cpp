#include "qw_xinjian.h"
#include "ui_qw_xinjian.h"

QW_xinJian::QW_xinJian(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::QW_xinJian)
{
    ui->setupUi(this);
}

QW_xinJian::~QW_xinJian()
{
    delete ui;
}
