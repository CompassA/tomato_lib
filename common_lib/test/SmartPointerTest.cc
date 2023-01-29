/*
 * @Author: Tomato
 * @Date: 2023-01-28 22:14:24
 * @LastEditTime: 2023-01-29 22:30:26
 */
#include <gtest/gtest.h>
#include <tomato/SmartPointer.h>
#include <string.h>
struct tomato_smart_test {
    int v1;
    std::string v2;

    tomato_smart_test(const int& v1, const std::string& v2)
        : v1(v1), v2(v2) {}
};

TEST(SMART_POINTER, smart_pointer_val_test) {
    using namespace tomato;
    using namespace std;

    const int v1 = 12;
    const string v2 = "test_str";
    SmartPointer<tomato_smart_test> p = SmartPointer<tomato_smart_test>(new tomato_smart_test(v1, v2));
    EXPECT_EQ(v1, p->v1);
    EXPECT_EQ(v2, p->v2);
}

TEST(SMART_POINTER, smart_pointer_scope_test) {
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
}