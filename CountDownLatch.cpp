//
// Created by Tomato on 2021/2/28.
//

#include "CountDownLatch.h"
#include "MutexLockGuard.h"

CountDownLatch::CountDownLatch(const int& count): mutex_(), condition_(mutex_), count_(count) {
}

void CountDownLatch::wait() {
    MutexLockGuard lock(mutex_);
    while (count_ > 0) {
        condition_.wait();
    }
}

void CountDownLatch::countDown() {
    MutexLockGuard lock(mutex_);
    --count_;
    if (count_ < 1) {
        condition_.notifyAll();
    }
}
