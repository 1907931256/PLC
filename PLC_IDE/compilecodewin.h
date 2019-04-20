#ifndef COMPILECODEWIN_H
#define COMPILECODEWIN_H

#include <QWidget>

namespace Ui {
class compileCodeWin;
}

class compileCodeWin : public QWidget
{
    Q_OBJECT

public:
    explicit compileCodeWin(QWidget *parent = 0);
    void showCompileCode(QString text);//显示设置输出编译后的代码
    ~compileCodeWin();

private:
    Ui::compileCodeWin *ui;
};

#endif // COMPILECODEWIN_H
