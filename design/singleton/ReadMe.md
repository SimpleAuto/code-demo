####test_del 是注释了m_creater.donothing()
####test_ori 是原始版本
####test_sg  是测试注释了m_creater.donothing()之后,单例对象在不同线程中是否是同一份
####makefile中没有del和ori的make,这个需要更改源文件test.cpp才能达到目标

####存在差异,m_creater是否被创建
####涉及到C++的一个哲学观点：不要为不必要的成本付出代价。所以C++编译器通常只有第一次使用静态变量时才会进行初始化
####更具体的解释可以看test.cpp中的注释
