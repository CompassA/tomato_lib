/*
 * @Author: Tomato
 * @Date: 2023-01-29 22:40:24
 * @LastEditTime: 2023-01-29 22:40:25
 */

#include <cassert>
#include <tomato/MutexLock.h>

MutexLock::MutexLock(): holder_(0) {
    pthread_mutex_init(&mutex_, nullptr);
}

MutexLock::~MutexLock() {
    assert(holder_ == 0);
    pthread_mutex_destroy(&mutex_);
}

void MutexLock::lock() {
    pthread_mutex_lock(&mutex_);
    //holder_ = CurrentThread::tid();
}

void MutexLock::unlock() {
    holder_ = 0;
    pthread_mutex_unlock(&mutex_);
}

pthread_mutex_t *MutexLock::getPthreadMutex() {
    return &mutex_;
}
