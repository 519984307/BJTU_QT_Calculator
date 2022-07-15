#include <QtTest>
#include<string.h>
#include "../Calculator/HPFloat.h"
#include "../Calculator/HPFloat.cpp"
#include <fstream>
#include<iostream>
// add necessary includes here

class HPFloat;

class AutoTest : public QObject
{
    Q_OBJECT

public:
    AutoTest();
    ~AutoTest();

private slots:
    void test_case1_plus();
    void test_case2_sub();
    void test_case3_mul();
    void test_case4_div();
    void test_case5_sin();
    void test_case6_cos();
    void test_case7_log();
    void test_case8_pow();
    void test_case9_conversion();
    void test_case10_square();
    void test_case11_cube();

private:
    HPFloat a,b;
    HPFloat plus_res,sub_res,mul_res,div_res,sin_res_a,sin_res_b,cos_res_a,cos_res_b,log_res_a,log_res_b,pow_res;
    HPFloat conv_res_2,conv_res_3,conv_res_4,conv_res_5,conv_res_6,conv_res_7,conv_res_8,conv_res_9,conv_res_10,conv_res_11,conv_res_12,conv_res_13,conv_res_14,conv_res_15,conv_res_16;
    HPFloat square_res,cube_res;
};

AutoTest::AutoTest()
{

    // 初始化所有测试的变量内容
    std::string a_s,b_s,plus_res_s,sub_res_s,mul_res_s,div_res_s,sin_res_a_s,sin_res_b_s,cos_res_a_s,cos_res_b_s,log_res_a_s,log_res_b_s,pow_res_s;
    std::string conv_res_2_s,conv_res_3_s,conv_res_4_s,conv_res_5_s,conv_res_6_s,conv_res_7_s,conv_res_8_s,conv_res_9_s,conv_res_10_s,conv_res_11_s,conv_res_12_s,conv_res_13_s,conv_res_14_s,conv_res_15_s,conv_res_16_s;
    std::string square_res_s,cube_res_s;


    // 从文件中读取测试样例的内容
    std::ifstream test_file;
    test_file.open("..\\Calculator_Test\\test_samples\\test_5.txt");   // 该文件要加到CMakeLists.txt里面
    if(test_file.fail())
    {
        std::puts("Cannot open this file!");
    }
    getline(test_file,a_s);
    getline(test_file,b_s);
    getline(test_file,plus_res_s);
    getline(test_file,sub_res_s);
    getline(test_file,mul_res_s);
    getline(test_file,div_res_s);
    getline(test_file,sin_res_a_s);
    getline(test_file,sin_res_b_s);
    getline(test_file,cos_res_a_s);
    getline(test_file,cos_res_b_s);
    getline(test_file,log_res_a_s);
    getline(test_file,log_res_b_s);
    getline(test_file,pow_res_s);
    getline(test_file,conv_res_2_s);
    getline(test_file,conv_res_3_s);
    getline(test_file,conv_res_4_s);
    getline(test_file,conv_res_5_s);
    getline(test_file,conv_res_6_s);
    getline(test_file,conv_res_7_s);
    getline(test_file,conv_res_8_s);
    getline(test_file,conv_res_9_s);
    getline(test_file,conv_res_10_s);
    getline(test_file,conv_res_11_s);
    getline(test_file,conv_res_12_s);
    getline(test_file,conv_res_13_s);
    getline(test_file,conv_res_14_s);
    getline(test_file,conv_res_15_s);
    getline(test_file,conv_res_16_s);
    getline(test_file,square_res_s);
    getline(test_file,cube_res_s);

    test_file.close();

    a=HPFloat(a_s);
    b=HPFloat(b_s);
    plus_res=HPFloat(plus_res_s);
    sub_res=HPFloat(sub_res_s);
    mul_res=HPFloat(mul_res_s);
    div_res=HPFloat(div_res_s);
    sin_res_a=HPFloat(sin_res_a_s);
    sin_res_b=HPFloat(sin_res_b_s);
    cos_res_a=HPFloat(cos_res_a_s);
    cos_res_b=HPFloat(cos_res_b_s);
    log_res_a=HPFloat(log_res_a_s);
    log_res_b=HPFloat(log_res_b_s);
    pow_res=HPFloat(pow_res_s);
    conv_res_2=HPFloat(conv_res_2_s);
    conv_res_3=HPFloat(conv_res_3_s);
    conv_res_4=HPFloat(conv_res_4_s);
    conv_res_5=HPFloat(conv_res_5_s);
    conv_res_6=HPFloat(conv_res_6_s);
    conv_res_7=HPFloat(conv_res_7_s);
    conv_res_8=HPFloat(conv_res_8_s);
    conv_res_9=HPFloat(conv_res_9_s);
    conv_res_10=HPFloat(conv_res_10_s);
    conv_res_11=HPFloat(conv_res_11_s);
    conv_res_12=HPFloat(conv_res_12_s);
    conv_res_13=HPFloat(conv_res_13_s);
    conv_res_14=HPFloat(conv_res_14_s);
    conv_res_15=HPFloat(conv_res_15_s);
    conv_res_16=HPFloat(conv_res_16_s);
    square_res=HPFloat(square_res_s);
    cube_res=HPFloat(cube_res_s);
}

AutoTest::~AutoTest()
{

}

void AutoTest::test_case1_plus()
{
    HPFloat tmp=a+b;
    bool pass=(tmp==plus_res);
    QVERIFY(pass);
}

void AutoTest::test_case2_sub()
{
    HPFloat tmp=a-b;
    bool pass=(tmp==sub_res);
    QVERIFY(pass);
}

void AutoTest::test_case3_mul()
{
    HPFloat tmp=a*b;
    bool pass=(tmp==mul_res);
    QVERIFY(pass);
}

void AutoTest::test_case4_div()
{
    HPFloat tmp=a/b;
    bool pass=(tmp==div_res);
    QVERIFY(pass);
}

void AutoTest::test_case5_sin()
{
    HPFloat tmp_a=a.HPFsin(),tmp_b=b.HPFsin();
    bool pass=(tmp_a.fuzzy_equal(sin_res_a) && tmp_b.fuzzy_equal(sin_res_b));
    QVERIFY(pass);
}

void AutoTest::test_case6_cos()
{
    HPFloat tmp_a=a.HPFcos(),tmp_b=b.HPFcos();
    bool pass=(tmp_a.fuzzy_equal(cos_res_a) && tmp_b.fuzzy_equal(cos_res_b));
    QVERIFY(pass);
}

void AutoTest::test_case7_log()
{
    HPFloat tmp_a=a.log(),tmp_b=b.log();
    bool pass=(tmp_a.fuzzy_equal(log_res_a) && tmp_b.fuzzy_equal(log_res_b));
    QVERIFY(pass);
}

void AutoTest::test_case8_pow()
{
    HPFloat tmp=a.pow(b);
    bool pass=tmp.fuzzy_equal(pow_res);
    // 因为测试样例有时会缩减位数
    QVERIFY(pass);
}

void AutoTest::test_case9_conversion()
{
    HPFloat tmp_2=a.conversion(2);
    HPFloat tmp_2_10=tmp_2.reconversion(2);
    bool pass_2=(tmp_2.fuzzy_equal(conv_res_2)&&tmp_2_10.fuzzy_equal(a));
    HPFloat tmp_3=a.conversion(3);
    HPFloat tmp_3_10=tmp_3.reconversion(3);
    bool pass_3=(tmp_3.fuzzy_equal(conv_res_3)&&tmp_3_10.fuzzy_equal(a));
    HPFloat tmp_4=a.conversion(4);
    HPFloat tmp_4_10=tmp_4.reconversion(4);
    bool pass_4=(tmp_4.fuzzy_equal(conv_res_4)&&tmp_4_10.fuzzy_equal(a));
    HPFloat tmp_5=a.conversion(5);
    HPFloat tmp_5_10=tmp_5.reconversion(5);
    bool pass_5=(tmp_5.fuzzy_equal(conv_res_5)&&tmp_5_10.fuzzy_equal(a));
    HPFloat tmp_6=a.conversion(6);
    HPFloat tmp_6_10=tmp_6.reconversion(6);
    bool pass_6=(tmp_6.fuzzy_equal(conv_res_6)&&tmp_6_10.fuzzy_equal(a));
    HPFloat tmp_7=a.conversion(7);
    HPFloat tmp_7_10=tmp_7.reconversion(7);
    bool pass_7=(tmp_7.fuzzy_equal(conv_res_7)&&tmp_7_10.fuzzy_equal(a));
    HPFloat tmp_8=a.conversion(8);
    HPFloat tmp_8_10=tmp_8.reconversion(8);
    bool pass_8=(tmp_8.fuzzy_equal(conv_res_8)&&tmp_8_10.fuzzy_equal(a));
    HPFloat tmp_9=a.conversion(9);
    HPFloat tmp_9_10=tmp_9.reconversion(9);
    bool pass_9=(tmp_9.fuzzy_equal(conv_res_9)&&tmp_9_10.fuzzy_equal(a));
    HPFloat tmp_10=a.conversion(10);
    HPFloat tmp_10_10=tmp_10.reconversion(10);
    bool pass_10=(tmp_10.fuzzy_equal(conv_res_10)&&tmp_10_10.fuzzy_equal(a));
    HPFloat tmp_11=a.conversion(11);
    HPFloat tmp_11_10=tmp_11.reconversion(11);
    bool pass_11=(tmp_11.fuzzy_equal(conv_res_11)&&tmp_11_10.fuzzy_equal(a));
    HPFloat tmp_12=a.conversion(12);
    HPFloat tmp_12_10=tmp_12.reconversion(12);
    bool pass_12=(tmp_12.fuzzy_equal(conv_res_12)&&tmp_12_10.fuzzy_equal(a));
    HPFloat tmp_13=a.conversion(13);
    HPFloat tmp_13_10=tmp_13.reconversion(13);
    bool pass_13=(tmp_13.fuzzy_equal(conv_res_13)&&tmp_13_10.fuzzy_equal(a));
    HPFloat tmp_14=a.conversion(14);
    HPFloat tmp_14_10=tmp_14.reconversion(14);
    bool pass_14=(tmp_14.fuzzy_equal(conv_res_14)&&tmp_14_10.fuzzy_equal(a));
    HPFloat tmp_15=a.conversion(15);
    HPFloat tmp_15_10=tmp_15.reconversion(15);
    bool pass_15=(tmp_15.fuzzy_equal(conv_res_15)&&tmp_15_10.fuzzy_equal(a));
    HPFloat tmp_16=a.conversion(16);
    HPFloat tmp_16_10=tmp_16.reconversion(16);
    bool pass_16=(tmp_16.fuzzy_equal(conv_res_16)&&tmp_16_10.fuzzy_equal(a));
    QVERIFY(pass_2);
    QVERIFY(pass_3);
    QVERIFY(pass_4);
    QVERIFY(pass_5);
    QVERIFY(pass_6);
    QVERIFY(pass_7);
    QVERIFY(pass_8);
    QVERIFY(pass_9);
    QVERIFY(pass_10);
    QVERIFY(pass_11);
    QVERIFY(pass_12);
    QVERIFY(pass_13);
    QVERIFY(pass_14);
    QVERIFY(pass_15);
    QVERIFY(pass_16);
}

void AutoTest::test_case10_square()
{
    HPFloat tmp_a=a.square();
    bool pass=(tmp_a.fuzzy_equal(square_res));
    QVERIFY(pass);
}

void AutoTest::test_case11_cube()
{
    HPFloat tmp_a=a.cube();
    bool pass=(tmp_a.fuzzy_equal(cube_res));
    QVERIFY(pass);
}


QTEST_APPLESS_MAIN(AutoTest)

#include "tst_autotest.moc"
