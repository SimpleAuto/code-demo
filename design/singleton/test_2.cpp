/*
 *************************************************************************
 *    File Name:  test.cpp
 *       Author: Thomas Beijing,Inc.
 *         Mail: 982737593@qq.com
 * Created Time: 2018年06月16日 星期六 15时24分08秒
 * 
 *  Description: 模板类静态的类成员构造探析 
 * 
 *************************************************************************
*/
#include<iostream>
using namespace std;

template <typename T>
class Foo {
public:
   static std::size_t count() {
       return ctr;
   }
   void addctr() {
       ctr++;
   }
   void subctr() {
       ctr--;
   }
   class B
   {
       public:
        B(){
            std::cout << "BB()" << std::endl;
        }
   };
private:
   static std::size_t ctr;
   static B cc;
   // 下面可以有其他成员接口
};
template <typename T>
std::size_t Foo<T>::ctr;    //定义并初始化 ctr
template <typename T> typename Foo<T>::B Foo<T>::cc;

class Faa {
public:
   static std::size_t count() {
       return ctr;
   }
   void addctr() {
       ctr++;
   }
   void subctr() {
       ctr--;
   }
   Faa(){
       std::cout << "Faa()" << std::endl;
   }

   class B
   {
       public:
        B(){
            std::cout << "B()" << std::endl;
        }
   };
private:
   static std::size_t ctr;
   static B bbb;
   // 下面可以有其他成员接口
};
std::size_t Faa::ctr;
typename Faa::B Faa::bbb; 

int main()
{
    std::cout << "int main()" << std::endl;
    std::cout << "out main()" << std::endl;
	return 0;
}
