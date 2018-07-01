/*
 *************************************************************************
 *    File Name:  CoutEchoColor.cpp
 *       Author: Thomas Beijing,Inc.
 *         Mail: 982737593@qq.com
 * Created Time: 2018年06月20日 星期三 12时43分25秒
 * 
 *  Description: ...
 * 
 *************************************************************************
*/
#include<iostream>
using namespace std;

#include <iostream>
 
//the following are UBUNTU/LINUX ONLY terminal color codes.
#define RESET   "\033[0m"
#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */
#define MAGENTA "\033[35m"      /* Magenta */
#define CYAN    "\033[36m"      /* Cyan */
#define WHITE   "\033[37m"      /* White */
#define BOLDBLACK   "\033[1m\033[30m"      /* Bold Black */
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
#define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
#define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
#define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */
#define BOLDWHITE   "\033[1m\033[37m"      /* Bold White */
 
int main(int argc, const char * argv[])
{
    // insert code here...
    std::cout<<RED      <<"Hello, World! in RED\n";
    std::cout<<GREEN    <<"Hello, World! in GREEN\n";
    std::cout<<YELLOW   <<"Hello, World! in YELLOW\n";
    std::cout<<BLUE     <<"Hello, World! in BLUE\n";
    std::cout<<MAGENTA  <<"Hello, World! in MAGENTA\n";
    std::cout<<CYAN     <<"Hello, World! in CYAN\n";
    std::cout<<WHITE    <<"Hello, World! in WHITE\n";
    std::cout<<BOLDRED  <<"Hello, World! in BOLDRED\n";
    std::cout<<BOLDCYAN <<"Hello, World! in BOLDCYAN\n";
    return 0;
}
