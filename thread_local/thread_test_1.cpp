/*
 *************************************************************************
 *    File Name:  thread_test_1.cpp
 *       Author: Thomas Beijing,Inc.
 *         Mail: 982737593@qq.com
 * Created Time: 2018年04月05日 星期四 15时32分50秒
 * 
 *  Description: test thread_local 
 * 
 *************************************************************************
*/
#include <iostream>
#include <future>
#include <vector>
#include <chrono>
#include <random>
using namespace std;
using namespace chrono;

// C++11 随机数产生器 default_random_engine
thread_local default_random_engine dre;

vector<int> test_dre(int seed)
{
    // 设置种子
    dre.seed(seed);
    int vecSize = 10;
    vector<int> temp(vecSize);
    for (int i = 0; i < vecSize; ++i)
    {
        temp[i] = dre();
        this_thread::sleep_for(milliseconds(100));
    }
    return temp;
}

bool equal(const vector<int> &v1, const vector<int> &v2)
{
    int size1 = v1.size();
    int size2 = v2.size();
    if (size1 != size2)
        return false;

    for (int i = 0; i < size1; ++i)
    {
        if (v1[i] != v2[i])
            return false;
    }
    return true;
}

int main()
{
    int numThread = 2;
    using returnType = vector<int>;

    // std::future可以从异步任务中获取结果，一般与std::async配合使用，std::async用于创建异步任务，实际上就是创建一个线程执行相应任务
    future<returnType> future1 = async(test_dre, 0);
    returnType result2 = test_dre(0);
    returnType result1 = future1.get();

    if (equal(result1, result2))
        cout << "they are equal" << endl;
    else
        cout << "they are not equal" << endl;

    return 0;
}
