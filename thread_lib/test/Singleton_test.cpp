/*
 * @Author: Tomato
 * @Date: 2023-01-29 22:35:03
 * @LastEditTime: 2023-01-29 22:43:24
 */
#include <gtest/gtest.h>
#include <tomato/Singleton.h>
#include <stack>

TEST(SINGLETON, singleton_test) {
    std::stack<int>& v1 = tomato::Singleton<std::stack<int>>::getInstance();
    std::stack<int>& v2 = tomato::Singleton<std::stack<int>>::getInstance();
    v1.push(1);
    v2.push(2);
    EXPECT_EQ(v1, v2);
    EXPECT_EQ(2, v1.top());
    v1.pop();
    EXPECT_EQ(1, v2.top());
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
}