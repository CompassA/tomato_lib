/*
 * @Author: Tomato
 * @Date: 2023-01-29 22:35:52
 * @LastEditTime: 2023-01-29 22:35:52
 */

#ifndef TOMATO_LIB_COUNT_DOWN_LATCH_H
#define TOMATO_LIB_COUNT_DOWN_LATCH_H

#include <tomato/MutexLock.h>
#include <tomato/Condition.h>

class CountDownLatch {
public:
    explicit CountDownLatch(const int&);
    ~CountDownLatch() = default;
    CountDownLatch(const CountDownLatch&) = delete;
    CountDownLatch& operator=(const CountDownLatch&) = delete;

public:
    void wait();
    void countDown();

private:
    MutexLock mutex_;
    Condition condition_;
    int count_;
};


#endif //TOMATO_LIB_COUNT_DOWN_LATCH_H
