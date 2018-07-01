/*
 *************************************************************************
 *    File Name:  test.cpp
 *       Author: Thomas Beijing,Inc.
 *         Mail: 982737593@qq.com
 * Created Time: 2018年06月27日 星期三 16时22分11秒
 * 
 *  Description: ...
 * 
 *************************************************************************
*/
#include <iostream>
#include "cout_color.h"
using namespace std;
            
# define U 0.06
# define V 0.025
            
# define M 1.1
# define N 1.2

int main(void)
{           
    float x, y;
    float m, n;
            
    for ( y=1.5; y>=-1.5; y-=U )
    {       
        for ( x=-1.2; x<=1.2; x+=V)
        {   
            if ( ( ( (x*x + y*y - 1)*(x*x + y*y - 1)*(x*x + y*y - 1) - x*x*y*y*y ) <= 0 ) ) 
                std::cout << BOLDWHITE << "*";
            else
                std::cout << " ";
        }   
        std::cout << std::endl;
    }       

    std::cout << BOLDWHITE << "                                    亲爱的猪猪侠,生日快乐!!!                                 " << std::endl;
    return 0;
} 
