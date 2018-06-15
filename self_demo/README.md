# gtest 编译demo
## 指定运行某一test  --gtest_filter=STRTEST.Test1 
## 可以在测试中不带有main函数，默认会有一个main函数
``` c++
GTEST_API_ int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return  RUN_ALL_TESTS();
}
### GTEST_API_的说明
#ifndef GTEST_API_

#ifdef _MSC_VER
# if GTEST_LINKED_AS_SHARED_LIBRARY
#  define GTEST_API_ __declspec(dllimport)
# elif GTEST_CREATE_SHARED_LIBRARY
#  define GTEST_API_ __declspec(dllexport)
# endif
#elif __GNUC__ >= 4 || defined(__clang__)
# define GTEST_API_ __attribute__((visibility ("default")))
#endif  // _MSC_VER

#endif  // GTEST_API_

#ifndef GTEST_API_
# define GTEST_API_
#endif  // GTEST_API_

/*
    gcc的visibility是说，如果编译的时候用了这个属性，那么动态库的符号都是hidden的，除非强制声明。
    visibility用于设置动态链接库中函数的可见性，将变量或函数设置为hidden，则该符号仅在本so中可见，在其他库中则不可见
    __declspec(dllimport) 引入宏,导入公共符号
    __declspec(dllexport) 导出宏,导出公共符号
    对于__declspec(dllimport)是否定义，问题不是很大，主要是两点：
    1. 维护问题。写了好代码，以后维护的时候容易
    2. 效率上会所有改善
    如果不使用 __declspec(dllimport)，那么编译生成的代码最终会类似：
    call 0xXXXXXXXX
    0xXXXXXXXX:  jmp dword ptr __imp_function
    而如果使用了dllimport，连接器会直接生成如下代码，省去中间的间接调用：
    call dword ptr __imp_func
*/
// 具体的细节可以参考这篇 https://bbs.csdn.net/topics/330169671

```
