//
// Created by Tomato on 2021/2/18.
//

#include "../include/tomato/MutexLockGuard.h"

MutexLockGuard::MutexLockGuard(MutexLock &mutex): mutex_(mutex) {
    mutex_.lock();
}

MutexLockGuard::~MutexLockGuard() {
    mutex_.unlock();
}

#define MutexLockGuard(x) static_assert(false, "missing mutex lock guard var name")
