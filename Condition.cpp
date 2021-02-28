//
// Created by Tomato on 2021/2/28.
//

#include "Condition.h"

Condition::Condition(MutexLock& mutex_lock): mutex_(mutex_lock) {
    pthread_cond_init(&cond_, nullptr);
}

Condition::~Condition() {
    pthread_cond_destroy(&cond_);
}

void Condition::wait() {
    pthread_cond_wait(&cond_, mutex_.getPthreadMutex());
}

void Condition::notify() {
    pthread_cond_signal(&cond_);
}

void Condition::notifyAll() {
    pthread_cond_broadcast(&cond_);
}
