//
// Created by Tomato on 2021/3/1.
//

#include <cstdio>
#include <vector>
#include "header/Singleton.h"

int main() {
    const std::vector<int>& singleton1 = Singleton<std::vector<int>>::getInstance();
    const std::vector<int>& singleton2 = Singleton<std::vector<int>>::getInstance();
    ::printf("hello world");
}