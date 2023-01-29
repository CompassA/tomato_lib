/*
 * @Author: Tomato
 * @Date: 2023-01-29 22:40:36
 * @LastEditTime: 2023-01-29 22:40:36
 */

#include <tomato/MutexLockGuard.h>

MutexLockGuard::MutexLockGuard(MutexLock &mutex): mutex_(mutex) {
    mutex_.lock();
}

MutexLockGuard::~MutexLockGuard() {
    mutex_.unlock();
}

#define MutexLockGuard(x) static_assert(false, "missing mutex lock guard var name")
