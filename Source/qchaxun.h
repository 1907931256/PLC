#ifndef QCHAXUN_H
#define QCHAXUN_H

#include <QWidget>

namespace Ui {
class QchaXun;
}

class QchaXun : public QWidget
{
    Q_OBJECT

public:
    explicit QchaXun(QWidget *parent = 0);
    ~QchaXun();

private:
    Ui::QchaXun *ui;
};

#endif // QCHAXUN_H
