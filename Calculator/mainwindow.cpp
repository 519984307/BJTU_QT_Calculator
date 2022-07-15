#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include<QPushButton>
#include<QTextEdit>
#include<string.h>
#include"calculator.h"
#include<QTextCharFormat>
#include<QFont>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    in_s="";
    out_s="";

    setFixedSize(500,600);  // 固定窗口大小
    setWindowTitle("CALCULATOR");

    QPushButton* button_1 = new QPushButton(this);
    QPushButton* button_2 = new QPushButton(this);
    QPushButton* button_3 = new QPushButton(this);
    QPushButton* button_4 = new QPushButton(this);
    QPushButton* button_5 = new QPushButton(this);
    QPushButton* button_6 = new QPushButton(this);
    QPushButton* button_7 = new QPushButton(this);
    QPushButton* button_8 = new QPushButton(this);
    QPushButton* button_9 = new QPushButton(this);
    QPushButton* button_0 = new QPushButton(this);
    QPushButton* button_plus = new QPushButton(this);
    QPushButton* button_sub = new QPushButton(this);
    QPushButton* button_mul = new QPushButton(this);
    QPushButton* button_div = new QPushButton(this);
    QPushButton* button_clear = new QPushButton(this);
    QPushButton* button_equal = new QPushButton(this);
    QPushButton* button_point = new QPushButton(this);
    QPushButton* button_square = new QPushButton(this);
    QPushButton* button_cube = new QPushButton(this);
    QPushButton* button_delete = new QPushButton(this);
    QPushButton* button_sin = new QPushButton(this);
    QPushButton* button_cos = new QPushButton(this);
    QPushButton* button_log = new QPushButton(this);
    QPushButton* button_conv = new QPushButton(this);
    QPushButton* button_reconv=new QPushButton(this);
    QPushButton* button_pow = new QPushButton(this);

    button_0->setText("0");
    button_1->setText("1");
    button_2->setText("2");
    button_3->setText("3");
    button_4->setText("4");
    button_5->setText("5");
    button_6->setText("6");
    button_7->setText("7");
    button_8->setText("8");
    button_9->setText("9");
    button_plus->setText("+");
    button_sub->setText("-");
    button_mul->setText("*");
    button_div->setText("/");
    button_clear->setText("AC");
    button_equal->setText("=");
    button_point->setText(".");
    button_square->setText("x^2");
    button_cube->setText("x^3");
    button_delete->setText("Del");
    button_sin->setText("sin");
    button_cos->setText("cos");
    button_log->setText("log");
    button_conv->setText("10->X");
    button_reconv->setText("X->10");
    button_pow->setText("pow");

    // 设置显示窗口
    QTextEdit *text = new QTextEdit(this);
    text->resize(500,100);
    text->move(0,0);
    QTextCharFormat fmt;
    fmt.setFont(QFont("Timers",20,QFont::Bold));
    text->setCurrentCharFormat(fmt);
    text->setEnabled(true);
    text->setWordWrapMode(QTextOption::WrapAnywhere);

    // 按钮布局
    button_clear->resize(100,100);
    button_clear->move(0,100);
    button_clear->setFont(QFont("微软雅黑",18));


    button_square->resize(100,100);
    button_square->move(100,100);
    button_square->setFont(QFont("微软雅黑",18));

    button_cube->resize(100,100);
    button_cube->move(200,100);
    button_cube->setFont(QFont("微软雅黑",18));

    button_sin->resize(100,100);
    button_sin->move(300,100);
    button_sin->setFont(QFont("微软雅黑",18));

    button_cos->resize(100,100);
    button_cos->move(400,100);
    button_cos->setFont(QFont("微软雅黑",18));

    button_7->resize(100,100);
    button_7->move(0,200);
    button_7->setFont(QFont("微软雅黑",18));

    button_8->resize(100,100);
    button_8->move(100,200);
    button_8->setFont(QFont("微软雅黑",18));

    button_9->resize(100,100);
    button_9->move(200,200);
    button_9->setFont(QFont("微软雅黑",18));

    button_plus->resize(100,100);
    button_plus->move(300,200);
    button_plus->setFont(QFont("微软雅黑",18));

    button_log->resize(100,100);
    button_log->move(400,200);
    button_log->setFont(QFont("微软雅黑",18));

    button_4->resize(100,100);
    button_4->move(0,300);
    button_4->setFont(QFont("微软雅黑",18));

    button_5->resize(100,100);
    button_5->move(100,300);
    button_5->setFont(QFont("微软雅黑",18));

    button_6->resize(100,100);
    button_6->move(200,300);
    button_6->setFont(QFont("微软雅黑",18));

    button_sub->resize(100,100);
    button_sub->move(300,300);
    button_sub->setFont(QFont("微软雅黑",18));

    button_pow->resize(100,100);
    button_pow->move(400,300);
    button_pow->setFont(QFont("微软雅黑",18));

    button_1->resize(100,100);
    button_1->move(0,400);
    button_1->setFont(QFont("微软雅黑",18));

    button_2->resize(100,100);
    button_2->move(100,400);
    button_2->setFont(QFont("微软雅黑",18));

    button_3->resize(100,100);
    button_3->move(200,400);
    button_3->setFont(QFont("微软雅黑",18));

    button_mul->resize(100,100);
    button_mul->move(300,400);
    button_mul->setFont(QFont("微软雅黑",18));

    button_conv->resize(100,50);
    button_conv->move(400,400);
    button_conv->setFont(QFont("微软雅黑",18));

    button_reconv->resize(100,50);
    button_reconv->move(400,450);
    button_reconv->setFont(QFont("微软雅黑",18));

    button_point->resize(100,100);
    button_point->move(0,500);
    button_point->setFont(QFont("微软雅黑",18));

    button_0->resize(100,100);
    button_0->move(100,500);
    button_0->setFont(QFont("微软雅黑",18));

    button_delete->resize(100,100);
    button_delete->move(200,500);
    button_delete->setFont(QFont("微软雅黑",18));

    button_div->resize(100,100);
    button_div->move(300,500);
    button_div->setFont(QFont("微软雅黑",18));

    button_equal->resize(100,100);
    button_equal->move(400,500);
    button_equal->setFont(QFont("微软雅黑",18));

    connect(button_0,&QPushButton::clicked,[=]()
    {
        in_s+="0";
        out_s=in_s;
        text->setText(out_s);
    });

    connect(button_1,&QPushButton::clicked,[=]()
    {
        in_s+="1";
        out_s=in_s;
        text->setText(out_s);
    });

    connect(button_2,&QPushButton::clicked,[=]()
    {
        in_s+="2";
        out_s=in_s;
        text->setText(out_s);
    });

    connect(button_3,&QPushButton::clicked,[=]()
    {
        in_s+="3";
        out_s=in_s;
        text->setText(out_s);
    });

    connect(button_4,&QPushButton::clicked,[=]()
    {
        in_s+="4";
        out_s=in_s;
        text->setText(out_s);
    });

    connect(button_5,&QPushButton::clicked,[=]()
    {
        in_s+="5";
        out_s=in_s;
        text->setText(out_s);
    });

    connect(button_6,&QPushButton::clicked,[=]()
    {
        in_s+="6";
        out_s=in_s;
        text->setText(out_s);
    });

    connect(button_7,&QPushButton::clicked,[=]()
    {
        in_s+="7";
        out_s=in_s;
        text->setText(out_s);
    });

    connect(button_8,&QPushButton::clicked,[=]()
    {
        in_s+="8";
        out_s=in_s;
        text->setText(out_s);
    });

    connect(button_9,&QPushButton::clicked,[=]()
    {
        in_s+="9";
        out_s=in_s;
        text->setText(out_s);
    });

    connect(button_point,&QPushButton::clicked,[=]()
    {
        if(in_s=="")
        {
            in_s+="0.";
            out_s=".";
            text->setText(out_s);
        }
        QString search=".";
        if(in_s.indexOf(search)==-1)
        {
            in_s+=".";
            out_s=in_s;
            text->setText(out_s);
        }
    });

    connect(button_plus,&QPushButton::clicked,[=]()
    {
        if(in_s!="")  // 第一次运算
        {
            std::string str=in_s.toStdString();
            c.save_number(str);
        }
        std::string cal="+";
        c.save_cal(cal);
        in_s.clear();
        out_s=QString::fromStdString(c.send_res());
        text->setText(out_s);
    });

    connect(button_sub,&QPushButton::clicked,[=]()
            // 注意减号可以表示减法也可以表示负数
    {
        if(out_s!="" && c.have_caled())  // 有被减数的时候
        {
            in_s=out_s;
            std::string str=in_s.toStdString();
            c.save_number(str);
            std::string cal="-";
            c.save_cal(cal);
            in_s.clear();
            out_s=QString::fromStdString(c.send_res());
            text->setText(out_s);
        }
        else if(in_s=="")
        {
            in_s+="-";
            out_s=in_s;
            text->setText(out_s);
        }
    });

    connect(button_mul,&QPushButton::clicked,[=]()
    {
        if(in_s!="")
        {
            std::string str=in_s.toStdString();
            c.save_number(str);
        }
        std::string cal="*";
        c.save_cal(cal);
        in_s.clear();
        out_s=QString::fromStdString(c.send_res());
        text->setText(out_s);
    });

    connect(button_div,&QPushButton::clicked,[=]()
    {
        if(in_s!="")
        {
            std::string str=in_s.toStdString();
            c.save_number(str);
        }
        std::string cal="/";
        c.save_cal(cal);
        in_s.clear();
        out_s=QString::fromStdString(c.send_res());
        text->setText(out_s);
    });

    connect(button_equal,&QPushButton::clicked,[=]()
    {
        if(in_s!="")
        {
            std::string str=in_s.toStdString();
            c.save_number(str);
        }
        in_s.clear();
        out_s=QString::fromStdString(c.send_res());
        text->setText(out_s);
        std::string cal="";
        c.save_cal(cal);  // 消除之前的运算符号
    });

    connect(button_clear,&QPushButton::clicked,[=]()
    {
        c.clear();
        in_s="",out_s="";
        text->setText(out_s);
    });

    connect(button_square,&QPushButton::clicked,[=]()
    {
        in_s=out_s;
        std::string str=in_s.toStdString();
        c.save_number(str);
        std::string cal="x2";
        c.save_cal(cal);
        in_s.clear();
        out_s=QString::fromStdString(c.send_res());
        text->setText(out_s);
    });

    connect(button_cube,&QPushButton::clicked,[=]()
    {
        in_s=out_s;
        std::string str=in_s.toStdString();
        c.save_number(str);
        std::string cal="x3";
        c.save_cal(cal);
        in_s.clear();
        out_s=QString::fromStdString(c.send_res());
        text->setText(out_s);
    });

    connect(button_sin,&QPushButton::clicked,[=]()
    {
        in_s=out_s;
        std::string str=in_s.toStdString();
        c.save_number(str);
        std::string cal="sin";
        c.save_cal(cal);
        in_s.clear();
        out_s=QString::fromStdString(c.send_res());
        text->setText(out_s);
    });

    connect(button_cos,&QPushButton::clicked,[=]()
    {
        in_s=out_s;
        std::string str=in_s.toStdString();
        c.save_number(str);
        std::string cal="cos";
        c.save_cal(cal);
        in_s.clear();
        out_s=QString::fromStdString(c.send_res());
        text->setText(out_s);
    });

    connect(button_log,&QPushButton::clicked,[=]()
    {
        in_s=out_s;
        std::string str=in_s.toStdString();
        c.save_number(str);
        std::string cal="log";
        c.save_cal(cal);
        in_s.clear();
        out_s=QString::fromStdString(c.send_res());
        text->setText(out_s);
    });

    connect(button_delete,&QPushButton::clicked,[=]()
    {
        if(in_s!="")
        {
            in_s=in_s.left(in_s.length()-1);
        }
        out_s=in_s;
        text->setText(out_s);
    });

    connect(button_pow,&QPushButton::clicked,[=]()
    {
        if(in_s!="")
        {
            std::string str=in_s.toStdString();
            c.save_number(str);
        }
        std::string cal="pow";
        c.save_cal(cal);
        in_s.clear();
        out_s=QString::fromStdString(c.send_res());
        text->setText(out_s);
    });

    connect(button_conv,&QPushButton::clicked,[=]()
    {
        if(in_s!="")
        {
            std::string str=in_s.toStdString();
            c.save_number(str);
        }
        std::string cal="conv";
        c.save_cal(cal);
        in_s.clear();
        out_s=QString::fromStdString(c.send_res());
        text->setText(out_s);
    });

    connect(button_reconv,&QPushButton::clicked,[=]()
    {
        if(in_s!="")
        {
            std::string str=in_s.toStdString();
            c.save_number(str);
        }
        std::string cal="reconv";
        c.save_cal(cal);
        in_s.clear();
        out_s=QString::fromStdString(c.send_res());
        text->setText(out_s);
    });
}

MainWindow::~MainWindow()
{
}

