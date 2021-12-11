//
// Created by Tomato on 2021/2/28.
//

#ifndef TOMATO_LIB_COUNT_DOWN_LATCH_H
#define TOMATO_LIB_COUNT_DOWN_LATCH_H

#include "MutexLock.h"
#include "Condition.h"

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
