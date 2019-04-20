#include "compilecodewin.h"
#include "ui_compilecodewin.h"

compileCodeWin::compileCodeWin(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::compileCodeWin)
{
    ui->setupUi(this);
    this->setWindowTitle("生成后的代码");
    this->setWindowIcon(QIcon(":/imj/tuBiao.png"));
    this->layout()->setMargin(1);
}

void compileCodeWin::showCompileCode(QString text)
{
    ui->plainTextEdit->setPlainText(text);
}

compileCodeWin::~compileCodeWin()
{
    delete ui;
}
