#include"calculator.h"

calculator::calculator()
{
    now=HPFloat(0);
    ans=HPFloat(0);
    cal="0";
    calculated=true;
}

std::string calculator::calculate()
{
    calculated=true;
    if(cal=="+")
    {
        now=ans+now;
        ans=now;
        return now.to_string();
    }
    if(cal=="-")
    {
        now=ans-now;
        ans=now;
        return now.to_string();
    }
    if(cal=="*")
    {
        now=ans*now;
        ans=now;
        return now.to_string();
    }
    if(cal=="/")
    {
        now=ans/now;
        ans=now;
        return now.to_string();
    }
    if(cal=="conv")
    {
        now=ans.conversion(int(now.to_num()));
        ans=now;
        return now.to_string();
    }
    if(cal=="reconv")
    {
        now=ans.reconversion(int(now.to_num()));
        ans=now;
        return now.to_string();
    }
    if(cal=="sin")
    {
        now=now.HPFsin();
        ans=now;
        cal="";
        return now.to_string();
    }
    if(cal=="cos")
    {
        now=now.HPFcos();
        ans=now;
        cal="";
        return now.to_string();
    }
    if(cal=="x2")
    {
        now=now.square();
        ans=now;
        cal=""; // 防止重复运算
        return now.to_string();
    }
    if(cal=="x3")
    {
        now=now.cube();
        ans=now;
        cal=""; // 防止重复运算
        return now.to_string();
    }
    if(cal=="pow")
    {
        now=ans.pow(now);
        ans=now;
        return now.to_string();
    }
    if(cal=="log")
    {
        now=now.log();
        ans=now;
        cal=""; // 防止重复运算
        return now.to_string();
    }
    std::string s="";
    return s;
}

void calculator::save_number(std::string&s)
{
    if(cal_num==0) now=HPFloat(s),calculated=false;
    else if(cal_num>0)
    {
        ans=now;
        now=HPFloat(s);
        calculate();
    }
    cal_num++;
}

void calculator::save_cal(std::string&s)
{
    cal=s;
    if(s=="x2"||s=="x3"||s=="sin"||s=="cos"||s=="log") {calculate();}
    else if(s=="") calculated=true;
    else{
        calculated=false;
    }
}

std::string calculator::send_res()
{
    return now.to_string();
}

void calculator::clear()
{
    now=HPFloat(0);
    ans=HPFloat(0);
    cal="";
    calculated=true;
    cal_num=0;
}
