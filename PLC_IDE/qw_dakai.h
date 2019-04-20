#ifndef QW_DAKAI_H
#define QW_DAKAI_H

#include <QWidget>

namespace Ui {
class QW_daKai;
}

class QW_daKai : public QWidget
{
    Q_OBJECT

public:
    explicit QW_daKai(QWidget *parent = 0);
    ~QW_daKai();

private:
    Ui::QW_daKai *ui;
};

#endif // QW_DAKAI_H
