//
// Created by Tomato on 2021/2/18.
//

#ifndef TOMATO_LIB_MUTEX_LOCK_GUARD_H
#define TOMATO_LIB_MUTEX_LOCK_GUARD_H

#include "MutexLock.h"

class MutexLockGuard {
public:
    explicit MutexLockGuard(MutexLock&);

    ~MutexLockGuard();

    MutexLockGuard(const MutexLockGuard&) = delete;

    MutexLockGuard& operator=(const MutexLockGuard&) = delete;
private:
    MutexLock& mutex_;
};

#endif //TOMATO_LIB_MUTEX_LOCK_GUARD_H
