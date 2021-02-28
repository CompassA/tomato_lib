//
// Created by Tomato on 2021/2/18.
//

#ifndef TOMATO_LIB_MUTEX_LOCK_H
#define TOMATO_LIB_MUTEX_LOCK_H

#include <pthread.h>
#include <unistd.h>

class MutexLock {
    friend class MutexLockGuard;
    friend class Condition;
public:
    MutexLock();

    ~MutexLock();

    MutexLock& operator=(const MutexLock&) = delete;

    MutexLock(const MutexLock&) = delete;

private:
    void lock();

    void unlock();

    pthread_mutex_t* getPthreadMutex();

private:
    pthread_mutex_t mutex_;
    pid_t holder_;
};


#endif //TOMATO_LIB_MUTEX_LOCK_H
