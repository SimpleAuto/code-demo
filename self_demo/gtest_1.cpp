/*
 *************************************************************************
 *    File Name:  gtest_1.cpp
 *       Author: Thomas Beijing,Inc.
 *         Mail: 982737593@qq.com
 * Created Time: 2018年04月21日 星期六 23时23分40秒
 * 
 *  Description: ...
 * 
 *************************************************************************
*/
#include<iostream>
using namespace std;

#include <gtest/gtest.h>

int func_1(int a, int b, int c, int d)
{
    return (a+c) - (b+d);
}

TEST(func_1Test, Test1)
{
    EXPECT_EQ(2, func_1(4,3,2,1));
}

TEST(STRTEST,Test1)
{
    std::string str_1 = "hello";
    std::string str_2(str_1);
    EXPECT_EQ(str_1, str_2);
    EXPECT_STREQ(str_1.c_str(), str_2.c_str());
}

TEST(STRTEST,Test2)
{
    std::string str_1 = "hello";
    std::string str_2 = "world";
    EXPECT_EQ(str_1, str_2);
    EXPECT_STREQ(str_1.c_str(), str_2.c_str());
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
