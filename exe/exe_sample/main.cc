#include <cstdio>
#include <tsample.h>
#include <tomato/Singleton.h>
#include <vector>
#include <numeric>

int main() {
    for (int i = 0; i < 10; ++i) {
        tomato::Singleton<std::vector<int>>::getInstance().push_back(i);
    }

    std::vector<int>& v = tomato::Singleton<std::vector<int>>::getInstance();
    int sum = std::accumulate(v.begin(), v.end(), 0);

    ::printf("hello world, sum = %d\n", sum);
    return 0;
}