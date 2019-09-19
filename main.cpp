#include <iostream>
#include <list>
#include "container/learn_container.h"
#include <algorithm>
#include <Windows.h>

#include <atomic>
#include <thread>
#include <chrono>
#include "container/static_test.h"
int main() {
    std::chrono::system_clock::time_point begin = std::chrono::system_clock::now();
    Sleep(5);
    std::chrono::system_clock::time_point end = std::chrono::system_clock::now();
    auto duction=std::chrono::duration_cast<std::chrono::microseconds >(end - begin);
    std::cout << double(duction.count()) << std::endl;
    StaticTest::ConfigTimer::RecordStageTimerCost("test", begin, end, "");
    return 0;
}