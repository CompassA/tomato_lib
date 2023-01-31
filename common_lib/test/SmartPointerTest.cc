/*
 * @Author: Tomato
 * @Date: 2023-01-28 22:14:24
 * @LastEditTime: 2023-01-31 22:28:09
 */
#include <gtest/gtest.h>
#include <tomato/SmartPointer.h>
#include <string.h>

namespace tomato {
struct TestClassA {
    int v1;
    std::string v2;

    TestClassA(const int& v1, const std::string& v2): v1(v1), v2(v2) {}

    virtual std::string echo() {
        return "ClassA";
    }
};

struct TestClassB: public TestClassA {
    
    TestClassB(const int& v1, const std::string& v2): TestClassA(v1, v2) {}

    virtual std::string echo() override {
        return "ClassB";
    }
};

TEST(SMART_POINTER, smart_pointer_val_test) {
    const int v1 = 12;
    const std::string v2 = "test_str";
    SmartPointer<TestClassA> p = SmartPointer<TestClassA>(new TestClassA(v1, v2));
    EXPECT_EQ(v1, p->v1);
    EXPECT_EQ(v2, p->v2);
}

TEST(SMART_POINTER, operator_copy_test) {  
    SmartPointer<TestClassA> p1 = SmartPointer<TestClassA>(new TestClassA(123, "test_str_1"));
    SmartPointer<TestClassA> p2 = SmartPointer<TestClassA>(new TestClassA(456, "test_str_2"));
    p2 = p1;
    
    EXPECT_EQ(p1->v1, p2->v1);
    EXPECT_EQ(p1->v2, p2->v2);
    EXPECT_EQ(p1.get_point_count(), p2.get_point_count());
    EXPECT_EQ(p2.get_point_count(), 2);
}

TEST(SMART_POINTER, swap_test) {
    SmartPointer<TestClassA> p1 = SmartPointer<TestClassA>(new TestClassA(123, "test_str_1"));
    SmartPointer<TestClassA> p2 = SmartPointer<TestClassA>(new TestClassA(456, "test_str_2"));
    SmartPointer<TestClassA> p3 = p1;
    swap(p1, p2);
    
    EXPECT_EQ(p1->v1, 456);
    EXPECT_EQ(p1->v2, "test_str_2");
    EXPECT_EQ(p2->v1, 123);
    EXPECT_EQ(p2->v2, "test_str_1");
    EXPECT_EQ(p1.get_point_count(), 1);
    EXPECT_EQ(p2.get_point_count(), 2);
}

TEST(SMART_POINTER, pointer_cast_test) {
    SmartPointer<TestClassB> p1 = SmartPointer<TestClassB>(new TestClassB(123, "test_str1"));
    SmartPointer<TestClassA> p2 = p1;
    EXPECT_EQ(p1.get_point_count(), p2.get_point_count());
    EXPECT_EQ(p2.get_point_count(), 2);
    EXPECT_EQ(p1->v1, p2->v1);
    EXPECT_EQ(p1->v2, p2->v2);
    EXPECT_EQ(p2->echo(), "ClassB");
}

}