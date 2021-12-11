//
// Created by Tomato on 2021/2/28.
//

#ifndef TOMATO_LIB_SINGLETON_H
#define TOMATO_LIB_SINGLETON_H

#include <pthread.h>

namespace tomato {

template<typename T>
class Singleton {
public:
    Singleton() = delete;

    ~Singleton() = delete;

    Singleton(const Singleton&) = delete;

    Singleton& operator=(const Singleton&) = delete;

public:
    static T& getInstance() {
        pthread_once(&p_once_, &Singleton::init);
        return *value_;
    }

private:
    static void init() {
        value_ = new T();
    }

private:
    static pthread_once_t p_once_;

    static T* value_;
};


template<typename T>
pthread_once_t Singleton<T>::p_once_ = PTHREAD_ONCE_INIT;

template<typename T>
T* Singleton<T>::value_ = nullptr;

}
#endif //TOMATO_LIB_SINGLETON_H
