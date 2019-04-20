#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#define SET_COLOUR "break*aa/case*bb/switch*cc/char*/const*/continue*/default*/do*/double*/else*/if*/enum*/float*/for*/goto*/int*/long*/register*/return*/short*/signed*/sizoef*/static*/struct*/typedef*/union*/unsigned*/void*/volatile*/while*/"
#define int_cs2030 {{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}}
#define bool_cs2030 {{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}}
#define null_cs2030 {{NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL},{NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL},{NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL},{NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL},{NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL},{NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL},{NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL},{NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL},{NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL},{NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL},{NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL},{NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL},{NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL},{NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL},{NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL},{NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL},{NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL},{NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL},{NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL},{NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL}}
#define zero1000 {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,}
#define INCLUDE0 "#define ChangKai0 digitalRead(10)\n#define ChangKai1 digitalRead(11)\n#define ChangKai2 digitalRead(12)\n#define ChangKai3 digitalRead(13)\n#define ChangKai4 digitalRead(14)\n#define ChangKai5 digitalRead(15)\n#define ChangKai6 digitalRead(16)\n#define ChangKai7 digitalRead(17)\n"
#define INCLUDE1 "#define ChangBi0 (!digitalRead(10))\n#define ChangBi1 (!digitalRead(11))\n#define ChangBi2 (!digitalRead(12))\n#define ChangBi3 (!digitalRead(13))\n#define ChangBi4 (!digitalRead(14))\n#define ChangBi5 (!digitalRead(15))\n#define ChangBi6 (!digitalRead(16))\n#define ChangBi7 (!digitalRead(17)\n"
#include<QCursor>
#include<QDir>
#include <QMainWindow>
#include <QIcon>
#include<QMenu>
#include<QMessageBox>
#include<QSize>
#include<QPainter>
#include<QPen>
#include<QMouseEvent>
#include<QString>
#include<QDebug>
#include<QDialog>
#include<QRectF>
#include<QTime>
#include<QLabel>
#include<math.h>
#include<Qprocess.h>
#include<QCoreApplication>
#include<qout.h>
#include<QScrollBar>
#include<QTime>
#include<QClipboard>
#include<QFileDialog>
#include<Qfile>
#include"setup_widget.h"
#include"qchaxun.h"
#include"compilecodewin.h"
extern QString px1;


struct logic{
    int x=5555;
    int y=5555;
    QString leiXin="";//常开，常闭，上身，下降
    QString pin_leiXin="";//x或y或m
    int bianHao=0;//引脚编号
    logic* addr=NULL;//下一个链表单元地址
    logic* addr2=NULL;//上一个链表单元地址
    bool Del=false;//撤回还原时候做相反操作
    int changDu=0;
    logic *shi=NULL;//撤回还原(多个逻辑时)时起启动停止作用
    logic *mou=NULL;//撤回还原(多个逻辑时)时起停止作用
    bool compileOK=0;//是否编译了
};



struct canShu{
    QString can1="";
    QString can2="";
    int can3=0;
};

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    struct shangCiJiLu{//上次记录结构体
        QString file="";//上次打开的文件
        QString zuiJinFile="";//最近打开的文件
    };
    shangCiJiLu scjl;//上次记录文件地址
    QString dqwj;//当前文件
    setup_widget *setup_w=NULL;
    bool isNull();
    QString  jiLuWenJian="/jiLu.txt";//记录文件地址
    void delLian(logic *tou,logic *wei);
    QString ret;//编译结束的生成的代码
    ~MainWindow();
protected:
    void paintEvent(QPaintEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void keyPressEvent(QKeyEvent *k);
    void keyReleaseEvent ( QKeyEvent * k );
    void closeEvent();

    bool press=false;
    int pressX=0;
    int pressY=0;
    int releaseX=0;
    int releaseY=0;
    int pasteX=0;
    int pasteY=0;
    bool xuanZhong=false;


private slots:
    void on_buttonXianQuan_pressed();

    void on_buttonBianYi_pressed();

    void on_buttonShangChuang_pressed();

    void on_buttonTiaoShi_pressed();

    void on_buttonChanKai_pressed();

    void on_buttonChangBi_pressed();

    void on_buttonShangShenYan_pressed();

    void on_buttonXiaJianYan_pressed();

    void on_buttonWanNen_pressed();

    void on_buttonH_pressed();

    void on_buttonS_pressed();

    void on_buttonCheHui_pressed();

    void on_buttonHuanYuan_pressed();

    void on_buttonTTL_pressed();

    void actionDaiKai();

    void menu_ShiTu();

   // void contextMenuEvent(QContextMenuEvent *event);

   // void menuDel();

  // void on_spinBox_editingFinished();

  //void on_spinBox_valueChanged(int arg1);



    void on_del_button_pressed();

   // void on_lineEdit_editingFinished();

    //void on_lineEdit_textChanged(const QString &arg1);

    void on_lineEdit_editingFinished();

    void on_lineEdit_textChanged(const QString &arg1);

    void copy_Button_2_released();

    void cut_pushButton_3_released();

    void paste_pushButton_4_released();

    void on_action2_triggered();

    void on_actionPointAdd_triggered();

    void on_actionPointJian_triggered();

    void on_actionSheZhi_triggered();

    void on_actionChongZuo_triggered();

    void on_actionCheHui_triggered();

    void on_actionChaZhao_triggered();

    void on_actionout_w_triggered();

    void on_verticalScrollBar_sliderMoved(int position);

    void on_verticalScrollBar_valueChanged(int value);

    void on_copy_Button_2_released();

    void on_cut_Button_3_released();

    void on_paste_Button_4_released();

    void on_actionDaKai_triggered();

    void on_actionXingJian_triggered();

    void on_actionxinJian_triggered();

    void on_actionbaoCun_triggered();

    void on_actionguanBi_triggered();

    void on_actionlinCun_triggered();

    void actionLiShi();

    void actionShiLi();

    void on_actiontuiChu_triggered();

    void on_actionjianQie_triggered();

    void on_actionfuZhi_triggered();

    void on_actionnianTie_triggered();

    void on_action1_triggered();

    void on_pushButton_clicked();

    void on_codeEdit_textChanged();

    void processError(QProcess::ProcessError);

private:
    Ui::MainWindow *ui;
    void tianXie_compileY0();
    int addx=0;
    int addy=0;
    bool huaDongYN=false;
    bool huaDongPB=false;
    int maxaddy=10;
    void changkaiHT(QPainter * , int dx, int dy);
    void changbiHT(QPainter * P,int dx,int dy);
    void xianquanHT(QPainter *P, int dx, int dy);
    void xiajianHT(QPainter *P, int dx, int dy);
    void shangShenHT(QPainter * P,int dx,int dy);
    void HHT(QPainter *P, int dx, int dy);
    void SHT(QPainter * P,int dx,int dy);
    void wanNenHT(QPainter * P,int dx,int dy);
    logic * set_logic(int x,int y);
    logic chaXun(int x,int y);
    logic chaXun_S(int x,int y);
    struct logic * logicTU=NULL;//逻辑图谱,新链地址放在旧链条中保存，需要保存链头链尾，只能从第一个链找，
    struct logic * logic_O=NULL;
    struct logic * logicNEW=NULL;

    struct logic * logic_copy=NULL;//复制
    struct logic * logic_copy_tou   =NULL;//复制

    struct logic * jiLu=NULL;//记录操作数据,链旧链单元地址放在新链当中保存，需要保存链头链尾，只能从最后一个链找，
    struct logic * jiLu_o=NULL;
    struct logic * jiLu_NEW=NULL;
    struct logic * jiLu_Temp;
    void NO_2();
    void wjl_del(int x, int y);//无记录删除逻辑
    void wjl_del_S(int x,int y);//无记录删除逻辑S


    QString XZbutton="";
    void del(int x=0, int y=0);
    void del_S(int x=0,int y=0);
    void del_ku();
    bool ggdel=false;
    int huoDe_weiX(int px,int py,int rx,int ry);
    int huoDe_weiY(int px,int py,int rx,int ry);
    int huoDe_weiXS(int px,int py,int rx,int ry);
    int huoDe_weiYS(int px,int py,int rx,int ry);
    int tongJi(int px,int py,int rx,int ry);
    int tongJi_S(int px,int py,int rx,int ry);
    void copy_ku();
    void paste_ku();
    void del_copyLian();
    void drawR(QPainter * p,int px,int py,int rx,int ry);

    int S_x(int x,int y);
    int S_y(int x,int y);


    QString text;
    int set_x=0,set_y=0;


    //QMenu menu;
    int mouseX=0,mouseY=0;
    int gbX=0,gbY=0;

    canShu fenJie(QString text);
    logic textFormatCheck(QString text);
    bool isDigitStr(QString src) ;


    QString compile();
    QString code_compile(QString text="");
    int JDtoXY(int jdName, const int p[][30][2], int p2[][2]);//用节点名称查询xy坐标值

    int keyCtrlPress=0;//ctrl按键是否被按着
    QString path_c(QString path);
    Qout *out_w=NULL;
    QchaXun *cx_w=NULL;
    int compileMuXian[1000]=zero1000;

    QClipboard *jianTieBan=NULL;//剪贴板对象
    void write_LD(logic *tou, logic *wei);//将梯形图写入剪贴板
    void read_LD();//将梯形图从剪贴板读出

    struct ew{//编译结束后返回的错误AND警告
        QString e_tiShi="";//错误信息提示
        int e_han=0;//错误位置行
        int e_x=0;//错误位置x
        QString w_tiShi="";//警告信息提示
        int w_han=0;//警告位置行
        int w_x=0;//警告位置x
        ew* addrX=NULL;//下一个错误或警告的位置
    };
    ew* ewTou=NULL;//ewTou:输出的错误和警告链的头;
    ew* ewWei=NULL;//ewWei:输出的错误和警告链的尾;
    void yuFaJianCha(logic *tou,logic *wei,int *eGeShu,int wGeShu,ew* ewTou,ew* ewWei);//错误检查函数；参数>>>tou：待处理逻辑链的头，wei：待处理逻辑的尾，eGeShu:输出的错误个数填写在这个，wGeShu:输出的警告个数填写在这个,ewTou:输出的错误和警告链的头;ewWei:输出的错误和警告链的尾;

    QFileDialog file;//打开的文件
    void write_LD(logic *tou, logic *wei,QString file_addr);//将梯形图写入指定文件
    void read_LD(QString file_addr);//将梯形图从指定文件读出
    void addShiLi();//添加示例程序
    void addLiShi();//历史记录
    QAction *action_arry[10]={NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
    QString zuiJinPATH[10]={"","","","","","","","","","",};
    QAction *shiLi_arry[10]={NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
    QString shiLiPATH[10]={"","","","","","","","","","",};
    compileCodeWin compilOut;
    QString retColour(QString str);
    const QString setColur=SET_COLOUR;
    QString toArduino(QString str);//单据编译后的文件转换成Arduino代码
    QString compileOut="";
    QString includeStr="";
    void include_shangShenYan(QString funName,QString digitalRead);//为上升沿建立函数

};

#endif // MAINWINDOW_H













