//
// Created by Tomato on 2021/2/28.
//

#ifndef TOMATO_LIB_CONDITION_H
#define TOMATO_LIB_CONDITION_H

#include "MutexLock.h"
#include <pthread.h>

class Condition {
public:
    explicit Condition(MutexLock&);

    ~Condition();

    Condition(const Condition&) = delete;

    Condition& operator=(const Condition&) = delete;

public:
    void wait();

    void notify();

    void notifyAll();

private:
    MutexLock& mutex_;
    pthread_cond_t cond_;
};


#endif //TOMATO_LIB_CONDITION_H
