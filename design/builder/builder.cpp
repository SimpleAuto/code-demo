/*
 *************************************************************************
 *    File Name:  builder.cpp
 *       Author: Thomas Beijing,Inc.
 *         Mail: 982737593@qq.com
 * Created Time: 2018年05月20日 星期日 16时25分34秒
 * 
 *  Description: ...
 * 
 *************************************************************************
*/
#include<iostream>
using namespace std;

//car属性类
class Car
{
public:
    void setEngine(string engine){ m_Engine = engine;}
    void setWheel(string wheel){ m_Wheel = wheel;}
    void setBody(string body){ m_Body = body;}
    void disPlay(){
        std::cout << "Car engine:" << m_Engine << std::endl;
        std::cout << "Car wheel:" << m_Wheel  << std::endl;
        std::cout << "Car body:" << m_Body   << std::endl;
    }
private:
    string  m_Engine;
    string  m_Wheel;
    string  m_Body;
};

//建造者模式抽象类，组装流程
class Assemble
{
public:
    virtual void assembleEngine(){};
    virtual void assembleWheel(){};
    virtual void assembleBody(){};
    virtual Car* getCar(){ return NULL;};
};

//a型车组装流程
class AssembleCarA : public Assemble
{
public:
    AssembleCarA(){ _carA = new Car();}
    virtual void assembleEngine( ){ _carA->setEngine("engineA");};
    virtual void assembleWheel( ){ _carA->setWheel("whellA");}
    virtual void assembleBody( ){ _carA->setBody("bodyA");};
    virtual Car* getCar(){ return _carA; }
private:
    Car *_carA;
};

//b型车组装流程
class AssembleCarB : public Assemble
{
public:
    AssembleCarB(){ _carB = new Car();}
    virtual void assembleEngine( ){ _carB->setEngine("engineB");};
    virtual void assembleWheel( ){ _carB->setWheel("wheelB");}
    virtual void assembleBody( ){ _carB->setBody("bodyB");};
    virtual Car* getCar(){ return _carB; }
private:
    Car *_carB;
};

//工厂类
class Factory
{
public:
    Factory(Assemble* assemble){ m_assemble = assemble;}
    void assembleCar(){
        m_assemble->assembleEngine();
        m_assemble->assembleWheel();
        m_assemble->assembleBody();
    }
    Car* getCar(){return m_assemble->getCar();}
private:
    Assemble* m_assemble;
};

int main()
{
    Assemble *m_assemble = new AssembleCarA();
    Factory  *m_factory  = new Factory(m_assemble);
    m_factory->assembleCar();
    m_factory->getCar()->disPlay();

    Assemble *m_assemble_ = new AssembleCarB();
    Factory  *m_factory_  = new Factory(m_assemble_);
    m_factory_->assembleCar();
    m_factory_->getCar()->disPlay();    

    return 0;
}
