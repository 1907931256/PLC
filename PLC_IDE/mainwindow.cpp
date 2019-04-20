#include "mainwindow.h"
#include "ui_mainwindow.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    jianTieBan=QApplication::clipboard();//使用 QApplication::clipboard() 函数获得系统剪贴板对象。这个函数的返回值是 QClipboard 指针
    out_w=new Qout(this);//输出窗口
    this->out_w->setGeometry(0,this->height()-200,this->width(),200);
    cx_w=new QchaXun();//查询窗口
    this->setWindowIcon(QIcon(":/imj/tuBiao.png"));
    ui->verticalScrollBar->setGeometry(this->width()-ui->verticalScrollBar->width(),0,ui->verticalScrollBar->width(),this->height()-220);
   // ui->verticalScrollBar->setVisible(false);//默认竖直关闭滑块
    this->setup_w=new setup_widget;
    setup_w->com_read();
    logicTU=new logic;
    logic_O=logicTU;
    logicTU->addr=logicTU;//开辟数据链的第一个

    jiLu=new logic;//开辟记录数据链的第一个
    jiLu_o=jiLu;
    jiLu_NEW=jiLu;
    keyCtrlPress=false;
    ui->label_2->setVisible(false);

    this->setGeometry(1920/4,30,1920/2,1000);//setup init size
    ui->actionPointAdd->setIcon(QIcon(":/imj/a+.png"));
    ui->actionPointJian->setIcon(QIcon(":/imj/a-.png"));
    ui->actionjianQie->setIcon(QIcon(":/imj/jianQie.png"));
    ui->actionnianTie->setIcon(QIcon(":/imj/nianTie.png"));
    ui->actionxinJian->setIcon(QIcon(":/imj/xinJian.png"));
    ui->actionbaoCun->setIcon(QIcon(":/imj/baoCun.png"));
    ui->actionlinCun->setIcon(QIcon(":/imj/linCun.png"));
    ui->actionDaKai->setIcon(QIcon(":/imj/wenJian.png"));
    ui->actionSheZhi->setIcon(QIcon(":/imj/setup.png"));
    ui->actionChaZhao->setIcon(QIcon(":/imj/soSuo.png"));
    ui->actionCheHui->setIcon(QIcon(":/imj/zh.png"));
    ui->actionChongZuo->setIcon(QIcon(":/imj/fy.png"));
    ui->actionfuZhi->setIcon(QIcon(":/imj/copy.png"));
    ui->actionguanBi->setIcon(QIcon(":/imj/close.png"));
    ui->codeEdit->setVisible(false);
    QIcon changkaiTU(":/imj/ck.png");
    ui->buttonChanKai->setIcon(changkaiTU);
    ui->buttonChanKai->setIconSize(QSize(40,40));
    QIcon changbiTU(":/imj/cb.png");
    ui->buttonChangBi->setIcon(changbiTU);
    ui->buttonChangBi->setIconSize(QSize(40,40));
    QIcon shangshenTU(":/imj/ss.png");
    ui->buttonShangShenYan->setIcon(shangshenTU);
    ui->buttonShangShenYan->setIconSize(QSize(40,40));
    QIcon xiajianTU(":/imj/xq.png");
    ui->buttonXiaJianYan->setIcon(xiajianTU);
    ui->buttonXiaJianYan->setIconSize(QSize(40,40));
    QIcon xianquanTU(":/imj/xqq.png");
    ui->buttonXianQuan->setIcon(xianquanTU);
    ui->buttonXianQuan->setIconSize(QSize(36,36));
    QIcon bianyiTU(":/imj/by.png");
    ui->buttonBianYi->setIcon(bianyiTU);
    ui->buttonBianYi->setIconSize(QSize(42,42));
    QIcon shanchuan(":/imj/sc.png");
    ui->buttonShangChuang->setIcon(shanchuan);
    ui->buttonShangChuang->setIconSize(QSize(44,44));
    QIcon tiaoshi(":/imj/ts.png");
    ui->buttonTiaoShi->setIcon(tiaoshi);
    ui->buttonTiaoShi->setIconSize(QSize(44,44));
    QIcon chehui(":/imj/zh.png");
    ui->buttonCheHui->setIcon(chehui);
    ui->buttonCheHui->setIconSize(QSize(44,44));
    QIcon huanyuan(":/imj/fy.png");
    ui->buttonHuanYuan->setIcon(huanyuan);
    ui->buttonHuanYuan->setIconSize(QSize(44,44));
    QIcon lianjie(":/imj/lianjie.png");
    ui->buttonTTL->setIcon(lianjie);
    ui->buttonTTL->setIconSize(QSize(50,50));
    QIcon wannen(":/imj/wn.png");
    ui->buttonWanNen->setIcon(wannen);
    ui->buttonWanNen->setIconSize(QSize(32,32));
    QIcon h(":/imj/h.png");
    ui->buttonH->setIcon(h);
    ui->buttonH->setIconSize(QSize(40,40));
    QIcon s(":/imj/s.png");
    ui->buttonS->setIcon(s);
    ui->buttonS->setIconSize(QSize(40,40));
    //ui->widget_2->setStyleSheet("background-color:rgb(0,96,198)");
    // ui->widget->setVisible(false);
    ui->label->setVisible(false);
    ui->lineEdit->setVisible(false);
    ui->widget_2->setVisible(false);
    ui->lineEdit_2->setVisible(false);
    ui->lineEdit_2->setStyleSheet("background-color:transparent;");
    //connect(ui->actionDaKai,SIGNAL(ui->actionDaKai->triggered();), )
    connect(ui->actionDaKai,SIGNAL(triggered()),this,SLOT(actionDaiKai()));
    connect(ui->menuShiTu,SIGNAL(aboutToShow()),this,SLOT(menu_ShiTu()));
    //file.getOpenFileName(this,"选择要打开的项目文件");
    //applicationDirPath
    //this->
    //读取系统记录文件
    jiLuWenJian=px1+jiLuWenJian;
    QFile f(jiLuWenJian);
    if(f.open(QIODevice::ReadOnly)){
    QTextStream writeJL(&f);
    QString temp=writeJL.readAll();
    scjl.file=temp.section("**",0,0);
    scjl.zuiJinFile=temp.section("**",1);
    qDebug()<<"从记录读出的"<<jiLuWenJian<<temp<<scjl.file<<scjl.zuiJinFile;
    f.close();
    }
    addLiShi();//添加历史记录
    addShiLi();//添加示例文件
    disconnect(ui->codeEdit,SIGNAL(textChanged()),this,SLOT(on_codeEdit_textChanged()));//断开关键字色彩设置
    //读取Arduino程序样板
    QFile f2(px1+"/Arduino.txt");
    if(f2.open(QIODevice::ReadWrite)){
        QTextStream ino(&f2);
        includeStr=ino.readAll();
        f2.close();
        if(includeStr!="")
            qDebug()<<"Arduino程序样板加载成功"<<includeStr;
    }
    ui->codeEdit->setText(includeStr);//添加默认高级语言
    this->layout()->setMargin(0);//设置边距等于零

    ui->buttonBianYi->setFocusPolicy(Qt::NoFocus);
    ui->buttonChangBi->setFocusPolicy(Qt::NoFocus);
    ui->buttonShangChuang->setFocusPolicy(Qt::NoFocus);
    ui->buttonChangBi->setFocusPolicy(Qt::NoFocus);
    ui->buttonChanKai->setFocusPolicy(Qt::NoFocus);
    ui->buttonCheHui->setFocusPolicy(Qt::NoFocus);
    ui->buttonH->setFocusPolicy(Qt::NoFocus);
    ui->buttonHuanYuan->setFocusPolicy(Qt::NoFocus);
    ui->buttonS->setFocusPolicy(Qt::NoFocus);
    ui->buttonShangShenYan->setFocusPolicy(Qt::NoFocus);
    ui->buttonTiaoShi->setFocusPolicy(Qt::NoFocus);
    ui->buttonTTL->setFocusPolicy(Qt::NoFocus);
    ui->buttonWanNen->setFocusPolicy(Qt::NoFocus);
}

bool MainWindow::isNull()//没有逻辑单元时返回真
{
    logic *logicTemp=logic_O;
    for(int i=0;i<10;i++){
        if(logicTemp->x!=5555 && logicTemp->y!=5555  && logicTemp->leiXin!="S" ){
            return false;
        }
        if(logicTemp==logicNEW)
            return true;
        logicTemp=logicTemp->addr;
    }
    return true;

}

void MainWindow::delLian(logic *tou, logic *wei)
{
 //
    if(tou==tou->addr&&wei==NULL)//梯形图空时新建
        return;
    if(tou==wei && tou!=NULL)//没有逻辑时
        return;
    logic *temp=tou,*temp1=NULL;
    temp=temp->addr;
    while(1){
        if(temp==wei) {delete wei;break;}//到头结束
        if(temp!=NULL){temp1=temp;temp=temp->addr;}//后移
        if(temp1!=NULL)delete temp1;//删除当前节点
        if(temp==NULL)break;
    }

}
void MainWindow::changkaiHT(QPainter * P,int dx,int dy)
{
    P->drawLine(dx,dy+35,dx+50,dy+35);
    P->drawLine(dx+50,dy+10,dx+50,dy+60);
    P->drawLine(dx+70,dy+10,dx+70,dy+60);
    P->drawLine(dx+70,dy+35,dx+120,dy+35);
}
void MainWindow:: changbiHT(QPainter * P,int dx,int dy)
{
    P->drawLine(dx,dy+35,dx+50,dy+35);
    P->drawLine(dx+50,dy+10,dx+50,dy+60);
    P->drawLine(dx+70,dy+10,dx+70,dy+60);
    P->drawLine(dx+70,dy+35,dx+120,dy+35);
    P->drawLine(dx+50,dy+10,dx+70,dy+60);
}
void MainWindow::xianquanHT(QPainter * P,int dx,int dy)
{
    P->drawLine(dx,dy+35,dx+50,dy+35);
    QRectF rect(dx+50,dy+10,70,50);
    P->drawArc(rect,2400,950);
    P->drawArc(rect,5300,950);
}
void MainWindow::xiajianHT(QPainter * P,int dx,int dy)
{
    P->drawLine(dx,dy+35,dx+50,dy+35);
    P->drawLine(dx+50,dy+10,dx+50,dy+60);
    P->drawLine(dx+70,dy+10,dx+70,dy+60);
    P->drawLine(dx+70,dy+35,dx+120,dy+35);
    P->drawLine(dx+60,dy+20,dx+60,dy+50);
    P->drawLine(dx+50,dy+40,dx+60,dy+50);
    P->drawLine(dx+60,dy+50,dx+70,dy+40);
}
void MainWindow::shangShenHT(QPainter * P,int dx,int dy)
{
    P->drawLine(dx,dy+35,dx+50,dy+35);
    P->drawLine(dx+50,dy+10,dx+50,dy+60);
    P->drawLine(dx+70,dy+10,dx+70,dy+60);
    P->drawLine(dx+70,dy+35,dx+120,dy+35);
    P->drawLine(dx+60,dy+20,dx+60,dy+50);
    P->drawLine(dx+50,dy+30,dx+60,dy+20);
    P->drawLine(dx+60,dy+20,dx+70,dy+29);

}
void MainWindow::HHT(QPainter * P,int dx,int dy)
{
    P->drawLine(dx,dy+35,dx+120,dy+35);
}
void MainWindow::SHT(QPainter * P,int dx,int dy)
{
    P->drawLine(dx,dy,dx,dy+70);
}
void MainWindow::wanNenHT(QPainter * P,int dx,int dy)
{
    P->drawLine(dx,dy+15,dx+10,dy+15);
    P->drawLine(dx,dy+15,dx,dy+55);
    P->drawLine(dx,dy+55,dx+10,dy+55);
    P->drawLine(dx+110,dy+15,dx+120,dy+15);
    P->drawLine(dx+120,dy+15,dx+120,dy+55);
    P->drawLine(dx+110,dy+55,dx+120,dy+55);
}

void MainWindow::paintEvent(QPaintEvent *event)//QPaintEvent *event)
{
    pressY=pressY-addy;
    releaseY=releaseY-addy;
    QPainter painter(this);
    QPen pen(Qt::black,3,Qt::SolidLine,Qt::RoundCap,Qt::RoundJoin);//设置画笔
    QFont font;
    painter.setFont(font);
    painter.setPen(pen);
    //绘制线条
    painter.drawLine(10,67,10,1001);//母线
    if(press==true||xuanZhong==true){//绘制选中矩形背景
        int px=pressX,py=pressY,rx=releaseX,ry=releaseY;
        if(releaseX<pressX && releaseY >pressY){
           rx= pressX;
           py =pressY;
           px =releaseX;
           ry =releaseY;
        }
        else if(releaseX>pressX && releaseY<pressY){
           px=pressX;
           ry=pressY;
           rx =releaseX;
           py =releaseY;
        }
        else if(releaseX<pressX && releaseY<pressY){
           rx =pressX;
           ry =pressY;
           px =releaseX;
           py =releaseY;
        }
        if((tongJi((px-10)/120,(py-67)/70,(rx-10)/120,(ry-67)/70)>0||tongJi_S((px-10)/120+1,(py-35-67)/70+1,(rx-10)/120,(ry-67-35)/70+1)>0)&&(px>20 && py>30))
             drawR(&painter,px,py,rx,ry);//背景矩形
        painter.setPen(pen);
    }

    int x=0,y=0;
    while(1){
        painter.drawPoint(x*120+10,y*70+67);
        if(x==10&&y==13)
            break;
        if(x==10){
            y++;
            x=0;
        }
        x++;
    }

    if(logicNEW!=NULL){
        logicTU=logic_O;
        while(1){//绘图
            if(logicTU->pin_leiXin+QString::number(logicTU->bianHao)!="0"&&logicTU->leiXin!="WanNen"
                    &&logicTU->leiXin!="SET"&&logicTU->leiXin!="set"&&logicTU->leiXin!="RST"&&logicTU->leiXin!="rst"
                    &&logicTU->leiXin!="XianQuan"&&logicTU->leiXin.mid(0,1).toUpper()!="T"){//绘制编号如：X11
                font.setPixelSize(20);
                painter.setFont(font);
                painter.drawText(logicTU->x*120+10,logicTU->y*70-addy+77,60,20,Qt::AlignHCenter,logicTU->pin_leiXin.toUpper()+QString::number(logicTU->bianHao));
            }
            else if(logicTU->leiXin.toUpper()=="SET"){
                font.setPixelSize(25);
                painter.setFont(font);
                painter.drawText(logicTU->x*120+10,logicTU->y*70-addy+90,120,70,Qt::AlignHCenter,QString("SET  ")+logicTU->pin_leiXin.toUpper()+QString::number(logicTU->bianHao));
            }
            else if(logicTU->leiXin.mid(0,1).toUpper()=="T"){
                font.setPixelSize(25);
                painter.setFont(font);
                painter.drawText(logicTU->x*120+10,logicTU->y*70-addy+90,120,70,Qt::AlignHCenter,logicTU->leiXin.toUpper()+QString("  ")+QString::number(logicTU->bianHao)+logicTU->pin_leiXin.toLower());
            }
            else if(logicTU->leiXin.toUpper()=="RST"){
                font.setPixelSize(25);
                painter.setFont(font);
                painter.drawText(logicTU->x*120+10,logicTU->y*70-addy+90,120,70,Qt::AlignHCenter,QString("RST  ")+logicTU->pin_leiXin.toUpper()+QString::number(logicTU->bianHao));
            }
            else if(logicTU->leiXin=="XianQuan"&&logicTU->pin_leiXin!=""){
                font.setPixelSize(25);
                painter.setFont(font);
                painter.drawText(logicTU->x*120+30,logicTU->y*70-addy+90,120,70,Qt::AlignHCenter,logicTU->pin_leiXin.toUpper()+QString::number(logicTU->bianHao));
            }
            if(logicTU->y*70-addy>=0&&logicTU->y*70-addy<70*14){
                if ("ChangKai"==logicTU->leiXin)
                    changkaiHT(&painter,10+logicTU->x*120,67+logicTU->y*70-addy);
                else if("ChangBi"==logicTU->leiXin)
                    changbiHT(&painter,10+logicTU->x*120,67+logicTU->y*70-addy);
                else if("XianQuan"==logicTU->leiXin)
                    xianquanHT(&painter,10+logicTU->x*120,67+logicTU->y*70-addy);
                else if("XiaJianYan"==logicTU->leiXin)
                    xiajianHT(&painter,10+logicTU->x*120,67+logicTU->y*70-addy);
                else if("ShangShenYan"==logicTU->leiXin)
                    shangShenHT(&painter,10+logicTU->x*120,67+logicTU->y*70-addy);
                else if("H"==logicTU->leiXin)
                    HHT(&painter,10+logicTU->x*120,67+logicTU->y*70-addy);
                else if("S"==logicTU->leiXin)
                    SHT(&painter,10+logicTU->x*120,67+(logicTU->y-1)*70+35-addy);
                else if(("WanNen"==logicTU->leiXin)||("set"==logicTU->leiXin)
                        ||("SET"==logicTU->leiXin)||("rst"==logicTU->leiXin)||("RST"==logicTU->leiXin)
                        ||("T"==logicTU->leiXin.mid(0,1).toUpper()))
                    wanNenHT(&painter,10+logicTU->x*120,67+logicTU->y*70-addy);
            }
            if(logicTU==logicNEW)
                break;
            logicTU=logicTU->addr;
            }
        logicTU=logicNEW;
    }
    //绘制光标矩形框
    QPainter painter2(this);
    QPen pen2(Qt::black,1,Qt::SolidLine,Qt::RoundCap,Qt::RoundJoin);//设置画笔
    painter2.setPen(pen2);
    if(press==true||xuanZhong==true){
        if(pressX>20&&pressY>30)
            painter2.drawRect(pressX,pressY,releaseX-pressX,releaseY-pressY);//型矩形
    }
    else if(XZbutton!="S"){
        painter2.drawRect((gbX)*120+10,(gbY)*70+67-addy,120,70);//矩形
    }
    if(((ui->label->x()+10)/120!=gbX)&&((ui->label->y()+67)/70!=gbY)){//光标框移动到其它框，原来框的引脚输入栏显示关闭
        ui->label->setVisible(false);
        ui->lineEdit->setVisible(false);
    }
    if(ui->codeEdit->isVisible()==true){
        ui->codeEdit->setGeometry(0,ui->buttonBianYi->x()+ui->buttonBianYi->height(),this->width(),this->height()-((out_w->isVisible()==true)?out_w->height()+ui->buttonBianYi->x()+ui->buttonBianYi->height()+13:0));
        ui->verticalScrollBar->setVisible(false);
    }
    //重绘输出窗口
    this->out_w->setGeometry(0,this->height()-200,this->width(),200);
    //重绘查询窗口
    this->cx_w->move(this->x()+this->width()/2-this->cx_w->width()/2,this->y()+this->height()/2-this->cx_w->height()/2);
    //重绘竖直滚动条
    if(this->out_w->isVisible()==false)//关闭输出窗口后要改变竖直滑块高度
         ui->verticalScrollBar->setGeometry(this->width()-ui->verticalScrollBar->width(),0,ui->verticalScrollBar->width(),this->height());
    else
         ui->verticalScrollBar->setGeometry(this->width()-ui->verticalScrollBar->width(),0,ui->verticalScrollBar->width(),this->height()-220);
    //判断输出窗口是否为空
    if(this->out_w->label()->text()[0]=='\n')//去除输出窗口第一行空格
        this->out_w->label()->setText( this->out_w->label()->text().mid(1));
    if(this->out_w->label2()->text()[0]=='\n')
        this->out_w->label2()->setText( this->out_w->label2()->text().mid(1));
    pressY=pressY+addy;//复原
    releaseY=releaseY+addy;
}
void MainWindow::keyPressEvent(QKeyEvent *k){
    int key=k->key();
    if(key==61)//ctrl+'+'按下
        on_actionPointAdd_triggered();
    else if(key==45)//ctrl+‘-’按下
        on_actionPointJian_triggered();
    else if(key==16777249){//Ctrl键按下
        this->keyCtrlPress=true;}
    else if(this->keyCtrlPress==true &&  key==16777217)//'Ctrl'按下+'Tab'按下时编辑视图切换
        on_action2_triggered();

}
void MainWindow::keyReleaseEvent(  QKeyEvent * k )
{
    int key=k->key();
    qDebug()<<k->modifiers()<<key;
    if(ui->codeEdit->isVisible()==false){//codeEdit没打开时，才执行下面代码
        if((Qt::Key_Up==key)&&(gbY!=0)){
            gbY--;
            ui->lineEdit_2->setVisible(false);
        }
        else if(Qt::Key_Down==key){
            gbY++;
            ui->lineEdit_2->setVisible(false);
        }
        else if((Qt::Key_Left==key)&&(gbX!=0)){
            gbX--;
            ui->lineEdit_2->setVisible(false);
        }
        else if(Qt::Key_Right==key){
            gbX++;
            ui->lineEdit_2->setVisible(false);
        }
        else if(Qt::Key_Delete==key){
            if(xuanZhong==true){
                del_ku();
            }
            else{
                del(gbX,gbY);
            }
        }
        else if(k->modifiers() == Qt::ControlModifier && key == Qt::Key_Z){
            on_buttonCheHui_pressed();
        }
        else if(k->modifiers() == Qt::ControlModifier && key == Qt::Key_Y){
            on_buttonHuanYuan_pressed();
        }
        else if(k->modifiers() == Qt::ControlModifier && key == Qt::Key_C){
            copy_ku();
        }
        else if(k->modifiers() == Qt::ControlModifier && key == Qt::Key_V){
            paste_ku();
        }
        else if(k->modifiers() == Qt::ControlModifier && key == Qt::Key_X){
            qDebug()<<"XXXXX1" <<pressX<<pressY<<releaseX<<releaseY;
            copy_ku();
            qDebug()<<"XXXX2"<< pressX<<pressY<<releaseX<<releaseY;
            del_ku();
        }
        else if((16777220 ==key)&&(ui->label->isVisible()==false)){//引脚输入框未显示时

            QString temp=chaXun(gbX,gbY).leiXin;
            if((temp!="")&&(temp!="H")&&(temp!="s")&&(temp!="WanNen")){//当前光标存在的图标是否要输入引脚编号
                ui->lineEdit->setText("");
                ui->label->show();
                ui->lineEdit->show();
                static int dx=ui->lineEdit->x()-ui->label->x(),dy=ui->lineEdit->y()-ui->label->y();//优化速度
                ui->lineEdit->move(gbX*120+10+dx,gbY*70+91+dy-addy);
                ui->label->move(gbX*120+10,gbY*70+91-addy);
                ui->lineEdit->setEnabled (true);
                ui->lineEdit->setFocus ();
            }
            else if(((temp=="")||(temp=="WanNen"))&&(ui->lineEdit_2->isVisible()==false)){//回车键按下时光标位置为空，显示lineDeit_2来输入逻辑图标信息
                ui->lineEdit_2->show();
                ui->lineEdit_2->setText("");
                ui->lineEdit_2->move(gbX*120+10,gbY*70+91-addy);
                ui->lineEdit_2->setEnabled (true);
                ui->lineEdit_2->setFocus ();
            }
            else if(((temp=="")||(temp=="WanNen"))&&(ui->lineEdit_2->isVisible()==true)){//回车键按下时光标位置为空，如果此时lineEdit_2显示着，则讲输入栏的text转换成图标存入链表

                ui->lineEdit_2->setVisible(false);
                logic retu=textFormatCheck(ui->lineEdit_2->text());//设置该单元的值，检测文本是否规规范
                qDebug()<<"调试"<<retu.leiXin;
                this->out_w->label2()->setText(this->out_w->label2()->text()+"\n"+"调试"+retu.leiXin);
                if(retu.leiXin!=""){
                    NO_2();//删除原先还原的那条路径
                    qDebug()<<"创建其它单元"<<gbX<<gbY;
                    this->out_w->label2()->setText(this->out_w->label2()->text()+"\n"+"创建其它单元 "+QString::number(gbX)+" "+QString::number(gbY));
                    logicTU->addr=new logic;
                    logicTU=logicTU->addr;
                    logicTU->x=gbX;
                    logicTU->y=gbY;
                    logicTU->leiXin=retu.leiXin;
                    logicTU->pin_leiXin=retu.pin_leiXin;
                    logicTU->bianHao=retu.bianHao;
                    logicNEW=logicTU;
                    if(maxaddy<logicTU->y){
                        huaDongPB=true;
                        ui->verticalScrollBar->setValue(100*maxaddy/logicTU->y);
                        qDebug()<<(100*maxaddy/logicTU->y);
                    }
                    maxaddy=(maxaddy<logicTU->y)? logicTU->y:maxaddy;//改变竖直滑块移动的最小单位
                    jiLu_Temp=jiLu;//记录操作
                    jiLu=new logic;
                    *jiLu=*logicTU;
                    jiLu->addr=jiLu_Temp;//旧地址放新单元
                    jiLu_Temp->addr2=jiLu;//新地址放旧单元
                    jiLu->Del=false;
                    jiLu_NEW=jiLu;
                    if(logicTU->leiXin=="XianQuan"){//光标自动后移
                        QString temp1;
                        while(1){
                            gbY++;gbX=0;
                            temp1=chaXun(gbX,gbY).leiXin;
                            if((temp1=="")||(temp1=="S"))
                                break;
                        }
                    }
                    else{
                        gbX++;
                    }
                    if(chaXun(gbX,gbY).leiXin==""){//输入完成移动到下个位置，判断该位置是否为空，空则显示lineEdit_2
                        ui->lineEdit_2->setVisible(true);
                        ui->lineEdit_2->setText("");
                        ui->lineEdit_2->move(gbX*120+10,gbY*70+91-addy);
                        ui->lineEdit_2->setEnabled (true);
                        ui->lineEdit_2->setFocus ();
                    }
                }
                else{//在lineEdit_2没输入任何文字情况下按得回车，则只关闭lineEdit_2显示
                    ui->lineEdit_2->setVisible(false);
                }

            }


        }
        else if((16777220 ==key)&&(ui->label->isVisible()==true)){//引脚输入框显示时,按下了回车则关闭引脚输入框；lineEdit槽函数会将引脚值存入链表对应单元
            ui->label->setVisible(false);
            ui->lineEdit->setVisible(false);
        }


        update();
    }
    else{//codeEdit打开时，执行下面代码
        if(key==16777249)//按键'ctrl'释放时按下为假
            this->keyCtrlPress =false;
    }
}

void MainWindow::mouseReleaseEvent(QMouseEvent *event)//鼠标按下
{
    if(ui->codeEdit->isVisible()==false){
        pasteX=event->x();pasteY=event->y()+addy;
        if(event->button()==Qt::LeftButton) {
            if (sqrt(pow(event->x()-pressX,2)+pow(event->y()+addy-pressY,2))>50){
                qDebug()<<"块处理"<<"选中块目标";
                this->out_w->label2()->setText(this->out_w->label2()->text()+"\n"+"块处理 "+"选中块目标");
                XZbutton="";
                xuanZhong=true;
                releaseX=event->x();
                releaseY=event->y()+addy;
                int px=pressX,py=pressY,rx=releaseX,ry=releaseY;
                if(rx<px && ry>py){
                    pressX=rx;
                    pressY=py;
                    releaseX=px;
                    releaseY=ry;
                }
                else if(rx>px && ry<py){
                    pressX=px;
                    pressY=ry;
                    releaseX=rx;
                    releaseY=py;
                }
                else if(rx<px && ry<py){
                    pressX=rx;
                    pressY=ry;
                    releaseX=px;
                    releaseY=py;
                }
            }
            press=false;
        }
        ui->labelx->setText(QString::number(event->x()-10) );
        ui->labely->setText(QString::number(event->y()+addy-67) );
        int x =event->x()-10;
        int y =event->y()+addy-67;
        mouseX=x;
        mouseY=y;
        gbX=x/120;
        gbY=y/70;

        if(event->button() == Qt::LeftButton&&xuanZhong==false){
            static int timeS=0;
            static int time=0;
            static int xS=0;
            static int xX=0;
            xX=x;
            static int yS=0;
            static int yX=0;
            yX=y;

            ui->widget_2->setVisible(false);
            ui->lineEdit_2->setVisible(false);
            ui->lineEdit->setVisible(false);
            ui->label->setVisible(false);
            time=QTime::currentTime().second()*1000+QTime::currentTime().msec();
            if( (timeS+800 > time)&&(timeS < time)&&(xS<xX+20)&&(xS>xX-20)&(yS<yX+20)&&(yS>yX-20)){//连续点击获得输入引脚信息栏
                QString temp=chaXun(x/120,y/70).leiXin;
                if((temp!="")&&(temp!="H")&&(temp!="s")&&(temp!="WanNen")){
                    ui->lineEdit->setText("");
                    ui->label->show();
                    ui->lineEdit->show();
                    ui->lineEdit->move(x+10+ui->lineEdit->x()-ui->label->x(),y+67+ui->lineEdit->y()-ui->label->y()-addy);
                    ui->label->move(x+10,y+67-addy);
                    //获得lineEdit光标
                    ui->lineEdit->setEnabled (true);
                    ui->lineEdit->setFocus ();
                }
                else if(temp=="WanNen"){
                    ui->lineEdit_2->show();
                    ui->lineEdit_2->setText("");
                    ui->lineEdit_2->move(gbX*120+10,gbY*70+91-addy);
                    ui->lineEdit_2->setEnabled (true);
                    ui->lineEdit_2->setFocus ();
                }
                else if(temp==""){
                    ui->lineEdit_2->show();
                    ui->lineEdit_2->setText("");
                    ui->lineEdit_2->move(gbX*120+10,gbY*70+91-addy);
                    ui->lineEdit_2->setEnabled (true);
                    ui->lineEdit_2->setFocus ();
                }
            }
            timeS=time;
            xS=xX;
            yS=yX;

            if(XZbutton=="H"||XZbutton=="S"||XZbutton=="ChangKai"||XZbutton=="ChangBi"
                    ||XZbutton=="XianQuan"||XZbutton=="XiaJianYan"||XZbutton=="ShangShenYan"
                    ||XZbutton=="WanNen"){
                if(XZbutton=="S"){
                    if((x%120>60)&&(y%70>35)){
                        x=x/120+1;
                        y=y/70+1;
                    }
                    else if((x%120<60)&&(y%70<35)){
                        x=x/120;
                        y=y/70;
                    }
                    else if((x%120>60)&&(y%70<35)){
                        x=x/120+1;
                        y=y/70;
                    }
                    else if((x%120<60)&&(y%70>35)){
                        x=x/120;
                        y=y/70+1;
                    }


                    logic temp=chaXun_S(x,y);
                    if(temp.leiXin==""&& x>0 && y>0){

                        NO_2();//删除原先还原的那条路径

                        qDebug()<<"创建S单元"<<x<<y;
                        this->out_w->label2()->setText(this->out_w->label2()->text()+"\n"+"创建S单元 "+QString::number(x)+" "+QString::number(y));
                        logicTU->addr=new logic;
                        logicTU=logicTU->addr;
                        logicTU->x=x;
                        logicTU->y=y;
                        logicTU->leiXin="S";
                        logicNEW=logicTU;
                        if(maxaddy<logicTU->y){
                            huaDongPB=true;
                            ui->verticalScrollBar->setValue(100*maxaddy/logicTU->y);
                            qDebug()<<(100*maxaddy/logicTU->y);
                        }
                        maxaddy=(maxaddy<logicTU->y)? logicTU->y:maxaddy;//改变竖直滑块移动的最小单位
                        jiLu_Temp=jiLu;//记录操作
                        jiLu=new logic;
                        *jiLu=*logicTU;
                        jiLu->addr=jiLu_Temp;//旧地址放新单元
                        jiLu_Temp->addr2=jiLu;//新地址放旧单元
                        jiLu->Del=false;
                        jiLu_NEW=jiLu;
                    }

                }
                else {
                    x=x/120;
                    y=y/70;

                    logic temp2=chaXun(x,y);
                    if(temp2.leiXin==""){

                        NO_2();//删除原先还原的那条路径

                        qDebug()<<"创建其它单元"<<x<<y;
                        this->out_w->label2()->setText(this->out_w->label2()->text()+"\n"+"创建其它单元 "+QString::number(x)+" "+QString::number(y));
                        logicTU->addr=new logic;
                        logicTU=logicTU->addr;
                        logicTU->x=x;
                        logicTU->y=y;
                        logicTU->leiXin=XZbutton;
                        logicNEW=logicTU;
                        if(maxaddy<logicTU->y){
                            huaDongPB=true;
                            ui->verticalScrollBar->setValue(100*maxaddy/logicTU->y);
                            qDebug()<<(100*maxaddy/logicTU->y);
                        }
                        maxaddy=(maxaddy<logicTU->y)? logicTU->y:maxaddy;//改变竖直滑块移动的最小单位
                        jiLu_Temp=jiLu;//记录操作
                        jiLu=new logic;
                        *jiLu=*logicTU;
                        jiLu->addr=jiLu_Temp;//旧地址放新单元
                        jiLu_Temp->addr2=jiLu;//新地址放旧单元
                        jiLu->Del=false;
                        jiLu_NEW=jiLu;
                    }

                }

            }
        }
        else if(event->button() == Qt::RightButton){
            if(!(event->x()>((pressX-10)/120)*120 && event->x()<((releaseX-10)/120+1)*120 && event->y()+addy>((pressY-67)/70)*70+70 && event->y()+addy<((releaseY-67)/70+1)*70+70)&&xuanZhong==true){//
                xuanZhong=false;
                ui->widget_2->setVisible(false);
            }
            else{
                ui->widget_2->setGeometry(ui->widget_2->geometry().x(),ui->widget_2->geometry().y(),ui->widget_2->geometry().width(),31*4-2);
                ui->widget_2->setVisible(true);
                ui->widget_2->move(x+10,y+37-addy);
            }
            XZbutton="";
            //ui->widget->setVisible(false);
            ui->label->setVisible(false);
            ui->lineEdit->setVisible(false);
            if((x%120<100)&&(x%120>20)){//右键非S的单元图标
                if(chaXun(x/120,y/70).leiXin!=""){
                    ui->widget_2->setGeometry(ui->widget_2->geometry().x(),ui->widget_2->geometry().y(),ui->widget_2->geometry().width(),31*4-2);
                    ui->widget_2->setVisible(true);
                    ui->widget_2->move(x+10,y+37-addy);
                }
            }
            else if((x%120>100)||(x%120<20)){//右键S单元
                ui->widget_2->move(x+10,y+37-addy);
                if((x%120>60)&&(y%70>35)){
                    x=x/120+1;
                    y=y/70+1;
                }
                else if((x%120<60)&&(y%70<35)){
                    x=x/120;
                    y=y/70;
                }
                else if((x%120>60)&&(y%70<35)){
                    x=x/120+1;
                    y=y/70;
                }
                else if((x%120<60)&&(y%70>35)){
                    x=x/120;
                    y=y/70+1;
                }
                if(chaXun_S(x,y).leiXin!=""){
                    ui->widget_2->setGeometry(ui->widget_2->geometry().x(),ui->widget_2->geometry().y(),ui->widget_2->geometry().width(),31*4-2);
                    ui->widget_2->setVisible(true);
                }

            }            
        }

        update();
    }
}
void MainWindow::mousePressEvent(QMouseEvent *event)
{
    if(ui->codeEdit->isVisible()==false){//codeEdit没打开时，才执行下面代码
        if(event->button()==Qt::LeftButton){
            press=true;
            xuanZhong=false;
            pressX=event->x();
            pressY=event->y()+addy;

        }

    }
}
void MainWindow::mouseMoveEvent(QMouseEvent *event){
    if(ui->codeEdit->isVisible()==false){//codeEdit没打开时，才执行下面代码
        if (sqrt(pow(event->x()-releaseX,2)+pow(event->y()+addy-releaseY,2))>10 && press ==true){
            releaseX=event->x();
            releaseY=event->y()+addy;
            update();
        }
        ui->labelx->setText(QString::number((event->x()-10)/120));
        ui->labely->setText(QString::number((event->y()+addy-67)/70));
    }
}

MainWindow::~MainWindow()
{
    delete setup_w;
    delete ui;
}
//线圈
void MainWindow::on_buttonXianQuan_pressed()
{
  ui->textBrowser->setText(ui->textBrowser->toPlainText()+"线圈\n");
  XZbutton="XianQuan";
}
//编译
void MainWindow::on_buttonBianYi_pressed()
{
    QString compileCode="";
 ui->textBrowser->setText(ui->textBrowser->toPlainText()+"编译\n");
 XZbutton="BianYi";
 ui->textBrowser->setText("");
 if(ui->codeEdit->isVisible()==true){
     compileCode=ui->codeEdit->toPlainText();
 }
 else{
     if(this->isNull()==true){
         qDebug()<<"空";
         this->out_w->label2()->setText(this->out_w->label2()->text()+"\n"+"空");
     }
     else{
         qDebug()<<"非空";
         this->out_w->label2()->setText(this->out_w->label2()->text()+"\n"+"非空");
         compileCode=code_compile(compile());
     }
 }
 qDebug()<<"结束编译";
 this->out_w->label2()->setText(this->out_w->label2()->text()+"\n"+"结束编译");
 //将编译后的文件添加进c代码
 QFile f(px1+"/code/code.ino");
 qDebug()<<px1+"/code/code.ino";
 if(f.open(QIODevice::WriteOnly)){
     qDebug()<<"修改代码成功";
     QTextStream code(&f);
     if(ui->codeEdit->isVisible()==false)
       code<<includeStr.mid(0,includeStr.indexOf("//inputCode")+12)+compileCode+includeStr.mid(includeStr.indexOf("//inputCode")+11);
     else
         code<<compileCode;
     f.close();
 }
 else{
      qDebug()<<"修改代码失败";
 }
}
//上传
void MainWindow::on_buttonShangChuang_pressed()
{
 ui->textBrowser->setText(ui->textBrowser->toPlainText()+"上传\n");
 QProcess process(this);//调用外部程序的对象
 connect(&process, SIGNAL(error(QProcess::ProcessError)), this, SLOT(processError(QProcess::ProcessError)));
 QStringList arguments;//参数
 QMessageBox msgBox(this);//消息对话框
 if(setup_w->com_read()==false){
     msgBox.setText("没有链接PLC-----请先链接      ");
     msgBox.exec();
     return;
 }
 QString strResult="",exe_path=QCoreApplication::applicationDirPath();//下载完成时信息字符串;应用所在的路径
 qDebug()<<"exe地址："<<exe_path;
 arguments << "--board"<<"arduino:avr:uno"//设置板子型号
           <<"--port"<<setup_w->com()//从设置窗口获取下载的串口
           <<"--upload"<<path_c(exe_path)+"\\code\\code.ino";//下载程序存在的位置
 process.start(path_c(exe_path)+"\\arduino-1.6.0-windows\\arduino-1.6.0\\arduino_debug.exe",arguments);//开始请求Arduino.exe编译下载
 msgBox.setText("点击OK则开始下载,会需要小一会\n\r下载过程中会出现软件没反应");
 process.waitForStarted();//等待开始
 QFont font;
 font.setPointSize(font.pointSize()+40);
 ui->label_2->setFont(font);
 ui->label_2->setText("正在下载中");
 qDebug()<<"X"<<this->x()<<"W"<<(this->width()/2)<<"Y"<<this->y()<<"H"<<(this->height()/2);
 ui->label_2->move(this->width()/2-ui->label_2->width()/2,this->height()/2-ui->label_2->height()/2);
 ui->label_2->setVisible(true);
 msgBox.exec();
 process.waitForFinished();//等到结束
 ui->label_2->setVisible(false);
 strResult = QString::fromLocal8Bit(process.readAllStandardOutput());//获取屏幕上的输出
 qDebug()<<"CMD输出："<<strResult;
 msgBox.setText(QString("下载成功")+"\n\r"+strResult);
 msgBox.exec();
 XZbutton="ShangChuang";
}
//调试
void MainWindow::on_buttonTiaoShi_pressed()
{
ui->textBrowser->setText(ui->textBrowser->toPlainText()+"调试\n");
XZbutton="TiaoShi";
}
//常开
void MainWindow::on_buttonChanKai_pressed()
{
ui->textBrowser->setText(ui->textBrowser->toPlainText()+"常开\n");
XZbutton="ChangKai";
}
//常闭
void MainWindow::on_buttonChangBi_pressed()
{
ui->textBrowser->setText(ui->textBrowser->toPlainText()+"常闭\n");
XZbutton="ChangBi";
}
//上升沿
void MainWindow::on_buttonShangShenYan_pressed()
{
ui->textBrowser->setText(ui->textBrowser->toPlainText()+"上升沿\n");
XZbutton="ShangShenYan";
}
//下降沿
void MainWindow::on_buttonXiaJianYan_pressed()
{
ui->textBrowser->setText(ui->textBrowser->toPlainText()+"下降沿\n");
XZbutton="XiaJianYan";
}
//万能
void MainWindow::on_buttonWanNen_pressed()
{
ui->textBrowser->setText(ui->textBrowser->toPlainText()+"万能\n");
XZbutton="WanNen";
}
//横
void MainWindow::on_buttonH_pressed()
{
ui->textBrowser->setText(ui->textBrowser->toPlainText()+"横\n");
XZbutton="H";
}
//竖
void MainWindow::on_buttonS_pressed()
{
ui->textBrowser->setText(ui->textBrowser->toPlainText()+"竖\n");
XZbutton="S";
}
//撤回
void MainWindow::on_buttonCheHui_pressed()
{
logic *mou=NULL;
xuanZhong=false;
press=false;
gbY=0;
gbX=0;
 for(int i=0;i<200;i++){//先进入循环，根据jiLu链中遇到的情况来退出
    if(jiLu==jiLu_o)//撤回以到底
        return;
    if(jiLu->Del==true){//如果记录中描述他是删除，则撤回时新建这个单元
        if(jiLu->leiXin=="S"){//S逻辑新建
            logic temp=chaXun_S(jiLu->x,jiLu->y);
            if(temp.leiXin==""){
                logicTU->addr=new logic;
                logicTU=logicTU->addr;
                logicTU->x=jiLu->x;
                logicTU->y=jiLu->y;
                logicTU->leiXin="S";
                logicNEW=logicTU;
                }
        }
        else if((jiLu->leiXin!="S")&&(jiLu->leiXin!="")){//普通逻辑单元新建
            logic temp2=chaXun(jiLu->x,jiLu->y);
            if(temp2.leiXin==""){
                logicTU->addr=new logic;
                logicTU=logicTU->addr;
                logicTU->x=jiLu->x;
                logicTU->y=jiLu->y;
                logicTU->bianHao=jiLu->bianHao;
                logicTU->pin_leiXin=jiLu->pin_leiXin;
                logicTU->leiXin=jiLu->leiXin;
                logicNEW=logicTU;
            }
        }
    }
    else  if(jiLu->Del==false){//如果记录中描述他是新建，则撤回时删除这个单元
        if(jiLu->leiXin=="S")
            wjl_del_S(jiLu->x,jiLu->y);
        else if((jiLu->leiXin!="S")&&(jiLu->leiXin!=""))
            wjl_del(jiLu->x,jiLu->y);
    }
    qDebug()<<"i次数"<<i;
    if(jiLu->shi==jiLu->mou&&jiLu->shi!=NULL)//当选中的只有一个时
        break;
   if(jiLu->shi!=NULL){//遇到框选中的末位删除的逻辑时，记录下此时的地址
       mou=jiLu;
   }
   if(jiLu->mou==mou&&mou!=NULL){//遇到到存有末位地址的起始逻辑单元，结束此次撤回
       break;
   }

   if(jiLu->shi==NULL&&mou==NULL){//这是单个单元撤回时结束
       break;
   }

    jiLu=jiLu->addr;

}
 jiLu=jiLu->addr;
update();
    //XZbutton="CheHui";
}
//还原
void MainWindow::on_buttonHuanYuan_pressed()
{
    xuanZhong=false;
    press=false;
    gbX=0;
    gbY=0;
    logic *shi=NULL;
for(int i=0;i<200;i++){
    if(jiLu==jiLu_NEW)
        return;

    jiLu=jiLu->addr2;

    if(jiLu->Del==false){
        if(jiLu->leiXin=="S"){
            logic temp=chaXun_S(jiLu->x,jiLu->y);
            qDebug()<<"temp.leiXin"<<temp.leiXin;
            if(temp.leiXin==""){
                qDebug()<<"创建S单元";
                logicTU->addr=new logic;
                logicTU=logicTU->addr;
                logicTU->x=jiLu->x;
                logicTU->y=jiLu->y;
                logicTU->leiXin="S";
                logicNEW=logicTU;
                }
        }
        else if((jiLu->leiXin!="S")&&(jiLu->leiXin!="")){
            logic temp2=chaXun(jiLu->x,jiLu->y);
            qDebug()<<"temp2.leiXin"<<temp2.leiXin;
            if(temp2.leiXin==""){
                qDebug()<<"创建其它单元";
                logicTU->addr=new logic;
                logicTU=logicTU->addr;
                logicTU->x=jiLu->x;
                logicTU->y=jiLu->y;
                logicTU->bianHao=jiLu->bianHao;
                logicTU->pin_leiXin=jiLu->pin_leiXin;
                logicTU->leiXin=jiLu->leiXin;
                logicNEW=logicTU;
            }
        }
    }
    else  if(jiLu->Del==true){
        if(jiLu->leiXin=="S")
            wjl_del_S(jiLu->x,jiLu->y);
        else if((jiLu->leiXin!="S")&&(jiLu->leiXin!=""))
            wjl_del(jiLu->x,jiLu->y);
    }

    qDebug()<<"i次数"<<i;
    if(jiLu->shi==jiLu->mou&&jiLu->shi!=NULL)//当框选中的只有一个时
        break;
    if(jiLu->mou!=NULL){//遇到框选中的始位删除的逻辑时，记录下此时的地址
       shi=jiLu;
    }
    if(jiLu->shi==shi&&shi!=NULL){//遇到到存有末位地址的起始逻辑单元，结束此次撤回
       break;
    }
    if(jiLu->shi==NULL&&shi==NULL){//这是单个单元撤回时结束
       break;
    }

  }
update();



//XZbutton="HuanYuan";
}
//串口通讯
void MainWindow::on_buttonTTL_pressed()
{
ui->textBrowser->setText(ui->textBrowser->toPlainText()+"串口\n");
XZbutton="TTL";
}

 logic  MainWindow::chaXun(int x,int y)//查询
 {
     logic logicTemp;
     logicTU=logic_O;
     while (1) {
         if( ((logicTU->x)==x)&&((logicTU->y)==y)&&(logicTU->leiXin!="S") )
         {logicTemp=*logicTU;/*
<<"找到";*/break;}
         if((logicTU==logicNEW)||(logicNEW==NULL))//链表查询结束或没有逻辑时返货数据空对象
             {/*qDebug()<<"链表查询结束"*/;return *logic_O;}
         logicTU=logicTU->addr;//进入下个存储单元
     }
     if(logicNEW!=NULL)
        logicTU=logicNEW;
     return logicTemp;
 }

 logic  MainWindow::chaXun_S(int x,int y)
 {
     logic logicTemp;
     logicTU=logic_O;
     while (1) {
         if( ((logicTU->x)==x)&&((logicTU->y)==y)&&(logicTU->leiXin=="S"))
         {logicTemp=*logicTU;/*qDebug()<<"找到";*/break;}
         if((logicTU==logicNEW)||(logicNEW==NULL))//链表查询结束或没有逻辑时返货数据空对象
             {/*qDebug()<<"链表查询结束未找到S";*/return *logic_O;}
         logicTU=logicTU->addr;//进入下个存储单元
     }
     if(logicNEW!=NULL)
        logicTU=logicNEW;
     return logicTemp;
 }

 void MainWindow::del(int x,int y)//不可以删除"S"链表单元
 {
     logic *b=logic_O;
     logic *shang;
     logic *xia=logic_O;

     NO_2();//删除原先还原路径

     while (1) {
         if( ((b->x)==x)&&((b->y)==y)&&(b->leiXin!="S") )//删除一个链表单元，并链接上下
         {
            // qDebug()<<"找到并记录删除操作";
             jiLu_Temp=jiLu;//记录操作
             jiLu=new logic;
             *jiLu=*b;
             jiLu->addr=jiLu_Temp;//旧地址放新单元
             jiLu_Temp->addr2=jiLu;//新地址放旧单元
             jiLu->Del=true;
             jiLu_NEW=jiLu;

             delete b;shang->addr=xia;
             break;
         }
         if((xia->x==x)&&(xia->y==y)&&(xia==logicNEW)&&(xia->leiXin!="S"))//删除链表末端
         {
             //qDebug()<<"找到并记录删除操作";
             jiLu_Temp=jiLu;//记录操作
             jiLu=new logic;
             *jiLu=*xia;
             jiLu->addr=jiLu_Temp;//旧地址放新单元
             jiLu_Temp->addr2=jiLu;//新地址放旧单元
             jiLu->Del=true;
             jiLu_NEW=jiLu;

             delete xia;b->addr=NULL;logicNEW=b;logicTU=logicNEW;
             break;
         }
         if((xia==logicNEW)||(logicNEW==NULL))//链表查询结束或没有逻辑时结束
         {return ;}
         shang=b;
         b=xia;
         xia=xia->addr;//进入下个存储单元
     }

 }
 void MainWindow::del_S(int x,int y)//删除"S"链表单元
 {
     logic *b=logic_O;
     logic *shang;
     logic *xia=logic_O;

     NO_2();//删除原先还原路径

     while (1) {
         if( ((b->x)==x)&&((b->y)==y)&&(b->leiXin=="S") )//删除一个链表单元，并链接上下
         {
             /*qDebug()<<"找到S并记录删除操作";*/
             jiLu_Temp=jiLu;//记录操作
             jiLu=new logic;
             *jiLu=*b;
             jiLu->addr=jiLu_Temp;//旧地址放新单元
             jiLu_Temp->addr2=jiLu;//新地址放旧单元
             jiLu->Del=true;
             jiLu_NEW=jiLu;

             delete b;shang->addr=xia;
             break;
         }
         if((xia->x==x)&&(xia->y==y)&&(xia==logicNEW)&&(xia->leiXin=="S"))//删除链表末端
         {
             /*qDebug()<<"找到S并记录删除操作";*/
             jiLu_Temp=jiLu;//记录操作
             jiLu=new logic;
             *jiLu=*xia;
             jiLu->addr=jiLu_Temp;//旧地址放新单元
             jiLu_Temp->addr2=jiLu;//新地址放旧单元
             jiLu->Del=true;
             jiLu_NEW=jiLu;

             delete xia;b->addr=NULL;logicNEW=b;logicTU=logicNEW;
             break;
         }
         if((xia==logicNEW)||(logicNEW==NULL))//链表查询结束或没有逻辑时结束
         {/*qDebug()<<"链表查询结束未找到S";*/return ;}
         shang=b;
         b=xia;
         xia=xia->addr;//进入下个存储单元
     }

 }

 void MainWindow::NO_2()//为避免两条还原情况当出现，当新建新逻辑时删除记录链表juLu以后的链单元
 {
     while (1) {
         if(jiLu!=jiLu_NEW){
             jiLu_Temp=jiLu_NEW;
             jiLu_NEW=jiLu_NEW->addr;
             delete jiLu_Temp;
         }
         else if(jiLu==jiLu_NEW){
             break;
         }
     }
     //qDebug()<<"删除记录链表juLu以后的链单元";
 }

 void  MainWindow::wjl_del(int x,int y)//无记录删除逻辑
 {
     logic *b=logic_O;
     logic *shang;
     logic *xia=logic_O;

     while (1) {
         if( ((b->x)==x)&&((b->y)==y)&&(b->leiXin!="S") )//删除一个链表单元，并链接上下
         {
             /*qDebug()<<"找到并删除 不记录";*/
             delete b;shang->addr=xia;
             break;
         }
         if((xia->x==x)&&(xia->y==y)&&(xia==logicNEW)&&(xia->leiXin!="S"))//删除链表末端
         {
             /*qDebug()<<"找到并删除 不记录";*/
             delete xia;b->addr=NULL;logicNEW=b;logicTU=logicNEW;
             break;
         }
         if((xia==logicNEW)||(logicNEW==NULL))//链表查询结束或没有逻辑时结束
         {/*qDebug()<<"链表查询结束未找到";*/return ;}
         shang=b;
         b=xia;
         xia=xia->addr;//进入下个存储单元
     }

 }
 void  MainWindow::wjl_del_S(int x,int y)//无记录删除逻辑S
 {
     logic *b=logic_O;
     logic *shang;
     logic *xia=logic_O;

     while (1) {
         if( ((b->x)==x)&&((b->y)==y)&&(b->leiXin=="S") )//删除一个链表单元，并链接上下
         {
             /*qDebug()<<"找到并删除 不记录";*/
             delete b;shang->addr=xia;
             break;
         }
         if((xia->x==x)&&(xia->y==y)&&(xia==logicNEW)&&(xia->leiXin=="S"))//删除链表末端
         {
             /*qDebug()<<"找到并删除 不记录";*/
             delete xia;b->addr=NULL;logicNEW=b;logicTU=logicNEW;
             break;
         }
         if((xia==logicNEW)||(logicNEW==NULL))//链表查询结束或没有逻辑时结束
         {/*qDebug()<<"链表查询结束未找到S";*/return ;}
         shang=b;
         b=xia;
         xia=xia->addr;//进入下个存储单元
     }

 }

logic * MainWindow::set_logic(int x,int y)
{
    logic* logicTemp;
    logicTU=logic_O;
    while (1) {
        if( ((logicTU->x)==x)&&((logicTU->y)==y)&&(logicTU->leiXin!="S") )
        {logicTemp=logicTU;/*qDebug()<<"找到"*/;break;}
        if((logicTU==logicNEW)||(logicNEW==NULL))//链表查询结束或没有逻辑时返货数据空对象
            {/*qDebug()<<"链表查询结束";*/return NULL;}
        logicTU=logicTU->addr;//进入下个存储单元
    }
    if(logicNEW!=NULL)
       logicTU=logicNEW;
    return logicTemp;
}

void MainWindow::on_del_button_pressed()
{
   ui->widget_2->setVisible(false);
   if(((mouseX%120>90)||(mouseX%120<30))&&xuanZhong==false){
       int x=mouseX,y=mouseY;
       if((x%120>60)&&(y%70>35)){
           x=x/120+1;
           y=y/70+1;
       }
       else if((x%120<60)&&(y%70<35)){
           x=x/120;
           y=y/70;
       }
       else if((x%120>60)&&(y%70<35)){
           x=x/120+1;
           y=y/70;
       }
       else if((x%120<60)&&(y%70>35)){
           x=x/120;
           y=y/70+1;
       }
       del_S(x,y);
   }
   else if(xuanZhong==true){
       del_ku();
   }
   else{
       del(mouseX/120,mouseY/70);
   }

   xuanZhong=false;
   update();
}

void MainWindow::on_lineEdit_editingFinished()
{
    //ui->label->setVisible(false);
    //ui->lineEdit->setVisible(false);
    if( (set_logic(gbX,gbY)!=NULL)&&(ui->lineEdit->text()!="")&&!(set_logic(gbX,gbY)->leiXin=="XianQuan"&&text.mid(0,1)=="x")
            &&(text.mid(0,1)=="x"||text.mid(0,1)=="y"||text.mid(0,1)=="m"||text.mid(0,1)=="t")){
    set_logic(gbX,gbY)->bianHao=text.mid(1).toInt();
    set_logic(gbX,gbY)->pin_leiXin=text.mid(0,1);
    qDebug()<<"引脚设置成功"<<text.mid(1).toInt()<<text.mid(0,1);
    //给记录信息也设置编号
    logic* temp=jiLu_o;
    while(1){
        if((temp->x==gbX)&&(temp->y==gbY)){
            temp->bianHao=text.mid(1).toInt();
            temp->pin_leiXin=text.mid(0,1);
        }
        if(temp==jiLu_NEW)
            break;
        temp=temp->addr2;
    }
    }
    update();
}

void MainWindow::on_lineEdit_textChanged(const QString &arg1)
{
    text=arg1;
    set_x=mouseX/120;
    set_y=mouseY/70;
}

logic MainWindow::textFormatCheck(QString text)
{
    /*指令      参数/对象      参数           示例         解释
     * LD      [X/Y/M/S]   [引脚号/编号]     ld x1       常开X1
     * LDI     [X/Y/M]   [引脚号/编号]     ldi x1      常闭X1
     * OUT     [Y/M]     [引脚号/编号]     out y1      线圈Y1
     * LDP     [X/M]     [引脚号/编号]     ldp x1      检测X1的上升沿,如果检测到上升沿则输出一个周期的闭合
     * LDF     [X/M]     [引脚号/编号]     ldf x1      检测X1的下降沿,如果检测到上升沿则输出一个周期的闭合
     * SET     [M/Y/S]     [引脚号/编号]     set m1      输入端true则置位被操作对象，输入端为false不动作
     * RST     [M/Y/S]     [引脚号/编号]     rst y1      输入端true则复位被操作对象，输入端为false不动作
     * T       [编号]    [(延时值)MS/S] t1 100ms    输入端由false变为true时，延时100ms(毫秒)后输出端由false变为true，输入端变为false时输出端也变为false(s为秒，ms为毫秒)
     *OR       []       []                []
     * 。。。。
    */

     canShu retu=fenJie(text);
     qDebug()<<"分解"<<retu.can1<<retu.can2<<retu.can3;
     logic temp;
     if(retu.can1!=""){//输入内容真确则执行，优化执行效率
         temp.pin_leiXin=retu.can2;
         if("LD"==retu.can1.toUpper()){
             temp.leiXin="ChangKai";
         }
         else if("LDI"==retu.can1.toUpper() && "S"!=temp.pin_leiXin.toUpper()){
                 temp.leiXin="ChangBi";
         }
         else if("OUT"==retu.can1.toUpper() && "X"!=temp.pin_leiXin.toUpper() && "S"!=temp.pin_leiXin.toUpper()){
             temp.leiXin="XianQuan";
         }
         else if("LDP"==retu.can1.toUpper() && temp.pin_leiXin.toUpper()!="S" && temp.pin_leiXin.toUpper()!="Y"){
             temp.leiXin="ShangShenYan";
         }
         else if("LDF"==retu.can1.toUpper() && temp.pin_leiXin.toUpper()!="S" && temp.pin_leiXin.toUpper()!="Y"){
             temp.leiXin="XiaJianYan";
         }
         else if("SET"==retu.can1.toUpper() && temp.pin_leiXin.toUpper()!="X"){
             temp.leiXin="SET";
         }
         else if("RST"==retu.can1.toUpper() && temp.pin_leiXin.toUpper()!="X"){
             temp.leiXin="RST";
         }
         else if("T"==retu.can1.mid(0,1).toUpper() &&(temp.pin_leiXin=="MS"||temp.pin_leiXin=="S")&&(retu.can1.mid(1)!="")){
             temp.leiXin=retu.can1.toUpper();
         }
         temp.bianHao=retu.can3;
     }
     if(temp.leiXin==""){
         temp.bianHao=0;
         temp.pin_leiXin="";
     }
     return temp;

}

canShu MainWindow::fenJie(QString text)
{
    canShu retu;
    QString temp;
    text.insert(0," ");
    temp=text.section(" ",1,1);
    if(temp=="ld" ||temp=="LD"
            ||temp=="ldi" ||temp=="LDI"
            ||temp=="out"||temp=="OUT"
            ||temp=="ldp"||temp=="LDP"
            ||temp=="ldf"||temp=="LDF"
            ||temp=="set"||temp=="SET"
            ||temp=="rst"||temp=="RST"){//判断输入字符的格式是否符合语法

        retu.can1=temp;
        temp=text.section(" ",2,2);
        if(temp.length()==1&&(temp.toUpper()=="X"||temp.toUpper()=="Y"||temp.toUpper()=="M"||temp.toUpper()=="T"||temp.toUpper()=="S")){//输入时x和编号间有空格情况
            if((retu.can1.toUpper()=="SET"||retu.can1.toUpper()=="RST")&&(temp.toUpper()=="X"))//为SET和RST时不可以为X
                goto hole;//函数返回空
            retu.can2=temp;
            temp=text.section(" ",3,3);
            if(isDigitStr(temp)&&temp.length()>0 && text.section(" ",4,4)=="" &&(((retu.can2.toUpper()=="X"||retu.can2.toUpper()=="Y")&&temp.toInt()<8)||((retu.can2.toUpper()=="T")&&temp.toInt()<10)||((retu.can2.toUpper()=="M")&&temp.toInt()<50))){//逻辑单元为X或Y时引脚编号要小于8
                retu.can3=temp.toInt();
                return retu;
            }
            else{
                retu.can1="";retu.can2="";retu.can3=0;return retu;
            }
        }
        else if(temp.length()>1){//输入时x和间编号没有空格情况
            temp=temp.mid(0,1);
            if(temp.toUpper()=="X"||temp.toUpper()=="Y"||temp.toUpper()=="M"||temp.toUpper()=="T"||temp.toUpper()=="S"){
                if((retu.can1.toUpper()=="SET"||retu.can1.toUpper()=="RST")&&(temp.toUpper()=="X"))//为SET和RST时不可以为X
                    goto hole2;//函数返回空
                if (isDigitStr(text.section(" ",2,2).mid(1))&&(((temp.toUpper()=="X"||temp.toUpper()=="Y")&&text.section(" ",2,2).mid(1).toInt()<8)||((temp.toUpper()=="T")&&text.section(" ",2,2).mid(1).toInt()<10)||((temp.toUpper()=="M")&&text.section(" ",2,2).mid(1).toInt()<50))){//逻辑单元为X或Y时引脚编号要小于8
                    retu.can2=temp;retu.can3=text.section(" ",2,2).mid(1).toInt();
                }
                else{
                    retu.can1="";retu.can2="";retu.can3=0;return retu;
                }
            }
            else{
                retu.can1="";retu.can2="";retu.can3=0;return retu;
            }
        }
        else{
            retu.can1="";retu.can2="";retu.can3=0;return retu;
        }

    }
    else if((temp.mid(0,1)=="T"||temp.mid(0,1)=="t")&&isDigitStr(temp.mid(1))){//输入为T延时
        retu.can1=temp.toUpper();
        temp=text.section(" ",2,2);
        if(temp.indexOf("ms",Qt::CaseInsensitive)!=-1&&isDigitStr(temp.replace("ms","",Qt::CaseInsensitive))){
            retu.can2="MS";
            retu.can3=temp.replace("ms","",Qt::CaseInsensitive).toInt();
            return retu;
        }
        else if(temp.indexOf("s",Qt::CaseInsensitive)!=-1&&isDigitStr(temp.replace("s","",Qt::CaseInsensitive))){
            retu.can2="S";
            retu.can3=temp.replace("s","",Qt::CaseInsensitive).toInt();
            return retu;
        }
        else
            goto hole3;
    }
    else{
        hole :
        hole2 :
        hole3 :
        retu.can1="";retu.can2="";retu.can3=0;return retu;
    }


    return retu;
}

bool MainWindow::isDigitStr(QString src)
{
    QByteArray ba = src.toLatin1();//QString 转换为 char*
     const char *s = ba.data();

    while(*s && *s>='0' && *s<='9') s++;

    if (*s)
    { //不是纯数字
        return false;
    }
    else
    { //纯数字
        return true;
    }
}

void MainWindow::del_ku()
{
    bool one=false;
    bool biaoji=false;
    logic *s=NULL,*m=NULL;
    int x=pressX;
    int y=pressY;
    int ry=releaseY;
    pressX=(pressX-10)/120;
    pressY=(pressY-67)/70;
    releaseX=(releaseX-10)/120;
    releaseY=(releaseY-67)/70;
    qDebug()<<"pressX"<<pressX<<"pressY"<<pressY<<"releaseX"<<releaseX<<"releaseY"<<releaseY;
    out_w->label2()->setText(out_w->label2()->text()+'\n'+"pressX "+QString::number(pressX)+" pressY "+QString::number(pressY)+" releaseX "+QString::number(releaseX)+" releaseY "+QString::number(releaseY));
    if(tongJi(pressX,pressY,releaseX,releaseY)==0&&tongJi_S((x-10)/120+1,(y-35-67)/70+1,releaseX,(ry-67-35)/70+1)==0)
        return;
    int weiX=huoDe_weiX(pressX,pressY,releaseX,releaseY);
    int weiY=huoDe_weiY(pressX,pressY,releaseX,releaseY);
    qDebug()<<"尾部X"<< weiX<<"尾部Y"<<weiY;
    out_w->label2()->setText(out_w->label2()->text()+'\n'+"尾部X "+QString::number(weiX)+" 尾部Y "+QString::number(weiY));

    for(int i=0;i<200;i++){
            if(chaXun(pressX,pressY).leiXin!=""&&one==false){
                one=true;
                del(pressX,pressY);
                s=jiLu;//记录块的起始地址
                biaoji=true;
            }
            if(pressX==weiX&&pressY==weiY){
                del(pressX,pressY);
                if(tongJi_S((x-10)/120+1,(y-35-67)/70+1,releaseX,(ry-67-35)/70+1)==0)//如果选中的块中没有S逻辑对象，则此时的jiLu地址为记录块的尾部地址
                    m=jiLu;
            }
            else if(chaXun(pressX,pressY).leiXin!=""){
                del(pressX,pressY);
            }


        if((pressX==releaseX) && (pressY==releaseY))//退出循环
            break;
        if(pressX==releaseX){//控制增加
            pressY++;
            pressX=(x-10)/120;
        }
        else
        pressX++;
    }


    //删除块中的S逻辑对象
    one=false;
    pressY=(y-35-67)/70+1;
    pressX=(x-10)/120+1;
    releaseY=(ry-67-35)/70+1;

    int weiXS=huoDe_weiXS(pressX,pressY,releaseX,releaseY);
    int weiYS=huoDe_weiYS(pressX,pressY,releaseX,releaseY);
    if(pressX>releaseX||pressY>releaseY)//防止出现死循环，跳过特别项
        goto tiao;
    qDebug()<<"尾部X"<< weiXS<<"尾部Y"<<weiYS;
        for(int i=0;i<200;i++){
            if(chaXun_S(pressX,pressY).leiXin=="S"){
            qDebug()<<"调试2"<<pressX<<pressY<<releaseX<<releaseY;
            if(chaXun_S(pressX,pressY).leiXin=="S"&&one==false){
                one=true;
                if(biaoji==true){
                   del_S(pressX,pressY);
                   }
                else{
                    del_S(pressX,pressY);
                    s=jiLu;
                }
            }
            if(pressX==weiXS&&pressY==weiYS){
                del_S(pressX,pressY);
                m=jiLu;
            }
            else if(chaXun_S(pressX,pressY).leiXin=="S"){
                del_S(pressX,pressY);
            }
            }
            if((pressX==releaseX) && (pressY==releaseY))
                break;
            if(pressX==releaseX){
                pressY++;
                pressX=(x-10)/120+1;
            }
            else
            pressX++;
        }
    tiao: ;
        s->mou=m;
        m->shi=s;
}

void MainWindow::copy_ku()
{
    if(xuanZhong==false){
        qDebug()<<"单个copy不执行" ;
        //logic_copy=new logic;
        //logic_copy_tou=logic_copy;
        return;
    }
    if(logic_copy_tou!=NULL)
        del_copyLian();
    qDebug()<<"copy_ku";
    int x=pressX;
    int y=pressY;
    int rx=releaseX;
    int ry=releaseY;
    logic_copy=new logic;
    logic_copy_tou=logic_copy;
    logic temp;
    pressX=(pressX-10)/120;
    pressY=(pressY-67)/70;
    releaseX=(releaseX-10)/120;
    releaseY=(releaseY-67)/70;
    if(tongJi(pressX,pressY,releaseX,releaseY)==0&&tongJi_S((x-10)/120+1,(y-35-67)/70+1,releaseX,(ry-67-35)/70+1)==0){
       qDebug()<<"选中框为空";
    }
    if(tongJi(pressX,pressY,releaseX,releaseY)==0)
        goto h;
    for(int i=0;i<200;i++){
       // qDebug()<<i;
        if(i>100)qDebug()<<"陷入死循环";
        temp=chaXun(pressX,pressY);
        if(temp.leiXin!=""&&temp.leiXin!="S"){
            qDebug()<<temp.leiXin;
            *logic_copy=temp;
            logic_copy->addr=new logic;
            logic_copy=logic_copy->addr;
        }
        if((pressX==releaseX) && (pressY==releaseY))//退出循环
            break;
        if(pressX==releaseX){//控制增加
          pressY++;
            pressX=(x-10)/120;
        }
        else
        pressX++;
    }
    h:
    if(tongJi_S((x-10)/120+1,(y-35-67)/70+1,releaseX,(ry-67-35)/70+1)==0){
        pressX=x;pressY=y;releaseY=ry;releaseX=rx;
        write_LD(logic_copy_tou,logic_copy);//在结束前吧copy块写进剪贴板
        del_copyLian();//删除copy链
        return;}
    pressY=(y-35-67)/70+1;
    pressX=(x-10)/120+1;
    releaseY=(ry-67-35)/70+1;
    for(int i=0;i<200;i++){
        if(i>100)qDebug()<<"陷入死循环";
        temp=chaXun_S(pressX,pressY);
        if(temp.leiXin=="S"){
            *logic_copy=temp;
            logic_copy->addr=new logic;
            logic_copy=logic_copy->addr;
        }
        if((pressX==releaseX) && (pressY==releaseY))
            break;
        if(pressX==releaseX){
            pressY++;
            pressX=(x-10)/120+1;
        }
        else
        pressX++;
    }
    pressX=x;pressY=y;releaseY=ry;releaseX=rx;
    write_LD(logic_copy_tou,logic_copy);//在结束前把copy块写进剪贴板
    del_copyLian();//删除copy链
}

void MainWindow::paste_ku()
{
    logic *s=NULL,*m=NULL;//块撤回（还原）时，方便jiLu链表块多个逻辑单元一次撤回，s和m是临时存储jiLu链表单元的
    read_LD();//将剪贴板中的内容读到
    int youX=100,topY=100;
    //copy为空时结束
    if(logic_copy_tou==NULL){
        ui->widget_2->setVisible(false);
        goto pa;}
    //确定右上角
    logic_copy=logic_copy_tou;
    for(int i=0;i<200;i++){
        if(i>100)
            qDebug()<<"陷入死循环";
        if(logic_copy->addr==NULL){
            break;
        }
        youX=logic_copy->x<youX? logic_copy->x:youX;
        topY=logic_copy->y<topY? logic_copy->y:topY;
        logic_copy=logic_copy->addr;
    }
    //防止重复逻辑
    logic_copy=logic_copy_tou;
    if(logic_copy->leiXin=="")
        return;
    for(int i=0;i<200;i++){
        if(i>100)
            qDebug()<<"陷入死循环";
        if(logic_copy->addr==NULL){
            break;
        }
        if((logic_copy->leiXin=="S"&&chaXun_S(logic_copy->x-youX+((pasteX-10)/120),logic_copy->y-topY+(pasteY-67)/70).leiXin=="S")
                ||((chaXun(logic_copy->x-youX+((pasteX-10)/120),logic_copy->y-topY+(pasteY-67)/70).leiXin!="S"
                &&chaXun(logic_copy->x-youX+((pasteX-10)/120),logic_copy->y-topY+(pasteY-67)/70).leiXin!="")&&logic_copy->leiXin!="S"))//存在重复逻辑结束
            return;//存在bug允许有S逻辑的地方放常见逻辑
        logic_copy=logic_copy->addr;
    }
    qDebug()<<"paste_ku"<<youX<<topY;
    logic_copy=logic_copy_tou;
    for(int i=0;i<200;i++){
        if(i>100)
            qDebug()<<"陷入死循环";
        if(logic_copy->addr==NULL){
            m=jiLu;
            break;
        }

        logicTU->addr=new logic;
        logicTU=logicTU->addr;
        *logicTU=*logic_copy;
        logicTU->x-=youX;
        logicTU->x+=((pasteX-10)/120);
        logicTU->y-=topY;
        logicTU->y+=(pasteY-67)/70;
        logicTU->addr=NULL;
        logic_copy=logic_copy->addr;
        //记录操作
        jiLu_Temp=jiLu;//记录操作
        jiLu=new logic;
        *jiLu=*logicTU;
        jiLu->addr=jiLu_Temp;//旧地址放新单元
        jiLu_Temp->addr2=jiLu;//新地址放旧单元
        jiLu->Del=false;
        jiLu_NEW=jiLu;
        if(s==NULL)
            s=jiLu;
    }
    s->mou=m;//在jiLu链表中交换，让恢复（撤回）多个逻辑单元时知道何时停止
    m->shi=s;
    logicNEW=logicTU;
    pa:
    update();
}

void MainWindow::del_copyLian()
{
    logic *temp=NULL;
    logic_copy=logic_copy_tou;
    if(logic_copy->leiXin=="")
        return;
    for(int i=0;i<200;i++){
        if(logic_copy->addr==NULL)
            i=200;
        temp=logic_copy->addr;
        delete logic_copy;
        logic_copy=temp;
    }
}

void MainWindow::drawR(QPainter * p,int px, int py, int rx, int ry)
{
    px=((px-10)/120)*120;
    py=((py-67)/70)*70;
    rx=((rx-10)/120+1)*120;
    ry=((ry-67)/70+1)*70;
    p->setPen(Qt::NoPen);
    p->setBrush(Qt::gray);
    p->drawRect(px+10,py+67,rx-px,ry-py);
}
int  MainWindow::S_x(int x,int y)
{
    if((x%120>60)&&(y%70>35)){
        x=x/120+1;
        y=y/70+1;
    }
    else if((x%120<60)&&(y%70<35)){
        x=x/120;
        y=y/70;
    }
    else if((x%120>60)&&(y%70<35)){
        x=x/120+1;
        y=y/70;
    }
    else if((x%120<60)&&(y%70>35)){
        x=x/120;
        y=y/70+1;
    }
    return x;

}
int  MainWindow::S_y(int x,int y)
{
    if((x%120>60)&&(y%70>35)){
        x=x/120+1;
        y=y/70+1;
    }
    else if((x%120<60)&&(y%70<35)){
        x=x/120;
        y=y/70;
    }
    else if((x%120>60)&&(y%70<35)){
        x=x/120+1;
        y=y/70;
    }
    else if((x%120<60)&&(y%70>35)){
        x=x/120;
        y=y/70+1;
    }
    return y;

}

int MainWindow::huoDe_weiX(int px,int py,int rx,int ry)
{

    int rx_copy=rx;
    for(int i=0;i<200;i++){
        if(chaXun(rx,ry).leiXin!=""){//找到尾部逻辑单元
            return rx;
        }
        if(rx==px&&ry==py){//块扫描完毕跳出
            return 0;//空，没有尾部单元
        }
        if(rx==px){//走到端点y上移x归原位
            rx=rx_copy;
            ry--;
        }
        else
           rx--;
    }
    return 0;//空，没有尾部单元
}
int MainWindow::huoDe_weiY(int px,int py,int rx,int ry)
{

    int rx_copy=rx;
    for(int i=0;i<200;i++){
        if(chaXun(rx,ry).leiXin!=""){//找到尾部逻辑单元
            return ry;
        }
        if(rx==px&&ry==py){//块扫描完毕跳出
            return 0;//空，没有尾部单元
        }
        if(rx==px){//走到端点y上移x归原位
            rx=rx_copy;
            ry--;
        }
        else
           rx--;
    }
    return 0;//空，没有尾部单元
}
int MainWindow::huoDe_weiXS(int px,int py,int rx,int ry)
{

    int rx_copy=rx;
    for(int i=0;i<200;i++){
        if(chaXun_S(rx,ry).leiXin!=""){//找到尾部逻辑单元
            return rx;
        }
        if(rx==px&&ry==py){//块扫描完毕跳出
            return 0;//空，没有尾部单元
        }
        if(rx==px){//走到端点y上移x归原位
            rx=rx_copy;
            ry--;
        }
        else
           rx--;
    }
    return 0;//空，没有尾部单元
}

int MainWindow::huoDe_weiYS(int px,int py,int rx,int ry)
{

    int rx_copy=rx;
    for(int i=0;i<200;i++){
        if(chaXun_S(rx,ry).leiXin!=""){//找到尾部逻辑单元
            return ry;
        }
        if(rx==px&&ry==py){//块扫描完毕跳出
            return 0;//空，没有尾部单元
        }
        if(rx==px){//走到端点y上移x归原位
            rx=rx_copy;
            ry--;
        }
        else
           rx--;
    }
    return 0;//空，没有尾部单元
}
int  MainWindow::tongJi(int px,int py,int rx,int ry)//函数用来返回被选中框中的非S逻辑个数
{
    int k=0,px_copy=px;
    for(int i=0 ;i<200;i++){
        QString temp=chaXun(px,py).leiXin;
        if(temp!=""&&temp!="S")
            k++;
        if(px==rx&&py==ry)
            break;
        if(px==rx){
            px=px_copy;
            py++;
        }
        else
            px++;
    }
    return k;
}
int  MainWindow::tongJi_S(int px,int py,int rx,int ry)//函数用来返回被选中框中的逻辑s个数
{
    int k=0,px_copy=px;
    for(int i=0 ;i<200;i++){
        QString temp=chaXun_S(px,py).leiXin;
        if(temp=="S")
            k++;
        if(px==rx&&py==ry)
            break;
        if(px==rx){
            px=px_copy;
            py++;
        }
        else
            px++;
    }
    return k;
}



void MainWindow::copy_Button_2_released()
{
    qDebug()<<"右键copy";
    copy_ku();
}

void MainWindow::cut_pushButton_3_released()
{
    qDebug()<<"右键cut";
    copy_ku();del_ku();
}

void MainWindow::paste_pushButton_4_released()
{
    qDebug()<<"右键paste";
    paste_ku();
}


QString  MainWindow::compile()
{
    ret ="";
    QTime jiShi;//计时编译时间
    jiShi.start();
    /*编译函数
     */
    tianXie_compileY0();
    int compileY=0;
    //这里进入循环
    while(1){
        jiShi.restart();
        for(;compileY<1000;compileY++){//编译完一个小块后向下移动
            if(compileY==999)
                goto gotoDB;
            if(compileMuXian[compileY]==true){
                qDebug()<<"出来原因"<<compileY;
                break;
            }
        }

        //把链表里的逻辑单元读入到数组里
        bool xy[20][30]=bool_cs2030,xys[20][30]=bool_cs2030;//定义及初始化
        logic *logicxy[20][30]=null_cs2030, *logicxys[20][30]=null_cs2030;//指针数组，方便快速访问逻辑单元
        logic *logicTemp=logic_O;
        for(int i=0;i<200;i++){
            if(logicTemp->x!=5555 && logicTemp->y!=5555  && logicTemp->leiXin!="S" && logicTemp->x<20  &&  logicTemp->y<compileY+30 && logicTemp->y>=compileY ){
                xy[logicTemp->x][logicTemp->y-compileY]=true;
                logicxy[logicTemp->x][logicTemp->y-compileY]=logicTemp;
            }
            else if(logicTemp->x!=5555 && logicTemp->y!=5555  && logicTemp->leiXin=="S"&& logicTemp->x<20  &&  logicTemp->y<compileY+30 && logicTemp->y>=compileY ){
                xys[logicTemp->x][logicTemp->y-compileY]=true;
                logicxys[logicTemp->x][logicTemp->y-compileY]=logicTemp;
            }

            if(logicTemp==logicNEW)
                break;
            logicTemp=logicTemp->addr;
        }


        //病毒侵染式，来找到所有连接在一起的块

        bool ZQJD[20][30]=bool_cs2030;//入侵的最前端节点
        bool XZQJD[20][30]=bool_cs2030;//新入侵的最前端节点
        bool YRQ[20][30]=bool_cs2030;//已入侵的逻辑单元
        bool YRQS[20][30]=bool_cs2030;//已入侵的S逻辑单元
        ZQJD[0][0]=true;//第入侵一个节点
        while(1){
            for(int i=0;i<20;i++)
                for(int j=0;j<30;j++){//遍历每个节点
                    if(ZQJD[i][j]==true){//找到最前入侵节点
                        if(i==0){//当入侵节点为母线上时，不可以上下左侵入
                            if(YRQ[i][j]==false && xy[i][j]==true){//入侵右单元，看右单元是否未侵入
                                YRQ[i][j]=true;//标记为以入侵
                                XZQJD[i+1][j]=true;//在新入侵的最前节点数组上标记
                            }
                        }
                        else{//当入侵节点不在母线上时
                            if(YRQ[i][j]==false && xy[i][j]==true){//入侵右单元，看右单元是否未侵入
                                YRQ[i][j]=true;//标记为以入侵
                                XZQJD[i+1][j]=true;//在新入侵的最前节点数组上标记
                            }
                            if(YRQ[i-1][j]==false && xy[i-1][j]==true){//入侵左单元，看左单元是否未侵入
                                YRQ[i-1][j]=true;
                                XZQJD[i-1][j]=true;
                            }
                            if( j-1>=0 && YRQS[i][j]==false && xys[i][j]==true){//向上入侵单元，看向上是否未侵入
                                YRQS[i][j]=true;
                                XZQJD[i][j-1]=true;
                            }
                            if( j+1<20 && YRQS[i][j+1]==false && xys[i][j+1]==true){//向下入侵单元，看向下是否未侵入
                                YRQS[i][j+1]=true;
                                XZQJD[i][j+1]=true;
                            }

                        }
                    }
                }
            int dd=0;
            for(int i=0;i<20;i++)
                for(int j=0;j<30;j++){
                    if(XZQJD[i][j]==true)
                        dd++;//记录新增节点个数
                    ZQJD[i][j]=XZQJD[i][j];
                    XZQJD[i][j]=0;//新的入侵最前节点替换旧的
                }
            if(dd==0)//新增记录节点为零则入侵结束
                break;
        }
        for(int y=0;y<30;y++){
            if(YRQ[0][y]==true){
                compileMuXian[compileY+y]=false;
                qDebug()<<"compileY+y:"<<compileY+y;
            }
        }


        //统一同一节点名称
        int xy_jDName[20][30][2];//新建节点数组【x】【Y】【0该节点是否入侵了/1节点名称】
        for(int i=0;i<20;i++)//初始化数组
            for(int j=0;j<30;j++){
                xy_jDName[i][j][0]=0;
                xy_jDName[i][j][1]=-1;
            }
        for(int i=0;i<20;i++)//往节点数组里填入是否入侵了的信息
            for(int j=0;j<30;j++){
                if(YRQ[i][j]==1){
                    if(i+1<30)
                        xy_jDName[i][j][0]=xy_jDName[i+1][j][0]=1;
                }
                if(YRQS[i][j]==1){
                    if(i-1>=0)
                        xy_jDName[i][j-1][0]=xy_jDName[i][j][0]=1;
                }
            }
        int jd=0,jd2=0;
        for(int i=0;i<20;i++)//统一同一节点名称
            for(int j=0;j<30;j++){
                if(xy_jDName[i][j][0]==1 && xy_jDName[i][j][1]==-1){//节点存在&&节点未被设置名字
                    int xx=i,yy=j,zqjd[20][30]=int_cs2030,xzqjd[20][30]=int_cs2030,yrqjd[20][30]=int_cs2030;
                    if(i==0){//节点在母线上
                        xy_jDName[i][j][1]=0;
                        yrqjd[i][j]=1;
                        jd=0;
                    }
                    else{
                        jd=jd2;
                        jd++;
                        jd2=jd;
                        xy_jDName[i][j][1]=jd;
                    }
                    qDebug()<<jd;
                    //病毒式传染标记同一节点
                    zqjd[xx][yy]=1;
                    while(1){
                        for(int i=0;i<20;i++)
                            for(int j=0;j<30;j++){
                                if(zqjd[i][j]==1){//最前节点
                                    if(j-1>=0 && YRQS[i][j]==1 && yrqjd[i][j-1]==0 ){//往上有路 && 数组不会越界  &&  节点没有被访问
                                        xzqjd[i][j-1]=1;//添加新节点到数组
                                        yrqjd[i][j-1]=1;//标记为已访问
                                        xy_jDName[i][j-1][1]=jd;
                                    }
                                    if(j+1<30 && YRQS[i][j+1]==1 && yrqjd[i][j+1]==0){//往下有路 && 数组不会越界  &&  节点没有被访问
                                        xzqjd[i][j+1]=1;//添加新节点到数组
                                        yrqjd[i][j+1]=1;//标记为已访问
                                        xy_jDName[i][j+1][1]=jd;
                                    }
                                    if(i-1>=0 && logicxy[i-1][j]!=NULL && logicxy[i-1][j]->leiXin=="H" && yrqjd[i-1][j]==0){//往左有路 && 数组不会越界  &&  节点没有被访问
                                        xzqjd[i-1][j]=1;//添加新节点到数组
                                        yrqjd[i-1][j]=1;//标记为已访问
                                        xy_jDName[i-1][j][1]=jd;
                                    }
                                    if(i+1<20 && logicxy[i][j]!=NULL && logicxy[i][j]->leiXin=="H" && yrqjd[i+1][j]==0){//往右有路 && 数组不会越界  &&  节点没有被访问
                                        xzqjd[i+1][j]=1;//添加新节点到数组
                                        yrqjd[i+1][j]=1;//标记为已访问
                                        xy_jDName[i+1][j][1]=jd;
                                    }
                                }
                            }
                        int ff=0;
                        for(int i=0;i<20;i++)
                            for(int j=0;j<30;j++){
                                if(xzqjd[i][j]==1)
                                    ff++;
                                zqjd[i][j]=xzqjd[i][j];
                                xzqjd[i][j]=0;
                            }
                        if(ff==0)
                            break;
                    }
                }
            }
        /*此段程序用来显示20X30的矩阵数据，但用时及长
    for(int i=0;i<30;i++)
        for(int j=0;j<20;j++){
            ui->textBrowser->setText(ui->textBrowser->toPlainText()+QString::number(xy_jDName[j][i][1],10)+" ");
            if(j==19)
                ui->textBrowser->setText(ui->textBrowser->toPlainText()+"\n");
        }*/



        //逻辑链接
        int xy_logicJD[20][30][2];//[x][y][逻辑单元头节点名称，逻辑单元尾节点名称]
        int YBY[20][30];//已经编译了的逻辑单元
        for(int i=0;i<20;i++)
            for(int j=0;j<30;j++){//给每个逻辑单元填上头尾节点名称
                xy_logicJD[i][j][0]=xy_logicJD[i][j][1]=YBY[i][j]=0;
                if(YRQ[i][j]==1){
                    xy_logicJD[i][j][0]=xy_jDName[i][j][1];
                    xy_logicJD[i][j][1]=xy_jDName[i+1][j][1];
                }
            }

        struct JD{//链表中的单个节点单元
            int jd_name=0;
            JD* shang=NULL;
            JD* xia=NULL;
        };
        QString byDNA[jd+1];//[jd节点名称][1分支汇和记录AND逻辑编译结果]
        int fenCha_name=0;//分叉名称
        JD* zq_jd_tou=NULL;//最前节点链，头端单元
        JD* zq_jd_wei=NULL;//最前节点链，尾端单元
        JD* zq_jd=NULL;//最前节点链，当前访问单元
        int xjddc=0;//用于防止新节点链表头多次定义
        JD* x_jd_tou=NULL;//新入侵的节点链，头端单元
        JD* x_jd_wei=NULL;//新入侵的节点链，尾端单元
        JD* x_jd=NULL;//新入侵的节点链，当前访问单元

        zq_jd_tou=new JD;
        zq_jd_wei=new JD;
        zq_jd_tou->jd_name=0;//在最前节点中填入初始节点，即母线节点
        zq_jd_tou->shang=NULL;
        zq_jd_tou->xia=NULL;
        zq_jd=zq_jd_tou;
        *zq_jd_wei=*zq_jd_tou;//c++中结构体可以直接赋值，c不可以直接赋值
        int panDuanSFTC=0;//判断是否跳出,当新入侵链表当中添加了单元就置一
        QString fzcf="";//防止新节点重复添加
        while(1){//入侵式编译，逻辑单元连接
            xjddc=0;
            panDuanSFTC=0;
            while(1)
            {//整条链表
                //判断这个节点的汇合情况
                fzcf="";//防止新节点重复添加
                int jd_gs=0,dian[30][2];
                int HHFM=0,HHFZ=0;//汇合分母分子
                QString qmjd="";//汇合节点的前面的节点名称存储字符串
                jd_gs=JDtoXY(zq_jd->jd_name,xy_jDName,dian);//读取该节点的所有点
                for(int i=0;i<jd_gs;i++){
                    if(dian[i][0]-1>=0 && xy[dian[i][0]-1][dian[i][1]]==true && xy_jDName[dian[i][0]-1][dian[i][1]][1]!=zq_jd->jd_name){//该点前面存在logic单元&&前面的点不能是同一节点
                        if(qmjd.indexOf("_"+QString::number(xy_jDName[dian[i][0]-1][dian[i][1]][1])+"_")==-1){//该节点不存在
                            qmjd+=("_"+QString::number(xy_jDName[dian[i][0]-1][dian[i][1]][1])+"_");//加入到这个字符串
                            HHFM++;
                            if(YBY[dian[i][0]-1][dian[i][1]]==1){//得到以汇合节点,（前面节点在编译信息里,命名方式："_本节点名_h_汇合支节点名_）
                                HHFZ++;
                            }
                        }
                    }
                }

                //判断这个节点是否分叉了(判断依据找到两个下节点)
                int panDuanSFFC=0;
                for(int i=0;i<jd_gs;i++){
                    if(xy[dian[i][0]][dian[i][1]]==true && xy_jDName[dian[i][0]+1][dian[i][1]][1]!=zq_jd->jd_name){//该点后面存在logic单元
                        if(xy_jDName[dian[i][0]+1][dian[i][1]][1]!=panDuanSFFC && panDuanSFFC!=0){//该节后面的点！=上次点&&上次点！=初始值0
                            panDuanSFFC=1;goto fz;}//确定有分叉，退出for循环判断
                        if(panDuanSFFC==0)
                            panDuanSFFC=xy_jDName[dian[i][0]+1][dian[i][1]][1];
                    }
                }
                panDuanSFFC=0;//没有分叉时，pabDuanSFFC=0
fz:;

                //是汇合节点时
                QString byTemp="";
                JD *JDtemp1=NULL;
                if(HHFM!=0){//成立则该节点是汇合节点
goto_b:;
                    if(HHFZ<HHFM){//汇合没完全，该节点不动
                        if(fzcf.indexOf("_"+QString::number(zq_jd->jd_name)+"_")==-1){//防止汇合时重复添加新节点
                            fzcf+=("_"+QString::number(zq_jd->jd_name)+"_");//加入到这个字符串
                            if(xjddc==0){
                                xjddc=1;
                                x_jd=new JD;//添加新入侵的节点到新节点链表里
                                x_jd->jd_name=zq_jd->jd_name;
                                x_jd_tou=x_jd;}
                            else{
                                x_jd->xia=new JD;//添加新入侵的节点到新节点链表里
                                JDtemp1=x_jd;
                                x_jd=x_jd->xia;
                                x_jd->shang=JDtemp1;
                                x_jd->jd_name=zq_jd->jd_name;
                            }
                            panDuanSFTC=1;
                            goto goto1;
                        }
                    }
                    else if(HHFM!=0 && HHFM!=1 && HHFZ==HHFM){//汇合完全，该节点可以动了
                        QString hui[HHFM];//用来存储分支的字符串信息
                        int zhjd[HHFM];//汇合分支字符串最后节点名
                        for(int i=0;i<HHFM;i++){//每个汇合分支一个数组
                            hui[i]=byDNA[zq_jd->jd_name].section('#',i,i);
                            zhjd[i]=-1;
                        }
                        for(int i=0;i<HHFM;i++){//找字符串的最后节点
                            zhjd[i]=(hui[i].lastIndexOf("_f_")==-1)?-1:hui[i].mid(hui[i].lastIndexOf("_f_")+3,3).toInt();
                            qDebug()<<i<<" "<<hui[i]<<endl;
                        }
                        int max12=-1,max_gs=0,max_fc=5555;//找到出现次数大于等于二的分叉，且优先级数最大的分叉。
                        for(int i=0;i<HHFM;i++){
                            for(int j=0;j<HHFM;j++){//统计这个节点出现的次数
                                if(j!=i && zhjd[j]==zhjd[i] &&zhjd[j]!=-1)//自己不计入&&节点名称相同&&节点名称不是初始值
                                    max_gs++;
                            }
                            if(max_gs>=2 && zhjd[i]>max12){//出现次数大于二&&且优先级最大
                                max_fc=i;
                                max12=zhjd[i];
                                max_gs=(i==HHFM-1)?max_gs:0;
                            }
                        }
                        if(max_fc==5555){//没有个数大于等于两个的汇合小分差了
                            bool to1=true;
                            QString temp="";
                            temp+=QString("(");
                            for(int i=0;i<HHFM;i++){
                                if(to1==true){
                                    to1=false;
                                    if(hui[i].indexOf("_f_")!=-1){
                                        temp+=QString("(")+hui[i].mid(hui[i].lastIndexOf("_f_")+7)+")";
                                    }
                                    else{
                                        temp+=QString("(")+hui[i]+")";
                                    }
                                }
                                else{
                                    if(hui[i].indexOf("_f_")!=-1){
                                        temp+=QString("||(")+hui[i].mid(hui[i].lastIndexOf("_f_")+7)+")";
                                    }
                                    else{
                                        temp+=QString("||(")+hui[i]+")";
                                    }
                                }
                            }
                            temp+=QString(")");
                            byDNA[zq_jd->jd_name]=temp;
                            goto goto_s;//
                        }
                        QString h="",h1="",orr="",temp_str="";int cc=0,bb=0,xc=0;//合成消除掉了一个分叉;递归xc下次汇合分支个数
                        for(int i=0;i<HHFM;i++){
                            if(zhjd[i]!=zhjd[max_fc]){//收集不是汇合小分叉的汇合分支
                                xc++;
                                if(cc==0){//收集第一个前面不要#
                                    h=hui[i];
                                    cc=1;
                                }
                                else
                                    h+=QString("#")+hui[i];
                            }
                            else{//是汇合小分叉的汇合分支
                                if(bb==0){//收集or小分叉时，第一次前面不要加||
                                    bb=1;
                                    temp_str=hui[i].mid(hui[i].lastIndexOf("_f_")+7);
                                    if(temp_str[0]=='&')
                                        orr=QString("(")+temp_str.mid(2)+")";
                                    else
                                        orr=QString("(")+temp_str+")";
                                }
                                else{
                                    temp_str=hui[i].mid(hui[i].lastIndexOf("_f_")+7);
                                    if(temp_str[0]=='&')
                                        orr+=QString("||")+"("+temp_str.mid(2)+")";
                                    else
                                        orr+=QString("||")+"("+temp_str+")";
                                }
                            }
                        }
                        if(hui[max_fc].indexOf("_f_")!=-1 && hui[max_fc].mid(0,hui[max_fc].lastIndexOf("_f_"))!="")//汇合小分叉的前面字符串
                            h1=hui[max_fc].mid(0,hui[max_fc].lastIndexOf("_f_"));
                        if(h=="" && h1!="")//h剩下其它汇和分叉,h1汇合小分叉的前面字符串
                            byDNA[zq_jd->jd_name]=h1+"&&("+orr+")";
                        else if(h!="" && h1 =="")
                            byDNA[zq_jd->jd_name]=h+"#("+orr+")";
                        else if(h=="" && h1=="")
                            byDNA[zq_jd->jd_name]=QString("(")+orr+")";
                        else if(h!="" && h1!="")
                            byDNA[zq_jd->jd_name]=h+"#"+h1+"&&"+"("+orr+")";
                        qDebug()<<"汇合小分叉后："<<byDNA[zq_jd->jd_name]<<endl;
                        HHFZ=HHFM=xc+1;
                        goto goto_b;
                    }
                }
goto_s:;
                //分叉信息加入到编译当中
                if(panDuanSFFC==1){
                    byDNA[zq_jd->jd_name]+=(QString("_f_")+QString::number(((fenCha_name)/100)%10)+QString::number(((fenCha_name)/10)%10)+QString::number((fenCha_name)%10)+"_");
                    fenCha_name++;
                }

                for(int i=0;i<jd_gs;i++){
                    if(xy[dian[i][0]][dian[i][1]]==true && YBY[dian[i][0]][dian[i][1]]==false && logicxy[dian[i][0]][dian[i][1]]->leiXin!="H"){//该点后面存在logic单元&&没有编译
                        YBY[dian[i][0]][dian[i][1]]=true;//标记该逻辑为以编译
                        if(xy_jDName[dian[i][0]][dian[i][1]][1]==0)//当逻辑直接连接母线时byTemp前面不用加“&&”
                            byTemp=QString("(")+logicxy[dian[i][0]][dian[i][1]]->leiXin+logicxy[dian[i][0]][dian[i][1]]->pin_leiXin+QString::number(logicxy[dian[i][0]][dian[i][1]]->bianHao);//byTemp的初始值
                        else
                            byTemp=QString("&&")+"("+logicxy[dian[i][0]][dian[i][1]]->leiXin+logicxy[dian[i][0]][dian[i][1]]->pin_leiXin+QString::number(logicxy[dian[i][0]][dian[i][1]]->bianHao);//byTemp的初始值
                        for(int j=0;j<jd_gs;j++){//头尾节点相同或单元
                            if(xy[dian[j][0]][dian[j][1]]==true&& j!=i//该点后面存在logic单元&&j!=i(不是同一个逻辑单元)
                                    && xy_logicJD[dian[j][0]][dian[j][1]][0]==xy_logicJD[dian[i][0]][dian[i][1]][0]//&&头结点相同
                                    && xy_logicJD[dian[j][0]][dian[j][1]][1]==xy_logicJD[dian[i][0]][dian[i][1]][1]){//&&尾节点相同
                                YBY[dian[j][0]][dian[j][1]]=true;//标记该逻辑为以编译
                                byTemp+=("||"+logicxy[dian[j][0]][dian[j][1]]->leiXin+logicxy[dian[j][0]][dian[j][1]]->pin_leiXin+QString::number(logicxy[dian[j][0]][dian[j][1]]->bianHao));
                            }
                        }
                        byTemp+=")";
                        if(byDNA[xy_jDName[dian[i][0]+1][dian[i][1]][1]].isEmpty()==true)//字符串为空
                            byDNA[xy_jDName[dian[i][0]+1][dian[i][1]][1]]=byDNA[zq_jd->jd_name]+byTemp;//编译结果保存到新节点
                        else
                            byDNA[xy_jDName[dian[i][0]+1][dian[i][1]][1]]+=QString("#")+byDNA[zq_jd->jd_name]+byTemp;//编译结果用‘#’隔开
                        JD *JDtemp=NULL;
                        if(fzcf.indexOf("_"+QString::number(xy_jDName[dian[i][0]+1][dian[i][1]][1])+"_")==-1){//防止汇合时重复添加新节点
                            fzcf+=("_"+QString::number(xy_jDName[dian[i][0]+1][dian[i][1]][1])+"_");//加入到这个字符串
                            if(xjddc==0){
                                xjddc=1;
                                x_jd=new JD;//添加新入侵的节点到新节点链表里
                                x_jd->jd_name=xy_jDName[dian[i][0]+1][dian[i][1]][1];
                                x_jd_wei=x_jd_tou=x_jd;}
                            else{
                                x_jd->xia=new JD;//添加新入侵的节点到新节点链表里
                                JDtemp=x_jd;
                                x_jd=x_jd->xia;
                                x_jd->shang=JDtemp;
                                x_jd->jd_name=xy_jDName[dian[i][0]+1][dian[i][1]][1];
                            }
                        }
                        panDuanSFTC=1;
                    }
                }
goto1:;//汇合没完全，跳到这里
                if(zq_jd_wei->jd_name==zq_jd->jd_name)//最前节点链表结束，跳出循环
                    goto fff;
                zq_jd=zq_jd->xia;//访问节点后移
            }
fff:;
            //新链表结尾
            x_jd_wei=x_jd;
            //delete最前节点链表单元
            JD*temp111=NULL;
            zq_jd=zq_jd_tou;
            zq_jd_tou=NULL;
            while(1){
                if(zq_jd==zq_jd_wei)
                    goto goto33;
                if(zq_jd->jd_name==zq_jd_wei->jd_name){
                    delete zq_jd;delete zq_jd_tou;delete zq_jd_wei;
                    goto goto333;
                }
                temp111=zq_jd->xia;
                delete zq_jd;
                zq_jd=temp111;
            }
goto33:;
goto333:;
            delete zq_jd;
            zq_jd=NULL;
            //如果新链表为空则编译结束
            if(panDuanSFTC==0){
                zq_jd=zq_jd_tou=zq_jd_wei=NULL;
                x_jd=x_jd_tou=x_jd_wei=NULL;
                goto goto12;
            }
            //新链表复制给最前链表
            zq_jd_tou=zq_jd=x_jd_tou;
            zq_jd_wei=x_jd_wei;
        }
goto12:;//编译结束跳到这里
        for(int i=0;i<20;i++){
            for(int j=0;j<30;j++){
                if(xy[i][j]!=0){
                    QString temp=logicxy[i][j]->leiXin;
                    if(logicxy[i][j]->pin_leiXin=="" && temp!="" && logicxy[i][j]->leiXin.toUpper()!="H"){//输入不完全的错误检查
                        out_w->setCurrentIndex(0);//让第一个窗口显示
                        out_w->label()->setText(out_w->label()->text()+"\n"+"编译意外终止"+"\n第"+QString::number(j+1)+"行,第"+QString::number(i+1)+"列,逻辑单元未输入类型");
                        return "";
                    }
                    if(xy[i][j]!=0 && YRQ[i][j]==true && i>0){//遇到XianQuan,SET,RST,T则输出编译句子
                        QString arduinoStr;
                        if(temp=="XianQuan"||temp=="SET"||temp=="RST"||temp[0].toLatin1()=='T')
                            arduinoStr=toArduino(byDNA[xy_logicJD[i][j][0]]);
                        while(arduinoStr.indexOf("_f_")!=-1){
                           arduinoStr=arduinoStr.mid(0,arduinoStr.indexOf("_f_"))+arduinoStr.mid(arduinoStr.indexOf("_f_")+7);//继续
                        }

                        if(temp=="XianQuan"){
                            if(logicxy[i][j]->pin_leiXin=="y"){
                                qDebug()<<"策士"<<QString("y[")+QString::number(logicxy[i][j]->bianHao,10)+"]="+arduinoStr+";";
                                ret+=QString("\n y[")+QString::number(logicxy[i][j]->bianHao,10)+"]="+arduinoStr+";";
                            }
                            else if(logicxy[i][j]->pin_leiXin=="m"){
                                qDebug()<<"策士"<<QString("m[")+QString::number(logicxy[i][j]->bianHao,10)+"]="+arduinoStr+";";
                                ret+=QString("\n m[")+QString::number(logicxy[i][j]->bianHao,10)+"]="+arduinoStr+";";
                            }
                        }
                        if(temp=="SET"){
                            if(logicxy[i][j]->pin_leiXin=="y"){
                                qDebug()<<"策士"<<"\nif("+arduinoStr+" == true)"+"\n{ y["+QString::number(logicxy[i][j]->bianHao,10)+"]=true; }";
                                ret+="\n if("+arduinoStr+" == true)"+"\n{ y["+QString::number(logicxy[i][j]->bianHao,10)+"]=true; }";
                            }
                            else if(logicxy[i][j]->pin_leiXin=="m"){
                                qDebug()<<"策士"<<"\nif("+arduinoStr+" == true)"+"\n{ m["+QString::number(logicxy[i][j]->bianHao,10)+"]=true; }";
                                ret+="\n if("+arduinoStr+" == true)"+"\n{ m["+QString::number(logicxy[i][j]->bianHao,10)+"]=true; }";
                            }
                        }
                        if(temp=="RST"){
                            if(logicxy[i][j]->pin_leiXin=="y"){
                                qDebug()<<"策士"<<"\nif("+arduinoStr+" == true)"+"\n{ y["+QString::number(logicxy[i][j]->bianHao,10)+"]=false; }";
                                ret+="\n if("+arduinoStr+" == true)"+"\n{ y["+QString::number(logicxy[i][j]->bianHao,10)+"]=false; }";
                            }
                            else if(logicxy[i][j]->pin_leiXin=="m"){
                                qDebug()<<"策士"<<"\nif("+arduinoStr+" == true)"+"\n{ m["+QString::number(logicxy[i][j]->bianHao,10)+"]=false; }";
                                ret+="\n if("+arduinoStr+" == true)"+"\n{ m["+QString::number(logicxy[i][j]->bianHao,10)+"]=false; }";
                            }
                        }
                        if(temp[0].toLatin1()=='T'){
                            if(logicxy[i][j]->pin_leiXin=="MS" && temp.mid(1).toInt()<10){
                                qDebug()<<"策士"<<"if(("+arduinoStr+")&&(Tvar["+temp.mid(1)+"]==0))\n Tset["+temp.mid(1)+"]="+QString::number((logicxy[i][j]->bianHao/10)*10)+";\n else if((!"+arduinoStr+")&&(Tvar["+temp.mid(1)+"]!=0))\n Tvar["+temp.mid(1)+"]=Tset["+temp.mid(1)+"]=0;";
                                ret+="\n if(("+arduinoStr+")&&(Tvar["+temp.mid(1)+"]==0))\n Tset["+temp.mid(1)+"]="+QString::number((logicxy[i][j]->bianHao/10)*10)+";\n else if((!"+arduinoStr+")&&(Tvar["+temp.mid(1)+"]!=0))\n Tvar["+temp.mid(1)+"]=Tset["+temp.mid(1)+"]=0;";
                            }
                        }
                        out_w->label2()->setText(out_w->label2()->text()+'\n'+temp+"  "+QString::number(i)+" "+QString::number(j)+" "+byDNA[xy_logicJD[i-1][j][1]]);
                    }
                }
            }
        }
    }
gotoDB:;
    return ret;
}

QString MainWindow::code_compile(QString text){
return text;
}
//可以通过节点名称来获得该节点的所{有点的xy值
int MainWindow::JDtoXY(int jdName, const int p[][30][2], int p2[][2])//jdName节点名称，p[][30][2]查询样本，p2[][2]输出结果，返回值为找到该节点的点数
{int i=0;
for(int x=0;x<20;x++)
    for(int y=0;y<30;y++){
        if(p[x][y][1]==jdName){
            p2[i][0]=x;
            p2[i][1]=y;
            i++;
        }
    }
return i;
}

QString MainWindow::path_c(QString path)
{
    int length=path.length();
    for(int i=0;i<length;i++){
        if(path[i]=='/')
            path[i]='\\';
    }
    return path;
}

void MainWindow::write_LD(logic *tou=NULL ,logic *wei=NULL)//将梯形图写入剪贴板
{
    /*int x=5555;
    int y=5555;
    QString leiXin="";
    QString pin_leiXin="";
    int bianHao=0;//引脚编号
    logic* addr=NULL;
    logic* addr2=NULL;
    bool Del=false;
    int changDu=0;
    logic *shi=NULL;
    logic *mou=NULL;
    bool compileOK=0;//是否编译了*/
    qDebug()<<"write_LD";
    QString JTB="";//剪贴板缩写
    logic *logicTemp=tou;
    int copy_GeShu=0;//复制的逻辑个数
    for(int i=0;i<1000;i++)
    {
        copy_GeShu++;
        JTB+="**";
        JTB+=QString::number(logicTemp->x);
        JTB+="#";
        JTB+=QString::number(logicTemp->y);
        JTB+="#";
        JTB+=logicTemp->leiXin;
        JTB+="#";
        JTB+=logicTemp->pin_leiXin;
        JTB+="#";
        JTB+=QString::number(logicTemp->bianHao);
        JTB+="#";
        JTB+=(logicTemp->Del==true)?"true":"false";
        JTB+="#";
        JTB+=QString::number(logicTemp->changDu);
        JTB+="#";
        JTB+=(logicTemp->compileOK==true)?"compileOK":"compileNO";
        //JTB+="\n";
        if(logicTemp==wei)
            break;
        logicTemp=logicTemp->addr;
    }
    JTB+="_geShu_";
    JTB+=QString::number(copy_GeShu);
    jianTieBan->setText(JTB);
    qDebug()<<JTB;

}

void MainWindow::read_LD()//将梯形图从剪贴板读出
{
    logic *jiu=NULL;//旧值，上一个链单元
    QString temp=jianTieBan->text();//从剪贴板读出数据
    int i=temp.mid(temp.indexOf("_geShu_")+7).toInt();//获取剪贴板中的逻辑单元个数
    int p=0;//位置偏移记录
    bool to1=true;//防止重复
    while(i--){//i正好是逻辑个数
        if(to1==true){
            to1=false;
            logic_copy_tou=logic_copy=new logic;
        }
        else{
            jiu=logic_copy;
            logic_copy=new logic;
            jiu->addr=logic_copy;
            logic_copy->addr2=jiu;
        }
        p+=2;

        logic_copy->x=temp.mid(p).section("#",0,0).toInt();
        logic_copy->y=temp.mid(p).section("#",1,1).toInt();
        logic_copy->leiXin=temp.mid(p).section("#",2,2);
        logic_copy->pin_leiXin=temp.mid(p).section("#",3,3);
        logic_copy->bianHao=temp.mid(p).section("#",4,4).toInt();
        logic_copy->Del=((temp.mid(p).section("#",5,5))=="true")?true:false;
        logic_copy->changDu=temp.mid(p).section("#",6,6).toInt();
        p=temp.indexOf("**",p);//位置后移动
    }
}



void MainWindow::actionDaiKai(){//点击 （文件/打开文件）的slot函数
    qDebug()<<"打开文件";
}

void MainWindow::menu_ShiTu()
{
    qDebug()<<"menuShiTu点击";
    if(this->out_w->isVisible()==true){
        ui->actionout_w->setText("关闭输出窗口");
        qDebug()<<"关闭输出窗口";
    }
    else{
        ui->actionout_w->setText("打开输出窗口");
        qDebug()<<"打开输出窗口";
    }
}


void MainWindow::on_action2_triggered()//点击（视图/高级语言视图）
{
    qDebug()<<"高级语言视图";
    if(ui->codeEdit->isVisible()==true){
        ui->codeEdit->setGeometry(0,ui->buttonBianYi->x()+ui->buttonBianYi->height(),this->width(),this->height()-((out_w->isVisible()==true)?out_w->height()+ui->buttonBianYi->x()+ui->buttonBianYi->height()+13:0));
        ui->codeEdit->setVisible(false);
        ui->action2->setText("视图切换(高级语言) 'Ctrl' + 'Tab'");
        ui->verticalScrollBar->setVisible(true);
    }
    else{
        ui->codeEdit->setGeometry(0,ui->buttonBianYi->x()+ui->buttonBianYi->height(),this->width(),this->height()-((out_w->isVisible()==true)?out_w->height()+ui->buttonBianYi->x()+ui->buttonBianYi->height()+13:0));
        ui->codeEdit->setVisible(true);
        ui->action2->setText("视图切换(梯形图) 'Ctrl' + 'Tab'");
        ui->verticalScrollBar->setVisible(false);
    }
}

void MainWindow::on_actionPointAdd_triggered()//增加codeEdit字体大小
{
     QFont temp=ui->codeEdit->font();
     temp.setPointSize(temp.pointSize()+1);
     ui->codeEdit->setFont(temp);
}

void MainWindow::on_actionPointJian_triggered()//减小codeEdit字体大小
{
    QFont temp=ui->codeEdit->font();
    if(temp.pointSize()>=1)
    temp.setPointSize(temp.pointSize()-1);
    ui->codeEdit->setFont(temp);
}

void MainWindow::on_actionSheZhi_triggered()
{
    setup_w->com_read();
    setup_w->show();
}

void MainWindow::on_actionChongZuo_triggered()
{
    on_buttonHuanYuan_pressed();
}

void MainWindow::on_actionCheHui_triggered()
{
    on_buttonCheHui_pressed();
}

void MainWindow::on_actionChaZhao_triggered()
{
    this->cx_w->setVisible(!(this->cx_w->isVisible()));
}

void MainWindow::closeEvent()
{
    this->cx_w->setVisible(false);
    this->setup_w->setVisible(false);
    if(dqwj=="")
        return;
    //打开记录文件
    QFile f(jiLuWenJian);
    f.open(QIODevice::WriteOnly);
    QTextStream add(&f);
    qDebug()<<"上次"<<scjl.file<<scjl.zuiJinFile;
    scjl.file=dqwj;
    add<<scjl.file<<"**";//这次打开文件
    scjl.zuiJinFile=((scjl.zuiJinFile.section("**",0,0)==scjl.file)? scjl.zuiJinFile:(scjl.file+"**"+scjl.zuiJinFile));//新打开文件+历史打开文件
    add<<scjl.zuiJinFile;
    qDebug()<<"关闭时记录"<<scjl.file<<scjl.zuiJinFile;
    f.close();


}

void MainWindow::on_actionout_w_triggered()
{
    this->out_w->setVisible(!(this->out_w->isVisible()));
    if(this->out_w->isVisible()==false){//关闭输出窗口后要改变竖直滑块高度
        ui->verticalScrollBar->setGeometry(ui->verticalScrollBar->x(),ui->verticalScrollBar->y(),ui->verticalScrollBar->width(),this->height());
    }
    else{
        ui->verticalScrollBar->setGeometry(ui->verticalScrollBar->x(),ui->verticalScrollBar->y(),ui->verticalScrollBar->width(),this->height()-220);
    }
}

void MainWindow::on_verticalScrollBar_sliderMoved(int position)//滑块移动槽
{
        ui->label->setVisible(false);
        ui->lineEdit->setVisible(false);
        ui->lineEdit_2->setValidator(false);
        huaDongYN=true;
        addy=((int)((position/100.0)*maxaddy))*70;
        qDebug()<<addy/70;
        this->update();

}
void MainWindow::on_verticalScrollBar_valueChanged(int value)
{
    static int sc=0;
    if(huaDongPB==false){
        if(huaDongYN==false){
            if(sc>value){
                if(addy>=70)
                    addy-=70;
            }
            else
                addy+=70;
        }
        huaDongYN=false;
        sc=value;
        this->update();
    }
    huaDongPB=false;
}

void MainWindow::tianXie_compileY0()
{
    logic *logicTemp=logic_O;
    for(int i=0;i<1000;i++){
        if(logicTemp->x==0 && logicTemp->y!=5555  && logicTemp->leiXin!="S" ){
            compileMuXian[logicTemp->y]=true;
        }
        if(logicTemp==logicNEW)
            break;
        logicTemp=logicTemp->addr;
    }
}



void MainWindow::on_copy_Button_2_released()
{
    qDebug()<<"右键copy";
    copy_ku();
}

void MainWindow::on_cut_Button_3_released()
{
    qDebug()<<"右键cut";
    copy_ku();del_ku();
    this->update();
}

void MainWindow::on_paste_Button_4_released()
{
    qDebug()<<"右键paste";
    paste_ku();
}


void MainWindow::on_actionDaKai_triggered()//菜单-》文件-》打开，槽函数
{
    dqwj=file.getOpenFileName(this,"选择要打开的项目文件",scjl.file.mid(0,scjl.file.lastIndexOf("/")+1),"project(*.plcpro)");//打开文件选择模态对话框，默认打开上次打开位置，
    if(dqwj=="")return;
    this->setWindowTitle("PLC_IDE--"+dqwj.mid(dqwj.lastIndexOf("/")+1));
    delLian(logic_O,logicNEW);//删除现有逻辑单元释放内存
    logic_O->addr=NULL;//清除野指针
    logicNEW=logicTU=logic_O;
    read_LD(dqwj);//将逻辑单元读出
    qDebug()<<"当前打开的"<<dqwj;

    QFile f(jiLuWenJian);
    f.open(QIODevice::WriteOnly);
    QTextStream add(&f);
    qDebug()<<"上次"<<scjl.file<<scjl.zuiJinFile;
    scjl.file=dqwj;
    add<<scjl.file<<"**";//这次打开文件
    scjl.zuiJinFile=((scjl.zuiJinFile.section("**",0,0)==scjl.file)? scjl.zuiJinFile:(scjl.file+"**"+scjl.zuiJinFile));//新打开文件+历史打开文件
    add<<scjl.zuiJinFile;
    qDebug()<<"写入记录"<<scjl.file<<scjl.zuiJinFile;
    f.close();

}

void MainWindow::on_actionXingJian_triggered()
{
}

void MainWindow::on_actionxinJian_triggered()//菜单-》文件-》新建并打开，槽函数
{
    dqwj=file.getSaveFileName(this,"新建项目",scjl.file.mid(0,scjl.file.lastIndexOf("/")+1),"project(*.plcpro)");//
    if(dqwj=="")return;
    QFile f(dqwj);//保存项目
    if(!f.open(QIODevice::WriteOnly)){
        qDebug()<<"新建失败";
        return ;
    }
    f.close();
    this->setWindowTitle("PLC_IDE--"+dqwj.mid(dqwj.lastIndexOf("/")+1));
    delLian(logic_O,logicNEW);//删除现有逻辑单元释放内存
    logic_O->addr=NULL;//清除野指针
    logicNEW=logicTU=logic_O;
    qDebug()<<"当前新建的"<<dqwj;


    QFile ff(jiLuWenJian);
    ff.open(QIODevice::WriteOnly);
    QTextStream add(&ff);
    qDebug()<<"上次"<<scjl.file<<scjl.zuiJinFile;
    scjl.file=dqwj;
    add<<scjl.file<<"**";//这次打开文件
    scjl.zuiJinFile=((scjl.zuiJinFile.section("**",0,0)==scjl.file)? scjl.zuiJinFile:(scjl.file+"**"+scjl.zuiJinFile));//新打开文件+历史打开文件
    add<<scjl.zuiJinFile;
    qDebug()<<"写入记录"<<scjl.file<<scjl.zuiJinFile;
    ff.close();


}

void MainWindow::on_actionbaoCun_triggered()//菜单-》文件-》保存，槽函数
{
   write_LD(logic_O,logicNEW,dqwj);//将项目文件保存
}
void MainWindow::yuFaJianCha(logic *tou=NULL, logic *wei=NULL, int *eGeShu=NULL, int wGeShu=NULL, MainWindow::ew *ewTou=NULL, MainWindow::ew *ewWei=NULL)//逻辑单元语法检查函数；参数使用参考声明
{

}

void MainWindow::write_LD(logic *tou, logic *wei, QString file_addr)//将梯形图写入指定文件
{
    if(tou==NULL||wei==NULL)
        return;
    QString JTB="";//剪贴板缩写
    logic *logicTemp=tou;
    int copy_GeShu=0;//复制的逻辑个数
    for(int i=0;i<1000;i++)
    {
        qDebug()<<"w"<<i;
        copy_GeShu++;
        JTB+="**";
        JTB+=QString::number(logicTemp->x);
        JTB+="#";
        JTB+=QString::number(logicTemp->y);
        JTB+="#";
        JTB+=logicTemp->leiXin;
        JTB+="#";
        JTB+=logicTemp->pin_leiXin;
        JTB+="#";
        JTB+=QString::number(logicTemp->bianHao);
        JTB+="#";
        JTB+=(logicTemp->Del==true)?"true":"false";
        JTB+="#";
        JTB+=QString::number(logicTemp->changDu);
        JTB+="#";
        JTB+=(logicTemp->compileOK==true)?"compileOK":"compileNO";
        //JTB+="\n";
        if(logicTemp==wei)
            break;
        logicTemp=logicTemp->addr;
    }
    JTB+="_geShu_";
    JTB+=QString::number(copy_GeShu);
    QFile f(file_addr);//保存项目
    if(!f.open(QIODevice::WriteOnly)){
        qDebug()<<"读取失败";
        return ;
    }
    QTextStream proText(&f);
    proText<<JTB;
    f.close();
    qDebug()<<JTB;
}

void MainWindow::read_LD(QString file_addr)//将梯形图从指定文件读出
{
    logic *jiu=NULL;//旧值，上一个链单元
    QFile f(file_addr);
    if(!f.open(QIODevice::ReadOnly)){
        return ;
    }
    QTextStream proText(&f);
    QString temp=proText.readAll();//读出数据
    f.close();
    int i=temp.mid(temp.indexOf("_geShu_")+7).toInt();//获取剪贴板中的逻辑单元个数
    int p=0;//位置偏移记录
    bool to1=true;//防止重复
    while(i--){//i正好是逻辑个数
        qDebug()<<i;
        if(to1==true){
            to1=false;
            logic_O=logicTU=new logic;
        }
        else{
            jiu=logicTU;
            logicTU=new logic;
            jiu->addr=logicTU;
            logicTU->addr2=jiu;
        }
        p+=2;

        logicTU->x=temp.mid(p).section("#",0,0).toInt();
        logicTU->y=temp.mid(p).section("#",1,1).toInt();
        logicTU->leiXin=temp.mid(p).section("#",2,2);
        logicTU->pin_leiXin=temp.mid(p).section("#",3,3);
        logicTU->bianHao=temp.mid(p).section("#",4,4).toInt();
        logicTU->Del=((temp.mid(p).section("#",5,5))=="true")?true:false;
        logicTU->changDu=temp.mid(p).section("#",6,6).toInt();
        p=temp.indexOf("**",p);//位置后移动
    }
    logicNEW=logicTU;
    this->update();
}


//函数存在BUG
void MainWindow::on_actionguanBi_triggered()//菜单关闭
{
    if(dqwj!="")
        on_actionbaoCun_triggered();//保存文件
    delLian(logic_O,logicNEW);//删除链表
    logic_O->addr=NULL;//清除野指针
    logicNEW=logicTU=logic_O;//更新
    update();
    this->setWindowTitle("PLC_IDE");
}

void MainWindow::on_actionlinCun_triggered()//菜单>另存为
{
    QString temp="";
    temp=file.getSaveFileName(this,"另存为",scjl.file.mid(0,scjl.file.lastIndexOf("/")+1),"project(*.plcpro)");
    write_LD(logic_O,logicNEW,temp);//将项目文件保存
}


void MainWindow::addLiShi()//添加历史
{
    QString temp=scjl.zuiJinFile;
    qDebug()<<"历史"<<scjl.zuiJinFile;
    QAction *action_temp=new QAction(this);
    qDebug()<<temp.mid(0,temp.length()-2);
    action_temp=new QAction;
    for(int i=0;i<10;i++){
        if(temp.length()>3){//记录读取结束跳出
            ui->menuZuiJin->addAction(action_temp);//添加
            action_arry[i]=action_temp;
            temp=temp.mid(0,temp.length()-2);
            zuiJinPATH[i]=temp.mid(temp.indexOf("**")+2);
            action_temp->setText(zuiJinPATH[i].mid(zuiJinPATH[i].lastIndexOf("/")+1));
            connect(action_arry[i],SIGNAL(triggered(bool)),this,SLOT(actionLiShi()));
            temp=temp.mid(0,temp.lastIndexOf("**")+2);
            action_temp=new QAction(this);
        }
        else{
            action_arry[i]=NULL;
            zuiJinPATH[i]="";
        }
    }

}

void MainWindow::actionLiShi()//打开历史文件槽函数
{
    QAction *temp=(QAction*)QObject::sender();//获取信号对象
    QString dqwj=temp->text();
    qDebug()<<"历史打开"<<dqwj;
    this->setWindowTitle("PLC_IDE--"+dqwj.mid(dqwj.lastIndexOf("/")+1));
    delLian(logic_O,logicNEW);//删除现有逻辑单元释放内存
    logic_O->addr=NULL;//清除野指针
    logicNEW=logicTU=logic_O;
    read_LD(dqwj);//将逻辑单元读出
    qDebug()<<"当前打开的"<<dqwj;

}

void MainWindow::actionShiLi()//打开示例文件地址
{
    QDir dir;
    dir.cd("lib");
    qDebug()<<"示例文件打开地址"<<dir.canonicalPath();
    QAction *temp=(QAction*)QObject::sender();//获取信号对象
    QString dqwj=temp->text();
    qDebug()<<"示例打开"<<dqwj;
    this->setWindowTitle("PLC_IDE--"+dqwj.mid(dqwj.lastIndexOf("/")+1));
    delLian(logic_O,logicNEW);//删除现有逻辑单元释放内存
    logic_O->addr=NULL;//清除野指针
    logicNEW=logicTU=logic_O;
    read_LD(dir.canonicalPath()+"/"+dqwj);//将逻辑单元读出
    qDebug()<<"当前打开的"<<dqwj;

}

void MainWindow::addShiLi()//添加示例
{
    QDir dir;
    if(!dir.exists("lib")){
        dir.mkdir("lib");
    }
    dir.cd("lib");
    dir.setFilter(QDir::Files | QDir::Hidden | QDir::NoSymLinks);
    QStringList filters;
    filters << "*.plcpro";//设置过滤类型
    dir.setNameFilters(filters);//设置文件名的过滤
    QFileInfoList list = dir.entryInfoList();
    int file_count = list.count();
    if(file_count!=0){
        for (int i = 0; i < file_count&&i<10; ++i)
        {
            QAction *act=new QAction;
            ui->menuShiLi->addAction(act);
            QString str=list.at(i).fileName();
            act->setText(str.mid(str.lastIndexOf("/")+1));
            connect(act,SIGNAL(triggered(bool)),this,SLOT(actionShiLi()));
            qDebug() << list.at(i).fileName();
        }
    }
    else
    {
        qDebug()<<"文件夹没有文件";
    }
}



void MainWindow::on_actiontuiChu_triggered()//退出
{
    this->closeEvent();
    this->close();
}

void MainWindow::on_actionjianQie_triggered()//菜单剪切槽
{
    copy_ku();
    del_ku();
    update();
}

void MainWindow::on_actionfuZhi_triggered()//菜单复制槽
{
    copy_ku();
    update();
}

void MainWindow::on_actionnianTie_triggered()//菜单黏贴槽
{
    paste_ku();
    update();
}

void MainWindow::on_action1_triggered()//查看生成代码
{
    compilOut.setWindowFlags(Qt::WindowStaysOnTopHint);
    compilOut.setVisible(true);
    compilOut.showCompileCode(ret);
}

void MainWindow::on_pushButton_clicked()//textEdit输出
{
    QString temp=ui->codeEdit->toHtml();
    qDebug()<<temp<<endl<<ui->codeEdit->toPlainText();
    //ui->codeEdit->clear();
    //ui->codeEdit->setHtml(temp);
    //disconnect(ui->codeEdit,0,0,0);
    qDebug()<<"你好";

}

void MainWindow::on_codeEdit_textChanged()//代码编辑窗口代码变化
{
    qDebug()<<"查询颜色";
    static QString sc="";//变化前的代码
    QString tempStr=ui->codeEdit->toPlainText();//变化后的代码
    if(tempStr.length()==1)//屏蔽BUG
        return;
    int strL=(sc.length()<tempStr.length())? sc.length():tempStr.length();//决定读取字符长度防止越界
    int change=0;//变化的字符位置
    for(int i=0;i<strL;i++){
        if(sc[i]!=tempStr[i]){//检测到字符变化
            change=i;
            break;
        }
        else if(i==strL-1){//这种情况是新增最后一个字符
            change=tempStr.length()-1;
        }
    }
    sc=tempStr;//存储留下次使用
    int changeS=(change-10<0)? 0:change-10,changeX=(tempStr.length()>change+10)? change+10:tempStr.length()-1;//变化字符串字符段，起始位置
    int cS=0,cX=0;
    for(int i=change;i>=changeS;i--){
        if(i==change&&(tempStr[i].toLatin1()>'z' || tempStr[i].toLatin1() < 'a')){
            if(i>0)
                i--;
        }
        if(tempStr[i].toLatin1()>'z' || tempStr[i].toLatin1() < 'a'){
            cS=i+1;
            break;
        }
        else if(i==changeS){//到最前限位
            cS=changeS;
        }
    }
    for(int i=change;i<=changeX;i++){
        if(tempStr[i].toLatin1()>'z' || tempStr[i].toLatin1() < 'a'){
            cX=i-1;
            break;
        }
        else if(changeX==i){//到最后限位
            cX=changeX;
        }
    }
    QString str =tempStr.mid(cS,cX+1-cS);
    QString color=retColour(str);
    qDebug()<<"查询颜色"<<str<<color;
    color="rrr";//先假设有颜色


    static QString scHTML="";
    QString HTML=ui->codeEdit->toHtml();
    qDebug()<<HTML;
    int size=(HTML.length()>scHTML.length())? scHTML.length():HTML.length();
    int change2=0;
    for(int i=0;i<size;i++){//在HTML字符串中找变化字符位置
        if(scHTML[i]!=HTML[i]){
           change2=i;
           break;
        }
    }
    /*
     * 1：原先有配色现在没有了
     * 2：原先没有配色现在有了
     * 3：原先有配色现在也有
    */
    //在前后十个字符内搜索变化字符串
    //防止字符越界
    if(tempStr[change]>'z'||tempStr[change]<'a'){//新增字符为空格时，不做颜色不处理
         scHTML=HTML;//保存旧值
         return;
    }
    int htmlS=(change2-10>0)?change2-10:0;
    QString q=HTML.mid(0,HTML.indexOf(QString(">")+str+QString("<"),htmlS)+1);//要替换字符前半段
    qDebug()<<q;
    QString h=HTML.mid(HTML.indexOf(QString(">")+str+QString("<"),htmlS)+str.length()+1);//字符串后半段
    qDebug()<<endl<<h;
    if(h.indexOf("</font>")==0 && color!=""){//原先有配色现在有配色
        HTML=q+str+h;
        disconnect(ui->codeEdit,SIGNAL(textChanged()),this,SLOT(on_codeEdit_textChanged()));
        ui->codeEdit->setHtml(HTML);
        connect(ui->codeEdit,SIGNAL(textChanged()),this,SLOT(on_codeEdit_textChanged()));
    }
    else if(0){//原先有配色现在没有了
        ;
        }
    else {//原先没有配色现在有了
        HTML=q+"<font size=\"3\" color=\"red\">"+str+"</font>"+h;
        disconnect(ui->codeEdit,SIGNAL(textChanged()),this,SLOT(on_codeEdit_textChanged()));
        ui->codeEdit->setHtml(HTML);
        connect(ui->codeEdit,SIGNAL(textChanged()),this,SLOT(on_codeEdit_textChanged()));
    }
    scHTML=HTML;//保存旧值
    ui->codeEdit->moveCursor(QTextCursor::End, QTextCursor::MoveAnchor);//光标移到最后



}


void MainWindow::processError(QProcess::ProcessError error)
{
    qDebug()<<"CMD错误：";
    switch(error)
    {
    case QProcess::FailedToStart:
        QMessageBox::information(0, "Tip", "FailedToStart");
        break;
    case QProcess::Crashed:
        QMessageBox::information(0, "Tip", "Crashed");
        break;
    case QProcess::Timedout:
        QMessageBox::information(0, "Tip", "Timedout");
        break;
    case QProcess::WriteError:
        QMessageBox::information(0, "Tip", "WriteError");
        break;
    case QProcess::ReadError:
        QMessageBox::information(0, "Tip", "ReadError");
        break;
    case QProcess::UnknownError:
        QMessageBox::information(0, "Tip", "UnknownError");
        break;
    default:
        QMessageBox::information(0, "Tip", "UnknownError");
        break;
    }
}

QString MainWindow::retColour(QString str){
    QString strTemp=setColur,temp="",yuFa="",yanSe="";
    for(int i=0;i<100;i++){
        temp=strTemp.mid(0,strTemp.indexOf("/"));
        strTemp=strTemp.mid(strTemp.indexOf("/")+1);
        if(strTemp=="")
            return "";
        yuFa=temp.section("*",0,0);//待查询语法
        if(str==yuFa){
            yanSe=temp.section("*",1,1);//待查询颜色
            return yanSe;
        }
    }
}

QString MainWindow::toArduino(QString str){//将compile编译出来的转成Arduino可接受的字符串
    QString tempStr=str;
    QString q="",h="";
    int p=0;
    int end=0;
    for(int i=0;i<100;i++){//替换"changKai x/y 0-7"
        p=tempStr.indexOf("ChangKai",p);
        if(p==-1)//查询不到字符了
            break;
        q=tempStr.mid(0,p);
        h=tempStr.mid(p+QString("ChangKai").length());
        end=0;
        while(h[++end].toLatin1()<='9' && h[end].toLatin1()>='0');//判定数字截取长度
        if(h[0].toLatin1()=='x'){
            tempStr=q+"(x["+h.mid(1,end-1)+"])"+h.mid(end);
        }
        else if(h[0].toLatin1()=='y'){
            tempStr=q+"(y["+h.mid(1,end-1)+"])"+h.mid(end);
        }
        else if(h[0].toLatin1()=='m'){
            tempStr=q+"(m["+h.mid(1,end-1)+"])"+h.mid(end);
        }
        else if(h[0].toLatin1()=='t'){
            tempStr=q+"(T["+h.mid(1,end-1)+"])"+h.mid(end);
        }
        else//不是x不是y,没有设置，报错
            return "";
        p+=1;
    }
    p=0;
    for(int i=0;i<100;i++){//替换"changBi x/y 0-7"
        p=tempStr.indexOf("ChangBi",p);
        if(p==-1)//查询不到字符了
            break;
        q=tempStr.mid(0,p);
        h=tempStr.mid(p+QString("ChangBi").length());
        end=0;
        while(h[++end].toLatin1()<='9' && h[end].toLatin1()>='0');
        if(h[0].toLatin1()=='x'){
            tempStr=q+"(!x["+h.mid(1,end-1)+"])"+h.mid(end);
        }
        else if(h[0].toLatin1()=='y'){
            tempStr=q+"(!y["+h.mid(1,end-1)+"])"+h.mid(end);
        }
        else if(h[0].toLatin1()=='m'){
            tempStr=q+"(!m["+h.mid(1,end-1)+"])"+h.mid(end);
        }
        else if(h[0].toLatin1()=='t'){
            tempStr=q+"(!T["+h.mid(1,end-1)+"])"+h.mid(end);
        }
        else//不是x不是y,没有设置，报错
            return "";
        p+=1;
    }

    p=0;
    for(int i=0;i<100;i++){//替换"ShangShenYan x/y 0-7"
        p=tempStr.indexOf("ShangShenYan",p);
        if(p==-1)//查询不到字符了
            break;
        q=tempStr.mid(0,p);
        h=tempStr.mid(p+QString("ShangShenYan").length());
        end=0;
        while(h[++end].toLatin1()<='9' && h[end].toLatin1()>='0');
        if(h[0].toLatin1()=='x')
            tempStr=q+"((xsc["+h.mid(1,end-1)+"]==false && x["+h.mid(1,end-1)+"]==true && one==false)?true:false)"+h.mid(end);
        else if(h[0].toLatin1()=='y')
            tempStr=q+"((ysc["+h.mid(1,end-1)+"]==false && y["+h.mid(1,end-1)+"]==true && one==false)?true:false)"+h.mid(end);
        else//不是x不是y,没有设置，报错
            return "";
        p+=1;
    }

    p=0;
    for(int i=0;i<100;i++){//替换"XiaJianYan x/y 0-7"
        p=tempStr.indexOf("XiaJianYan",p);
        if(p==-1)//查询不到字符了
            break;
        q=tempStr.mid(0,p);
        h=tempStr.mid(p+QString("XiaJianYan").length());
        end=0;
        while(h[++end].toLatin1()<='9' && h[end].toLatin1()>='0');
        if(h[0].toLatin1()=='x')
            tempStr=q+"((xsc["+h.mid(1,end-1)+"]==true && x["+h.mid(1,end-1)+"]==false && one==false)?true:false)"+h.mid(end);
        else if(h[0].toLatin1()=='y')
            tempStr=q+"((ysc["+h.mid(1,end-1)+"]==true && y["+h.mid(1,end-1)+"]==false && one==false)?true:false)"+h.mid(end);
        else//不是x不是y,没有设置，报错
            return "";
        p+=1;
    }

    return tempStr;//返回修改后的值

}


