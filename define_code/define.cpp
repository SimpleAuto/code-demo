/*
 *************************************************************************
 *    File Name:  define.cpp
 *       Author: Thomas Beijing,Inc.
 *         Mail: 982737593@qq.com
 * Created Time: 2018年08月31日 星期五 17时02分58秒
 * 
 *  Description: ...
 * 
 *************************************************************************
*/
#include<iostream>
using namespace std;

#define GENERAL_FUNC(name) \
{ \
    name = "123"; \
}

int main()
{
    std::string str;
    GENERAL_FUNC(str);
    std::cout << str << std::endl;
    return 0;
}
