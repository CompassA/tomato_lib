/*
 * @Author: Tomato
 * @Date: 2023-01-29 22:36:39
 * @LastEditTime: 2023-01-29 22:36:40
 */

#ifndef TOMATO_LIB_MUTEX_LOCK_GUARD_H
#define TOMATO_LIB_MUTEX_LOCK_GUARD_H

#include <tomato/MutexLock.h>

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
