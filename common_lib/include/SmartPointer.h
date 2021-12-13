#ifndef SMART_POINTER_H
#define SMART_POINTER_H
 
#include <utility>

namespace tomato {

/**
 * @brief 指针计数
 * 
 */
class SharedCounter {
public:
    explicit SharedCounter(): cnt_(1) {
    }

    void add() {
        ++cnt_;
    }

    long reduce() {
        return --cnt_;
    }

    long get() const {
        return cnt_;
    }

private:
    long cnt_;
};
   
/**
 * @brief 智能指针
 * 
 * @tparam T 指针类型 
 */
template <typename T>
class SmartPointer {
public:
    /**
     * @brief 构造时传入裸指针
     * 
     * @param ptr 
     */
    explicit SmartPointer(T* ptr = nullptr): ptr_(ptr) {
        if (ptr) {
            counter_ = new SharedCounter();
        }
    }
    
    /**
     * @brief 析构时释放内存  
     * 
     */
    ~SmartPointer() {
        if (ptr_ && !counter_->reduce()) {
            delete ptr_;
            delete counter_;
            ptr_ = nullptr;
            counter_ = nullptr;
        }
    }

    SmartPointer(const SmartPointer& rhs) {
        ptr_ = rhs.ptr_;
        if (ptr_) {
            rhs.counter_->add();
            counter_ = rhs.counter_;
        }
    }

    SmartPointer& operator=(SmartPointer rhs) noexcept {
        rhs.swap(*this);
        return *this;
    }


    void swap(SmartPointer& rhs) noexcept {
        using std::swap;
        swap(ptr_, rhs.ptr_);
        swap(counter_, rhs.counter_);
    }

    /**
     * @brief 
     * 
     * @return T& 
     */
    T& operator*() const {
        return *ptr_;
    }
 
    /**
     * @brief 获取成员变量
     * 
     * @return T* 
     */
    T* operator->() const {
        return ptr_;
    }
    
    /**
     * @brief 
     * 
     * @return true 指针非空
     * @return false 指针为空
     */
    operator bool() const {
        return ptr_;
    }
private:
    T* ptr_;
    SharedCounter* counter_;
};



}
#endif