#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QPixmap"
#include "QDebug"
#include "QPainter"
#include "QMenu"
#include "QAction"
#include "QComboBox"
#include "QString"
#include "QStack"
#include "QMessageBox"
#include "QLabel"
#include "QtMath"
#include <QDesktopServices>
#include <QUrl>




MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ditu_width=ui->label->width();
    ditu_height=ui->label->height();

    ditu_x=0;
    ditu_y=0;
    cnt = 0;

    QPixmap temp(":/map/map.jpg");
    temp.save("temp.png");
    yuantu=temp;
    yuantu=yuantu.scaled(ui->label->width(), ui->label->height(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    ui->label->setGeometry(0,0,ditu_width,ditu_height);
    ui->label->setPixmap(yuantu);

    huitu_button_cnt=51;
    setWindowTitle("上海大学校园导航");
    lcdNumber();
    didianzuobiao();
    guanjiandianzuobiao();
    biandejianli();
    julijuzheng(); //距离矩阵建立
    label_10();
    xinxijianli(); //信息建立
   // jisuanZuiduanLujing();

}

MainWindow::~MainWindow()
{
    delete ui;

}

void MainWindow::label_10(){                  //查看天气，调用系统默认浏览器打开指定网页

    ui->label_10->setText("<a href='https://caiyunapp.com/weather/'>点我查看天气情况</a>");
    ui->label_10->setOpenExternalLinks(true);
//    QDesktopServices::openUrl(QUrl("https://caiyunapp.com/weather/"));
}

void MainWindow::mousePressEvent(QMouseEvent *e){             //鼠标单击输出点坐标，读取坐标时使用
     last=e->globalPos();
    if(xinxi_flag==0){
         xinxi_flag=1;
         qDebug()<<"xinxi_weizhi["<<xinxi_cnt<<"].x1="<<e->x()<<",xinxi_weizhi["<<xinxi_cnt<<"].y1="<<e->y()<<";";
         huitu_button[xinxi_cnt]=new QPushButton(this);
//         connect(huitu_button[huitu_button_cnt], SIGNAL(clicked()), this, SLOT(huituClicked()));
         huitu_button[xinxi_cnt]->setObjectName(QString::number(xinxi_cnt));
         huitu_button[xinxi_cnt]->setText(QString::number(xinxi_cnt));
         huitu_button[xinxi_cnt]->setGeometry(e->x(),e->y(),20,20);
//         huitu_button[xinxi_cnt]->show();

    }
    else if(xinxi_flag==1){
        xinxi_flag=0;
        qDebug()<<"xinxi_weizhi["<<xinxi_cnt<<"].x2="<<e->x()<<",xinxi_weizhi["<<xinxi_cnt<<"].y2="<<e->y()<<";";
        xinxi_cnt++;
    }

}

void MainWindow::mouseMoveEvent(QMouseEvent *e){              //实现鼠标拖动地图

    qDebug()<<"move";
      ditu_x=ui->label->x();
      ditu_y=ui->label->y();
      int dx=e->globalX()-last.x();
      int dy=e->globalY()-last.y();
      last=e->globalPos();
      ditu_x+=dx;
      ditu_y+=dy;
      ui->label->setGeometry(ditu_x,ditu_y,ui->label->width(),ui->label->height());
}

void MainWindow::mouseReleaseEvent(QMouseEvent *e){
//  qDebug()<<"release";
    mouse_flag=0;
}

void MainWindow::paintEvent(QPaintEvent *e){   //绘图点
//    qDebug()<<"paint";
//    QPainter painter(ui->label);
//    QPixmap pix(":/map/map.jpg");
//    painter.drawPixmap(0,0,ditu_width,ditu_height,pix);
//    update();
}

void MainWindow::wheelEvent(QWheelEvent *e){          //实现鼠标滚轮缩放
    if(e->delta()>0){
        if(suofang_flag==0){
            ditu_width*=1.1;
            ditu_height*=1.1;
            beishu=beishu*1.1;
            yuantu.load("temp.png");
            yuantu=yuantu.scaled(ditu_width, ditu_height, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
            ui->label->setPixmap(yuantu);
            ui->label->setGeometry(ui->label->x(),ui->label->y(),ditu_width,ditu_height);
            for(int i=0;i<XinxiNumber;i++){
               xinxi[i]->setGeometry(xinxi_weizhi[i].x1*beishu,xinxi_weizhi[i].y1*beishu,(xinxi_weizhi[i].x2-xinxi_weizhi[i].x1)*beishu,(xinxi_weizhi[i].y2-xinxi_weizhi[i].y1)*beishu);
            }
         }
        else if(suofang_flag==1){
            QMessageBox *suofang_jinggao=new QMessageBox(this);
            suofang_jinggao->setText("正在进行路径规划，无法缩放，请稍候");
            suofang_jinggao->setWindowTitle("警告信息");
            suofang_jinggao->show();
        }

    }
    else if (e->delta()<0){

        if(suofang_flag==0){
            ditu_width*=0.9;
            ditu_height*=0.9;
            beishu=beishu*0.9;
            yuantu.load("temp.png");
            yuantu=yuantu.scaled(ditu_width, ditu_height, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
            ui->label->setPixmap(yuantu);
            ui->label->setGeometry(ui->label->x(),ui->label->y(),ditu_width,ditu_height);
            for(int i=0;i<XinxiNumber;i++){
               xinxi[i]->setGeometry(xinxi_weizhi[i].x1*beishu,xinxi_weizhi[i].y1*beishu,(xinxi_weizhi[i].x2-xinxi_weizhi[i].x1)*beishu,(xinxi_weizhi[i].y2-xinxi_weizhi[i].y1)*beishu);
            }
         }
        else if(suofang_flag==1){
            QMessageBox *suofang_jinggao=new QMessageBox(this);
            suofang_jinggao->setText("正在进行路径规划，无法缩放，请稍候");
            suofang_jinggao->setWindowTitle("警告信息");
            suofang_jinggao->show();
        }
    }
}

void MainWindow::on_comboBox_activated(const QString &arg1)         //选择起点
{
    if(arg1=="东门") s=0;
    else if(arg1=="一号体育场（K区）")s=1;
    else if(arg1=="音乐学院")s=2;
    else if(arg1=="体育馆")s=3;
    else if(arg1=="训练馆")s=4;
    else if(arg1=="游泳馆")s=5;
    else if(arg1=="乐乎新楼")s=6;
    else if(arg1=="训练场（A区）")s=7;
    else if(arg1=="风雨操场（C区）")s=8;
    else if(arg1=="篮球场（B区）")s=9;
    else if(arg1=="北门")s=10;
    else if(arg1=="校医院")s=11;
    else if(arg1=="出版社")s=12;
    else if(arg1=="玄陵网球馆")s=13;
    else if(arg1=="网球场（E区）")s=14;
    else if(arg1=="篮球场/排球场（F区）")s=15;
    else if(arg1=="篮球场（G区）")s=16;
    else if(arg1=="尔美食堂")s=17;
    else if(arg1=="山明食堂")s=18;
    else if(arg1=="益新食堂")s=19;
    else if(arg1=="1号楼")s=20;
    else if(arg1=="伟长楼")s=21;
    else if(arg1=="G楼")s=22;
    else if(arg1=="GJ")s=23;
    else if(arg1=="F楼")s=24;
    else if(arg1=="FJ")s=25;
    else if(arg1=="E楼")s=26;
    else if(arg1=="EJ")s=27;
    else if(arg1=="J楼")s=28;
    else if(arg1=="水秀食堂")s=29;
    else if(arg1=="D楼")s=30;
    else if(arg1=="DJ")s=31;
    else if(arg1=="C楼")s=32;
    else if(arg1=="CJ")s=33;
    else if(arg1=="B楼")s=34;
    else if(arg1=="BJ")s=35;
    else if(arg1=="A楼")s=36;
    else if(arg1=="AJ")s=37;
    else if(arg1=="行政楼")s=38;
    else if(arg1=="溯园")s=39;
    else if(arg1=="美术学院")s=40;
    else if(arg1=="南正门")s=41;
    else if(arg1=="图书馆/图报厅")s=42;
    else if(arg1=="篮球场（H区）")s=43;
    else if(arg1=="足球场（J区）")s=44;
    else if(arg1=="篮球场（I区）")s=45;
    else if(arg1=="沙滩/高尔夫球场/排球场（L区）")s=46;
    else if(arg1=="后勤基建大楼")s=47;
    else if(arg1=="南二门")s=48;
    else if(arg1=="五馨食堂")s=49;
    else if(arg1=="新世纪")s=50;
}

void MainWindow::didianzuobiao(){                    //地点坐标
    didian[0].x=515,didian[0].y=191;
    didian[1].x=471,didian[1].y=174;
    didian[2].x=406,didian[2].y=190;
    didian[3].x=442,didian[3].y=162;
    didian[4].x=416,didian[4].y=133;
    didian[5].x=382,didian[5].y=133;
    didian[6].x=357,didian[6].y=78;
    didian[7].x=342,didian[7].y=113;
    didian[8].x=332,didian[8].y=107;
    didian[9].x=320,didian[9].y=118;
    didian[10].x=196,didian[10].y=72;
    didian[11].x=177,didian[11].y=88;
    didian[12].x=137,didian[12].y=94;
    didian[13].x=169,didian[13].y=142;
    didian[14].x=157,didian[14].y=138;
    didian[15].x=145,didian[15].y=167;
    didian[16].x=143,didian[16].y=212;
    didian[17].x=291,didian[17].y=137;
    didian[18].x=191,didian[18].y=214;
    didian[19].x=187,didian[19].y=280;
    didian[20].x=184,didian[20].y=313;
    didian[21].x=438,didian[21].y=201;
    didian[22].x=343,didian[22].y=250;
    didian[23].x=409,didian[23].y=243;
    didian[24].x=358,didian[24].y=270;
    didian[25].x=423,didian[25].y=265;
    didian[26].x=372,didian[26].y=291;
    didian[27].x=435,didian[27].y=287;
    didian[28].x=374,didian[28].y=318;
    didian[29].x=458,didian[29].y=281;
    didian[30].x=377,didian[30].y=349;
    didian[31].x=451,didian[31].y=339;
    didian[32].x=388,didian[32].y=368;
    didian[33].x=461,didian[33].y=358;
    didian[34].x=403,didian[34].y=386;
    didian[35].x=476,didian[35].y=378;
    didian[36].x=422,didian[36].y=410;
    didian[37].x=491,didian[37].y=392;
    didian[38].x=481,didian[38].y=436;
    didian[39].x=483,didian[39].y=451;
    didian[40].x=342,didian[40].y=441;
    didian[41].x=444,didian[41].y=471;
    didian[42].x=305,didian[42].y=263;
    didian[43].x=153,didian[43].y=307;
    didian[44].x=168,didian[44].y=413;
    didian[45].x=176,didian[45].y=398;
    didian[46].x=143,didian[46].y=430;
    didian[47].x=158,didian[47].y=451;
    didian[48].x=186,didian[48].y=485;
    didian[49].x=162,didian[49].y=528;
    didian[50].x=80,didian[50].y=322;
}

void MainWindow::guanjiandianzuobiao(){                              //关键点坐标
    guanjiandian[0].x=515,guanjiandian[0].y=191,guanjiandian[ 0 ].duiyingjianzhu= 0 ;
    guanjiandian[1].x=471,guanjiandian[1].y=174,guanjiandian[ 1 ].duiyingjianzhu= 1 ;
    guanjiandian[2].x=406,guanjiandian[2].y=190,guanjiandian[ 2 ].duiyingjianzhu= 2 ;
    guanjiandian[3].x=442,guanjiandian[3].y=162,guanjiandian[ 3 ].duiyingjianzhu= 3 ;
    guanjiandian[4].x=416,guanjiandian[4].y=133,guanjiandian[ 4 ].duiyingjianzhu= 4 ;
    guanjiandian[5].x=382,guanjiandian[5].y=133,guanjiandian[ 5 ].duiyingjianzhu= 5 ;
    guanjiandian[6].x=357,guanjiandian[6].y=78,guanjiandian[ 6 ].duiyingjianzhu= 6 ;
    guanjiandian[7].x=342,guanjiandian[7].y=113,guanjiandian[ 7 ].duiyingjianzhu= 7 ;
    guanjiandian[8].x=332,guanjiandian[8].y=107,guanjiandian[ 8 ].duiyingjianzhu= 8 ;
    guanjiandian[9].x=320,guanjiandian[9].y=118,guanjiandian[ 9 ].duiyingjianzhu= 9 ;
    guanjiandian[10].x=196,guanjiandian[10].y=72,guanjiandian[ 10 ].duiyingjianzhu= 10 ;
    guanjiandian[11].x=177,guanjiandian[11].y=88,guanjiandian[ 11 ].duiyingjianzhu= 11 ;
    guanjiandian[12].x=137,guanjiandian[12].y=94,guanjiandian[ 12 ].duiyingjianzhu= 12 ;
    guanjiandian[13].x=169,guanjiandian[13].y=142,guanjiandian[ 13 ].duiyingjianzhu= 13 ;
    guanjiandian[14].x=157,guanjiandian[14].y=138,guanjiandian[ 14 ].duiyingjianzhu= 14 ;
    guanjiandian[15].x=145,guanjiandian[15].y=167,guanjiandian[ 15 ].duiyingjianzhu= 15 ;
    guanjiandian[16].x=143,guanjiandian[16].y=212,guanjiandian[ 16 ].duiyingjianzhu= 16 ;
    guanjiandian[17].x=291,guanjiandian[17].y=137,guanjiandian[ 17 ].duiyingjianzhu= 17 ;
    guanjiandian[18].x=191,guanjiandian[18].y=214,guanjiandian[ 18 ].duiyingjianzhu= 18 ;
    guanjiandian[19].x=187,guanjiandian[19].y=280,guanjiandian[ 19 ].duiyingjianzhu= 19 ;
    guanjiandian[20].x=184,guanjiandian[20].y=313,guanjiandian[ 20 ].duiyingjianzhu= 20 ;
    guanjiandian[21].x=438,guanjiandian[21].y=201,guanjiandian[ 21 ].duiyingjianzhu= 21 ;
    guanjiandian[22].x=343,guanjiandian[22].y=250,guanjiandian[ 22 ].duiyingjianzhu= 22 ;
    guanjiandian[23].x=409,guanjiandian[23].y=243,guanjiandian[ 23 ].duiyingjianzhu= 23 ;
    guanjiandian[24].x=358,guanjiandian[24].y=270,guanjiandian[ 24 ].duiyingjianzhu= 24 ;
    guanjiandian[25].x=423,guanjiandian[25].y=265,guanjiandian[ 25 ].duiyingjianzhu= 25 ;
    guanjiandian[26].x=372,guanjiandian[26].y=291,guanjiandian[ 26 ].duiyingjianzhu= 26 ;
    guanjiandian[27].x=435,guanjiandian[27].y=287,guanjiandian[ 27 ].duiyingjianzhu= 27 ;
    guanjiandian[28].x=374,guanjiandian[28].y=318,guanjiandian[ 28 ].duiyingjianzhu= 28 ;
    guanjiandian[29].x=458,guanjiandian[29].y=281,guanjiandian[ 29 ].duiyingjianzhu= 29 ;
    guanjiandian[30].x=377,guanjiandian[30].y=349,guanjiandian[ 30 ].duiyingjianzhu= 30 ;
    guanjiandian[31].x=451,guanjiandian[31].y=339,guanjiandian[ 31 ].duiyingjianzhu= 31 ;
    guanjiandian[32].x=388,guanjiandian[32].y=368,guanjiandian[ 32 ].duiyingjianzhu= 32 ;
    guanjiandian[33].x=461,guanjiandian[33].y=358,guanjiandian[ 33 ].duiyingjianzhu= 33 ;
    guanjiandian[34].x=403,guanjiandian[34].y=386,guanjiandian[ 34 ].duiyingjianzhu= 34 ;
    guanjiandian[35].x=476,guanjiandian[35].y=378,guanjiandian[ 35 ].duiyingjianzhu= 35 ;
    guanjiandian[36].x=422,guanjiandian[36].y=410,guanjiandian[ 36 ].duiyingjianzhu= 36 ;
    guanjiandian[37].x=491,guanjiandian[37].y=392,guanjiandian[ 37 ].duiyingjianzhu= 37 ;
    guanjiandian[38].x=481,guanjiandian[38].y=436,guanjiandian[ 38 ].duiyingjianzhu= 38 ;
    guanjiandian[39].x=483,guanjiandian[39].y=451,guanjiandian[ 39 ].duiyingjianzhu= 39 ;
    guanjiandian[40].x=342,guanjiandian[40].y=441,guanjiandian[ 40 ].duiyingjianzhu= 40 ;
    guanjiandian[41].x=444,guanjiandian[41].y=471,guanjiandian[ 41 ].duiyingjianzhu= 41 ;
    guanjiandian[42].x=305,guanjiandian[42].y=263,guanjiandian[ 42 ].duiyingjianzhu= 42 ;
    guanjiandian[43].x=153,guanjiandian[43].y=307,guanjiandian[ 43 ].duiyingjianzhu= 43 ;
    guanjiandian[44].x=168,guanjiandian[44].y=413,guanjiandian[ 44 ].duiyingjianzhu= 44 ;
    guanjiandian[45].x=176,guanjiandian[45].y=398,guanjiandian[ 45 ].duiyingjianzhu= 45 ;
    guanjiandian[46].x=143,guanjiandian[46].y=430,guanjiandian[ 46 ].duiyingjianzhu= 46 ;
    guanjiandian[47].x=158,guanjiandian[47].y=451,guanjiandian[ 47 ].duiyingjianzhu= 47 ;
    guanjiandian[48].x=186,guanjiandian[48].y=485,guanjiandian[ 48 ].duiyingjianzhu= 48 ;
    guanjiandian[49].x=162,guanjiandian[49].y=528,guanjiandian[ 49 ].duiyingjianzhu= 49 ;
    guanjiandian[50].x=80,guanjiandian[50].y=322,guanjiandian[ 50 ].duiyingjianzhu= 50 ;
    guanjiandian[ 51 ].x= 465 ,guanjiandian[ 51 ].y= 189 ;
    guanjiandian[ 52 ].x= 445 ,guanjiandian[ 52 ].y= 190 ;
    guanjiandian[ 53 ].x= 384 ,guanjiandian[ 53 ].y= 193 ;
    guanjiandian[ 54 ].x= 383 ,guanjiandian[ 54 ].y= 163 ;
    guanjiandian[ 55 ].x= 381 ,guanjiandian[ 55 ].y= 99 ;
    guanjiandian[ 56 ].x= 345 ,guanjiandian[ 56 ].y= 103 ;
    guanjiandian[ 57 ].x= 290 ,guanjiandian[ 57 ].y= 109 ;
    guanjiandian[ 58 ].x= 346 ,guanjiandian[ 58 ].y= 191 ;
    guanjiandian[ 59 ].x= 308 ,guanjiandian[ 59 ].y= 199 ;
    guanjiandian[ 60 ].x= 336 ,guanjiandian[ 60 ].y= 274 ;
    guanjiandian[ 61 ].x= 421 ,guanjiandian[ 61 ].y= 254 ;
    guanjiandian[ 62 ].x= 408 ,guanjiandian[ 62 ].y= 226 ;
    guanjiandian[ 63 ].x= 448 ,guanjiandian[ 63 ].y= 291 ;
    guanjiandian[ 64 ].x= 452 ,guanjiandian[ 64 ].y= 312 ;
    guanjiandian[ 65 ].x= 381 ,guanjiandian[ 65 ].y= 309 ;
    guanjiandian[ 66 ].x= 379 ,guanjiandian[ 66 ].y= 303 ;
    guanjiandian[ 67 ].x= 462 ,guanjiandian[ 67 ].y= 325 ;
    guanjiandian[ 68 ].x= 483 ,guanjiandian[ 68 ].y= 349 ;
    guanjiandian[ 69 ].x= 488 ,guanjiandian[ 69 ].y= 370 ;
    guanjiandian[ 70 ].x= 500 ,guanjiandian[ 70 ].y= 386 ;
    guanjiandian[ 71 ].x= 504 ,guanjiandian[ 71 ].y= 410 ;
    guanjiandian[ 72 ].x= 470 ,guanjiandian[ 72 ].y= 450 ;
    guanjiandian[ 73 ].x= 439 ,guanjiandian[ 73 ].y= 465 ;
    guanjiandian[ 74 ].x= 354 ,guanjiandian[ 74 ].y= 465 ;
    guanjiandian[ 75 ].x= 328 ,guanjiandian[ 75 ].y= 397 ;
    guanjiandian[ 76 ].x= 403 ,guanjiandian[ 76 ].y= 379 ;
    guanjiandian[ 77 ].x= 412 ,guanjiandian[ 77 ].y= 428 ;
    guanjiandian[ 78 ].x= 393 ,guanjiandian[ 78 ].y= 389 ;
    guanjiandian[ 79 ].x= 375 ,guanjiandian[ 79 ].y= 361 ;
    guanjiandian[ 80 ].x= 396 ,guanjiandian[ 80 ].y= 352 ;
    guanjiandian[ 81 ].x= 414 ,guanjiandian[ 81 ].y= 390 ;
    guanjiandian[ 82 ].x= 402 ,guanjiandian[ 82 ].y= 403 ;
    guanjiandian[ 83 ].x= 350 ,guanjiandian[ 83 ].y= 315 ;
    guanjiandian[ 84 ].x= 293 ,guanjiandian[ 84 ].y= 379 ;
    guanjiandian[ 85 ].x= 262 ,guanjiandian[ 85 ].y= 351 ;
    guanjiandian[ 86 ].x= 184 ,guanjiandian[ 86 ].y= 354 ;
    guanjiandian[ 87 ].x= 160 ,guanjiandian[ 87 ].y= 321 ;
    guanjiandian[ 88 ].x= 155 ,guanjiandian[ 88 ].y= 297 ;
    guanjiandian[ 89 ].x= 211 ,guanjiandian[ 89 ].y= 296 ;
    guanjiandian[ 90 ].x= 246 ,guanjiandian[ 90 ].y= 288 ;
    guanjiandian[ 91 ].x= 225 ,guanjiandian[ 91 ].y= 429 ;
    guanjiandian[ 92 ].x= 298 ,guanjiandian[ 92 ].y= 441 ;
    guanjiandian[ 93 ].x= 201 ,guanjiandian[ 93 ].y= 313 ;
    guanjiandian[ 94 ].x= 177 ,guanjiandian[ 94 ].y= 344 ;
    guanjiandian[ 95 ].x= 175 ,guanjiandian[ 95 ].y= 433 ;
    guanjiandian[ 96 ].x= 141 ,guanjiandian[ 96 ].y= 435 ;
    guanjiandian[ 97 ].x= 139 ,guanjiandian[ 97 ].y= 451 ;
    guanjiandian[ 98 ].x= 185 ,guanjiandian[ 98 ].y= 435 ;
    guanjiandian[ 99 ].x= 151 ,guanjiandian[ 99 ].y= 213 ;
    guanjiandian[ 100 ].x= 151 ,guanjiandian[ 100 ].y= 184 ;
    guanjiandian[ 101 ].x= 157 ,guanjiandian[ 101 ].y= 170 ;
    guanjiandian[ 102 ].x= 217 ,guanjiandian[ 102 ].y= 111 ;
    guanjiandian[ 103 ].x= 206 ,guanjiandian[ 103 ].y= 94 ;
    guanjiandian[ 104 ].x= 358 ,guanjiandian[ 104 ].y= 86 ;
    guanjiandian[ 105 ].x= 295 ,guanjiandian[ 105 ].y= 84 ;
    guanjiandian[ 106 ].x= 406 ,guanjiandian[ 106 ].y= 82 ;
    guanjiandian[ 107 ].x= 305 ,guanjiandian[ 107 ].y= 268 ;
    guanjiandian[ 108 ].x= 126 ,guanjiandian[ 108 ].y= 291 ;
    guanjiandian[ 109 ].x= 124 ,guanjiandian[ 109 ].y= 314 ;
    guanjiandian[ 110 ].x= 252 ,guanjiandian[ 110 ].y= 233 ;
    guanjiandian[ 111 ].x= 269 ,guanjiandian[ 111 ].y= 218;
    guanjiandian[ 112 ].x= 356 ,guanjiandian[ 112 ].y= 397;
}

void MainWindow::huituClicked(){             //测试用
    huitu_button_cnt--;
    delete huitu_button[huitu_button_cnt];
}

void MainWindow::on_pushButton_clicked()     //确定按钮
{
    if(suofang_flag==0){
        if(s==e){
           QMessageBox *message=new QMessageBox(this);
           message->setText("起点和终点不能相同！");
           message->setWindowTitle("警告信息");
           message->show();
        }
        else {
            jisuanZuiduanLujing(s);
            lujingjisuan(e,s);
            huaxian();
            lcdNumber();
        }
    }
    else if(suofang_flag==1){
        QMessageBox *message=new QMessageBox(this);
        message->setText("请等待本次路径规划完毕再进行下次路径规划！");
        message->setWindowTitle("警告信息");
        message->show();
    }
//  huitu();
}

void MainWindow::on_comboBox_2_activated(const QString &arg1)         //选择终点
{
      if (arg1=="东门")e=0;
      else if(arg1=="一号体育场（K区）")e=1;
      else if(arg1=="音乐学院")e=2;
      else if(arg1=="体育馆")e=3;
      else if(arg1=="训练馆")e=4;
      else if(arg1=="游泳馆")e=5;
      else if(arg1=="乐乎新楼")e=6;
      else if(arg1=="训练场（A区）")e=7;
      else if(arg1=="风雨操场（C区）")e=8;
      else if(arg1=="篮球场（B区）")e=9;
      else if(arg1=="北门")e=10;
      else if(arg1=="校医院")e=11;
      else if(arg1=="出版社")e=12;
      else if(arg1=="玄陵网球馆")e=13;
      else if(arg1=="网球场（E区）")e=14;
      else if(arg1=="篮球场/排球场（F区）")e=15;
      else if(arg1=="篮球场（G区）")e=16;
      else if(arg1=="尔美食堂")e=17;
      else if(arg1=="山明食堂")e=18;
      else if(arg1=="益新食堂")e=19;
      else if(arg1=="1号楼")e=20;
      else if(arg1=="伟长楼")e=21;
      else if(arg1=="G楼")e=22;
      else if(arg1=="GJ")e=23;
      else if(arg1=="F楼")e=24;
      else if(arg1=="FJ")e=25;
      else if(arg1=="E楼")e=26;
      else if(arg1=="EJ")e=27;
      else if(arg1=="J楼")e=28;
      else if(arg1=="水秀食堂")e=29;
      else if(arg1=="D楼")e=30;
      else if(arg1=="DJ")e=31;
      else if(arg1=="C楼")e=32;
      else if(arg1=="CJ")e=33;
      else if(arg1=="B楼")e=34;
      else if(arg1=="BJ")e=35;
      else if(arg1=="A楼")e=36;
      else if(arg1=="AJ")e=37;
      else if(arg1=="行政楼")e=38;
      else if(arg1=="溯园")e=39;
      else if(arg1=="美术学院")e=40;
      else if(arg1=="南正门")e=41;
      else if(arg1=="图书馆/图报厅")e=42;
      else if(arg1=="篮球场（H区）")e=43;
      else if(arg1=="足球场（J区）")e=44;
      else if(arg1=="篮球场（I区）")e=45;
      else if(arg1=="沙滩/高尔夫球场/排球场（L区）")e=46;
      else if(arg1=="后勤基建大楼")e=47;
      else if(arg1=="南二门")e=48;
      else if(arg1=="五馨食堂")e=49;
      else if(arg1=="新世纪")e=50;
}

void MainWindow::edgeClicked(){
    QPushButton *clickedButton = qobject_cast<QPushButton *>(sender());
    int i=clickedButton->text().toInt();
    if(edge_huitu_flag==0){
        e_s=i;
        edge_huitu_flag=1;
    }
    else if(edge_huitu_flag==1){
        e_e=i;
        edge_huitu_flag=0;
        qDebug()<<"edge["<<edge_cnt<<"].start="<<e_s<<",edge["<<edge_cnt<<"].end="<<e_e<<";";
        edge_cnt++;
        //      edge[0].start=0,edge[0].end=1;
    }
}

void MainWindow::biandejianli(){                      //定义边（无方向）
    edge[ 0 ].start=0 ,edge[ 0 ].end=51;
    edge[ 1 ].start=51 ,edge[ 1 ].end=1;
    edge[ 2 ].start=1 ,edge[ 2 ].end=3;
    edge[ 3 ].start=3 ,edge[ 3 ].end=52;
    edge[ 4 ].start=52 ,edge[ 4 ].end=51;
    edge[ 5 ].start=52 ,edge[ 5 ].end=21;
    edge[ 6 ].start=3 ,edge[ 6 ].end=4;
    edge[ 7 ].start=52 ,edge[ 7 ].end=2;
    edge[ 8 ].start=51 ,edge[ 8 ].end=61;
    edge[ 9 ].start=61 ,edge[ 9 ].end=23;
    edge[ 10 ].start=2 ,edge[ 10 ].end=53;
    edge[ 11 ].start=53 ,edge[ 11 ].end=54;
    edge[ 12 ].start=4 ,edge[ 12 ].end=54;
    edge[ 13 ].start=54 ,edge[ 13 ].end=5;
    edge[ 14 ].start=4 ,edge[ 14 ].end=106;
    edge[ 15 ].start=5 ,edge[ 15 ].end=55;
    edge[ 16 ].start=55 ,edge[ 16 ].end=56;
    edge[ 17 ].start=106 ,edge[ 17 ].end=104;
    edge[ 18 ].start=104 ,edge[ 18 ].end=6;
    edge[ 19 ].start=104 ,edge[ 19 ].end=105;
    edge[ 20 ].start=105 ,edge[ 20 ].end=57;
    edge[ 21 ].start=57 ,edge[ 21 ].end=58;
    edge[ 22 ].start=57 ,edge[ 22 ].end=17;
    edge[ 23 ].start=58 ,edge[ 23 ].end=59;
    edge[ 24 ].start=59 ,edge[ 24 ].end=60;
    edge[ 25 ].start=60 ,edge[ 25 ].end=22;
    edge[ 26 ].start=22 ,edge[ 26 ].end=24;
    edge[ 27 ].start=60 ,edge[ 27 ].end=83;
    edge[ 28 ].start=24 ,edge[ 28 ].end=60;
    edge[ 29 ].start=60 ,edge[ 29 ].end=107;
    edge[ 30 ].start=107 ,edge[ 30 ].end=42;
    edge[ 31 ].start=107 ,edge[ 31 ].end=83;
    edge[ 32 ].start=83 ,edge[ 32 ].end=66;
    edge[ 33 ].start=28 ,edge[ 33 ].end=66;
    edge[ 34 ].start=83 ,edge[ 34 ].end=84;
    edge[ 35 ].start=66 ,edge[ 35 ].end=65;
    edge[ 36 ].start=65 ,edge[ 36 ].end=28;
    edge[ 37 ].start=83 ,edge[ 37 ].end=30;
    edge[ 38 ].start=83 ,edge[ 38 ].end=79;
    edge[ 39 ].start=30 ,edge[ 39 ].end=79;
    edge[ 40 ].start=30 ,edge[ 40 ].end=80;
    edge[ 41 ].start=79 ,edge[ 41 ].end=80;
    edge[ 42 ].start=80 ,edge[ 42 ].end=32;
    edge[ 43 ].start=79 ,edge[ 43 ].end=32;
    edge[ 44 ].start=79 ,edge[ 44 ].end=78;
    edge[ 45 ].start=32 ,edge[ 45 ].end=76;
    edge[ 46 ].start=76 ,edge[ 46 ].end=34;
    edge[ 47 ].start=34 ,edge[ 47 ].end=81;
    edge[ 48 ].start=78 ,edge[ 48 ].end=82;
    edge[ 49 ].start=82 ,edge[ 49 ].end=77;
    edge[ 50 ].start=77 ,edge[ 50 ].end=73;
    edge[ 51 ].start=77 ,edge[ 51 ].end=36;
    edge[ 52 ].start=82 ,edge[ 52 ].end=36;
    edge[ 53 ].start=77 ,edge[ 53 ].end=40;
    edge[ 54 ].start=81 ,edge[ 54 ].end=35;
    edge[ 55 ].start=35 ,edge[ 55 ].end=69;
    edge[ 56 ].start=41 ,edge[ 56 ].end=39;
    edge[ 57 ].start=73 ,edge[ 57 ].end=41;
    edge[ 58 ].start=39 ,edge[ 58 ].end=72;
    edge[ 59 ].start=72 ,edge[ 59 ].end=38;
    edge[ 60 ].start=38 ,edge[ 60 ].end=71;
    edge[ 61 ].start=71 ,edge[ 61 ].end=70;
    edge[ 62 ].start=37 ,edge[ 62 ].end=70;
    edge[ 63 ].start=70 ,edge[ 63 ].end=69;
    edge[ 64 ].start=69 ,edge[ 64 ].end=68;
    edge[ 65 ].start=68 ,edge[ 65 ].end=33;
    edge[ 66 ].start=33 ,edge[ 66 ].end=76;
    edge[ 67 ].start=80 ,edge[ 67 ].end=31;
    edge[ 68 ].start=31 ,edge[ 68 ].end=67;
    edge[ 69 ].start=68 ,edge[ 69 ].end=67;
    edge[ 70 ].start=67 ,edge[ 70 ].end=64;
    edge[ 71 ].start=64 ,edge[ 71 ].end=65;
    edge[ 72 ].start=64 ,edge[ 72 ].end=63;
    edge[ 73 ].start=63 ,edge[ 73 ].end=66;
    edge[ 74 ].start=63 ,edge[ 74 ].end=29;
    edge[ 75 ].start=63 ,edge[ 75 ].end=27;
    edge[ 76 ].start=27 ,edge[ 76 ].end=29;
    edge[ 77 ].start=27 ,edge[ 77 ].end=25;
    edge[ 78 ].start=25 ,edge[ 78 ].end=61;
    edge[ 79 ].start=2 ,edge[ 79 ].end=62;
    edge[ 80 ].start=62 ,edge[ 80 ].end=61;
    edge[ 81 ].start=53 ,edge[ 81 ].end=58;
    edge[ 82 ].start=56 ,edge[ 82 ].end=7;
    edge[ 83 ].start=56 ,edge[ 83 ].end=8;
    edge[ 84 ].start=8 ,edge[ 84 ].end=9;
    edge[ 85 ].start=7 ,edge[ 85 ].end=9;
    edge[ 86 ].start=9 ,edge[ 86 ].end=57;
    edge[ 87 ].start=59 ,edge[ 87 ].end=111;
    edge[ 88 ].start=111 ,edge[ 88 ].end=110;
    edge[ 89 ].start=110 ,edge[ 89 ].end=90;
    edge[ 90 ].start=90 ,edge[ 90 ].end=107;
    edge[ 91 ].start=90 ,edge[ 91 ].end=85;
    edge[ 92 ].start=85 ,edge[ 92 ].end=84;
    edge[ 93 ].start=84 ,edge[ 93 ].end=83;
    edge[ 94 ].start=84 ,edge[ 94 ].end=75;
    edge[ 95 ].start=75 ,edge[ 95 ].end=112;
    edge[ 96 ].start=75 ,edge[ 96 ].end=40;
    edge[ 97 ].start=40 ,edge[ 97 ].end=74;
    edge[ 98 ].start=74 ,edge[ 98 ].end=73;
    edge[ 99 ].start=74 ,edge[ 99 ].end=92;
    edge[ 100 ].start=92 ,edge[ 100 ].end=91;
    edge[ 101 ].start=91 ,edge[ 101 ].end=86;
    edge[ 102 ].start=85 ,edge[ 102 ].end=86;
    edge[ 103 ].start=94 ,edge[ 103 ].end=45;
    edge[ 104 ].start=45 ,edge[ 104 ].end=44;
    edge[ 105 ].start=44 ,edge[ 105 ].end=95;
    edge[ 106 ].start=94 ,edge[ 106 ].end=95;
    edge[ 107 ].start=95 ,edge[ 107 ].end=46;
    edge[ 108 ].start=95 ,edge[ 108 ].end=96;
    edge[ 109 ].start=46 ,edge[ 109 ].end=96;
    edge[ 110 ].start=96 ,edge[ 110 ].end=97;
    edge[ 111 ].start=97 ,edge[ 111 ].end=47;
    edge[ 112 ].start=95 ,edge[ 112 ].end=98;
    edge[ 113 ].start=98 ,edge[ 113 ].end=48;
    edge[ 114 ].start=48 ,edge[ 114 ].end=49;
    edge[ 115 ].start=98 ,edge[ 115 ].end=91;
    edge[ 116 ].start=86 ,edge[ 116 ].end=94;
    edge[ 117 ].start=94 ,edge[ 117 ].end=87;
    edge[ 118 ].start=87 ,edge[ 118 ].end=20;
    edge[ 119 ].start=20 ,edge[ 119 ].end=93;
    edge[ 120 ].start=93 ,edge[ 120 ].end=89;
    edge[ 121 ].start=89 ,edge[ 121 ].end=88;
    edge[ 122 ].start=89 ,edge[ 122 ].end=19;
    edge[ 123 ].start=88 ,edge[ 123 ].end=19;
    edge[ 124 ].start=89 ,edge[ 124 ].end=90;
    edge[ 125 ].start=88 ,edge[ 125 ].end=108;
    edge[ 126 ].start=108 ,edge[ 126 ].end=109;
    edge[ 127 ].start=109 ,edge[ 127 ].end=50;
    edge[ 128 ].start=87 ,edge[ 128 ].end=43;
    edge[ 129 ].start=88 ,edge[ 129 ].end=43;
    edge[ 130 ].start=88 ,edge[ 130 ].end=99;
    edge[ 131 ].start=99 ,edge[ 131 ].end=18;
    edge[ 132 ].start=99 ,edge[ 132 ].end=16;
    edge[ 133 ].start=99 ,edge[ 133 ].end=100;
    edge[ 134 ].start=100 ,edge[ 134 ].end=101;
    edge[ 135 ].start=100 ,edge[ 135 ].end=15;
    edge[ 136 ].start=15 ,edge[ 136 ].end=101;
    edge[ 137 ].start=101 ,edge[ 137 ].end=14;
    edge[ 138 ].start=14 ,edge[ 138 ].end=13;
    edge[ 139 ].start=101 ,edge[ 139 ].end=13;
    edge[ 140 ].start=101 ,edge[ 140 ].end=102;
    edge[ 141 ].start=102 ,edge[ 141 ].end=13;
    edge[ 142 ].start=102 ,edge[ 142 ].end=57;
    edge[ 143 ].start=102 ,edge[ 143 ].end=103;
    edge[ 144 ].start=103 ,edge[ 144 ].end=105;
    edge[ 145 ].start=103 ,edge[ 145 ].end=11;
    edge[ 146 ].start=11 ,edge[ 146 ].end=12;
    edge[ 147 ].start=103 ,edge[ 147 ].end=10;
    edge[ 148 ].start=111 ,edge[ 148 ].end=42;
    edge[ 149 ].start=102 ,edge[ 149 ].end=111;
    edge[ 150 ].start=76 ,edge[ 150 ].end=78;
    edge[ 151 ].start=112 ,edge[ 151 ].end=75;
    edge[ 152 ].start=112 ,edge[ 152 ].end=78;
    edge[ 153 ].start=34 ,edge[ 153 ].end=78;
    edge[ 154 ].start=32 ,edge[ 154 ].end=78;
}

void MainWindow::julijuzheng(){                //将边的距离输入到数组
    for(int i=0;i<GuanjiandianNumber;i++){
        for(int j=0;j<GuanjiandianNumber;j++){
            juli[i][j]=0;
        }
    }
    for(int i=0;i<EdgeNumber;i++){
        juli[edge[i].start][edge[i].end]=juli[edge[i].end][edge[i].start]= sqrt(
                (guanjiandian[edge[i].start].x-guanjiandian[edge[i].end].x)*
                (guanjiandian[edge[i].start].x-guanjiandian[edge[i].end].x)+
                (guanjiandian[edge[i].start].y-guanjiandian[edge[i].end].y)*
                (guanjiandian[edge[i].start].y-guanjiandian[edge[i].end].y));
    }
}

void MainWindow::jisuanZuiduanLujing(int s)  //最短路径迪杰斯特拉算法
{
    bool fangwen_flag[GuanjiandianNumber]; 
    for(int i=0;i<GuanjiandianNumber;i++)
     {
        if(juli[s][i]>0&&i!=s)
        {
            gengxin[i]=juli[s][i];
            lujing[i]=s;
         }
        else
        {
            gengxin[i]=INT_MAX;
            lujing[i]=-1;
        }
        fangwen_flag[i]=false;
        lujing[s]=s;
        gengxin[s]=0;
    }
    fangwen_flag[s]=true;
    for(int i=1;i<GuanjiandianNumber;i++)
     {
        int min=INT_MAX;
        int temp = 0;
        for(int j=0;j<GuanjiandianNumber;j++)
         {
            if(fangwen_flag[j]==false&&gengxin[j]<min)
            {
                min=gengxin[j];
                temp=j;
            }
        }
        fangwen_flag[temp]=true;
        for(int k=0;k<GuanjiandianNumber;k++)
         {
            if(fangwen_flag[k]==false&&juli[temp][k]>0&&min+juli[temp][k]<gengxin[k])
            {
                gengxin[k]=min+juli[temp][k];
                lujing[k]=temp;
            }
        }
    }
}

void MainWindow::lujingjisuan(int e,int s)   //规划存储路径,建立栈
{
    for(int i=0;i<GuanjiandianNumber;i++)
        zuiduan_lujing[i]=-1;

    QTextStream cout(stdout,  QIODevice::WriteOnly);
    QStack<int> stack;
    while(e!=s)
    {
        stack.push(e); 
        e=lujing[e];
    }
    stack.push(e);
    while(!stack.empty())
    {
        cout<<stack.top()<<" ";
        zuiduan_lujing[cnt++]=stack.top();
        stack.pop();                       //出栈，输出路线经过的关键点
    }

}

void MainWindow::huaxian(){             //画出路径
        int s=this->s;
        int e=this->e;
        //画线
        suofang_flag=1;
        QPixmap pixmap_yuantu(":/map/map.jpg");
        pixmap_yuantu = pixmap_yuantu.scaled(ditu_width,ditu_height,Qt::IgnoreAspectRatio,Qt::SmoothTransformation);
        QPainter llpainter(&pixmap_yuantu);
        llpainter.setRenderHint(QPainter::Antialiasing);
        llpainter.setPen(QPen(Qt::black,5,Qt::DotLine,Qt::RoundCap,Qt::MiterJoin));
        if(s==0)
             llpainter.drawLine(515*beishu, (191-40)*beishu, guanjiandian[s].x*beishu, (guanjiandian[s].y-40)*beishu);
        else  if(s!=23&&s!=24&&s!=25&&s!=26)
        llpainter.drawLine(didian[s].x*beishu, (didian[s].y-40)*beishu, guanjiandian[s].x*beishu, (guanjiandian[s].y-40)*beishu);

        for (int i=1;zuiduan_lujing[i]!=-1;i++)
            {
                llpainter.drawLine(guanjiandian[zuiduan_lujing[i-1]].x*beishu, (guanjiandian[zuiduan_lujing[i-1]].y-40)*beishu, guanjiandian[zuiduan_lujing[i]].x*beishu, (guanjiandian[zuiduan_lujing[i]].y-40)*beishu);
                //延时
                sleep(200);
                QPixmap pixmap = pixmap_yuantu.scaled(ditu_width,ditu_height);
                QPainter painter(this);

                yuantu=pixmap;
                ui->label->setPixmap(yuantu);
                yuantu.save("temp.png");
            }
            llpainter.setPen(QPen(Qt::red,5,Qt::DotLine,Qt::RoundCap,Qt::MiterJoin)); //设置虚线
            if(e==0)
                llpainter.drawLine(515*beishu, (191-40)*beishu, guanjiandian[e].x*beishu, (guanjiandian[e].y-40)*beishu);
            else if(e!=23&&e!=24&&e!=25&&e!=26)
            llpainter.drawLine(didian[e].x*beishu, (didian[e].y-40)*beishu, guanjiandian[e].x*beishu, (guanjiandian[e].y-40)*beishu);
            llpainter.end();

            QPixmap pixmap = pixmap_yuantu.scaled(ditu_width,ditu_height);
            QPainter painter(this);
            yuantu=pixmap;
            ui->label->setPixmap(yuantu);
            yuantu.save("temp.png");
            suofang_flag=0;
}

void MainWindow::on_pushButton_2_clicked(){      //重置按钮
    if(suofang_flag==0)
    {
        QPixmap temp(":/map/map.jpg");
        temp.save("temp.png");
        yuantu=temp;
        yuantu=yuantu.scaled(ui->label->width(), ui->label->height(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
        ui->label->setPixmap(yuantu);
        distance = 0;
        time = 0;
        ui->lcdNumber->display(0);
        ui->lcdNumber_2->display(0);
    }
    else if(suofang_flag==1){
        QMessageBox *qingchu_jinggao=new QMessageBox(this);
        qingchu_jinggao->setText("请等待路径规划完毕再清除!");
        qingchu_jinggao->setWindowTitle("警告信息");
        qingchu_jinggao->show();
    }

}


void MainWindow::xinxijianli(){     //读取所需点坐标，设计用
    //信息标签初始化祖先
    for (int i=0;i<XinxiNumber;i++){
        xinxi[i]=new QLabel(ui->label);
    }

  //  xinxizuobiao();
//    信息位置与大小初始化
    for(int i=0;i<XinxiNumber;i++){
       xinxi[i]->setGeometry(xinxi_weizhi[i].x1,xinxi_weizhi[i].y1,xinxi_weizhi[i].x2-xinxi_weizhi[i].x1,xinxi_weizhi[i].y2-xinxi_weizhi[i].y1);

       xinxi[i]->show();
    }
}

/*void MainWindow::xinxizuobiao (){ //存储信息位置坐标x1，y1,x2,y2

    for(int i=0;i<XinxiNumber;i++)
        xinxi_weizhi[i].y1-=11,xinxi_weizhi[i].y2-=11;
}
*/

void MainWindow::sleep(unsigned int msec){            //延时
    QTime reachTime =QTime::currentTime().addMSecs(msec);
    while(QTime::currentTime()<reachTime){
        QCoreApplication::processEvents(QEventLoop::AllEvents,100);
    }
}

void MainWindow::lcdNumber(){
    int i = 0;
       for(i=1;i<cnt;i++){
          distance = distance + juli[zuiduan_lujing[i-1]][zuiduan_lujing[i]];
       }
    distance = distance*2.07;
 //   qDebug("%d",cnt);

    ui->lcdNumber->display(distance);
 //   ui->lcdNumber_2->display(time);
    cnt = 0;
}
void MainWindow::on_comboBox_3_activated(const QString &arg1) //选择出行方式
{
    if(arg1=="骑行")
        v = v_bicycle;
    else if(arg1=="步行")
        v = v_walk;
     time = distance/v;
     if(time == 0)
      time = 1;
    ui->lcdNumber_2->display(time);
}
