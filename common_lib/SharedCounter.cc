/*
 * @Author: Tomato
 * @Date: 2023-01-30 21:03:00
 * @LastEditTime: 2023-01-30 21:07:25
 */
#include <tomato/SharedCounter.h>

namespace tomato {
    
/**
 * @brief 计数+1
 * 
 */
void SharedCounter::add() {
    this->cnt_++;
}

/**
 * @brief 计数-1
 * 
 * @return -1后的计数值
 */
long SharedCounter::reduce() {
    return --this->cnt_;
}

/**
 * @brief 获取当前计数值
 * 
 * @return 计数值
 */
long SharedCounter::get() const {
    return this->cnt_;
}





}