/*
 *************************************************************************
 *    File Name:  test.cpp
 *       Author: Thomas Beijing,Inc.
 *         Mail: 982737593@qq.com
 * Created Time: 2018年06月16日 星期六 15时24分08秒
 * 
 *  Description: sf singleton 了解 
 * 
 *************************************************************************
*/
#include<iostream>
using namespace std;

/*
 *  编译器使用模板，通过更换模板参数来创建数据类型。这个过程就是模板实例化(Instantiation)。
 *  从模板类创建得到的类型称之为特例(specialization)。 
 *  模板实例化取决于编译器能够找到可用代码来创建特例(称之为实例化要素， point of instantiation)。
 *  要创建特例，编译器不但要看到模板的声明，还要看到模板的定义。 
 *  模板实例化过程是迟钝的，即只能用函数的定义来实现实例化。
 */

template<class T>
class singleton 
{            
public:      
    class creater
    {        
    public:  
        creater()
		{
			std::cout << "creater()" << std::endl;
            singleton<T>::getInstance();
        }    
        inline void do_nothing() const
		{
			std::cout << "do_nothing()" << std::endl;
		}    
    };       
    static T* getInstance()
    {        
		std::cout << "getInstance()" << std::endl;
        static T obj;
        m_creater.do_nothing();
        return &obj;
    }        
             
private:      
    static creater m_creater;
public:     
    singleton()
	{
		std::cout << "singleton()" << std::endl;
	}
};           
             
template<class T> typename singleton<T>::creater singleton<T>::m_creater;

class A
{
public:
	A()
	{
		std::cout << "A()" << std::endl;
	}

	~A()
	{
		 std::cout << "~A()" << std::endl;
	}

    void init()
    {
        std::cout << "A init()" << std::endl;
    }
};

class B
{
public:
	B()
	{
		std::cout << "B()" << std::endl;
	}

	~B()
	{
		 std::cout << "~B()" << std::endl;
	}

    void init()
    {
        std::cout << "B init()" << std::endl;
    }
};

int main()
{
    std::cout << "int main()" << std::endl;
    singleton<A>::getInstance()->init();
    singleton<B>::getInstance()->init();
    singleton<A>::getInstance()->init();
    std::cout << "out main()" << std::endl;
	return 0;
}
