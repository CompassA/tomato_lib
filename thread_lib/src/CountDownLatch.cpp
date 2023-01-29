/*
 * @Author: Tomato
 * @Date: 2023-01-29 22:37:10
 * @LastEditTime: 2023-01-29 22:43:01
 */

#include <tomato/CountDownLatch.h>
#include <tomato/MutexLockGuard.h>

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
