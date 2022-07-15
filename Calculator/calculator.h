#ifndef CALCULATOR_H
#define CALCULATOR_H

#include"HPFloat.h"
#include<iostream>
#include<string.h>

class calculator
{
public:
    calculator();
    std::string calculate();
    void save_number(std::string&);
    void save_cal(std::string&);
    std::string send_res();
    void clear();
    bool have_cal()
    {
        if(cal!="") return true;
        else return false;
    }
    bool have_caled()
    {
        return calculated;
    }
private:
    HPFloat ans,now;
    std::string cal; // 运算符
    int cal_num;
    bool calculated;
};

#endif // CALCULATOR_H
