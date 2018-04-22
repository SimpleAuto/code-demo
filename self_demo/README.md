# gtest 编译demo
## 指定运行某一test  --gtest_filter=STRTEST.Test1 
## 可以在测试中不带有main函数，默认会有一个main函数
``` c++
    testing::InitGoogleTest(&argc, argv);
    return  RUN_ALL_TESTS();
```
