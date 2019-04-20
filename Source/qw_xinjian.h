#ifndef QW_XINJIAN_H
#define QW_XINJIAN_H

#include <QWidget>

namespace Ui {
class QW_xinJian;
}

class QW_xinJian : public QWidget
{
    Q_OBJECT

public:
    explicit QW_xinJian(QWidget *parent = 0);
    ~QW_xinJian();

private:
    Ui::QW_xinJian *ui;
};

#endif // QW_XINJIAN_H
