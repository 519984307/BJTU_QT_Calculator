#ifndef HPFLOAT_H
#define HPFLOAT_H

#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <iostream>

class HPFloat
{
public:
    HPFloat();
    HPFloat(std::string &);
    HPFloat(int);
    HPFloat(const HPFloat &);
    HPFloat(std::vector<char> &, std::vector<char> &, bool);
    HPFloat operator=(const HPFloat &);
    HPFloat square();
    HPFloat cube();
    HPFloat HPFsin();
    HPFloat HPFcos();
    HPFloat conversion(int);
    HPFloat reconversion(int);
    double to_num();
    HPFloat pow(HPFloat&);
    HPFloat log();
    void show();
    bool fuzzy_equal(const HPFloat&);
    std::string to_string();
    friend HPFloat operator+(const HPFloat &, const HPFloat &);
    friend HPFloat operator-(const HPFloat &, const HPFloat &);
    friend HPFloat operator*(const HPFloat &, const HPFloat &);
    friend HPFloat operator/(const HPFloat &, const HPFloat &);
    friend HPFloat operator+=(HPFloat &, const HPFloat &);
    friend HPFloat operator-=(HPFloat &, const HPFloat &);
    friend HPFloat operator*=(HPFloat &, const HPFloat &);
    friend HPFloat operator/=(HPFloat &, const HPFloat &);
    friend HPFloat operator-(const HPFloat &);
    friend bool operator==(const HPFloat &, const HPFloat &);
    friend bool operator<(const HPFloat &, const HPFloat &);
    friend bool operator<=(const HPFloat &, const HPFloat &);
    friend bool operator>(const HPFloat &, const HPFloat &);
    friend bool operator>=(const HPFloat &, const HPFloat &);
    friend bool operator!=(const HPFloat &, const HPFloat &);

private:
    std::vector<char> integer, decimal;
    void trim(); // 删去多余的0
    bool tag;    // 1:正数，0:负数
};

inline HPFloat operator+=(HPFloat &a, const HPFloat &b)
{
    if (a.tag == b.tag)
    {
        char c = 0;
        if (a.decimal.size() < b.decimal.size())
        {
            while (a.decimal.size() < b.decimal.size())
            {
                a.decimal.insert(a.decimal.begin(), 0);
            }
            for (int i = 0; i < a.decimal.size(); i++)
            {
                a.decimal[i] = a.decimal[i] + b.decimal[i] + c;
                if (a.decimal[i] >= 10)
                {
                    c = 1;
                    a.decimal[i] = a.decimal[i] % 10;
                }
                else c=0;
            }
        }
        else
        {
            for (int i = a.decimal.size() - b.decimal.size(), j = 0; i < a.decimal.size() && j<b.decimal.size(); i++, j++)
            {
                a.decimal[i] = a.decimal[i] + b.decimal[j] + c;
                if (a.decimal[i] >= 10)
                {
                    c = 1;
                    a.decimal[i] = a.decimal[i] % 10;
                }
                else c=0;
            }
        }
        for (int i = 0; i < a.integer.size() || i < b.integer.size(); i++)
        {
            if (i < a.integer.size())
            {
                c += a.integer[i];
            }
            if (i < b.integer.size())
            {
                c += b.integer[i];
            }
            if (i < a.integer.size())
            {
                a.integer[i] = c % 10;
            }
            else
                a.integer.push_back(c % 10);
            c /= 10;
        }
        if (c)
            a.integer.push_back(c);
        a.trim();
        return a;
    }
    else
    {
        if (a.tag)
            return a -= (-b);
        else
            return a = b - (-a);
    }
}

inline HPFloat operator-=(HPFloat &a, const HPFloat &b)
{
    if (a.tag == b.tag) // 只处理符号相同的情况
    {
        if (a.tag)
        {
            if (a < b)
            {
                HPFloat tmp(b - a);
                a = -tmp;
                // std::puts("进入减法函数");
                // a.show();
                return a;
            }
        }
        else
        {
            if ((-a) > (-b))
                return a = -((-a) - (-b));
            else
                return a = (-b) - (-a);
        }
        char c = 0;
        if (a.decimal.size() < b.decimal.size())
        {
            while (a.decimal.size() < b.decimal.size())
            {
                a.decimal.insert(a.decimal.begin(), 0);
            }
            for (int i = 0; i < a.decimal.size(); i++)
            {
                a.decimal[i] = a.decimal[i] - b.decimal[i] - c;
                c = 0;
                if (a.decimal[i] < 0)
                {
                    c = 1;
                    a.decimal[i] += 10;
                }
            }
        }
        else
        {
            for (int i = a.decimal.size() - b.decimal.size(), j = 0; i < a.decimal.size(); i++, j++)
            {
                a.decimal[i] = a.decimal[i] - b.decimal[j] - c;
                c = 0;
                if (a.decimal[i] < 0)
                {
                    c = 1;
                    a.decimal[i] += 10;
                }
            }
        }
        for (int i = 0; i < a.integer.size(); i++)
        {
            c = a.integer[i] - c;
            if (i < b.integer.size())
            {
                c -= b.integer[i];
            }
            a.integer[i] = ((c + 10) % 10);
            if (c < 0)
                c = 1;
            else
                c = 0;
        }
        a.trim();
        return a;
    }
    else
    {
        if (a.tag)
        {
            return a += (-b);
        }
        else
        {
            return (a=-(b + (-a)));
        }
    }
}

inline HPFloat operator*=(HPFloat &a, const HPFloat &b) // 对于乘法，我们记录小数点的位置，然后把两个小数当作两个整数进行运算，最后补上小数点
{
    HPFloat res(0);
        HPFloat zero = HPFloat(0);
        if (a == zero || b == zero)
        {
            res = zero;
        }
        else
        {
            int sz = 0;
            std::vector<char> tmp_a(a.integer.begin(), a.integer.end());
            if (a.decimal.size() != 1 || (a.decimal.size() == 1 && a.decimal[0] != 0))
            {
                // 如果被乘数有小数部分，加进来
                tmp_a.insert(tmp_a.begin(), a.decimal.begin(), a.decimal.end());
                sz += a.decimal.size();
            }
            std::vector<char> tmp_b(b.integer.begin(), b.integer.end());
            if (b.decimal.size() != 1 || (b.decimal.size() == 1 && b.decimal[0] != 0))
            {
                tmp_b.insert(tmp_b.begin(), b.decimal.begin(), b.decimal.end());
                sz += b.decimal.size();
            }
            for (int i = 0; i < tmp_b.size(); i++)
            {
                if (tmp_b[i] != 0)
                {
                    std::deque<char> tmp(tmp_a.begin(), tmp_a.end());
                    char c = 0;
                    std::deque<char>::iterator it = tmp.begin();
                    while (it != tmp.end())
                    {
                        (*it) *= tmp_b[i];
                        (*it) += c;
                        c = (*it) / 10;
                        (*it) %= 10;
                        it++;
                    }
                    if (c != 0)
                        tmp.push_back(c);
                    int zeros = i;
                    while (zeros--)
                    {
                        tmp.push_front(0);
                    }
                    HPFloat t;
                    t.integer.clear();
                    t.integer.insert(t.integer.end(), tmp.begin(), tmp.end());
                    t.trim();
                    res = res + t;
                }
            }
            res.tag = ((a.tag && b.tag) || (!a.tag && !b.tag));
            if (sz != 0)
            {
                if (sz >= res.integer.size())  // 补上前导0
                {
                    int k = sz - res.integer.size();
                    for (int i = 0; i <= k; i++)
                    {
                        res.integer.insert(res.integer.end(), 0);
                    }
                }
                res.decimal.clear();
                res.decimal.insert(res.decimal.begin(), res.integer.begin(), res.integer.begin() + sz);
                res.integer.erase(res.integer.begin(), res.integer.begin() + sz);
            }
        }
        a = res;
        a.trim(); // 记得清除前导0
        return a;
}

inline HPFloat operator/=(HPFloat &a, const HPFloat &b)
{
    HPFloat zero = HPFloat(0), ten = HPFloat(10);
    // zero.show(),a.show();
    if (b == zero)
    {
        // err: div 0
        return a=HPFloat(0);
    }
    if (a == zero)
    {
        return a;
    }
    if (a == b)
        return a = HPFloat(1);
    else if (a == -b)
        return a = HPFloat(-1);
    bool tag_a=a.tag,tag_b=b.tag;
    HPFloat tmp_a(a), tmp_b(b);
    tmp_a.tag = tmp_b.tag = true; // 转换为无符号数
    int int_sz = 0;
    if ((tmp_b.decimal.size() == 1) && (tmp_b.decimal[0] == 0))
    {
    }
    else
    {
        int t = tmp_b.decimal.size(); // 把被除数和除数同时扩大
        while (t--)
        {
            tmp_a = tmp_a * ten;
            tmp_b = tmp_b * ten;
        }
    }
    if (tmp_a < tmp_b) // 被除数小于除数的情况
    {
        while (tmp_a < tmp_b)
        {
            tmp_a *= ten;
            int_sz--;
        }
    }
    else
    {
        while (tmp_a > tmp_b) // 被除数除以10
        {
            tmp_a.decimal.push_back(tmp_a.integer[0]);
            tmp_a.integer.erase(tmp_a.integer.begin());
            int_sz++;
        }
    }
    int acu = 200; // 准确度
    HPFloat res(0);
    while (acu--)
    {
        if (tmp_a < tmp_b)
        {
            if(tmp_a==zero) break;
            tmp_a = tmp_a * ten;
            res = res * ten;
        }
        else
        {
            int i;
            HPFloat compare;
            for (i = 2; i <=10; i++) // 试商操作
            {
                HPFloat BF(i);
                compare = tmp_b * BF;
                if (compare > tmp_a)
                    break;
            }
            compare -= tmp_b;
            tmp_a -= compare;
            HPFloat idx(i - 1);
            res = res + idx;
        }
    }
    if (int_sz < 0) // 小数除以大数
    {
        std::vector<char> tmp(res.integer.begin(), res.integer.end());
        res.integer.clear();
        res.integer.push_back(0); // 整数部分为0
        res.decimal.clear();
        for (int i = 0; i < -int_sz - 1; i++)
        {
            res.decimal.insert(res.decimal.begin(), 0);
        }
        res.decimal.insert(res.decimal.begin(), tmp.begin(), tmp.end());
    }
    else
    {
        if (res.integer.size() > int_sz)
        {
            // std::cout<<int_sz<<std::endl;
            std::vector<char> tmp(res.integer.begin(), res.integer.end());
            res.integer.clear();
            res.integer.assign(tmp.end() - int_sz, tmp.end());
            res.decimal.clear();
            res.decimal.insert(res.decimal.begin(), tmp.begin(), tmp.end() - int_sz);
        }
        else
        {
            int t = int_sz - res.integer.size();
            while (t--)
            {
                res = res * ten;
            }
        }
    }
    if(tag_a==tag_b) res.tag=true;
    else res.tag=false;
    // std::cout<<res.tag<<std::endl;
    // res.show();
    a = res;
    // std::cout<<a.tag<<std::endl;
    a.trim();
    return a;
}

inline HPFloat operator+(const HPFloat &a, const HPFloat &b)
{
    HPFloat tmp(a);
    tmp += b;
    return tmp;
}

inline HPFloat operator-(const HPFloat &a, const HPFloat &b)
{
    HPFloat tmp(a);
    tmp -= b;
    return tmp;
}

inline HPFloat operator*(const HPFloat &a, const HPFloat &b)
{
    HPFloat tmp(a);
    tmp *= b;
    return tmp;
}

inline HPFloat operator/(const HPFloat &a, const HPFloat &b)
{
    HPFloat tmp(a);
    tmp /= b;
    return tmp;
}

inline bool operator<(const HPFloat &a, const HPFloat &b)
{
    bool sgn = false;
    if (a.tag != b.tag)
    {
        sgn = !a.tag;
        return sgn;
    }
    else
    {
        if (a.tag)
        {
            if (a.integer.size() != b.integer.size())
            {
                return a.integer.size() < b.integer.size();
            }
            else
            {
                for (int i = a.integer.size() - 1; i >= 0; i--)
                {
                    if (a.integer[i] != b.integer[i])
                    {
                        return a.integer[i] < b.integer[i];
                    }
                    else
                        continue;
                }
            }
            int i, j;
            for (i = a.decimal.size() - 1, j = b.decimal.size() - 1; i >= 0 && j >= 0; i--, j--)
            {
                if (a.decimal[i] != b.decimal[j])
                    return a.decimal[i] < b.decimal[j];
            }
            if (i > 0)
                return false;
            if (j > 0)
                return true;
            return false;
        }
        else if(!a.tag)
        {
            if (a.integer.size() != b.integer.size())
            {
                return a.integer.size() > b.integer.size();
            }
            else
            {
                for (int i = a.integer.size() - 1; i >= 0; i--)
                {
                    if (a.integer[i] != b.integer[i])
                    {
                        return a.integer[i] > b.integer[i];
                    }
                    else
                        continue;
                }
            }
            int i, j;
            for (i = a.decimal.size() - 1, j = b.decimal.size() - 1; i >= 0 && j >= 0; i--, j--)
            {
                if (a.decimal[i] != b.decimal[j])
                    return a.decimal[i] > b.decimal[j];
            }
            if (i > 0)
                return true;
            if (j > 0)
                return false;
        }
        return false;
    }
}

inline bool operator>(const HPFloat &a, const HPFloat &b)
{
    return !(a <= b);
}

inline bool operator==(const HPFloat &a, const HPFloat &b)
{
    if (a.tag != b.tag)
        return false;
    if (a.integer.size() != b.integer.size())
        return false;
    if (a.decimal.size() != b.decimal.size())
        return false;
    for (int i = 0; i < a.integer.size(); i++)
    {
        if (a.integer[i] != b.integer[i])
            return false;
    }
    for (int i = 0; i < a.decimal.size(); i++)
    {
        if (a.decimal[i] != b.decimal[i])
            return false;
    }
    return true;
}

inline bool operator!=(const HPFloat &a, const HPFloat &b)
{
    return !(a == b);
}

inline bool operator>=(const HPFloat &a, const HPFloat &b)
{
    return ((a > b) || (a == b));
}

inline bool operator<=(const HPFloat &a, const HPFloat &b)
{
    return ((a < b) || (a == b));
}

#endif // HPFloat.h
