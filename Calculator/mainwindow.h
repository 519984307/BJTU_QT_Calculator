#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include"calculator.h"
#include <QChar>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    calculator c;
    QString in_s,out_s; // in_s负责记录输入，out_s负责记录输出
};
#endif // MAINWINDOW_H
