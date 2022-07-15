#include <iostream>
#include "HPFloat.h"
#include <string.h>
#include <cstdlib>
#include <vector>
#include <math.h>
#include <stdio.h>
#include <cmath>
#include <algorithm>

HPFloat::HPFloat()
{
    tag = true;
    integer.push_back(0);
    decimal.push_back(0); //无参初始化为0
}

HPFloat::HPFloat(std::string &num)
{
    bool type = true; // 记录小数时，type=true;
    tag = true;
    if (num.find('.') == -1)
        num += ".0";
    for (int i = num.size() - 1; i >= 0; i--)
    {
        char ch = num[i];
        if (ch == '.')
        {
            type = false;
            i--;
        }
        if (i == 0)
        {
            if (ch == '+')
            {
                break;
            }
            if (ch == '-')
            {
                tag = false;
                break;
            }
        }
        ch = num[i];
        if (type)
        {
            if(ch>='0'&&ch<='9')
            {
                decimal.push_back((char)(ch-'0'));
            }
            else decimal.push_back((char)(ch-'a'+10));
        }
        else
        {
            if(ch>='0'&&ch<='9')
            {
                integer.push_back((char)(ch-'0'));
            }
            else integer.push_back((char)(ch-'a'+10));
        }
    }
}

HPFloat::HPFloat(std::vector<char> &a, std::vector<char> &b, bool tag)
{
    this->tag = tag;
    this->integer = a;
    this->decimal = b;
}

HPFloat::HPFloat(int v)
{
    if (v >= 0)
        tag = true;
    else
        tag = false, v = -v;
    if (!v)
        integer.push_back((char)(v % 10));
    while (v)
    {
        integer.push_back((char)(v % 10));
        v /= 10;
    }
    decimal.push_back(0);
}


HPFloat::HPFloat(const HPFloat &a) // 复制构造
{
    integer = a.integer;
    decimal = a.decimal;
    tag = a.tag;
}

HPFloat operator-(const HPFloat &a)
{
    HPFloat tmp(a);
    tmp.tag = !tmp.tag;
    return tmp;
}

void HPFloat::trim()
{
    while (!integer.empty() && integer.back() == 0)
    {
        integer.pop_back();
    }
    if (!integer.size())
        integer.push_back(0);
    while (!decimal.empty() && decimal.front() == 0)
    {
        decimal.erase(decimal.begin());
    }
    if (!decimal.size())
        decimal.push_back(0);
}

HPFloat HPFloat::operator=(const HPFloat &a)
{
    this->integer = a.integer;
    this->decimal = a.decimal;
    this->tag = a.tag;
    return *this;
}

HPFloat HPFloat::square()
{
    HPFloat tmp(*this);
    HPFloat res=tmp*tmp;
    return res;
}

HPFloat HPFloat::cube()
{
    HPFloat tmp(*this);
    HPFloat res=tmp*tmp*tmp;
    return res;
}

double HPFloat::to_num()
{
    double a = 0, b = 0;
    for (int i = integer.size() - 1; i >= 0; i--)
    {
        a *= 10;
        a += integer[i];
    }
    double t = 10;
    for (int i = decimal.size() - 1; i >= std::max(0, int(decimal.size() - 5)); i--) // 保留5位小数
    {
        b += decimal[i] / t;
        t *= 10;
    }
    if(!tag) a=-a,b=-b;
    return a + b;
}

HPFloat HPFloat::HPFsin()
{
    std::string pi="3.1415926535897932384626433832795028841971693993751058209749";
    HPFloat tmp(*this),tpi=HPFloat(2)*HPFloat(pi);
    HPFloat m=tmp/tpi;
    std::vector<char>zero{0};
    HPFloat m_int(m.integer,zero,m.tag);
    tmp=tmp-m_int*tpi;
    HPFloat mul=tmp;
    HPFloat res(0),fac(1);
    for(int i=1;i<=50;i++)
    {
        // res.show();
        HPFloat cur=tmp/fac;
        // cur.show();
        if(i%2==1)
        {
            res+=cur;
        }
        else
        {
            res-=cur;
        }
        // res.show();
        tmp=tmp*mul*mul;
        fac=fac*HPFloat(2*i)*HPFloat(2*i+1);
    }
    if(res.decimal.size()>20) res.decimal.erase(res.decimal.begin(),res.decimal.end()-20);
    return res;
}

HPFloat HPFloat::HPFcos()
{
    std::string pi="3.1415926535897932384626433832795028841971693993751058209749";
    HPFloat tmp(*this),tpi=HPFloat(2)*HPFloat(pi);
    HPFloat m=tmp/tpi;
    std::vector<char>zero{0};
    HPFloat m_int(m.integer,zero,m.tag);
    tmp=tmp-m_int*tpi;
    HPFloat mul=tmp.square();
    HPFloat res(1),fac(2);
    tmp=tmp.square();
    for(int i=1;i<=50;i++)
    {
        if(i%2)
        {
            res-=tmp/fac;
        }
        else
        {
            res+=tmp/fac;
        }
        tmp*=mul;
        fac*=HPFloat(2*i+1)*HPFloat(2*i+2);
    }
    // 出于精度考虑 只保留15位小数
    if(res.decimal.size()>20) res.decimal.erase(res.decimal.begin(),res.decimal.end()-20);
    return res;
}


HPFloat HPFloat::conversion(int mode)
{
    HPFloat m(mode);
    std::vector<char> zero{0};
    HPFloat a(integer, zero, true);
    HPFloat b(zero, decimal, true);
    std::vector<char> conv_int, conv_dec;
    while (a > HPFloat(0))
    {
        HPFloat res = a / m;
        HPFloat res_int(res.integer, zero, true);
        HPFloat remainder = a - m * res_int;
        char t = 0;
        if (remainder.integer.size() == 1)
            t = remainder.integer[0];
        else if (remainder.integer.size() >= 2)
            t = remainder.integer[0] + 10 * remainder.integer[1];
        conv_int.push_back(t);
        a = res_int; // a是商的整数部分
        // res_int.show();
    }
    for (int i = 0; i < 100; i++) // 取100位有效数字
    {
        b = b * m;
        char t = 0;
        if (b.integer.size() == 1)
            t = b.integer[0];
        else if (b.integer.size() >= 2)
            t = b.integer[0] + 10 * b.integer[1];
        b -= HPFloat((int)t);
        conv_dec.push_back(t);
    }
    std::reverse(conv_dec.begin(), conv_dec.end());
    HPFloat res = HPFloat(conv_int, conv_dec, this->tag);
    // if(res.decimal.size()>20) res.decimal.erase(res.decimal.begin(),res.decimal.end()-20);
    res.trim();
    return res;
}


HPFloat HPFloat::reconversion(int mode)
{
    HPFloat base(mode);
    HPFloat inte(0);
    HPFloat power_int(1);
    for(int i=0;i<integer.size();i++)
    {
        HPFloat n(integer[i]);
        inte+=n*power_int;
        power_int*=base;
    }
    HPFloat deci(0);
    HPFloat power_dec(1);
    for(int i=decimal.size()-1;i>=std::max(0,int(decimal.size()-30));i--)
        // 只乘30次
    {
        power_dec/=base;
        HPFloat n(decimal[i]);
        HPFloat cur=n*power_dec;
        deci+=cur;
    }
    HPFloat res=inte+deci;
    res.tag=this->tag; // 注意正负号
    return res;
}


HPFloat HPFloat::pow(HPFloat &a) // 符合要求
{
    std::vector<char>zero{0};
    HPFloat power(a.integer,zero,true);
    HPFloat tmp(*this),mul(*this),Zero(0),one(1);
    if(!a.tag)  // a是负数的话 底数取倒数
    {
        tmp=one/tmp;
        mul=tmp;
    }
    while(power>one)
    {
        tmp=tmp*mul;
        power-=one;
    }
    return tmp;
}

HPFloat HPFloat::log() // 符合要求
{
    if (!tag || *this==HPFloat(0))
        return HPFloat(0); // 负数不能取ln值
    std::string s = "2.7182818284590452353602874713526624977572";
    HPFloat e(s);
    HPFloat tmp(*this),one(1);
    int cnt = 0;
    while (tmp > one)
    {
        tmp /= e;
        cnt++;
    }
    HPFloat res_int(cnt);
    tmp-=one;
    HPFloat fac(1),mul(tmp);
    HPFloat res(0);
    // tmp.show();
    for(int i=1;i<=100;i++)
    {
        HPFloat cur=tmp/fac;
        // cur.show();
        if(i%2)
        {
            res+=cur;
        }
        else
        {
            res-=cur;
        }
        // res.show();
        fac+=one;
        tmp*=mul;
    }
    res+=res_int;
    if(res.decimal.size()>20) res.decimal.erase(res.decimal.begin(),res.decimal.end()-20);
    return res;
}

void HPFloat::show() // 输出结果函数
{
    std::cout<<this->to_string()<<std::endl;
}

bool HPFloat::fuzzy_equal(const HPFloat&a)
// 模糊判断，整数部分相同，小数部分前8位相同即认为模糊相等
{
    if(this->tag!=a.tag) return false;
    std::vector<char>zero{0};
    std::vector<char>this_int_vec=this->integer;
    std::vector<char>a_int_vec=a.integer;
    HPFloat this_int(this_int_vec,zero,true);
    HPFloat a_int(a_int_vec,zero,true);
    if(this_int!=a_int) return false;
    else
    {
        // std::puts("The two numbers are integer equal.");
        // 数位太多，只比较前10位就可以了
        if(a.decimal.size()>10&&decimal.size()>10)
        {
            for(int i=decimal.size()-10,j=a.decimal.size()-10;i<decimal.size()&&j<a.decimal.size();i++,j++)
            {
                if(decimal[i]!=a.decimal[j])
                {
                    if(i==decimal.size()-10&&j==a.decimal.size()-10)
                    {
                        if(decimal[decimal.size()-11]>=5&&decimal[i]==a.decimal[j]+1 || a.decimal[a.decimal.size()-11]>=5&&a.decimal[j]==decimal[i]+1)
                        {
                            continue;
                        }
                        else return false;
                    }
                }
            }
            return true;
        }
        else
        {
            for(int i=decimal.size()-1,j=a.decimal.size()-1;i>=0&&j>=0;i--,j--)
            {
                if(decimal[i]!=a.decimal[j])
                {
                    if(i>0&&j>0) return false;
                    else if(i==0&&j>0)
                    {
                        if(a.decimal[j-1]>=5&&decimal[i]==a.decimal[j]+1)
                        {
                            return true;
                        }
                        else return false;
                    }
                    else if(j==0&&i>0)
                    {
                        if(decimal[i-1]>=5&&a.decimal[j]==decimal[i]+1)
                        {
                            return true;
                        }
                        else return false;
                    }
                }
            }
        }
    }
    return true;
}

std::string HPFloat::to_string()
{
    std::string s;
    if(!tag) s+='-';
    for(int i=integer.size()-1;i>=0;i--)
    {
        if(integer[i]>=0&&integer[i]<10)
        {
            s+=(char)(integer[i]+'0');
        }
        else s+=(char)(integer[i]-10+'a');
    }
    if(decimal.size()>1||(decimal.size()==1&&decimal[0]!=0))
    {
        s+='.';
        for(int i=decimal.size()-1;i>=0;i--)
        {
            if(decimal[i]>=0&&decimal[i]<10)
            {
                s+=(char)(decimal[i]+'0');
            }
            else s+=(char)(decimal[i]-10+'a');
        }
    }
    // std::cout<<s<<std::endl;
    return s;
}
