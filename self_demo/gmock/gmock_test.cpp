/*
 *************************************************************************
 *    File Name:  gmock_test.cpp
 *       Author: Thomas Beijing,Inc.
 *         Mail: 982737593@qq.com
 * Created Time: 2018年06月11日 星期一 17时51分49秒
 * 
 *  Description: ...
 * 
 *************************************************************************
*/
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include<iostream>
using namespace std;
using namespace testing;

class User {
public:
// 析构函数 必须是虚函数 
// 方法也得定义为纯虚函数
    virtual ~User(){ }   
public:
	virtual bool Login(const std::string& username, const std::string& password) = 0;    
	virtual bool Pay(int money) = 0;
    virtual bool Online() = 0;  
};

class TestUser : public User {
public:
// 有几个参数对应MOCK_METHOD后面跟的数字
	MOCK_METHOD2(Login, bool(const std::string&, const std::string&));                                   
	MOCK_METHOD1(Pay, bool(int));
    MOCK_METHOD0(Online, bool());
//Mock_METHOD#1(#2, #3(#4))
//#1是要Mock的方法有几个参数
//#2是要Mock的方法名称
//#3是要Mock的方法的返回值
//#4是要Mock的方法的具体参数
};

class Biz {
public:
    void SetUser(User* user) {
        _user = user;
    }

    std::string pay(const std::string& username, const std::string& password, int money) {
        std::string ret;
        if (!_user) {
            ret = "pointer is null.";
            return ret;
        }
        
        if (!_user->Online()) {
            ret = "logout status.";
            // 尚未登录，要求登录
            if (!_user->Login(username, password)) {
                // 登录失败
                ret += "login error.";
                return ret;
            } else {
                // 登录成功
                ret += username;
                ret += " login success.";
            }
        } else {
            // 已登录
            ret = "login.status";
        }

        if (!_user->Pay(money)) {
            ret += "pay error.";
        } else {
            ret += "pay success.";
        }

        return ret;
    }

private:
    User* _user;
};

TEST(GMOCK_TEST, uers)
{
    TestUser test_user;
    EXPECT_CALL(test_user, Online()).WillRepeatedly(Return(false));
    EXPECT_CALL(test_user, Login(StrNe("admin"), _)).WillRepeatedly(Return(true));
	EXPECT_CALL(test_user, Pay(_)).Times(4).WillOnce(Return(true)).WillOnce(Return(true)).WillRepeatedly(Return(false));

    Biz biz;
    biz.SetUser(&test_user);
    string user_ret = biz.pay("user", "", 1);
    cout << "test4 ret value: " << user_ret << endl;

    user_ret = biz.pay("user", "", 1);
    cout << "test4 ret value: " << user_ret << endl;

    user_ret = biz.pay("admin", "", 1);
    //user_ret = biz.pay("admins", "", 1);
    cout << "test4 ret value: " << user_ret << endl;

    user_ret = biz.pay("user", "", 1);
    cout << "test4 ret value: " << user_ret << endl;
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
