/*
 *************************************************************************
 *    File Name:  thread_test_2.cpp
 *       Author: Thomas Beijing,Inc.
 *         Mail: 982737593@qq.com
 * Created Time: 2018年04月05日 星期四 15时43分02秒
 * 
 *  Description: ...
 * 
 *************************************************************************
*/
#include <pthread.h>  
#include <unistd.h>
#include<iostream>
using namespace std;

const int i=5;  
__thread int var=i;//两种方式效果一样  

static __thread int var2 = 15;//  

static void* worker1(void* arg);  
static void* worker2(void* arg);  

int main(){  
    pthread_t pid1,pid2;  

    static __thread  int temp=10;//修饰函数内的static变量  

    pthread_create(&pid1,NULL,worker1,NULL);  
    pthread_create(&pid2,NULL,worker2,NULL);  
    pthread_join(pid1,NULL);  
    pthread_join(pid2,NULL);  

    cout<<"main var addr :" << &var<<endl;
    cout<<"main var2 addr :" << &var2<<endl;
    cout<<temp<<endl;//输出10  
    return 0;  
}  

static void* worker1(void* arg){  
    cout<<"worker1 var :" << ++var<<endl;//输出 6  
    cout<<"worker1 var addr :" << &var<<endl;
    cout<<"worker1 var2 :" << ++var2<<endl;   
    cout<<"worker1 var2 addr :" << &var2<<endl;
}  

static void* worker2(void* arg){  
    sleep(1);//等待线程1改变var值，验证是否影响线程2  
    cout<< "worker2 var :" << --var<<endl;
    cout<<"worker2 var addr :" << &var<<endl;

    cout<<"worker2 var2 :" << --var2<<endl;   
    cout<<"worker2 var2 addr :" << &var2<<endl;
}
