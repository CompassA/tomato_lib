#ifndef SMART_POINTER_H
#define SMART_POINTER_H
 
#include <utility>

#include <tomato/SharedCounter.h>

namespace tomato {

/**
 * @brief 智能指针
 * 
 * @tparam T 指针类型 
 */
template <typename T>
class SmartPointer {
public: 
    template <typename U>
    friend class SmartPointer;

public:
    /**
     * 
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
     * @brief 拷贝构造
     * 
     * @param rhs 
     */
    SmartPointer(const SmartPointer& rhs);

    /**
     * @brief 移动拷贝构造
     * 
     * @param rhs 
     */
    SmartPointer(SmartPointer&& rhs);

    /**
     * @brief 赋值运算符
     * 
     * @param rhs 
     * @return SmartPointer& 
     */
    SmartPointer& operator=(SmartPointer rhs) noexcept;

    /**
     * @brief 支持父子类指针构造
     * 
     * @tparam U 同类或子类
     * @param rhs 
     */
    template <typename U>
    SmartPointer(const SmartPointer<U> &rhs);

    /**
     * @brief 支持父子指针移动构造
     * 
     * @tparam U 同类或子类
     * @param rhs 
     */
    template <typename U>
    SmartPointer(SmartPointer<U> &&rhs);

    /**
     * @brief 析构时释放内存  
     * 
     */
    ~SmartPointer();

    /**
     * @brief 与另一个智能指针交换
     * 
     * @param rhs 
     */
    void swap(SmartPointer& rhs) noexcept;
    
    /**
     * @brief 
     * 
     * @return T& 
     */
    T& operator*() const noexcept;
 
    /**
     * @brief 获取成员变量
     * 
     * @return T* 
     */
    T* operator->() const noexcept;
    
    /**
     * @brief 
     * 
     * @return true 指针非空
     * @return false 指针为空
     */
    operator bool() const noexcept;

    /**
     * @brief 获取当前计数值
     * 
     * @return long 
     */
    long get_point_count();

private:
    T* ptr_;
    SharedCounter* counter_;
};

template <typename T>
SmartPointer<T>::SmartPointer(const SmartPointer& rhs) {
    this->ptr_ = rhs.ptr_;
    if (this->ptr_) {
        rhs.counter_->add();
        this->counter_ = rhs.counter_;
    }
}

template <typename T>
SmartPointer<T>::SmartPointer(SmartPointer&& rhs) {
    this->ptr_ = rhs.ptr_;
    this->counter_ = rhs.counter_;
    rhs.ptr_ = nullptr;
    rhs.counter_ = nullptr;
}

template <typename T>
SmartPointer<T>& SmartPointer<T>::operator=(SmartPointer<T> rhs) noexcept {
    rhs.swap(*this);
    return *this;
}

template <typename T>
SmartPointer<T>::~SmartPointer() {
    if (ptr_ && !counter_->reduce()) {
        delete ptr_;
        delete counter_;
        ptr_ = nullptr;
        counter_ = nullptr;
    } 
}

template <typename T>
void SmartPointer<T>::swap(SmartPointer& rhs) noexcept {
    using std::swap;
    swap(ptr_, rhs.ptr_);
    swap(counter_, rhs.counter_);
}

template <typename T>
T& SmartPointer<T>::operator*() const noexcept {
    return *ptr_;
}

template <typename T>
T* SmartPointer<T>::operator->() const noexcept {
    return ptr_;
}

template <typename T>
SmartPointer<T>::operator bool() const noexcept {
    return ptr_;
}

template <typename T>
long SmartPointer<T>::get_point_count() {
    return this->counter_->get();
}


template <typename T>
void swap(SmartPointer<T> &lhs, SmartPointer<T> &rhs) noexcept {
    lhs.swap(rhs);
}

template <typename T>
template <typename U>
SmartPointer<T>::SmartPointer(const SmartPointer<U> &rhs) {
    this->ptr_ = rhs.ptr_;
    if (this->ptr_) {
        this->counter_ = rhs.counter_;
        this->counter_->add();
    }
}

template <typename T>
template <typename U>
SmartPointer<T>::SmartPointer(SmartPointer<U> &&rhs) {
    this->ptr_ = rhs.ptr_;
    this->counter_ = rhs.counter_;
    rhs.ptr_ = nullptr;
    rhs.counter_ = nullptr;
}


}
#endif