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
    EXPECT_EQ(3, func_1(4,3,2,1));
}
