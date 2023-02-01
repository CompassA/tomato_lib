/*
 * @Author: Tomato
 * @Date: 2023-01-28 22:14:24
 * @LastEditTime: 2023-02-01 22:04:17
 */
#include <gtest/gtest.h>
#include <tomato/SmartPointer.h>
#include <string.h>
#include <utility>

namespace tomato {
struct TestClassA {
    int v1;
    std::string v2;

    TestClassA(const int& a, const std::string& b): v1(a), v2(b) {}

    virtual std::string echo() {
        return "ClassA";
    }

    virtual ~TestClassA() {}
};

struct TestClassB: public TestClassA {
    
    TestClassB(const int& a, const std::string& b): TestClassA(a, b) {}

    virtual std::string echo() override {
        return "ClassB";
    }
};

struct TestClassC {
    TestClassC(const int a, int &b, int && c): a_(a), b_(b), c_(c) {}

    int a_;
    int b_;
    int c_;
};

class SmartPointerTest: public ::testing::Test {
protected:
    virtual void SetUp() override {
        p1_ = SmartPointer<TestClassA>(new TestClassA(123, "test_str_1"));
        p2_ = SmartPointer<TestClassA>(new TestClassA(456, "test_str_2"));
    }

    virtual void TearDown() override {
    }
    
public:
    SmartPointer<TestClassA> p1_;
    SmartPointer<TestClassA> p2_;
};


TEST_F(SmartPointerTest, smart_pointer_val_test) {
    const int v1 = 12;
    const std::string v2 = "test_str";
    SmartPointer<TestClassA> p{new TestClassA(v1, v2)};
    EXPECT_EQ(v1, p->v1);
    EXPECT_EQ(v2, p->v2);
}

TEST_F(SmartPointerTest, operator_copy_test) {  
    p2_ = p1_;
    
    EXPECT_EQ(p1_->v1, p2_->v1);
    EXPECT_EQ(p1_->v2, p2_->v2);
    EXPECT_EQ(p1_.get_point_count(), p2_.get_point_count());
    EXPECT_EQ(p2_.get_point_count(), 2);
}

TEST_F(SmartPointerTest, swap_test) {
    SmartPointer<TestClassA> p3 = p1_;
    swap(p1_, p2_);
    
    EXPECT_EQ(p1_->v1, 456);
    EXPECT_EQ(p1_->v2, "test_str_2");
    EXPECT_EQ(p2_->v1, 123);
    EXPECT_EQ(p2_->v2, "test_str_1");
    EXPECT_EQ(p1_.get_point_count(), 1);
    EXPECT_EQ(p2_.get_point_count(), 2);
}

TEST_F(SmartPointerTest, pointer_cast_test) {
    SmartPointer<TestClassB> p1{new TestClassB(123, "test_str1")};
    SmartPointer<TestClassA> p2{p1};
    EXPECT_EQ(p1.get_point_count(), p2.get_point_count());
    EXPECT_EQ(p2.get_point_count(), 2);
    EXPECT_EQ(p1->v1, p2->v1);
    EXPECT_EQ(p1->v2, p2->v2);
    EXPECT_EQ(p2->echo(), "ClassB");
}

TEST_F(SmartPointerTest, move_construct_test) {
    SmartPointer<TestClassA> p2 = p1_;

    SmartPointer<TestClassA> p3 = std::move(p1_);
    SmartPointer<TestClassA> p4 = std::move(p2);
    
    EXPECT_EQ(p1_.operator->(), nullptr);
    EXPECT_EQ(p2.operator->(), nullptr);
    EXPECT_EQ(p3.get_point_count(), 2);
    EXPECT_EQ(p4.get_point_count(), 2);
    EXPECT_EQ(p3->v1, p4->v1);
    EXPECT_EQ(p3->v2, p4->v2);
}

TEST_F(SmartPointerTest, make_shard_forward_test) {
    int b = 2;
    SmartPointer<TestClassC> p = make_shared<TestClassC>(1, b, 3);
    EXPECT_EQ(p->a_, 1);
    EXPECT_EQ(p->b_, b);
    EXPECT_EQ(p->c_, 3);
    EXPECT_EQ(p.get_point_count(), 1);
}

}